#include "check_out.h"
#include "ui_check_out.h"
#include <QSerialPortInfo>
#include <QFile>
#include "mainwindow.h"
#include <cmath> // 添加 cmath 头文件
// 构造函数
extern QDateTime globaltime;
extern ESP8266 *globalESP;
check_out::check_out(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::check_out)
    , serial(new QSerialPort(this)) // 初始化串口对象
{
    ui->setupUi(this);
    connect(this, &check_out::closeroom, globalESP, &ESP8266::broadcastData);
    // 初始化数据库
    if (!initializeDatabase()) {
        QMessageBox::critical(this, "数据库连接失败", "无法连接到数据库，请检查配置！");
        return;
    }

    // 初始化串口
    connectToSerialPort();

    // 连接串口数据接收信号
    connect(serial, &QSerialPort::readyRead, this, &check_out::readFromSerialPort);
}

// 析构函数
check_out::~check_out()
{
    if (serial->isOpen()) {
        serial->close(); // 关闭串口
        qDebug() << "串口关闭了" ;
    }
    delete ui;
}

// 初始化数据库
bool check_out::initializeDatabase()
{
    // 数据库文件路径
    QString dbFilePath = "User.db"; // 确保文件路径正确

    // 检查数据库文件是否存在
    if (!QFile::exists(dbFilePath)) {
        QMessageBox::critical(this, "错误", "数据库文件未找到：" + dbFilePath);
        return false;
    }

    // 使用 SQLite 数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "check_out");
    db.setDatabaseName(dbFilePath);

    // 尝试打开数据库
    if (!db.open()) {
        qCritical() << "数据库连接失败：" << db.lastError().text();
        return false;
    }

    qDebug() << "数据库连接成功：" << dbFilePath;
    return true;
}

// 连接到串口
void check_out::connectToSerialPort()
{
    // 固定的串口名称（例如 Linux 上为 "/dev/ttySAC1" 或 "/dev/ttyUSB0"）
    QString fixedPortName = "/dev/ttySAC1";  // 根据实际设备调整

    // 遍历所有可用的串口，查找指定的串口
    QList<QSerialPortInfo> availablePorts = QSerialPortInfo::availablePorts();
    bool portFound = false;
    for (const QSerialPortInfo &portInfo : availablePorts) {
        qDebug() << "检测到串口：" << portInfo.portName();  // 打印可用的串口名称
        if (portInfo.systemLocation() == fixedPortName) {  // 使用 systemLocation 匹配完整路径
            serial->setPort(portInfo);
            portFound = true;
            break;
        }
    }

    if (!portFound) {
        QMessageBox::critical(this, "错误", "指定的串口未找到：" + fixedPortName);
        return;
    }

    // 设置串口参数
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    // 尝试打开串口
    if (serial->open(QIODevice::ReadWrite)) {
        qDebug() << "已成功连接到串口：" << fixedPortName;
    } else {
        QMessageBox::critical(this, "错误", "无法打开串口：" + serial->errorString());
    }
}

// 从串口读取数据
void check_out::readFromSerialPort()
{
    // 读取串口数据
    QByteArray data = serial->readAll();
    if (data.isEmpty()) {
        qDebug() << "未接收到数据";
        return;
    }

    QString receivedData = QString::fromUtf8(data).trimmed();  // 转换为字符串并去掉首尾多余的空白字符
    qDebug() << "接收到的原始数据：" << receivedData;

    // 检查数据格式并解析房间号
    if (receivedData.startsWith("roomid:")) {  // 确保数据以 "roomid:" 开头
        QString roomNumber = receivedData.mid(7);  // 提取 "roomid:" 之后的部分
        roomNumber = roomNumber.split("\r\n").first();  // 去掉可能的回车换行符
        qDebug() << "解析出的房间号：" << roomNumber;

        // 处理接收到的房间号
        if (!roomNumber.isEmpty()) {
            processRoomNumber(roomNumber);
        }
    } else {
        qDebug() << "接收到的数据格式不正确：" << receivedData<<"\r\n卡片未使用！";
    }
}

// 处理房间号
void check_out::processRoomNumber(const QString &roomNumber)
{
    QSqlQuery query(QSqlDatabase::database("check_out"));  // 使用指定的连接

    // 查询房间信息
    query.prepare("SELECT name, ID, room_id, room_type, in_time FROM check_in WHERE room_id = :room_id");
    query.bindValue(":room_id", roomNumber);

    if (!query.exec()) {
        QMessageBox::critical(this, "错误", "查询失败：" + query.lastError().text());
        return;
    }

    if (query.next()) {
        QString name = query.value("name").toString();
        QString id = query.value("ID").toString();
        QString room_id = query.value("room_id").toString();
        QString room_type = query.value("room_type").toString();
        QString in_time = query.value("in_time").toString();
        QString out_time = globaltime.toString("yyyy-MM-dd HH:mm:ss");

        // 设置 UI 显示信息
        ui->name->setText(name);
        ui->roomid->setText(room_id + " 号房间");
        ui->in_time->setText("入住时间：" + in_time);
        ui->out_time->setText("退房时间：" + out_time);
        ui->roomtype->setText("房间类型：" + room_type);

        qDebug() << "查询结果：";
        qDebug() << "Name:" << name;
        qDebug() << "ID:" << id;
        qDebug() << "Room ID:" << room_id;
        qDebug() << "Room Type:" << room_type;
        qDebug() << "In Time:" << in_time;
        qDebug() << "Out Time:" << out_time;

        // 计算入住时间与退房时间的差值
        QDateTime inDateTime = QDateTime::fromString(in_time, "yyyy-MM-dd HH:mm:ss");
        QDateTime outDateTime = QDateTime::fromString(out_time, "yyyy-MM-dd HH:mm:ss");

        if (!inDateTime.isValid() || !outDateTime.isValid()) {
            QMessageBox::critical(this, "错误", "时间格式无效！");
            return;
        }

        qint64 diffSeconds = inDateTime.secsTo(outDateTime); // 计算时间差（秒）

        // 规则计算住宿天数
        double diffHours = diffSeconds / 3600.0; // 转换为小时
        int daysStayed = 0;

        // 不满24小时算1天
        if (diffHours <= 24) {
            daysStayed = 1;
        } else {
            // 超过24小时后的部分
            double remainingHours = diffHours - 24;

            // 计算超过24小时的天数
            daysStayed = 1 + static_cast<int>(remainingHours / 24); // 已满的天数

            // 处理剩余时间（不满一天的部分）
            double leftoverHours = std::fmod(remainingHours, 24.0);
            if (leftoverHours > 6) {
                daysStayed += 1; // 超过6小时算一天
            }
        }

        qDebug() << "入住时长（小时）:" << diffHours;
        qDebug() << "住宿天数:" << daysStayed;

        // 显示住宿天数到 UI
        ui->daysStayed->setText(QString::number(daysStayed) + " 天");

        // 查询房间类型对应的价格
        QSqlQuery priceQuery(QSqlDatabase::database("check_out"));
        priceQuery.prepare("SELECT price FROM roomtype WHERE RoomType = :room_type");
        priceQuery.bindValue(":room_type", room_type);

        if (!priceQuery.exec()) {
            QMessageBox::critical(this, "错误", "查询房间类型价格失败：" + priceQuery.lastError().text());
            return;
        }

        double pricePerDay = 0.0;
        if (priceQuery.next()) {
            pricePerDay = priceQuery.value("price").toDouble(); // 查询出的每晚价格
        } else {
            QMessageBox::warning(this, "警告", "未找到对应房间类型的价格：" + room_type);
            return;
        }

        // 计算总费用
        double totalPrice = pricePerDay * daysStayed;

        qDebug() << "房间类型:" << room_type;
        qDebug() << "每日价格:" << pricePerDay << "元";
        qDebug() << "总费用:" << totalPrice << "元";

        // 显示详细费用信息到 UI
        ui->daysStayed->setText("房费：" + QString::number(pricePerDay, 'f', 2) + " 元/天");
        ui->totalPrice->setText("总费用：" + QString::number(totalPrice, 'f', 2) + " 元");

        // 插入退房记录
        QSqlQuery insertQuery(QSqlDatabase::database("check_out"));
        insertQuery.prepare("INSERT INTO check_out (name, ID, room_id, room_type, out_time, in_time) "
                            "VALUES (:name, :ID, :room_id, :room_type, :out_time, :in_time)");
        insertQuery.bindValue(":name", name);
        insertQuery.bindValue(":ID", id);
        insertQuery.bindValue(":room_id", room_id);
        insertQuery.bindValue(":room_type", room_type);
        insertQuery.bindValue(":out_time", out_time);
        insertQuery.bindValue(":in_time", in_time);

        if (!insertQuery.exec()) {
            QMessageBox::critical(this, "成功", "房间已退：" );
        } else {
            // 插入退房记录成功，更新 available_room 表的 State 字段为 0
            QSqlQuery updateQuery(QSqlDatabase::database("check_out"));
            updateQuery.prepare("UPDATE available_room SET State = 0 WHERE RoomID = :room_id");
            updateQuery.bindValue(":room_id", room_id);

            if (!updateQuery.exec()) {
                QMessageBox::critical(this, "错误", "更新房间状态失败：" + updateQuery.lastError().text());
                qDebug() << "更新房间状态失败：" << updateQuery.lastError().text();
            } else {
                QMessageBox::information(this, "成功", "退房记录已存入数据库，房间状态已更新！");
                qDebug() << "房间状态已更新为可用（State = 0）";
            }

            // 关闭串口并关闭窗口
            if (serial && serial->isOpen()) {
                serial->close(); // 关闭串口
                qDebug() << "串口已关闭（成功）";
            }
            QString data = "off:" + room_id;
            emit closeroom(data);

        }
    } else {
        QMessageBox::warning(this, "提示", "未找到对应房间号的记录：" + roomNumber);
    }
}

void check_out::on_pushButton_clicked()//确认按钮
{
    if (serial && serial->isOpen()) {
        QByteArray dataToSend = "t"; // 要发送的数据
        qint64 bytesWritten = serial->write(dataToSend); // 发送数据

        // 检查数据是否成功写入
        if (bytesWritten == -1) {
            QMessageBox::critical(this, "错误", "串口数据发送失败：" + serial->errorString());
            qDebug() << "串口数据发送失败：" << serial->errorString();
        } else {
            qDebug() << "成功通过串口发送数据：" << dataToSend;
        }

    } else {
        QMessageBox::warning(this, "提示", "串口未打开，无法发送数据！");
        qDebug() << "串口未打开，无法发送数据";
    }
}


void check_out::on_pushButton_2_clicked()
{
    if (serial && serial->isOpen()) {
        serial->close(); // 关闭串口
        qDebug() << "串口已关闭（取消按钮）";
    }
    this->close();
}

