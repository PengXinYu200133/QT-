// 包含其他窗口类头文件
#include "in.h"
#include "newroom.h"
#include "reservation.h"
#include "report_the_loss_of.h"
#include "check_out.h"

#include "esp8266.h"  // 包含ESP8266头文件
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QDebug>
#include <QTimer>
#include "reservation.h"
#include "available_room_list.h"
#include "reservation_list.h"
#include "card_replacement.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

extern ESP8266 *globalESP;
QDateTime globaltime;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(globalESP, &ESP8266::getDateCommandReceived, this, &MainWindow::senddate);
    connect(this, &MainWindow::sendjson, globalESP, &ESP8266::sendjson);
    connect(this, &MainWindow::gettime, globalESP, &ESP8266::getTime);
    connect(globalESP, &ESP8266::dateTimeParsed, this, &MainWindow::updateDateTimeEdit); // 连接时间信号
    // 连接 IP 地址信号到槽函数
    connect(globalESP, &ESP8266::ipAddressReceived, this, &MainWindow::displayIPAddress);
    connect(this, &MainWindow::findip, globalESP, &ESP8266::findIP);
    connect(this, &MainWindow::cleanreservation, this, &MainWindow::cleanreservation_list);
    myfindip();
    // 创建一个 QTimer 对象
    QTimer *timer = new QTimer(this);


    // 连接定时器信号到槽
    connect(timer, &QTimer::timeout, this, [this]() {
        // 每次触发时增加一秒
        customDateTime = customDateTime.addSecs(1);
        // 更新 QDateTimeEdit 的值
        ui->dateTimeEdit->setDateTime(customDateTime);
        globaltime = customDateTime;
        //qDebug() << "更新 QDateTimeEdit：" << globaltime;
        if (customDateTime.time().hour() == 0 && customDateTime.time().minute() == 0 && customDateTime.time().second() == 0) {
            emit cleanreservation(); // 发出信号
            qDebug() << "到晚上12点了清理这个时间段以前的预约记录！" << customDateTime;
        }
    });

    // 启动定时器，每秒触发一次
    timer->start(1000);

}

MainWindow::~MainWindow() {

    delete ui;
}
void MainWindow::cleanreservation_list() {
    // 确保数据库连接已打开
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("User.db");
    if (!db.open()) {
        qDebug() << "数据库连接失败：" << db.lastError().text();
        return;
    }

    QSqlQuery query(db);
    QSqlQuery updateQuery(db);

    // 查询 reservation 表中 state = 0 且 expect_check_in_time 小于当前时间的记录
    query.prepare("SELECT room_id FROM reservation WHERE state = 0 AND expect_check_in_time < :currentTime");
    query.bindValue(":currentTime", globaltime.toString("yyyy-MM-dd hh:mm:ss"));

    if (query.exec()) {
        while (query.next()) {
            QString roomId = query.value("room_id").toString();
            qDebug() << "过期的预约记录 RoomID：" << roomId;

            // 更新 reservation 表中对应记录的 state 字段为 1
            updateQuery.prepare("UPDATE reservation SET state = 1 WHERE room_id = :roomId AND state = 0");
            updateQuery.bindValue(":roomId", roomId);
            if (!updateQuery.exec()) {
                qDebug() << "更新 reservation 表失败：" << updateQuery.lastError().text();
            } else {
                qDebug() << "更新 reservation 表成功，RoomID：" << roomId;
            }

            // 更新 available_room 表中对应记录的 State 字段为 0
            updateQuery.prepare("UPDATE available_room SET State = 0 WHERE RoomID = :roomId");
            updateQuery.bindValue(":roomId", roomId);
            if (!updateQuery.exec()) {
                qDebug() << "更新 available_room 表失败：" << updateQuery.lastError().text();
            } else {
                qDebug() << "更新 available_room 表成功，RoomID：" << roomId;
            }
        }
    } else {
        qDebug() << "查询 reservation 表失败：" << query.lastError().text();
    }

    db.close();
}

void MainWindow::senddate(int a) {
    // 确保数据库连接已打开
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("User.db");
    if (!db.isOpen()) {
        qDebug() << "数据库未打开，尝试打开数据库...";
        if (!db.open()) {
            qDebug() << "无法打开数据库：" << db.lastError().text();
            return; // 数据库打开失败，终止函数执行
        }
    }

    QSqlQuery query(db);
    QDate currentDate = globaltime.date(); // 从 globaltime 提取当前日期

    // 一次查询并按时间范围拆分数据
    QJsonObject oneYearData;
    QJsonObject threeMonthsData;
    QJsonObject oneMonthData;
    QJsonObject topFiveRoomTypesData; // 新增的 JSON 对象，用于存储排名前五的房间类型

    // 查询近一年内的房间类型统计
    {
        qDebug() << "查询近一年内的房间类型统计";
        QDate oneYearAgo = currentDate.addYears(-1);
        query.prepare("SELECT room_type, COUNT(*) as count FROM check_in "
                      "WHERE DATE(in_time) >= :oneYearAgo "
                      "GROUP BY room_type");
        query.bindValue(":oneYearAgo", oneYearAgo.toString("yyyy-MM-dd"));
        QJsonArray oneYearStats;
        if (query.exec()) {
            while (query.next()) {
                QJsonObject roomStat;
                roomStat["room_type"] = query.value("room_type").toString();
                roomStat["count"] = query.value("count").toInt();
                oneYearStats.append(roomStat);
            }
        } else {
            qDebug() << "查询近一年的数据失败：" << query.lastError().text();
        }
        oneYearData["stats"] = oneYearStats;
        oneYearData["time_range"] = "one_year"; // 标记时间范围
    }

    // 查询近三个月内的房间类型统计
    {
        qDebug() << "查询近三个月内的房间类型统计";
        QDate threeMonthsAgo = currentDate.addMonths(-3);
        query.prepare("SELECT room_type, COUNT(*) as count FROM check_in "
                      "WHERE DATE(in_time) >= :threeMonthsAgo "
                      "GROUP BY room_type");
        query.bindValue(":threeMonthsAgo", threeMonthsAgo.toString("yyyy-MM-dd"));
        QJsonArray threeMonthsStats;
        if (query.exec()) {
            while (query.next()) {
                QJsonObject roomStat;
                roomStat["room_type"] = query.value("room_type").toString();
                roomStat["count"] = query.value("count").toInt();
                threeMonthsStats.append(roomStat);
            }
        } else {
            qDebug() << "查询近三个月的数据失败：" << query.lastError().text();
        }
        threeMonthsData["stats"] = threeMonthsStats;
        threeMonthsData["time_range"] = "three_months"; // 标记时间范围
    }

    // 查询近一个月内的房间类型统计
    {
        qDebug() << "查询近一个月内的房间类型统计";
        QDate oneMonthAgo = currentDate.addMonths(-1);
        query.prepare("SELECT room_type, COUNT(*) as count FROM check_in "
                      "WHERE DATE(in_time) >= :oneMonthAgo "
                      "GROUP BY room_type");
        query.bindValue(":oneMonthAgo", oneMonthAgo.toString("yyyy-MM-dd"));
        QJsonArray oneMonthStats;
        if (query.exec()) {
            while (query.next()) {
                QJsonObject roomStat;
                roomStat["room_type"] = query.value("room_type").toString();
                roomStat["count"] = query.value("count").toInt();
                oneMonthStats.append(roomStat);
            }
        } else {
            qDebug() << "查询近一个月的数据失败：" << query.lastError().text();
        }
        oneMonthData["stats"] = oneMonthStats;
        oneMonthData["time_range"] = "one_month"; // 标记时间范围
    }

    // 查询房间类型统计排名前五
    {
        qDebug() << "查询房间类型统计排名前五";
        query.prepare("SELECT room_type, COUNT(*) as count FROM check_in "
                      "GROUP BY room_type "
                      "ORDER BY count DESC "
                      "LIMIT 5");
        QJsonArray topFiveRoomTypes;
        if (query.exec()) {
            while (query.next()) {
                QJsonObject roomStat;
                roomStat["room_type"] = query.value("room_type").toString();
                roomStat["count"] = query.value("count").toInt();
                topFiveRoomTypes.append(roomStat);
            }
        } else {
            qDebug() << "查询房间类型排名前五失败：" << query.lastError().text();
        }

        // 如果不足五个，用 "敬请期待！" 填充
        while (topFiveRoomTypes.size() < 5) {
            QJsonObject placeholder;
            placeholder["room_type"] = "敬请期待！";
            placeholder["count"] = 0;
            topFiveRoomTypes.append(placeholder);
        }

        topFiveRoomTypesData["stats"] = topFiveRoomTypes;
        topFiveRoomTypesData["time_range"] = "top_five"; // 标记时间范围
    }

    // 将 JSON 数据转换为字符串并分四次发送
    QString oneYearJson = QJsonDocument(oneYearData).toJson(QJsonDocument::Compact);
    QString threeMonthsJson = QJsonDocument(threeMonthsData).toJson(QJsonDocument::Compact);
    QString oneMonthJson = QJsonDocument(oneMonthData).toJson(QJsonDocument::Compact);
    QString topFiveRoomTypesJson = QJsonDocument(topFiveRoomTypesData).toJson(QJsonDocument::Compact);

    qDebug() << "发送 one_year 数据：" << oneYearJson;
    qDebug() << "发送 three_months 数据：" << threeMonthsJson;
    qDebug() << "发送 one_month 数据：" << oneMonthJson;
    qDebug() << "发送 top_five 数据：" << topFiveRoomTypesJson;

    QTimer::singleShot(0, [this, a, oneYearJson]() {
        emit sendjson(a, oneYearJson); // 第一次发送
    });
    QTimer::singleShot(1500, [this, a, threeMonthsJson]() {
        emit sendjson(a, threeMonthsJson); // 第二次发送
    });
    QTimer::singleShot(2500, [this, a, oneMonthJson]() {
        emit sendjson(a, oneMonthJson); // 第三次发送
    });
    QTimer::singleShot(3500, [this, a, topFiveRoomTypesJson]() {
        emit sendjson(a, topFiveRoomTypesJson); // 第四次发送
    });
}

void MainWindow::updateDateTimeEdit(const QDateTime &dateTime) {
    if (dateTime.isValid()) {
        qDebug() << "更新 QDateTimeEdit：" << dateTime.toString();
        ui->dateTimeEdit->setDateTime(dateTime); // 设置到 QDateTimeEdit
        customDateTime = ui->dateTimeEdit->dateTime();
    } else {
        qDebug() << "收到的时间无效！";
    }
}
void MainWindow::myfindip(){
    emit findip();
}
void MainWindow::displayIPAddress(const QString &ip) {
    qDebug() << "显示IP地址：" << ip;
    ui->ip_address->setText("IP地址：" + ip);  // 更新标签内容
    emit gettime();
}


// 按钮槽函数实现
void MainWindow::on_pushButton_in_clicked()
{

    in *p = new in();
    p->show();
}

void MainWindow::on_pushButton_out_clicked()
{

    reservation_list *p = new reservation_list();
    p->show();
}

void MainWindow::on_pushButton_lost_clicked()
{

    report_the_loss_of *p = new report_the_loss_of();
    p->show();
}

void MainWindow::on_pushButton_continue_clicked()
{

    card_replacement *p = new card_replacement();
    p->show();

}

void MainWindow::on_pushButton_7_clicked()
{

    newroom *p = new newroom();
    p->show();
}

void MainWindow::on_pushButton_clicked()
{
    // 退出程序
    this->close();
    qApp->quit();
}

void MainWindow::on_pushButton_continue_2_clicked()
{

    check_out *p = new check_out();
    p->show();
}




void MainWindow::on_available_bigroom_clicked()
{
    QString roomtype="大床房";
    available_room_list *p = new available_room_list(roomtype);
    p->show();
}


void MainWindow::on_available_tvroom_clicked()//电影房
{
    QString roomtype="电影房";
    available_room_list *p = new available_room_list(roomtype);
    p->show();
}


void MainWindow::on_available_jimafang_clicked()//机麻房
{
    QString roomtype="机麻房";
    available_room_list *p = new available_room_list(roomtype);
    p->show();
}


void MainWindow::on_available_one_clicked()//普通单人间
{
    QString roomtype="普通单人间";
    available_room_list *p = new available_room_list(roomtype);
    p->show();
}


void MainWindow::on_available_double_clicked()//普通双人间
{
    QString roomtype="普通双人间";
    available_room_list *p = new available_room_list(roomtype);
    p->show();
}


void MainWindow::on_available_rowbedroom_clicked()//双床房
{
    QString roomtype="双床房";
    available_room_list *p = new available_room_list(roomtype);
    p->show();
}


void MainWindow::on_available_xingzhengfang_clicked()//行政房
{
    QString roomtype="行政房";
    available_room_list *p = new available_room_list(roomtype);
    p->show();
}


void MainWindow::on_available_zongtongtaof_clicked()//总统套房
{
    QString roomtype="总统套房";
    available_room_list *p = new available_room_list(roomtype);
    p->show();
}

