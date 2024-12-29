#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "esp8266.h"  // 包含ESP8266头文件
#include <QDateTime>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void findip();
    void gettime();
    void sendjson(int a,QString jsonString);
private slots:
    void displayIPAddress(const QString &ip); // 显示 IP 地址

    void on_pushButton_in_clicked();
    void on_pushButton_out_clicked();
    void on_pushButton_lost_clicked();
    void on_pushButton_continue_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_clicked();
    void on_pushButton_continue_2_clicked();
    void myfindip();
    void updateDateTimeEdit(const QDateTime &dateTime);


    void on_available_bigroom_clicked();
    void senddate(int a);//发送数据信号
    void on_available_tvroom_clicked();

    void on_available_jimafang_clicked();

    void on_available_one_clicked();

    void on_available_double_clicked();

    void on_available_rowbedroom_clicked();

    void on_available_xingzhengfang_clicked();

    void on_available_zongtongtaof_clicked();

private:
    Ui::MainWindow *ui;
    ESP8266 *esp;       // ESP8266 实例
    QThread *espThread; // 专门为 ESP8266 创建的线程
    QDateTime customDateTime; // 类的成员变量

};

#endif // MAINWINDOW_H
