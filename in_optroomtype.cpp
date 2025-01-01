#include "in_optroomtype.h"
#include "ui_in_optroomtype.h"
#include "mainwindow.h"
#include "in.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QStandardItem>
#include <QMessageBox>
#include <QDateTime>
#include <QDebug>
extern QDateTime globaltime;
extern ESP8266 *globalESP;
// 构造函数
in_optroomtype::in_optroomtype(QString *date, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::in_optroomtype)
    , model(new QStandardItemModel(this)) // 初始化模型
    , serial(new QSerialPort(this))       // 初始化串口对象
{
    ui->setupUi(this);
    //广播开门信号
connect(this, &in_optroomtype::opendoor, globalESP, &ESP8266::broadcastData);
    for (int i = 0; i < 4; ++i) {
        m_date[i] = date[i];
    }
    QString roomType = m_date[2]; // 获取房间类型
    qDebug() << "房间类型：" << roomType;

    // 打开数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "in_optroomtype");
    db.setDatabaseName("User.db");
    if (!db.open()) {
        qDebug() << "数据库连接未打开！";
    }

    // 执行查询
    QSqlQuery query(db);
    QString selectQuery = "SELECT RoomID, RoomType, notes FROM available_room WHERE RoomType = :roomType AND State = 0";
    query.prepare(selectQuery);
    query.bindValue(":roomType", roomType);
    if (!query.exec()) {
        qDebug() << "查询失败：" << query.lastError().text();
    }

    // 创建模型并填充数据
    model->setHorizontalHeaderLabels({"RoomID", "RoomType", "Notes"}); // 设置表头

    while (query.next()) {
        QString roomId = query.value(0).toString();   // RoomID
        QString roomType = query.value(1).toString(); // RoomType
        QString notes = query.value(2).toString();    // Notes

        QList<QStandardItem *> rowItems;
        rowItems.append(new QStandardItem(roomId));   // 第1列：RoomID
        rowItems.append(new QStandardItem(roomType)); // 第2列：RoomType
        rowItems.append(new QStandardItem(notes));    // 第3列：Notes

        model->appendRow(rowItems); // 添加一行数据到模型
    }

    // 将模型设置到 QTableView
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setStretchLastSection(true); // 自动调整列宽
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows); // 整行选择
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); // 单行选择
    db.close();

    // 初始化串口
    serial->setPortName("/dev/ttySAC1");
    if (!serial->open(QIODevice::ReadWrite)) {
        qDebug() << "无法打开 CON2 串口：" << serial->errorString();
        QMessageBox::information(this, "串口错误", "无法打开 CON2 串口！");
        return;
    }

    // 配置串口参数
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->clear(); // 清空接收和发送缓冲区
    // 连接串口信号，用于接收数据
    connect(serial, &QSerialPort::readyRead, this, &in_optroomtype::handleSerialData);
}

// 析构函数
in_optroomtype::~in_optroomtype()
{
    delete ui;
    if (model) {
        delete model;
    }

    /*if (serial) {
        if (serial->isOpen()) {
            serial->close();
        }
        delete serial;
        serial = nullptr;
    }*/
}

// 确认按钮
void in_optroomtype::on_pushButton_clicked()
{
    // 获取选中行的房间号
    QModelIndex index = ui->tableView->currentIndex(); // 获取当前选中的索引
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请选择一个房间！");

    }
    QString roomId = model->data(model->index(index.row(), 0)).toString(); // 获取第1列（RoomID）的数据
    qDebug() << "准备发送房间号到串口：" << roomId;

    if (serial && serial->isOpen()) {
        QString sendData = "r+" + roomId;
        QByteArray dataToSend = sendData.toUtf8();
        qint64 bytesWritten = serial->write(dataToSend);
        if (bytesWritten == -1) {
            qDebug() << "数据发送失败：" << serial->errorString();
            QMessageBox::information(this, "串口错误", "数据发送失败！");

        } else {
            qDebug() << "数据发送成功：" << sendData;
        }
    } else {
        QMessageBox::warning(this, "错误", "串口未初始化或未打开！");
    }
}

// 处理串口返回数据
void in_optroomtype::handleSerialData()
{
    // 检查串口是否已打开
    if (!serial || !serial->isOpen()) {
        qDebug() << "串口未打开，无法接收数据";
        return; // 提前返回，避免后续操作
    }

    static QByteArray receivedData; // 用于存储接收到的所有数据
    receivedData.append(serial->readAll()); // 将新接收到的数据追加到缓冲区

    // 循环处理完整的数据帧
    while (true) {
        int endIndex = receivedData.indexOf("\r\n"); // 查找消息结束标志 "\r\n"
        if (endIndex == -1) {
            // 未找到结束标志，等待下一次接收
            break;
        }

        // 提取完整的一条消息
        QString dataString = QString::fromUtf8(receivedData.left(endIndex)); // 转换为字符串
        receivedData.remove(0, endIndex + 2); // 移除已处理的数据，包括 "\r\n"

        qDebug() << "从 CON2 接收到的数据：" << dataString;

        // 动态密码提取逻辑
        if (dataString.startsWith("OK:") && dataString.length() >= 19) { // "OK:" + 16 位密码 = 至少 19 个字符
            QString dynamicPassword = dataString.mid(3, 16); // 提取从第 3 个字符开始的 16 位密码
            qDebug() << "提取到的动态密码：" << dynamicPassword;

            // 调用处理动态密码的函数
            handleDynamicPassword(dynamicPassword);

        } else {
            // 数据无效时的处理
            qDebug() << "接收到的无效数据：" << dataString;
            QMessageBox::warning(this, "错误", "串口返回数据无效！请先去退卡");
        }
    }
}

void in_optroomtype::handleDynamicPassword(const QString &dynamicPassword)
{
    // 检查数据库是否已打开
    QSqlDatabase db = QSqlDatabase::database("in_optroomtype");
    if (!db.isOpen()) {
        qDebug() << "数据库未打开";
        return; // 提前返回，避免后续操作
    }

    // 获取入住信息
    QString name = m_date[0];
    QString idCard = m_date[1];
    QString roomType = m_date[2];
    QModelIndex index = ui->tableView->currentIndex();
    QString roomId = model->data(model->index(index.row(), 0)).toString();
    QString formattedTime = globaltime.toString("yyyy-MM-dd hh:mm:ss");

    // 插入数据到 check_in 表
    QSqlQuery query(db);
    QString insertQuery = QString("INSERT INTO check_in (name, room_type, room_id, ID, in_time) VALUES (:name, :roomType, :roomId, :id, :time)");
    query.prepare(insertQuery);
    query.bindValue(":name", name);
    query.bindValue(":roomType", roomType);
    query.bindValue(":roomId", roomId);
    query.bindValue(":id", idCard);
    query.bindValue(":time", formattedTime);

    if (query.exec()) {
        qDebug() << "数据插入成功！";

        // 更新房间状态
        QString updateQuery = QString("UPDATE available_room SET State = 1 WHERE RoomID = :RoomID"); // 根据房间号匹配
        QSqlQuery updateStateQuery(db);
        updateStateQuery.prepare(updateQuery);
        updateStateQuery.bindValue(":RoomID", roomId);

        if (updateStateQuery.exec()) {
            qDebug() << "available_room 表的 State 字段更新成功！";
        } else {
            qDebug() << "available_room 表的 State 字段更新失败：" << updateStateQuery.lastError().text();
        }

        // 显示成功消息并关闭串口
        QMessageBox::information(this, "成功", "房间已成功入住！");
        if (serial && serial->isOpen()) {
            serial->close(); // 关闭串口
            qDebug() << "串口已关闭（成功）";
        }
        delete serial;

        // 将提取到的动态密码作为信号参数，通知其他模块开门
        QString maydata = "on:" + dynamicPassword;
        emit opendoor(maydata); // 发送信号，附加动态密码
        this->close();

    } else {
        qDebug() << "数据插入失败：" << query.lastError().text();
        QMessageBox::information(this, "错误", "数据插入失败！");
    }
}

void in_optroomtype::sendRoomNumber(const QString &roomNumber)
{
    if (!serial || !serial->isOpen()) {
        qDebug() << "串口未打开，无法发送数据";
        return;
    }

    QString message = "r+" + roomNumber + "\r\n"; // 格式化房间号消息
    serial->write(message.toUtf8()); // 发送数据
    serial->flush(); // 刷新串口，确保数据发送完成

    qDebug() << "准备发送房间号到串口：" << message.trimmed();
    QThread::msleep(100); // 等待 100 毫秒（根据设备响应时间调整）
    qDebug() << "数据发送成功：" << message.trimmed();
}

// 返回按钮
void in_optroomtype::on_pushButton_2_clicked()
{
    if (serial && serial->isOpen()) {
        serial->close(); // 关闭串口
        qDebug() << "串口已关闭（取消按钮）";
    }
    in *p = new in();
    p->show();
    this->close();
}

void in_optroomtype::on_pushButton_3_clicked()//清空串口接收缓冲区
{

}

