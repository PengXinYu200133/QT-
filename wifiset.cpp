#include "wifiset.h"
#include "ui_wifiset.h"
#include <QDebug>
#include <mainwindow.h>

wifiset::wifiset(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::wifiset)
{
    ui->setupUi(this);
    ui->frame_2->hide();
}

wifiset::~wifiset()
{
    delete ui;
}

void wifiset::on_pushButton_1_clicked()
{

    if (ui->wifiname->isEnabled()) {
        // 组件被禁用
        ui->wifiname->setText(ui->wifiname->toPlainText() + ui->pushButton_1->text());
        qDebug()<<ui->wifiname->toPlainText();
        qDebug() << "The input box is disabled.";
    } else {
        // 组件是启用的
        ui->wifipassword->setText(ui->wifipassword->toPlainText() + ui->pushButton_1->text());
        qDebug()<<ui->wifipassword->toPlainText();
        qDebug() << "The input box is enabled.";
    }
}


void wifiset::on_pushButton_2_clicked()
{
    if (ui->wifiname->isEnabled()) {
        // 组件被禁用
        ui->wifiname->setText(ui->wifiname->toPlainText() + ui->pushButton_2->text());
        qDebug()<<ui->wifiname->toPlainText();
        qDebug() << "The input box is disabled.";
    } else {
        // 组件是启用的
        ui->wifipassword->setText(ui->wifipassword->toPlainText() + ui->pushButton_2->text());
        qDebug()<<ui->wifipassword->toPlainText();
        qDebug() << "The input box is enabled.";
    }
}


void wifiset::on_pushButton_3_clicked()
{
    if (ui->wifiname->isEnabled()) {
        // 组件被禁用
        ui->wifiname->setText(ui->wifiname->toPlainText() + ui->pushButton_3->text());
        qDebug()<<ui->wifiname->toPlainText();
        qDebug() << "The input box is disabled.";
    } else {
        // 组件是启用的
        ui->wifipassword->setText(ui->wifipassword->toPlainText() + ui->pushButton_3->text());
        qDebug()<<ui->wifipassword->toPlainText();
        qDebug() << "The input box is enabled.";
    }
}


void wifiset::on_pushButton_4_clicked()
{
    if (ui->wifiname->isEnabled()) {
        // 组件被禁用
        ui->wifiname->setText(ui->wifiname->toPlainText() + ui->pushButton_4->text());
        qDebug()<<ui->wifiname->toPlainText();
        qDebug() << "The input box is disabled.";
    } else {
        // 组件是启用的
        ui->wifipassword->setText(ui->wifipassword->toPlainText() + ui->pushButton_4->text());
        qDebug()<<ui->wifipassword->toPlainText();
        qDebug() << "The input box is enabled.";
    }
}

void wifiset::on_pushButton_5_clicked()
{
    if (ui->wifiname->isEnabled()) {
        // 组件被禁用
        ui->wifiname->setText(ui->wifiname->toPlainText() + ui->pushButton_5->text());
        qDebug()<<ui->wifiname->toPlainText();
        qDebug() << "The input box is disabled.";
    } else {
        // 组件是启用的
        ui->wifipassword->setText(ui->wifipassword->toPlainText() + ui->pushButton_5->text());
        qDebug()<<ui->wifipassword->toPlainText();
        qDebug() << "The input box is enabled.";
    }
}

void wifiset::on_pushButton_6_clicked()
{
    if (ui->wifiname->isEnabled()) {
        // 组件被禁用
        ui->wifiname->setText(ui->wifiname->toPlainText() + ui->pushButton_6->text());
        qDebug()<<ui->wifiname->toPlainText();
        qDebug() << "The input box is disabled.";
    } else {
        // 组件是启用的
        ui->wifipassword->setText(ui->wifipassword->toPlainText() + ui->pushButton_6->text());
        qDebug()<<ui->wifipassword->toPlainText();
        qDebug() << "The input box is enabled.";
    }
}

void wifiset::on_pushButton_7_clicked()
{
    if (ui->wifiname->isEnabled()) {
        // 组件被禁用
        ui->wifiname->setText(ui->wifiname->toPlainText() + ui->pushButton_7->text());
        qDebug()<<ui->wifiname->toPlainText();
        qDebug() << "The input box is disabled.";
    } else {
        // 组件是启用的
        ui->wifipassword->setText(ui->wifipassword->toPlainText() + ui->pushButton_7->text());
        qDebug()<<ui->wifipassword->toPlainText();
        qDebug() << "The input box is enabled.";
    }
}

void wifiset::on_pushButton_8_clicked()
{
    if (ui->wifiname->isEnabled()) {
        // 组件被禁用
        ui->wifiname->setText(ui->wifiname->toPlainText() + ui->pushButton_8->text());
        qDebug()<<ui->wifiname->toPlainText();
        qDebug() << "The input box is disabled.";
    } else {
        // 组件是启用的
        ui->wifipassword->setText(ui->wifipassword->toPlainText() + ui->pushButton_8->text());
        qDebug()<<ui->wifipassword->toPlainText();
        qDebug() << "The input box is enabled.";
    }
}

void wifiset::on_pushButton_9_clicked()
{
    if (ui->wifiname->isEnabled()) {
        // 组件被禁用
        ui->wifiname->setText(ui->wifiname->toPlainText() + ui->pushButton_9->text());
        qDebug()<<ui->wifiname->toPlainText();
        qDebug() << "The input box is disabled.";
    } else {
        // 组件是启用的
        ui->wifipassword->setText(ui->wifipassword->toPlainText() + ui->pushButton_9->text());
        qDebug()<<ui->wifipassword->toPlainText();
        qDebug() << "The input box is enabled.";
    }
}

void wifiset::on_pushButton_0_clicked()
{
    if (ui->wifiname->isEnabled()) {
        // 组件被禁用
        ui->wifiname->setText(ui->wifiname->toPlainText() + ui->pushButton_0->text());
        qDebug()<<ui->wifiname->toPlainText();
        qDebug() << "The input box is disabled.";
    } else {
        // 组件是启用的
        ui->wifipassword->setText(ui->wifipassword->toPlainText() + ui->pushButton_0->text());
        qDebug()<<ui->wifipassword->toPlainText();
        qDebug() << "The input box is enabled.";
    }
}





void wifiset::on_pushButton_clicked()//回退按键
{
    if (ui->wifiname->isEnabled()) {
        // 组件被禁用
        QString currentText = ui->wifiname->toPlainText();
        if (currentText.length() > 0) {
            // 移除最后一个字符
            QString newText = currentText.left(currentText.length() - 1);
            ui->wifiname->setText(newText);
        }
    } else {
        // 组件是启用的
        QString currentText = ui->wifipassword->toPlainText();
        if (currentText.length() > 0) {
            // 移除最后一个字符
            QString newText = currentText.left(currentText.length() - 1);
            ui->wifipassword->setText(newText);
        }
    }

}


void wifiset::on_pushButton_10_clicked()//完成按键
{
    ui->frame->setEnabled(true);
    ui->wifipassword->setEnabled(true);
    ui->wifiname->setEnabled(true);
    QList<QWidget *> children = ui->frame->findChildren<QWidget *>();
    for (QWidget *child : children) {
        child->setEnabled(true);
    }
    ui->frame_2->hide();

}


void wifiset::on_pushButton_35_clicked()//取消按钮
{
    this->close();

}


void wifiset::on_pushButton_36_clicked()//确定按钮
{

}


void wifiset::on_test_clicked()//通信测试
{

}


void wifiset::on_test_2_clicked()
{

}

