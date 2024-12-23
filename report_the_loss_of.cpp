#include "report_the_loss_of.h"
#include "ui_report_the_loss_of.h"
#include <QDebug>
#include <reservation.h>
#include <mainwindow.h>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
extern ESP8266 *globalESP;
report_the_loss_of::report_the_loss_of(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::report_the_loss_of)
{
    ui->setupUi(this);
    ui->frame_2->hide();
connect(this, &report_the_loss_of::closedoor, globalESP, &ESP8266::broadcastData);
    // 替换默认的 QTextEdit 为自定义的 CustomTextEdit
    CustomTextEdit *phonenumber = new CustomTextEdit(this);
    phonenumber->setGeometry(ui->phonenumber->geometry());
    delete ui->phonenumber;
    ui->phonenumber = phonenumber;

    // 设置样式
    phonenumber->setStyleSheet("border: 2px solid rgba(0, 0, 0, 150); /* 黑色边框，150为不透明度 */background-color: rgba(255, 255, 255, 200); /* 白色背景，200为不透明度 */border-radius: 10px; /* 圆角边框 */");

    // 连接自定义信号
    connect(phonenumber, &CustomTextEdit::customMousePressed, this, &report_the_loss_of::myon_phonenumber_cursorPositionChanged);

    // 限制输入字符长度
    connect(phonenumber, &QTextEdit::textChanged, this, &report_the_loss_of::limitPhoneNumberLength);
}

report_the_loss_of::~report_the_loss_of()
{
    delete ui;
}

// 限制输入框长度为 4 个字符
void report_the_loss_of::limitPhoneNumberLength()
{
    QString text = ui->phonenumber->toPlainText();
    if (text.length() > 4) {
        // 如果超过 4 个字符，截断多余部分
        text = text.left(4);
        ui->phonenumber->setText(text);

        // 将光标移动到文本末尾
        QTextCursor cursor = ui->phonenumber->textCursor();
        cursor.movePosition(QTextCursor::End);
        ui->phonenumber->setTextCursor(cursor);
    }
}

void report_the_loss_of::myon_phonenumber_cursorPositionChanged(QMouseEvent *event)//按下手机尾号文本框
{
    // 这里可以根据event获取鼠标按下的位置、按键等信息
    qDebug() << "鼠标位置：" << event->pos();
    ui->frame_2->show();
}

void report_the_loss_of::on_pushButton_1_clicked()
{
    if (ui->phonenumber->toPlainText().length() < 4) {
        ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_1->text());
    }
    qDebug() << ui->phonenumber->toPlainText();
    qDebug() << "The input box is disabled.";
}

void report_the_loss_of::on_pushButton_2_clicked()
{
    if (ui->phonenumber->toPlainText().length() < 4) {
        ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_2->text());
    }
    qDebug() << ui->phonenumber->toPlainText();
    qDebug() << "The input box is disabled.";
}

void report_the_loss_of::on_pushButton_3_clicked()
{
    if (ui->phonenumber->toPlainText().length() < 4) {
        ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_3->text());
    }
    qDebug() << ui->phonenumber->toPlainText();
    qDebug() << "The input box is disabled.";
}

void report_the_loss_of::on_pushButton_4_clicked()
{
    if (ui->phonenumber->toPlainText().length() < 4) {
        ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_4->text());
    }
    qDebug() << ui->phonenumber->toPlainText();
    qDebug() << "The input box is disabled.";
}

void report_the_loss_of::on_pushButton_5_clicked()
{
    if (ui->phonenumber->toPlainText().length() < 4) {
        ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_5->text());
    }
    qDebug() << ui->phonenumber->toPlainText();
    qDebug() << "The input box is disabled.";
}

void report_the_loss_of::on_pushButton_6_clicked()
{
    if (ui->phonenumber->toPlainText().length() < 4) {
        ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_6->text());
    }
    qDebug() << ui->phonenumber->toPlainText();
    qDebug() << "The input box is disabled.";
}

void report_the_loss_of::on_pushButton_7_clicked()
{
    if (ui->phonenumber->toPlainText().length() < 4) {
        ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_7->text());
    }
    qDebug() << ui->phonenumber->toPlainText();
    qDebug() << "The input box is disabled.";
}

void report_the_loss_of::on_pushButton_8_clicked()
{
    if (ui->phonenumber->toPlainText().length() < 4) {
        ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_8->text());
    }
    qDebug() << ui->phonenumber->toPlainText();
    qDebug() << "The input box is disabled.";
}

void report_the_loss_of::on_pushButton_9_clicked()
{
    if (ui->phonenumber->toPlainText().length() < 4) {
        ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_9->text());
    }
    qDebug() << ui->phonenumber->toPlainText();
    qDebug() << "The input box is disabled.";
}

void report_the_loss_of::on_pushButton_0_clicked()
{
    if (ui->phonenumber->toPlainText().length() < 4) {
        ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_0->text());
    }
    qDebug() << ui->phonenumber->toPlainText();
    qDebug() << "The input box is disabled.";
}

void report_the_loss_of::on_pushButton_10_clicked() // 完成按钮
{
    ui->frame_2->hide();
}

void report_the_loss_of::on_pushButton_12_clicked()
{
    this->close();
}

#include <QMessageBox> // 添加用于消息框的头文件

void report_the_loss_of::on_pushButton_11_clicked() // 确认按钮
{
    // 确认操作：确保文本框中输入的房间号不为空
    if (!ui->phonenumber->toPlainText().isEmpty()) {
        QString data = "off:" + ui->phonenumber->toPlainText();
        emit closedoor(data);

        // 打开数据库
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("User.db");

        if (!db.open()) {
            qDebug() << "无法打开数据库：" << db.lastError().text();
            QMessageBox::critical(this, "错误", "无法打开数据库：" + db.lastError().text());
            return;
        }

        QString roomID = ui->phonenumber->toPlainText();  // 获取房间号

        // 查询 check_in 表，按房间号过滤
        QSqlQuery query;
        query.prepare("SELECT ID, name, room_id, room_type, in_time FROM check_in WHERE room_id = :roomID");
        query.bindValue(":roomID", roomID); // 绑定房间号作为查询条件

        if (!query.exec()) {
            qDebug() << "查询 check_in 表失败：" << query.lastError().text();
            QMessageBox::critical(this, "错误", "查询 check_in 表失败：" + query.lastError().text());
            db.close();
            return;
        }

        bool hasData = false; // 标记是否有查询数据
        while (query.next()) {
            hasData = true; // 查询到数据
            QString ID = query.value("ID").toString();
            QString name = query.value("name").toString();
            QString room_id = query.value("room_id").toString();
            QString room_type = query.value("room_type").toString();
            QString in_time = query.value("in_time").toString();

            // 将查询结果插入到 lost_replacement 表
            QSqlQuery insertQuery;
            insertQuery.prepare("INSERT INTO lost_replacement (ID, name, room_id, room_type, in_time) "
                                "VALUES (:ID, :name, :room_id, :room_type, :in_time)");
            insertQuery.bindValue(":ID", ID);
            insertQuery.bindValue(":name", name);
            insertQuery.bindValue(":room_id", room_id);
            insertQuery.bindValue(":room_type", room_type);
            insertQuery.bindValue(":in_time", in_time);

            if (!insertQuery.exec()) {
                qDebug() << "插入 lost_replacement 表失败：" << insertQuery.lastError().text();
                QMessageBox::critical(this, "错误", "插入 lost_replacement 表失败：" + insertQuery.lastError().text());
                db.close();
                return;
            }
        }

        // 关闭数据库
        db.close();

        // 显示结果提示
        if (hasData) {
            QMessageBox::information(this, "成功", "数据已成功插入到 lost_replacement 表！");
        } else {
            QMessageBox::warning(this, "提示", "未找到与该房间号匹配的记录！");
        }

        this->close(); // 关闭窗口
    } else {
        // 如果房间号为空，提示用户
        qDebug() << "房间号不能为空！";
        QMessageBox::warning(this, "警告", "房间号不能为空！");
    }
}
