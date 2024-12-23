#ifndef RESERVATION_H
#define RESERVATION_H

#include <QMainWindow>
#include <QTextEdit>
#include <QMouseEvent>
namespace Ui {
class reservation;
class CustomTextEdit;
}
class CustomTextEdit : public QTextEdit {
    Q_OBJECT

public:
    explicit CustomTextEdit(QWidget *parent = nullptr) : QTextEdit(parent) {}

protected:
    void mousePressEvent(QMouseEvent *event) override {
        emit customMousePressed(event); // 发出自定义信号
        QTextEdit::mousePressEvent(event); // 调用父类的默认实现
    }

signals:
    void customMousePressed(QMouseEvent *event); // 自定义信号
};
class reservation : public QMainWindow
{
    Q_OBJECT

public:
    explicit reservation(QWidget *parent = nullptr);
    ~reservation();

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

    void myon_phonenumber_cursorPositionChanged(QMouseEvent *event);

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void myintime_cursorPositionChanged(QMouseEvent *event);

private:
    Ui::reservation *ui;
};

#endif // RESERVATION_H
