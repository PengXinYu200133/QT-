#ifndef CHECK_OUT_H
#define CHECK_OUT_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include <QMessageBox>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class check_out; }
QT_END_NAMESPACE

class check_out : public QMainWindow
{
    Q_OBJECT

public:
    explicit check_out(QWidget *parent = nullptr);
    ~check_out();

private:
    Ui::check_out *ui;
    QSerialPort *serial;  // 串口对象
    bool initializeDatabase(); // 初始化数据库
    void connectToSerialPort(); // 连接到串口
    void processRoomNumber(const QString &roomNumber); // 处理房间号
signals:
    void closeroom(QString data);
private slots:
    void readFromSerialPort(); // 从串口读取数据

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // CHECK_OUT_H
