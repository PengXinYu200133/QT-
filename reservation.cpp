#include "reservation.h"
#include "ui_reservation.h"
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include <mainwindow.h>
#include <QDateTime>
#include "reservation_list.h"
extern QDateTime globaltime;
reservation::reservation(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::reservation)
{
    ui->setupUi(this);
    ui->frame_2->hide();
    CustomTextEdit *phonenumber = new CustomTextEdit(this);
    phonenumber->setGeometry(ui->phonenumber->geometry());
    delete ui->phonenumber;
    ui->phonenumber = phonenumber;
    phonenumber->setStyleSheet("border: 2px solid rgba(0, 0, 0, 150); /* 黑色边框，150为不透明度 */background-color: rgba(255, 255, 255, 200); /* 白色背景，200为不透明度 */border-radius: 10px; /* 圆角边框 */");
    connect(phonenumber, &CustomTextEdit::customMousePressed, this, &reservation::myon_phonenumber_cursorPositionChanged);

    CustomTextEdit *intime = new CustomTextEdit(this);
    intime->setGeometry(ui->intime->geometry());
    delete ui->intime;
    ui->intime = intime;
    intime->setStyleSheet("border: 2px solid rgba(0, 0, 0, 150); /* 黑色边框，150为不透明度 */background-color: rgba(255, 255, 255, 200); /* 白色背景，200为不透明度 */border-radius: 10px; /* 圆角边框 */");
    connect(intime, &CustomTextEdit::customMousePressed, this, &reservation::myintime_cursorPositionChanged);


    // 连接到 SQLite 数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","reservation");
    db.setDatabaseName("User.db");

    if (!db.open()) {
        QMessageBox::critical(nullptr, "PXYDatabase Error", db.lastError().text());
        return;
    }
    QSqlQuery query(db);
    query.exec("SELECT RoomType FROM roomtype");
    while (query.next()) {
        QString fontName = query.value(0).toString();
        ui->roomtybe->addItem(fontName);
        qDebug() << fontName;
    }
}

reservation::~reservation()
{
    delete ui;
}

void reservation::on_pushButton_1_clicked()
{
    if (ui->phonenumber->isEnabled()) {
        // 组件被禁用
        ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_1->text());
        qDebug()<<ui->phonenumber->toPlainText();
        qDebug() << "The input box is disabled.";
    } else {
        // 组件是启用的
        ui->intime->setText(ui->intime->toPlainText() + ui->pushButton_1->text());
        qDebug()<<ui->intime->toPlainText();
        qDebug() << "The input box is enabled.";
    }

}

void reservation::on_pushButton_2_clicked()
{
    if (ui->phonenumber->isEnabled()) {
        // 组件被禁用
        ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_2->text());
        qDebug()<<ui->phonenumber->toPlainText();
        qDebug() << "The input box is disabled.";
    } else {
        // 组件是启用的
        ui->intime->setText(ui->intime->toPlainText() + ui->pushButton_2->text());
        qDebug()<<ui->intime->toPlainText();
        qDebug() << "The input box is enabled.";
    }
}

void reservation::on_pushButton_3_clicked()
{
    if (ui->phonenumber->isEnabled()) {
        // 组件被禁用
        ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_3->text());
        qDebug()<<ui->phonenumber->toPlainText();
        qDebug() << "The input box is disabled.";
    } else {
        // 组件是启用的
        ui->intime->setText(ui->intime->toPlainText() + ui->pushButton_3->text());
        qDebug()<<ui->intime->toPlainText();
        qDebug() << "The input box is enabled.";
    }
}

void reservation::on_pushButton_4_clicked()
{
    if (ui->phonenumber->isEnabled()) {
        // 组件被禁用
        ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_4->text());
        qDebug()<<ui->phonenumber->toPlainText();
        qDebug() << "The input box is disabled.";
    } else {
        // 组件是启用的
        ui->intime->setText(ui->intime->toPlainText() + ui->pushButton_4->text());
        qDebug()<<ui->intime->toPlainText();
        qDebug() << "The input box is enabled.";
    }
}

void reservation::on_pushButton_5_clicked()
{
    if (ui->phonenumber->isEnabled()) {
        // 组件被禁用
        ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_5->text());
        qDebug()<<ui->phonenumber->toPlainText();
        qDebug() << "The input box is disabled.";
    } else {
        // 组件是启用的
        ui->intime->setText(ui->intime->toPlainText() + ui->pushButton_5->text());
        qDebug()<<ui->intime->toPlainText();
        qDebug() << "The input box is enabled.";
    }
}

void reservation::on_pushButton_6_clicked()
{
    if (ui->phonenumber->isEnabled()) {
        // 组件被禁用
        ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_6->text());
        qDebug()<<ui->phonenumber->toPlainText();
        qDebug() << "The input box is disabled.";
    } else {
        // 组件是启用的
        ui->intime->setText(ui->intime->toPlainText() + ui->pushButton_6->text());
        qDebug()<<ui->intime->toPlainText();
        qDebug() << "The input box is enabled.";
    }
}

void reservation::on_pushButton_7_clicked()
{
    if (ui->phonenumber->isEnabled()) {
        // 组件被禁用
        ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_7->text());
        qDebug()<<ui->phonenumber->toPlainText();
        qDebug() << "The input box is disabled.";
    } else {
        // 组件是启用的
        ui->intime->setText(ui->intime->toPlainText() + ui->pushButton_7->text());
        qDebug()<<ui->intime->toPlainText();
        qDebug() << "The input box is enabled.";
    }
}

void reservation::on_pushButton_8_clicked()
{
    if (ui->phonenumber->isEnabled()) {
        // 组件被禁用
        ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_8->text());
        qDebug()<<ui->phonenumber->toPlainText();
        qDebug() << "The input box is disabled.";
    } else {
        // 组件是启用的
        ui->intime->setText(ui->intime->toPlainText() + ui->pushButton_8->text());
        qDebug()<<ui->intime->toPlainText();
        qDebug() << "The input box is enabled.";
    }
}

void reservation::on_pushButton_9_clicked()
{
    if (ui->phonenumber->isEnabled()) {
        // 组件被禁用
        ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_9->text());
        qDebug()<<ui->phonenumber->toPlainText();
        qDebug() << "The input box is disabled.";
    } else {
        // 组件是启用的
        ui->intime->setText(ui->intime->toPlainText() + ui->pushButton_9->text());
        qDebug()<<ui->intime->toPlainText();
        qDebug() << "The input box is enabled.";
    }
}

void reservation::on_pushButton_0_clicked()
{
    if (ui->phonenumber->isEnabled()) {
        // 组件被禁用
        ui->phonenumber->setText(ui->phonenumber->toPlainText() + ui->pushButton_0->text());
        qDebug()<<ui->phonenumber->toPlainText();
        qDebug() << "The input box is disabled.";
    } else {
        // 组件是启用的
        ui->intime->setText(ui->intime->toPlainText() + ui->pushButton_0->text());
        qDebug()<<ui->intime->toPlainText();
        qDebug() << "The input box is enabled.";
    }
}

void reservation::on_pushButton_clicked()//回退按键
{
    if (ui->phonenumber->isEnabled()) {
        // 组件被禁用
        QString currentText = ui->phonenumber->toPlainText();
        if (currentText.length() > 0) {
            // 移除最后一个字符
            QString newText = currentText.left(currentText.length() - 1);
            ui->phonenumber->setText(newText);
        }
    } else {
        // 组件是启用的
        QString currentText = ui->intime->toPlainText();
        if (currentText.length() > 0) {
            // 移除最后一个字符
            QString newText = currentText.left(currentText.length() - 1);
            ui->intime->setText(newText);
        }
    }

}


void reservation::on_pushButton_10_clicked()//完成按键
{
    ui->frame->setEnabled(true);
    ui->intime->setEnabled(true);
    ui->phonenumber->setEnabled(true);
    QList<QWidget *> children = ui->frame->findChildren<QWidget *>();
    for (QWidget *child : children) {
        child->setEnabled(true);
    }
    ui->frame_2->hide();

}

void reservation::on_pushButton_11_clicked()//确认按钮
{
    QString phonenumber = ui->phonenumber->toPlainText();
    QString intime = ui->intime->toPlainText();
    QString standardTime;
    QString monthStr = intime.mid(0, 2);
    QString dayStr = intime.mid(2, 2);
    QString hourStr = intime.mid(4, 2);
    QString minuteStr = intime.mid(6, 2);

    int month = monthStr.toInt();
    int day = dayStr.toInt();
    int hour = hourStr.toInt();
    int minute = minuteStr.toInt();
    if (intime.length() == 8) {
        // 获取当前年份
        QString currentYear = globaltime.toString("yyyy");

        // 构建标准时间格式字符串
        standardTime = QString("%1-%2-%3 %4:%5:00")
                           .arg(currentYear)
                           .arg(month, 2, 10, QLatin1Char('0'))
                           .arg(day, 2, 10, QLatin1Char('0'))
                           .arg(hour, 2, 10, QLatin1Char('0'))
                           .arg(minute, 2, 10, QLatin1Char('0'));
        qDebug() << standardTime;
    } else {
        qDebug() << "输入格式不正确！";
    }
    QString roomtybe = ui->roomtybe->currentText();
    QSqlDatabase db = QSqlDatabase::database("reservation");
    QSqlQuery query(db);
    query.prepare("SELECT RoomID FROM available_room "
                  "WHERE State = 0 AND RoomType = :roomtype "
                  "LIMIT 1");
    query.bindValue(":roomtype", roomtybe);
    if (query.exec()) {
        if (query.next()) {
            QString room_id = query.value(0).toString();
            QDateTime currentDateTime = globaltime;
            QString formattedDateTime = globaltime.toString("yyyy-MM-dd hh:mm:ss");
            qDebug() << "查询到的currentDateTime: " << formattedDateTime;
            QDate currentDate = QDateTime::fromString(formattedDateTime, "yyyy-MM-dd hh:mm:ss").date();
            QDate expectDate = QDateTime::fromString(standardTime, "yyyy-MM-dd hh:mm:ss").date();

            // 比较预约时间和系统时间的月份和日期
            if (expectDate < currentDate) {
                int newYear = expectDate.year() + 1;
                QString newStandardTime = QString("%1-%2-%3 %4:%5:00")
                                              .arg(newYear)
                                              .arg(month, 2, 10, QLatin1Char('0'))
                                              .arg(day, 2, 10, QLatin1Char('0'))
                                              .arg(hour, 2, 10, QLatin1Char('0'))
                                              .arg(minute, 2, 10, QLatin1Char('0'));
                standardTime = newStandardTime;
            }
            qDebug() << "查询到的RoomID: " << room_id;
            query.prepare("INSERT INTO reservation (room_id, phonenumber, expect_check_in_time, expect_time) VALUES (:room_id, :phonenumber, :expect_check_in_time, :expect_time)");
            query.bindValue(":room_id", room_id);
            query.bindValue(":phonenumber", phonenumber);
            query.bindValue(":expect_check_in_time", standardTime);
            query.bindValue(":expect_time", formattedDateTime);


            if (!query.exec()) {
                qDebug() << "Data insertion failed：" << query.lastError().text();
                QMessageBox::critical(nullptr, "错误", "数据库插入错误");
            } else {
                qDebug() << "Data insertion successful";
                QSqlQuery updateQuery(db);
                QString updateQueryStr = QString("UPDATE available_room SET State = 1 WHERE RoomID = '%1'").arg(room_id);
                if (updateQuery.exec(updateQueryStr)) {
                    qDebug() << "available_room表中RoomID为 " << room_id << " 的数据的State字段已更新为1";
                } else {
                    qDebug() << "更新available_room表State字段失败：" << updateQuery.lastError().text();
                }
                QMessageBox::critical(this, "成功", "预约记录添加成功！" );
                db.close();
                this->close();

            }
        } else {
            qDebug() << "No data found that meets the criteria";
            QMessageBox::critical(nullptr, "错误", "没有找到房间号");
        }
    } else {
        qDebug() << "Query failed:" << query.lastError().text();
    }
}


void reservation::on_pushButton_12_clicked()
{
    reservation_list * p = new reservation_list();
    p->show();
    this->close();

}
void reservation::myon_phonenumber_cursorPositionChanged(QMouseEvent *event)//按下手机尾号文本框
{
    // 这里可以根据event获取鼠标按下的位置、按键等信息
    qDebug() << "鼠标位置：" << event->pos();
    ui->frame->setEnabled(false);
    ui->intime->setEnabled(false);
    ui->phonenumber->setEnabled(true);
    ui->frame_2->show();
    qDebug() << "intime isenabled："<<ui->intime->isEnabled();
}
void reservation::myintime_cursorPositionChanged(QMouseEvent *event)//按下入住时间文本框
{
    qDebug() << "鼠标位置：" << event->pos();
    ui->frame->setEnabled(false);
    ui->phonenumber->setEnabled(false);
    ui->intime->setEnabled(true);
    ui->frame_2->show();
    qDebug() << "phonenumber isenabled："<< ui->phonenumber->isEnabled();
}

