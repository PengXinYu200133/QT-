#include "reservation_list.h"
#include "ui_reservation_list.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QStandardItem>
#include "quick_check_in.h"
#include "reservation.h"
// 数据库连接函数
bool reservation_list::connectToDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","reservation_list"); // SQLite 数据库驱动
    db.setDatabaseName("User.db"); // 数据库文件路径（请确保文件存在）

    if (!db.open()) {
        qDebug() << "数据库连接失败: " << db.lastError().text();
        QMessageBox::critical(this, "数据库错误", "无法连接到数据库：" + db.lastError().text());
        return false;
    }

    qDebug() << "数据库连接成功!";
    return true;
}

// 构造函数
reservation_list::reservation_list(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::reservation_list)
    , itemModel(new QStandardItemModel(this)) // 初始化 QStandardItemModel
{
    ui->setupUi(this);

    // 连接数据库
    if (!connectToDatabase()) {
        return;
    }

    // 隐藏 frame_2
    ui->frame_2->hide();
    CustomTextEdit *phonenumber = new CustomTextEdit(this);
    phonenumber->setGeometry(ui->numberinput->geometry());
    delete ui->numberinput;
    ui->numberinput = phonenumber;
    phonenumber->setStyleSheet("border: 2px solid rgba(0, 0, 0, 150); /* 黑色边框，150为不透明度 */background-color: rgba(255, 255, 255, 200); /* 白色背景，200为不透明度 */border-radius: 10px; /* 圆角边框 */");
    connect(phonenumber, &CustomTextEdit::customMousePressed, this, &reservation_list::myon_phonenumber_cursorPositionChanged);

    // 默认加载所有数据
    loadReservationData();
}

// 析构函数
reservation_list::~reservation_list()
{
    delete itemModel;
    delete ui;
}

// 自定义 phonenumber 文本框点击事件
void reservation_list::myon_phonenumber_cursorPositionChanged()
{
    ui->frame_2->show();
}

// 加载预约数据
void reservation_list::loadReservationData(const QString &phoneNumber)
{
    // 设置表头
    itemModel->setHorizontalHeaderLabels({"房间号", "手机号", "预计入住时间", "预计离开时间"});

    // 查询数据库
    QSqlDatabase db = QSqlDatabase::database("reservation_list");
    QSqlQuery query(db);

    QString queryStr = "SELECT room_id, phonenumber, expect_check_in_time, expect_time FROM reservation WHERE state = 0";
    if (!phoneNumber.isEmpty()) {
        queryStr += " AND phonenumber LIKE :phoneNumber"; // 按手机号筛选
        query.prepare(queryStr);
        query.bindValue(":phoneNumber", "%" + phoneNumber + "%");
    } else {
        query.prepare(queryStr);
    }

    if (!query.exec()) {
        qDebug() << "查询失败: " << query.lastError().text();
        QMessageBox::critical(this, "数据库错误", "无法加载数据：" + query.lastError().text());
        return;
    }

    // 清空表格数据
    itemModel->removeRows(0, itemModel->rowCount());

    // 填充表格数据
    while (query.next()) {
        QString roomId = query.value(0).toString();
        QString phoneNumber = query.value(1).toString();
        QString checkInTime = query.value(2).toString();
        QString checkOutTime = query.value(3).toString();

        QList<QStandardItem *> rowItems;
        rowItems.append(new QStandardItem(roomId));
        rowItems.append(new QStandardItem(phoneNumber));
        rowItems.append(new QStandardItem(checkInTime));
        rowItems.append(new QStandardItem(checkOutTime));

        itemModel->appendRow(rowItems);
    }

    ui->tableView->setModel(itemModel);

    // 配置表格行为
    ui->tableView->horizontalHeader()->setStretchLastSection(true); // 自动调整列宽
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows); // 整行选择
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); // 单行选择
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); // 禁止编辑
}

// 查询按钮点击事件
void reservation_list::on_pushButton_search_clicked()
{
    QString phoneNumber = ui->numberinput->toPlainText(); // 获取文本框内容
    loadReservationData(phoneNumber); // 根据手机号查询数据
}

// 数字按钮点击事件
void reservation_list::on_pushButton_1_clicked()
{
    ui->numberinput->setText(ui->numberinput->toPlainText() + ui->pushButton_1->text());
}

void reservation_list::on_pushButton_2_clicked()
{
    ui->numberinput->setText(ui->numberinput->toPlainText() + ui->pushButton_2->text());
}

void reservation_list::on_pushButton_3_clicked()
{
    ui->numberinput->setText(ui->numberinput->toPlainText() + ui->pushButton_3->text());
}

void reservation_list::on_pushButton_4_clicked()
{
    ui->numberinput->setText(ui->numberinput->toPlainText() + ui->pushButton_4->text());
}

void reservation_list::on_pushButton_5_clicked()
{
    ui->numberinput->setText(ui->numberinput->toPlainText() + ui->pushButton_5->text());
}

void reservation_list::on_pushButton_6_clicked()
{
    ui->numberinput->setText(ui->numberinput->toPlainText() + ui->pushButton_6->text());
}

void reservation_list::on_pushButton_7_clicked()
{
    ui->numberinput->setText(ui->numberinput->toPlainText() + ui->pushButton_7->text());
}

void reservation_list::on_pushButton_8_clicked()
{
    ui->numberinput->setText(ui->numberinput->toPlainText() + ui->pushButton_8->text());
}

void reservation_list::on_pushButton_9_clicked()
{
    ui->numberinput->setText(ui->numberinput->toPlainText() + ui->pushButton_9->text());
}

void reservation_list::on_pushButton_0_clicked()
{
    ui->numberinput->setText(ui->numberinput->toPlainText() + ui->pushButton_0->text());
}

// 删除最后一个字符
void reservation_list::on_pushButton_10_clicked()
{
    QString currentText = ui->numberinput->toPlainText();
    if (!currentText.isEmpty()) {
        ui->numberinput->setText(currentText.left(currentText.length() - 1));
    }
}

// 隐藏 frame_2
void reservation_list::on_pushButton_11_clicked()
{
    ui->frame_2->hide();
}

// 关闭窗口
void reservation_list::on_pushButton_12_clicked()
{
    this->close();
}

void reservation_list::on_new_2_clicked()
{
    reservation *p = new reservation();
    p->show();
    this->close();
}


void reservation_list::on_pushButton_clicked() // 入住按钮
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
    // 查询数据库获取房间类型（RoomType）
    QSqlDatabase db = QSqlDatabase::database("reservation_list");
    if (!db.open()) {
        QMessageBox::critical(nullptr, "Database Error", db.lastError().text());
        return;
    }

    QString roomType; // 用于存储查询到的房间类型
    QSqlQuery query(db);
    query.prepare("SELECT RoomType FROM available_room WHERE RoomID = :roomNumber");
    query.bindValue(":roomNumber", roomNumber);

    if (query.exec()) {
        if (query.next()) {
            roomType = query.value(0).toString(); // 获取查询结果中的 RoomType
            qDebug() << "查询到的房间类型：" << roomType;
        } else {
            qDebug() << "未找到匹配的房间类型";
            QMessageBox::warning(this, "警告", "未找到匹配的房间类型");
            return;
        }
    } else {
        qDebug() << "查询失败：" << query.lastError().text();
        QMessageBox::critical(this, "错误", "查询房间类型失败");
        return;
    }

    quick_check_in *p = new quick_check_in(roomNumber, roomType);
    p->show();

    // ***** 新增部分：更新 reservation 表的 state 字段 *****
    // 假设手机尾号在表格的第 2 列
    QString phoneTail = model->data(model->index(row, 2)).toString(); // 第二列（手机尾号）

    QSqlQuery updateQuery(db);
    updateQuery.prepare("UPDATE reservation SET state = 1 WHERE phonenumber = :phoneTail AND room_id = :roomNumber");
    updateQuery.bindValue(":phoneTail", phoneTail);    // 绑定手机尾号
    updateQuery.bindValue(":roomNumber", roomNumber);  // 绑定房间号

    if (!updateQuery.exec()) {
        qDebug() << "更新 reservation 表失败：" << updateQuery.lastError().text();
        QMessageBox::critical(this, "错误", "更新预订状态失败：" + updateQuery.lastError().text());
        return;
    } else {
        qDebug() << "reservation 表已更新，state 字段设置为 1";
    }
}
