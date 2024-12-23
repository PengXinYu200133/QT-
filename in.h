#ifndef IN_H
#define IN_H

#include <QMainWindow>
#include <QThread>


namespace Ui {
class in;
}

class in : public QMainWindow
{
    Q_OBJECT

public:
    explicit in(QWidget *parent = nullptr);
    ~in();

private slots:
    void handleReceivedData(const QString &data);  // 处理 ESP8266 的 +IPD 数据





    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void myon_phonenumber_cursorPositionChanged();//数字输入框槽函数

    void on_optroom_clicked();

    void on_back_clicked();

    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();


    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_0_clicked();




private:
    Ui::in *ui;

};

#endif // IN_H
