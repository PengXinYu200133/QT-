#ifndef CARD_REPLACEMENT_H
#define CARD_REPLACEMENT_H

#include <QMainWindow>
#include <QStandardItemModel> // 用于管理表格数据的模型
#include <QSqlQuery>          // 用于直接执行 SQL 查询
#include <QSqlError>
#include <QDebug>
#include <QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui { class card_replacement; }
QT_END_NAMESPACE

class card_replacement : public QMainWindow
{
    Q_OBJECT

public:
    card_replacement(QWidget *parent = nullptr);
    ~card_replacement();
    void initializeSerialPort();

signals:
    void card_replacement_opendoor(QString data);

private slots:
    void on_pushButton_clicked();
    void handleSerialData();
    void on_pushButton_2_clicked();

private:
    Ui::card_replacement *ui;
    QStandardItemModel *model; // 数据模型，用于管理 QTableView 的数据
    QSerialPort *serial;       // 串口对象

    void loadLostReplacementData(); // 加载数据到 QTableView
};
#endif // CARD_REPLACEMENT_H
