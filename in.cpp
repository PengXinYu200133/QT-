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
extern ESP8266 *globalESP;
in::in(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::in)
{
    ui->setupUi(this);

    ui->frame_2->hide();
    CustomTextEdit *phonenumber = new CustomTextEdit(this);
    phonenumber->setGeometry(ui->phonenumber->geometry());
    delete ui->phonenumber;
    ui->phonenumber = phonenumber;
    phonenumber->setStyleSheet("border: 2px solid rgba(0, 0, 0, 150); /* 黑色边框，150为不透明度 */background-color: rgba(255, 255, 255, 200); /* 白色背景，200为不透明度 */border-radius: 10px; /* 圆角边框 */");
    connect(phonenumber, &CustomTextEdit::customMousePressed, this, &in::myon_phonenumber_cursorPositionChanged);

    connect(globalESP, &ESP8266::ipdDataReceived, this, &in::handleReceivedData);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "in");
    db.setDatabaseName("User.db");

    if (!db.open()) {
        qDebug() << "数据库连接失败：" << db.lastError().text();
        QMessageBox::warning(this, "错误", "无法连接到数据库！");

    }

    // 查询 RoomType 并加载到 QComboBox
    QSqlQuery query(db);
    QString selectQuery = "SELECT RoomType FROM roomtype";
    if (!query.exec(selectQuery)) {
        qDebug() << "查询失败：" << query.lastError().text();
        QMessageBox::warning(this, "错误", "无法加载房间类型！");

    }

    while (query.next()) {
        QString roomType = query.value(0).toString();
        ui->roomtype->addItem(roomType); // 将 RoomType 添加到 QComboBox
    }

    db.close();
}

in::~in()
{
    delete ui;
}
void in::myon_phonenumber_cursorPositionChanged(){
    ui->frame_2->show();
}
void in::handleReceivedData(const QString &data)
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




void in::on_pushButton_1_clicked()//1
{
    ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_1->text());
    qDebug()<<ui->phonenumber->toPlainText();
    qDebug() << "The input box is disabled.";
}

void in::on_pushButton_2_clicked()//2
{
    ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_2->text());
    qDebug()<<ui->phonenumber->toPlainText();
    qDebug() << "The input box is disabled.";
}

void in::on_pushButton_3_clicked()//3
{
    ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_3->text());
    qDebug()<<ui->phonenumber->toPlainText();
    qDebug() << "The input box is disabled.";
}
void in::on_pushButton_4_clicked()//4
{
    ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_4->text());
    qDebug()<<ui->phonenumber->toPlainText();
    qDebug() << "The input box is disabled.";
}
void in::on_pushButton_5_clicked()//3
{
    ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_3->text());
    qDebug()<<ui->phonenumber->toPlainText();
    qDebug() << "The input box is disabled.";
}





void in::on_pushButton_8_clicked()//8
{
    ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_8->text());
    qDebug()<<ui->phonenumber->toPlainText();
    qDebug() << "The input box is disabled.";
}


void in::on_pushButton_6_clicked()//6
{
    ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_6->text());
    qDebug()<<ui->phonenumber->toPlainText();
    qDebug() << "The input box is disabled.";
}


void in::on_pushButton_7_clicked()//7
{
    ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_7->text());
    qDebug()<<ui->phonenumber->toPlainText();
    qDebug() << "The input box is disabled.";
}


void in::on_pushButton_9_clicked()//9
{
    ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_9->text());
    qDebug()<<ui->phonenumber->toPlainText();
    qDebug() << "The input box is disabled.";
}


void in::on_pushButton_0_clicked()//0
{
    ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_0->text());
    qDebug()<<ui->phonenumber->toPlainText();
    qDebug() << "The input box is disabled.";
}


void in::on_pushButton_11_clicked()//回退
{
    QString currentText = ui->phonenumber->toPlainText();
    if (currentText.length() > 0) {
        // 移除最后一个字符
        QString newText = currentText.left(currentText.length() - 1);
        ui->phonenumber->setText(newText);
    }
}


void in::on_pushButton_12_clicked()//完成
{
    ui->frame_2->hide();
}


void in::on_optroom_clicked()
{
    // 示例按钮功能
    if (ui->name->toPlainText().isEmpty() || ui->ID->toPlainText().isEmpty()) {
        QMessageBox::warning(this, "警告", "请填写完整的姓名和身份证号！");
        return;
    }


    QString date[4];
    date[0] =ui->name->toPlainText();     // 姓名
    date[1] = ui->ID->toPlainText(); // 身份证号
    date[2] = ui->roomtype->currentText();   // 房间类型

    // 打开 in_optroomtype 页面并传递数据
    in_optroomtype *optRoomTypePage = new in_optroomtype(date, this);
    optRoomTypePage->show();

    // 关闭当前页面
    this->close();
    qDebug() << "姓名：" << date[0] << ", 身份证号：" << date[1];
}


void in::on_back_clicked()
{

    this->close();
}






