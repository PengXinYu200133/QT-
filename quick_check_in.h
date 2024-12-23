#ifndef QUICK_CHECK_IN_H
#define QUICK_CHECK_IN_H

#include <QMainWindow>
#include <QSerialPort>
namespace Ui {
class quick_check_in;
}

class quick_check_in : public QMainWindow
{
    Q_OBJECT

public:
    explicit quick_check_in(QString roomid,QString roomtype,QWidget *parent = nullptr);
    ~quick_check_in();

private slots:

    void on_pushButton_1_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_0_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_back_clicked();

    void myphonenumber_cursorPositionChanged();

    void handleReceivedData(const QString &data);

    void on_queding_clicked();
    void handleSerialData();
signals:
    void quick_opendoor(QString &data);
private:
    Ui::quick_check_in *ui;
    QString roomid;
    QString roomtype;
    QSerialPort *serial;           // 串口对象
};

#endif // QUICK_CHECK_IN_H
