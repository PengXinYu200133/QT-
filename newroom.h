#ifndef NEWROOM_H
#define NEWROOM_H

#include <QMainWindow>
#include <QSqlDatabase>
namespace Ui {
class newroom;
}

class newroom : public QMainWindow
{
    Q_OBJECT

public:
    explicit newroom(QWidget *parent = nullptr);
    ~newroom();

private slots:
    void on_pushButton_on_clicked();

  /*  void on_comboBox_2_currentTextChanged(const QString &arg1);

    void on_comboBox_currentTextChanged(const QString &arg1);*/

    void on_pushButton_back_clicked();

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
    void myon_phonenumber_cursorPositionChanged(QMouseEvent *event);
private:
    Ui::newroom *ui;
    QSqlDatabase db;
};

#endif // NEWROOM_H
