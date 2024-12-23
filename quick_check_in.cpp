#include "quick_check_in.h"
#include "ui_quick_check_in.h"
#include "in.h"
#include "ui_in.h"
#include "mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "in_optroomtype.h"
#include "reservation.h"
extern QDateTime globaltime;
extern ESP8266 *globalESP;
quick_check_in::quick_check_in(QString roomid, QString roomtype,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::quick_check_in)
    , roomid(roomid)
    , roomtype(roomtype)
    , serial(new QSerialPort(this))       // 初始化串口对象
{
    ui->setupUi(this);
    //广播开门信号
    connect(this, &quick_check_in::quick_opendoor, globalESP, &ESP8266::broadcastData);
    ui->frame_2->hide();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","quick_check_in"); // SQLite 数据库驱动
    db.setDatabaseName("User.db"); // 数据库文件路径（请确保文件存在）
    CustomTextEdit *intime = new CustomTextEdit(this);
    intime->setGeometry(ui->phonenumber->geometry());
    delete ui->phonenumber;
    ui->phonenumber = intime;
    intime->setStyleSheet("border: 2px solid rgba(0, 0, 0, 150); /* 黑色边框，150为不透明度 */background-color: rgba(255, 255, 255, 200); /* 白色背景，200为不透明度 */border-radius: 10px; /* 圆角边框 */");
    connect(intime, &CustomTextEdit::customMousePressed, this, &quick_check_in::myphonenumber_cursorPositionChanged);
    connect(globalESP, &ESP8266::ipdDataReceived, this, &quick_check_in::handleReceivedData);

    // 初始化串口
    serial->setPortName("/dev/ttySAC1");
    if (!serial->open(QIODevice::ReadWrite)) {
        qDebug() << "无法打开 CON2 串口：" << serial->errorString();
        QMessageBox::information(this, "串口错误", "无法打开 CON2 串口！");
        return;
    }

    // 配置串口参数
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    // 连接串口信号，用于接收数据
    connect(serial, &QSerialPort::readyRead, this, &quick_check_in::handleSerialData);
}

quick_check_in::~quick_check_in()
{
    delete ui;
}


// 处理串口返回数据
void quick_check_in::handleSerialData()
{
    if (!serial || !serial->isOpen()) {
        qDebug() << "串口未打开，无法接收数据";
        return;
    }

    QByteArray receivedData = serial->readAll(); // 读取串口数据
    QString dataString = QString::fromUtf8(receivedData); // 转换为字符串
    qDebug() << "从 CON2 接收到的数据：" << dataString;

    // 如果收到的返回数据有效，则插入数据库
    if (dataString.contains("OK")) {
        QSqlDatabase db = QSqlDatabase::database("quick_check_in"); // SQLite 数据库驱动

        if (!db.open()) {
            qDebug() << "数据库连接失败: " << db.lastError().text();
            QMessageBox::critical(this, "数据库错误", "无法连接到数据库：" + db.lastError().text());
            return;
        }


        QString name = ui->name->toPlainText(); ;
        QString idCard = ui->ID->toPlainText();;
        QString roomType = this->roomtype;
        QString roomId = this->roomid;
        QString formattedTime = globaltime.toString("yyyy-MM-dd hh:mm:ss");

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
            QMessageBox::information(this, "成功", "房间已成功入住！");
            if (serial && serial->isOpen()) {
                serial->close(); // 关闭串口
                qDebug() << "串口已关闭（确定按钮）";
            }
            db.close();
            delete serial;
            QString mydata = "on:"+roomId;
            emit quick_opendoor(mydata);
            this->close();

        } else {
            qDebug() << "数据插入失败：" << query.lastError().text();
            QMessageBox::information(this, "错误", "数据插入失败！");
        }
    } else {
        QMessageBox::warning(this, "错误", "串口返回数据无效！请先去退卡");
    }
}
void quick_check_in::handleReceivedData(const QString &data)
{
    qDebug() << "接收到的 +IPD 数据：" << data;

    // 假设数据格式为 "name=张三&idNumber=123456789&"
    int nameIndex = data.indexOf("name=");
    int idNumberIndex = data.indexOf("idNumber=");

    if (nameIndex != -1 && idNumberIndex != -1) {
        // 提取姓名
        QString name = data.mid(nameIndex + 5, data.indexOf("&", nameIndex) - nameIndex - 5);

        // 提取身份证号
        int idEndIndex = data.indexOf("&", idNumberIndex); // 找到 idNumber 后的分隔符
        if (idEndIndex == -1) {
            idEndIndex = data.length(); // 如果没有找到 &，截取到字符串末尾
        }
        QString idNumber = data.mid(idNumberIndex + 9, idEndIndex - idNumberIndex - 9);

        // 清理身份证号中的多余字符
        idNumber = idNumber.trimmed(); // 去除左右多余空格
        idNumber.remove(",CLOSED");   // 移除 ",CLOSED" 字符串

        // 更新 UI 上的文本框
        ui->name->setPlainText(name);  // 设置解析到的姓名
        ui->ID->setPlainText(idNumber); // 设置解析到的身份证号

        qDebug() << "解析结果：name=" << name << ", idNumber=" << idNumber;
    } else {
        qDebug() << "数据格式不正确，无法解析";
    }
}

void quick_check_in::myphonenumber_cursorPositionChanged(){
    ui->frame_2->show();
}

void quick_check_in::on_pushButton_1_clicked()
{
    ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_1->text());
    qDebug()<<ui->phonenumber->toPlainText();
    qDebug() << "The input box is disabled.";
}


void quick_check_in::on_pushButton_2_clicked()
{
    ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_2->text());
    qDebug()<<ui->phonenumber->toPlainText();
    qDebug() << "The input box is disabled.";
}


void quick_check_in::on_pushButton_3_clicked()
{
    ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_3->text());
    qDebug()<<ui->phonenumber->toPlainText();
    qDebug() << "The input box is disabled.";
}


void quick_check_in::on_pushButton_4_clicked()
{
    ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_4->text());
    qDebug()<<ui->phonenumber->toPlainText();
    qDebug() << "The input box is disabled.";
}


void quick_check_in::on_pushButton_5_clicked()
{
    ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_5->text());
    qDebug()<<ui->phonenumber->toPlainText();
    qDebug() << "The input box is disabled.";
}


void quick_check_in::on_pushButton_6_clicked()
{
    ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_6->text());
    qDebug()<<ui->phonenumber->toPlainText();
    qDebug() << "The input box is disabled.";
}


void quick_check_in::on_pushButton_7_clicked()
{
    ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_7->text());
    qDebug()<<ui->phonenumber->toPlainText();
    qDebug() << "The input box is disabled.";
}


void quick_check_in::on_pushButton_8_clicked()
{
    ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_8->text());
    qDebug()<<ui->phonenumber->toPlainText();
    qDebug() << "The input box is disabled.";
}


void quick_check_in::on_pushButton_9_clicked()
{
    ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_9->text());
    qDebug()<<ui->phonenumber->toPlainText();
    qDebug() << "The input box is disabled.";
}


void quick_check_in::on_pushButton_0_clicked()
{
    ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_0->text());
    qDebug()<<ui->phonenumber->toPlainText();
    qDebug() << "The input box is disabled.";
}


void quick_check_in::on_pushButton_11_clicked()//回退按钮
{
    QString currentText = ui->phonenumber->toPlainText();
    QString newText = currentText.left(currentText.length() - 1);
    ui->phonenumber->setText(newText);
}


void quick_check_in::on_pushButton_12_clicked()//完成按钮
{
    ui->frame_2->hide();
}


void quick_check_in::on_back_clicked()//返回按钮
{
    if (serial && serial->isOpen()) {
        serial->close(); // 关闭串口
        qDebug() << "串口已关闭（确定按钮）";
    }
    this->close();
}


void quick_check_in::on_queding_clicked()//确定按钮
{
    qDebug() << "准备发送房间号到串口：" << this->roomid;

    if (serial && serial->isOpen()) {
        QString sendData = "r+" + this->roomid;
        QByteArray dataToSend = sendData.toUtf8();
        qint64 bytesWritten = serial->write(dataToSend);
        if (bytesWritten == -1) {
            qDebug() << "数据发送失败：" << serial->errorString();
            QMessageBox::information(this, "串口错误", "数据发送失败！");
            return;
        } else {
            qDebug() << "数据发送成功：" << sendData;
        }
    } else {
        QMessageBox::warning(this, "错误", "串口未初始化或未打开！");
    }
}

