#ifndef WIFISET_H
#define WIFISET_H

#include <QMainWindow>

namespace Ui {
class wifiset;
}

class wifiset : public QMainWindow
{
    Q_OBJECT

public:
    explicit wifiset(QWidget *parent = nullptr);
    ~wifiset();

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

    void on_pushButton_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_36_clicked();

    void on_test_clicked();

    void on_test_2_clicked();

private:
    Ui::wifiset *ui;
};

#endif // WIFISET_H
