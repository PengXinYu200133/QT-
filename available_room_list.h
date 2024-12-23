#ifndef AVAILABLE_ROOM_LIST_H
#define AVAILABLE_ROOM_LIST_H

#include <QMainWindow>
#include <QStandardItemModel> // 用于表格模型

namespace Ui {
class available_room_list;
}

class available_room_list : public QMainWindow {
    Q_OBJECT

public:
    explicit available_room_list(QWidget *parent = nullptr);
    ~available_room_list();

private slots:
    void updateTable(); // 槽函数，用于更新表格内容


    void on_pushButton_4_clicked();


    void on_pushButton_clicked();

private:
    Ui::available_room_list *ui;
    QStandardItemModel *model; // 用于管理 QTableView 的数据


};

#endif // AVAILABLE_ROOM_LIST_H
