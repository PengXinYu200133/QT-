#ifndef ESP8266_H
#define ESP8266_H

#include <QObject>
#include <QSerialPort>
#include <QString>

class ESP8266 : public QObject {
    Q_OBJECT

public:
    explicit ESP8266(const QString &portName, int baudRate, QObject *parent = nullptr);
    ~ESP8266();

    void sendCommand(const QString &command);
    void configureAsServer();
    void findIP();
    void getTime();
    void mysendCommand(const QString &command);
    QString parseDateFromHeader(const QString &headerData);
    int parseConnectionNumber(const QString& ipdData);
    void processLine(const QString &line);
    void handleCompleteLine(const QString &line);
    void sendjson(int a,QString jsondata);
    void broadcastData(const QString data);

signals:
    void ipAddressReceived(const QString &ip); // 信号，用于传递 IP 地址
    void ipdDataReceived(const QString &data); // 新增信号，用于传递 +IPD 数据
    void dateTimeParsed(const QDateTime &dateTime);//信号：传递时间
    void getDateCommandReceived(int a);//获取数据信号

private slots:
    void readData();


private:
    QString parseStationIP(const QString &response);
    QString parseIPDData(const QString &data); // 新增方法，用于解析 +IPD 数据


    QSerialPort *serialPort;
    QByteArray responseBuffer;
};

#endif // ESP8266_H
