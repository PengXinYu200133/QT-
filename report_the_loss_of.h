#ifndef REPORT_THE_LOSS_OF_H
#define REPORT_THE_LOSS_OF_H

#include <QMainWindow>
#include <QTextEdit>
#include <QMouseEvent>
namespace Ui {
class report_the_loss_of;

}

class report_the_loss_of : public QMainWindow
{
    Q_OBJECT

public:
    explicit report_the_loss_of(QWidget *parent = nullptr);
    ~report_the_loss_of();

private slots:
    void myon_phonenumber_cursorPositionChanged(QMouseEvent *event);

    void on_pushButton_10_clicked();

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

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void limitPhoneNumberLength();

signals:
    void closedoor(QString data);
private:
    Ui::report_the_loss_of *ui;
};

#endif // REPORT_THE_LOSS_OF_H
