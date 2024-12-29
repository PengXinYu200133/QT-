#include "card_replacement.h"
#include "ui_card_replacement.h"
#include <QMessageBox>
#include "esp8266.h"

extern ESP8266 *globalESP; // 外部 ESP8266 对象，用于发送数据

card_replacement::card_replacement(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::card_replacement)
    , serial(new QSerialPort(this)) // 初始化串口对象
{
    ui->setupUi(this);

    // 连接信号和槽，用于发送开门信号
    connect(this, &card_replacement::card_replacement_opendoor, globalESP, &ESP8266::broadcastData, Qt::QueuedConnection);
    initializeSerialPort();
    // 初始化 QStandardItemModel
    model = new QStandardItemModel(this);

    // 设置列标题
    model->setColumnCount(5);
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Name"));
    model->setHeaderData(2, Qt::Horizontal, tr("Room ID"));
    model->setHeaderData(3, Qt::Horizontal, tr("Room Type"));
    model->setHeaderData(4, Qt::Horizontal, tr("In Time"));

    // 将模型绑定到 QTableView
    ui->tableView->setModel(model);

    // 设置表格属性
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows); // 整行选择
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); // 单选
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); // 禁止编辑
    ui->tableView->horizontalHeader()->setStretchLastSection(false); // 最后一列不强制拉伸
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents); // 根据内容调整列宽
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);   // 根据内容调整行高

    // 加载数据到 QStandardItemModel
    loadLostReplacementData();
}

card_replacement::~card_replacement()
{


    delete ui;
}

void card_replacement::initializeSerialPort()
{
    serial->setPortName("/dev/ttySAC1"); // 设置串口名
    if (!serial->open(QIODevice::ReadWrite)) {
        qDebug() << "无法打开串口：" << serial->errorString();
        QMessageBox::critical(this, "串口错误", "无法打开串口设备！");
        return;
    }

    // 配置串口参数
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    // 连接串口信号，用于接收数据
    connect(serial, &QSerialPort::readyRead, this, &card_replacement::handleSerialData);
    qDebug() << "串口初始化完成，已打开！";
}

void card_replacement::loadLostReplacementData()
{
    QSqlDatabase db;
    if (QSqlDatabase::contains("card_replacement_connection")) {
        db = QSqlDatabase::database("card_replacement_connection");
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE", "card_replacement_connection");
        db.setDatabaseName("User.db");
    }

    if (!db.open()) {
        qDebug() << "无法连接到数据库：" << db.lastError().text();
        QMessageBox::critical(this, "数据库错误", "无法连接到数据库！");
        return;
    }

    // 清空现有数据
    model->removeRows(0, model->rowCount());

    // 查询数据
    QSqlQuery query(db);
    if (!query.exec("SELECT ID, name, room_id, room_type, in_time, state FROM lost_replacement WHERE state = 0")) {
        qDebug() << "查询数据失败：" << query.lastError().text();
        QMessageBox::critical(this, "数据库错误", "无法查询数据！");
        return;
    }

    // 填充模型数据
    int row = 0;
    while (query.next()) {
        model->insertRow(row);
        model->setData(model->index(row, 0), query.value("ID"));
        model->setData(model->index(row, 1), query.value("name"));
        model->setData(model->index(row, 2), query.value("room_id"));
        model->setData(model->index(row, 3), query.value("room_type"));
        model->setData(model->index(row, 4), query.value("in_time"));

        row++;
    }

    qDebug() << "数据加载成功，共加载 " << row << " 条记录！";

    // 自动调整列宽和行高
    ui->tableView->resizeColumnsToContents(); // 根据内容调整列宽
    ui->tableView->resizeRowsToContents();    // 根据内容调整行高
}

void card_replacement::handleSerialData()
{
    if (!serial || !serial->isOpen()) {
        qDebug() << "串口未打开，无法接收数据";
        return;
    }

    QByteArray receivedData = serial->readAll(); // 读取串口数据
    QString dataString = QString::fromUtf8(receivedData).trimmed(); // 转换为字符串并去掉空白
    qDebug() << "从串口接收到的数据：" << dataString;

    if (dataString.contains("OK")) { // 如果接收数据包含 "OK"
        QModelIndex index = ui->tableView->currentIndex();
        if (!index.isValid()) {
            qDebug() << "未选择任何行，无法更新数据";
            QMessageBox::warning(this, "错误", "请选择一条记录！");
            return;
        }

        // 获取选中记录的所有字段数据
        QString ID = model->data(model->index(index.row(), 0)).toString();        // 获取 ID
        QString name = model->data(model->index(index.row(), 1)).toString();     // 获取 Name
        QString roomId = model->data(model->index(index.row(), 2)).toString();   // 获取 Room ID
        QString roomType = model->data(model->index(index.row(), 3)).toString(); // 获取 Room Type
        QString inTime = model->data(model->index(index.row(), 4)).toString();   // 获取 In Time


        QSqlDatabase db = QSqlDatabase::database("card_replacement_connection");
        if (!db.isOpen() && !db.open()) {
            qDebug() << "数据库连接未打开！";
            QMessageBox::critical(this, "错误", "数据库连接未打开！");
            return;
        }

        // 根据多个条件查询数据库
        QSqlQuery query(db);


        //更新记录状态
        query.prepare("UPDATE lost_replacement SET state = 1 WHERE ID = :ID AND name = :name AND room_id = :room_id AND room_type = :room_type AND in_time = :in_time ");
        query.bindValue(":ID", ID);
        query.bindValue(":name", name);
        query.bindValue(":room_id", roomId);
        query.bindValue(":room_type", roomType);
        query.bindValue(":in_time", inTime);

        if (query.exec()) {
            qDebug() << "成功更新记录的 state 字段为 1，ID：" << ID;

            // 刷新数据
            loadLostReplacementData();

            // 发射信号通知开门
            QString date = "on:" + roomId;
            emit card_replacement_opendoor(date);

            QMessageBox::information(this, "成功", "卡片替换成功！");
        } else {
            qDebug() << "数据更新失败：" << query.lastError().text();
            QMessageBox::critical(this, "错误", "数据更新失败！");
        }
    } else {
        QMessageBox::warning(this, "错误", "串口返回数据无效！");
    }
}

void card_replacement::on_pushButton_clicked()
{
    if (!serial || !serial->isOpen()) {
        QMessageBox::warning(this, "错误", "串口未初始化或未打开！");
        return;
    }

    QModelIndex index = ui->tableView->currentIndex(); // 获取当前选中的索引
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请选择一个房间！");
        return;
    }

    QString roomId = model->data(model->index(index.row(), 2)).toString(); // 获取 Room ID
    qDebug() << "准备发送房间号到串口：" << roomId;

    QString sendData = "r+" + roomId;
    QByteArray dataToSend = sendData.toUtf8();
    qint64 bytesWritten = serial->write(dataToSend);
    if (bytesWritten == -1) {
        qDebug() << "数据发送失败：" << serial->errorString();
        QMessageBox::critical(this, "串口错误", "数据发送失败！");
        return;
    } else {
        qDebug() << "数据发送成功：" << sendData;
    }
}

void card_replacement::on_pushButton_2_clicked()
{
    // 检查串口是否已打开
    if (serial && serial->isOpen()) {
        // 关闭串口
        serial->close();
        qDebug() << "返回键点击：串口已关闭";
    }

    // 关闭窗口
    this->close();
}
