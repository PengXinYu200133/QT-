#include "available_room_list.h"
#include "ui_available_room_list.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QStandardItemModel>
#include <QStandardItem>
#include "quick_check_in.h"
#include "quick_reservation.h"
available_room_list::available_room_list(QString roomname,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::available_room_list)
    , model(new QStandardItemModel(this)) // 初始化表格模型
{
    ui->setupUi(this);

    // 连接到 SQLite 数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "reservation");
    db.setDatabaseName("User.db");

    if (!db.open()) {
        QMessageBox::critical(nullptr, "Database Error", db.lastError().text());
        return;
    }
    int count=1;
    // 初始化下拉框
    ui->roomtybe->addItem("*"); // 添加默认值，表示查询所有房间类型
    QSqlQuery query(db);
    query.exec("SELECT RoomType FROM roomtype");
    while (query.next()) {
        QString roomType = query.value(0).toString();
        ui->roomtybe->addItem(roomType);
        qDebug() << "加载房间类型：" << roomType;
        if(roomType==roomname){
            ui->roomtybe->setCurrentIndex(count);
        }
        count++;

    }

    // 初始化 QTableView 的模型
    model->setHorizontalHeaderLabels({"RoomID", "RoomType", "Notes"}); // 设置表头
    ui->tableView->setModel(model); // 将模型设置到 QTableView
    ui->tableView->horizontalHeader()->setStretchLastSection(true); // 自动调整列宽
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows); // 整行选择
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); // 单行选择
    // 连接下拉框的信号到槽函数
    connect(ui->roomtybe, &QComboBox::currentTextChanged, this, &available_room_list::updateTable);


    // 初始化表格数据
    updateTable();


    db.close();
}

available_room_list::~available_room_list() {
    delete ui;
}

// 槽函数：根据下拉框的选择更新表格数据
void available_room_list::updateTable() {
    QString selectedRoomType = ui->roomtybe->currentText(); // 获取下拉框当前选中的文本
    qDebug() << "当前选中的房间类型：" << selectedRoomType;

    // 清空表格数据
    model->removeRows(0, model->rowCount());

    // 重新查询数据库
    QSqlDatabase db = QSqlDatabase::database("reservation");
    if (!db.open()) {
         qDebug() << "数据库未打开";
    }

    QSqlQuery query(db);
    QString queryString = "SELECT RoomID, RoomType, Notes FROM available_room WHERE State = 0";
    if (selectedRoomType != "*") {
        queryString += " AND RoomType = :roomType";
        query.prepare(queryString);
        query.bindValue(":roomType", selectedRoomType);
    } else {
        query.prepare(queryString);
    }

    if (!query.exec()) {
        qDebug() << "无数据";
    }

    // 将查询结果填充到表格中
    while (query.next()) {
        QString roomId = query.value(0).toString();   // RoomID
        QString roomType = query.value(1).toString(); // RoomType
        QString notes = query.value(2).toString();    // Notes

        QList<QStandardItem *> rowItems;
        rowItems.append(new QStandardItem(roomId));
        rowItems.append(new QStandardItem(roomType));
        rowItems.append(new QStandardItem(notes));
        qDebug() << "插入房间类型：" << roomType;
        model->appendRow(rowItems);
    }


}



void available_room_list::on_pushButton_4_clicked()
{ QSqlDatabase db = QSqlDatabase::database("reservation");
    db.close();
    this->close();

}


void available_room_list::on_pushButton_clicked()
{
    QItemSelectionModel *selectionModel = ui->tableView->selectionModel();
    QModelIndexList selectedRows = selectionModel->selectedRows();

    // 确保有选中的行
    if (selectedRows.isEmpty()) {
        qDebug() << "未选择任何行";
        return;
    }

    // 假设只处理第一选中行的房间号和房间类型
    const QModelIndex &rowIndex = selectedRows.first(); // 获取选中行的第一个索引
    int row = rowIndex.row();

    // 获取数据模型
    QAbstractItemModel *model = ui->tableView->model();
    if (!model) {
        qDebug() << "数据模型为空";
        return;
    }

    // 获取房间号（第 0 列）和房间类型（第 1 列）
    QString roomNumber = model->data(model->index(row, 0)).toString(); // 第一列（房间号）
    QString roomType = model->data(model->index(row, 1)).toString();   // 第二列（房间类型）
    quick_check_in *p = new quick_check_in(roomNumber,roomType);
    p->show();


}


void available_room_list::on_pushButton_2_clicked()
{
    QItemSelectionModel *selectionModel = ui->tableView->selectionModel();
    QModelIndexList selectedRows = selectionModel->selectedRows();

    // 确保有选中的行
    if (selectedRows.isEmpty()) {
        qDebug() << "未选择任何行";
        return;
    }

    // 假设只处理第一选中行的房间号和房间类型
    const QModelIndex &rowIndex = selectedRows.first(); // 获取选中行的第一个索引
    int row = rowIndex.row();

    // 获取数据模型
    QAbstractItemModel *model = ui->tableView->model();
    if (!model) {
        qDebug() << "数据模型为空";
        return;
    }

    // 获取房间号（第 0 列）和房间类型（第 1 列）
    QString roomNumber = model->data(model->index(row, 0)).toString(); // 第一列（房间号）

    quick_reservation *p = new quick_reservation(roomNumber);
    p->show();
}

