#ifndef QUICK_RESERVATION_H
#define QUICK_RESERVATION_H

#include <QMainWindow>

namespace Ui {
class quick_reservation;
}

class quick_reservation : public QMainWindow
{
    Q_OBJECT

public:
    explicit quick_reservation(QString roomid,QWidget *parent = nullptr);
    ~quick_reservation();

private slots:
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

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_queding_clicked();

    void on_back_clicked();
    void myphonenumber_cursorPositionChanged(QMouseEvent *event);
    void myintime_cursorPositionChanged(QMouseEvent *event);

private:
    Ui::quick_reservation *ui;
    QString roomid;
};

#endif // QUICK_RESERVATION_H
