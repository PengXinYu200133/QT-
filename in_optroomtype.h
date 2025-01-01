#ifndef IN_OPTROOMTYPE_H
#define IN_OPTROOMTYPE_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui { class in_optroomtype; }
QT_END_NAMESPACE

class in_optroomtype : public QMainWindow
{
    Q_OBJECT

public:
    explicit in_optroomtype(QString *date, QWidget *parent = nullptr);
    ~in_optroomtype();
    void sendRoomNumber(const QString &roomNumber);
    void handleDynamicPassword(const QString &dynamicPassword);

signals:
    void opendoor(QString date);
private slots:
    void on_pushButton_clicked();  // 确认按钮
    void on_pushButton_2_clicked(); // 返回按钮
    void handleSerialData();       // 处理串口返回数据

    void on_pushButton_3_clicked();

private:
    Ui::in_optroomtype *ui;
    QStandardItemModel *model;
    QSerialPort *serial;           // 串口对象
    QString m_date[4];             // 存储传入的数据
};

#endif // IN_OPTROOMTYPE_H
