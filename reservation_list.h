#ifndef RESERVATION_LIST_H
#define RESERVATION_LIST_H

#include <QMainWindow>
#include <QStandardItemModel> // 使用 QStandardItemModel
#include <QTableView>

QT_BEGIN_NAMESPACE
namespace Ui { class reservation_list; }
QT_END_NAMESPACE

class reservation_list : public QMainWindow
{
    Q_OBJECT

public:
    explicit reservation_list(QWidget *parent = nullptr);
    ~reservation_list();

private slots:
    void myon_phonenumber_cursorPositionChanged(); // 自定义文本框点击事件
    void loadReservationData(const QString &phoneNumber = QString()); // 加载数据，支持按手机号查询
    void on_pushButton_search_clicked(); // 查询按钮槽函数
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
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();

    void on_new_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::reservation_list *ui;
    QStandardItemModel *itemModel; // 表格数据模型
    bool connectToDatabase();     // 数据库连接函数
};

#endif // RESERVATION_LIST_H
