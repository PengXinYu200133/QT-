#include "newroom.h"
#include "ui_newroom.h"
#include <QLabel>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include "qdebug.h"
#include "mainwindow.h"
#include "reservation.h"
newroom::newroom(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::newroom)
    , db(QSqlDatabase::addDatabase("QSQLITE", "newroom")) // 初始化数据库连接对象
{
    ui->setupUi(this);
    ui->frame_2->hide();
    CustomTextEdit *phonenumber = new CustomTextEdit(this);
    phonenumber->setGeometry(ui->roomid->geometry());
    delete ui->roomid;
    ui->roomid = phonenumber;
    phonenumber->setStyleSheet("border: 2px solid rgba(0, 0, 0, 150); /* 黑色边框，150为不透明度 */background-color: rgba(255, 255, 255, 200); /* 白色背景，200为不透明度 */border-radius: 10px; /* 圆角边框 */");
    connect(phonenumber, &CustomTextEdit::customMousePressed, this, &newroom::myon_phonenumber_cursorPositionChanged);

    // 设置数据库文件路径（确保路径正确）
    db.setDatabaseName("User.db");

    // 打开数据库
    if (!db.open()) {
        QMessageBox::critical(nullptr, "Database Error", db.lastError().text());
        return;
    }



    // 加载房间类型到 comboBox_2
    QSqlQuery query1(db);
    if (query1.exec("SELECT RoomType FROM roomtype")) {
        while (query1.next()) {
            QString roomType = query1.value(0).toString();
            ui->comboBox_2->addItem(roomType); // 添加到 comboBox_2
            qDebug() << "加载房间类型:" << roomType; // 调试输出
        }
    } else {
        qDebug() << "加载房间类型失败:" << query1.lastError().text();
        QMessageBox::critical(nullptr, "查询错误", "无法加载房间类型");
    }
}

newroom::~newroom()
{
    delete ui;
}

void newroom::myon_phonenumber_cursorPositionChanged(QMouseEvent *event)//按下手机尾号文本框
{
    ui->frame_2->show();
}

void newroom::on_pushButton_on_clicked()
{
    QString insertQueryStr = "INSERT INTO available_room (RoomID, RoomType, price) VALUES (?,?,?)";
    QString roomId = ui->roomid->toPlainText();
    if (roomId.length() != 4) {
        QMessageBox::warning(this, "输入错误", "房间号必须是4个字符，请重新输入！");
        return; // 停止后续操作
    }
    QString roomType = ui->comboBox_2->currentText();

    // 检查房间是否已存在
    QSqlQuery checkQuery(db);
    QString checkQueryStr = QString("SELECT COUNT(*) FROM available_room WHERE RoomID = '%1'").arg(roomId);
    if (checkQuery.exec(checkQueryStr) && checkQuery.next()) {
        int count = checkQuery.value(0).toInt();
        if (count > 0) {
            QMessageBox::warning(nullptr, "插入失败", "该房间ID已存在，请重新选择");
            return;
        }
    } else {
        qDebug() << "检查房间ID失败:" << checkQuery.lastError().text();
        QMessageBox::critical(nullptr, "查询错误", "无法检查房间ID是否存在");
        return;
    }

    // 查询房间类型的价格
    QString priceQueryStr = QString("SELECT price FROM roomtype WHERE RoomType = '%1'").arg(roomType);
    QSqlQuery priceQuery(db);
    if (priceQuery.exec(priceQueryStr)) {
        if (priceQuery.next()) {
            QString price = priceQuery.value(0).toString();

            // 插入数据到 available_room 表
            QSqlQuery insertQuery(db);
            insertQuery.prepare(insertQueryStr);
            insertQuery.addBindValue(roomId);
            insertQuery.addBindValue(roomType);
            insertQuery.addBindValue(price);

            if (insertQuery.exec()) {
                QMessageBox::information(nullptr, "插入成功", "数据已成功插入到数据库");
            } else {
                qDebug() << "插入失败:" << insertQuery.lastError().text();
                QMessageBox::critical(nullptr, "插入失败", insertQuery.lastError().text());
            }
        } else {
            QMessageBox::warning(nullptr, "查询价格失败", "未能从 roomtype 表中获取价格信息");
        }
    } else {
        qDebug() << "查询价格失败:" << priceQuery.lastError().text();
        QMessageBox::critical(nullptr, "查询错误", "无法获取房间类型的价格");
    }
    // 关闭当前窗口并打开主窗口
    this->close();
}

void newroom::on_pushButton_back_clicked()
{
    this->close();

}

void newroom::on_pushButton_1_clicked()
{
    ui->roomid->setText(ui->roomid->toPlainText() + ui->pushButton_1->text());
    qDebug()<<ui->roomid->toPlainText();
    qDebug() << "The input box is disabled.";
}


void newroom::on_pushButton_2_clicked()
{
    ui->roomid->setText(ui->roomid->toPlainText() + ui->pushButton_2->text());
    qDebug()<<ui->roomid->toPlainText();
    qDebug() << "The input box is disabled.";
}


void newroom::on_pushButton_3_clicked()
{
    ui->roomid->setText(ui->roomid->toPlainText() + ui->pushButton_3->text());
    qDebug()<<ui->roomid->toPlainText();
    qDebug() << "The input box is disabled.";
}


void newroom::on_pushButton_4_clicked()
{
    ui->roomid->setText(ui->roomid->toPlainText() + ui->pushButton_4->text());
    qDebug()<<ui->roomid->toPlainText();
    qDebug() << "The input box is disabled.";
}


void newroom::on_pushButton_5_clicked()
{
    ui->roomid->setText(ui->roomid->toPlainText() + ui->pushButton_5->text());
    qDebug()<<ui->roomid->toPlainText();
    qDebug() << "The input box is disabled.";
}


void newroom::on_pushButton_6_clicked()
{
    ui->roomid->setText(ui->roomid->toPlainText() + ui->pushButton_6->text());
    qDebug()<<ui->roomid->toPlainText();
    qDebug() << "The input box is disabled.";
}


void newroom::on_pushButton_7_clicked()
{
    ui->roomid->setText(ui->roomid->toPlainText() + ui->pushButton_7->text());
    qDebug()<<ui->roomid->toPlainText();
    qDebug() << "The input box is disabled.";
}


void newroom::on_pushButton_8_clicked()
{
    ui->roomid->setText(ui->roomid->toPlainText() + ui->pushButton_8->text());
    qDebug()<<ui->roomid->toPlainText();
    qDebug() << "The input box is disabled.";
}


void newroom::on_pushButton_9_clicked()
{
    ui->roomid->setText(ui->roomid->toPlainText() + ui->pushButton_9->text());
    qDebug()<<ui->roomid->toPlainText();
    qDebug() << "The input box is disabled.";
}


void newroom::on_pushButton_0_clicked()
{
    ui->roomid->setText(ui->roomid->toPlainText() + ui->pushButton_0->text());
    qDebug()<<ui->roomid->toPlainText();
    qDebug() << "The input box is disabled.";
}


void newroom::on_pushButton_clicked()
{
    QString currentText = ui->roomid->toPlainText();
    if (currentText.length() > 0) {
        // 移除最后一个字符
        QString newText = currentText.left(currentText.length() - 1);
        ui->roomid->setText(newText);
    }
}


void newroom::on_pushButton_10_clicked()
{
    ui->frame_2->hide();
}

