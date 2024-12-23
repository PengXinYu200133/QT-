#include "esp8266.h"
#include <QDebug>
#include <QThread>
#include <QRegularExpression>
#include "QDateTime"
ESP8266::ESP8266(const QString &portName, int baudRate, QObject *parent)
    : QObject(parent), serialPort(new QSerialPort(this)) {
    serialPort->setPortName(portName);
    serialPort->setBaudRate(baudRate);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (serialPort->open(QIODevice::ReadWrite)) {
        qDebug() << "串口打开成功：" << portName;
    } else {
        qWarning() << "无法打开串口：" << portName << serialPort->errorString();
        return;
    }

    connect(serialPort, &QSerialPort::readyRead, this, &ESP8266::readData);
}

ESP8266::~ESP8266() {
    if (serialPort->isOpen()) {
        serialPort->close();
    }
}
void ESP8266::broadcastData(const QString data) {
    if (!serialPort->isOpen()) {
        qWarning() << "串口未打开，无法广播数据：" << data;
        return;
    }

    // 准备广播的数据
    QString fullData = data + "\r\n";
    int dataLength = fullData.toUtf8().length();

    // 构造 UDP 广播命令
    // 假设您已经使用 AT+CIPSTART=0,"UDP","0.0.0.0",5678,5678,0 启动了 UDP 服务
    QString sendCommand = QString("AT+CIPSEND=0,%1").arg(dataLength);

    // 发送 AT+CIPSEND 指令
    this->sendCommand(sendCommand);

    // ESP8266 应该返回 ">" 提示符，表示可以发送数据
    QThread::msleep(500); // 延时确保 ESP8266 准备好

    // 发送实际的数据
    this->sendCommand(fullData);

    // 打印调试信息
    qDebug() << QString("通过 UDP 广播数据：%1").arg(fullData);
}

void ESP8266::sendjson(int a, QString jsondata) {
    jsondata = jsondata+"\r\n";

    int dataLength = jsondata.toUtf8().length(); // 计算总数据长度

    // 第一步：通知 ESP8266 准备发送数据
    // 格式: AT+CIPSEND=<连接号>,<数据长度>
    QString sendCommand = QString("AT+CIPSEND=%1,%2").arg(a).arg(dataLength);
    this->sendCommand(sendCommand);

    // 等待 ESP8266 响应 ">" 提示符，表示可以发送数据
    QThread::msleep(500); // 延时确保 ESP8266 准备好

    // 第二步：发送实际的 HTTP 响应数据
    this->sendCommand(jsondata);

    // 打印调试信息
    qDebug() << "发送的完整 HTTP 数据：" << jsondata;


}
void ESP8266::getTime(){

    QString myweb ="GET\r\n/?app=life.time&appkey=10003&sign=b59bc3ef6191eb9f747dd4e83c99f2a4&format=json HTTP/1.1\r\nHost: api.k780.com:88\r\nConnection: close";
    sendCommand("AT+CIPSTART=3,\"TCP\",\"api.k780.com\",88");
    QThread::msleep(1000);
    sendCommand("AT+CIPSEND=3,"+QString::number(myweb.length()));
    QThread::msleep(1000);
    sendCommand(myweb);
}
void ESP8266::sendCommand(const QString &command) {
    if (serialPort->isOpen()) {
        QString fullCommand = command + "\r\n";
        serialPort->write(fullCommand.toUtf8());
        serialPort->flush();

        qDebug() << "发送指令：" << command;
    } else {
        qWarning() << "串口未打开，无法发送指令：" << command;
    }
}
//不加换行的发送，用来发送HHTTP请求
void ESP8266::mysendCommand(const QString &command) {
    if (serialPort->isOpen()) {
        serialPort->write(command.toUtf8());
        serialPort->flush();

        qDebug() << "发送指令：" << command;
    } else {
        qWarning() << "串口未打开，无法发送指令：" << command;
    }
}
//解析连接号
int ESP8266::parseConnectionNumber(const QString& ipdData) {
    QRegularExpression regex("\\+IPD,(\\d+),");  // 匹配 +IPD,连接号, 的正则表达式
    QRegularExpressionMatch match = regex.match(ipdData);

    if (match.hasMatch()) {
        QString connectionNumStr = match.captured(1); // 获取连接号
        bool ok;
        int connectionNum = connectionNumStr.toInt(&ok);
        if (ok) {
            qDebug() << "解析到的连接号：" << connectionNum;
            return connectionNum;
        }
    }

    qDebug() << "未解析到有效的连接号";
    return -1; // 返回 -1 表示未找到连接号
}
void ESP8266::readData() {
    QByteArray data = serialPort->readAll(); // 读取串口中的数据
    responseBuffer.append(data);             // 拼接到缓冲区

    // 打印每次接收到的片段
    qDebug() << "ESP返回片段：" << QString::fromUtf8(data.trimmed());

    // 按行分隔缓冲区中的数据
    while (responseBuffer.contains("\r\n")) {
        // 找到第一个完整的行
        int endIndex = responseBuffer.indexOf("\r\n");
        QByteArray line = responseBuffer.left(endIndex); // 提取完整行（不包括 \r\n）
        responseBuffer.remove(0, endIndex + 2);         // 从缓冲区中移除已处理的行

        // 打印解析到的完整行
        qDebug() << "解析到完整行：" << QString::fromUtf8(line);

        // 如果解析到完整行，处理该行
        processLine(QString::fromUtf8(line));
    }
}

void ESP8266::processLine(const QString &line) {
    // 检查是否包含 "+IPD" 数据
    if (line.contains("+IPD")) {
        QString ipdData = line;
        qDebug() << "解析到的 +IPD 数据：" << ipdData;
        // 如果完整行中包含 "getdate" 字段
        if (ipdData.contains("getdate")) {
                // 解析连接号
            int connectionIndex = parseConnectionNumber(ipdData);
            qDebug() << "检测到 'getdate' 字段，触发信号";
            emit getDateCommandReceived(connectionIndex); // 发出信号
        }else{
            ipdData = parseIPDData(ipdData);
        emit ipdDataReceived(ipdData); // 发出信号，传递 +IPD 数据
            qDebug() << "解析的身份数据：" << ipdData;
        }
    }

    // 检查是否包含 "+CIFSR:STAIP" 数据
    if (line.contains("+CIFSR:STAIP")) {
        QString response = line;
        QString stationIP = parseStationIP(response);
        if (!stationIP.isEmpty()) {
            qDebug() << "解析到的 STA 模式 IP 地址：" << stationIP;
            emit ipAddressReceived(stationIP); // 发出信号，传递 IP 地址
        }
    }

    // 检查是否包含 "Date:" 字段
    if (line.contains("Date:")) {
        QString dateLine = line;
        QString localTime = parseDateFromHeader(dateLine); // 调用解析函数
        if (!localTime.isEmpty()) {
            qDebug() << "解析到的本地时间：" << localTime;
            emit dateTimeParsed(QDateTime::fromString(localTime, "yyyy-MM-dd HH:mm:ss")); // 发出信号
        }
    }
}

QString ESP8266::parseDateFromHeader(const QString &headerData) {
    // 使用正则表达式匹配 "Date: ..." 格式
    static const QRegularExpression regex(R"(Date:\s+([A-Za-z]{3},\s+\d{2}\s+[A-Za-z]{3}\s+\d{4}\s+\d{2}:\d{2}:\d{2}\s+GMT))");
    QRegularExpressionMatch match = regex.match(headerData);

    if (match.hasMatch()) {
        QString dateTimeString = match.captured(1); // 提取时间字符串
        qDebug() << "匹配到的时间字符串：" << dateTimeString;

        // 使用 QLocale 解析日期时间
        QLocale locale(QLocale::English, QLocale::UnitedStates); // 指定英文环境
        QDateTime dateTime = locale.toDateTime(dateTimeString, "ddd, dd MMM yyyy HH:mm:ss 'GMT'");

        if (dateTime.isValid()) {
            qDebug() << "解析到的 UTC 时间：" << dateTime.toString("yyyy-MM-dd HH:mm:ss");
            dateTime.setTimeSpec(Qt::UTC); // 确保时间为 UTC

            // 手动加 8 小时
            QDateTime localTime = dateTime.addSecs(8 * 3600); // 加 8 小时
            return localTime.toString("yyyy-MM-dd HH:mm:ss"); // 返回本地时间
        } else {
            qDebug() << "时间字符串解析失败：" << dateTimeString;
        }
    } else {
        qDebug() << "正则表达式未匹配到时间字符串：" << headerData;
    }

    return QString();
}
QString ESP8266::parseIPDData(const QString &data) {
    // 假设 "+IPD" 后的数据格式为：name=张三&idNumber=123456789&...
    int nameIndex = data.indexOf("name=");
    int idNumberIndex = data.indexOf("idNumber=");

    if (nameIndex != -1 && idNumberIndex != -1) {
        // 提取 name 的值
        int nameEndIndex = data.indexOf("&", nameIndex);
        QString name = data.mid(nameIndex + 5, (nameEndIndex != -1 ? nameEndIndex : data.length()) - nameIndex - 5);

        // 提取 idNumber 的值
        int idNumberEndIndex = data.indexOf("&", idNumberIndex);
        QString idNumber = data.mid(idNumberIndex + 9, (idNumberEndIndex != -1 ? idNumberEndIndex : data.length()) - idNumberIndex - 9);
        qDebug() << "身份证号：" << idNumber;
        // 去掉身份证号末尾多余的字符（如 '0'）
        idNumber = idNumber.trimmed(); // 去掉首尾空格（如果有）
        while (idNumber.endsWith('0') && idNumber.length() > 15) {
            // 如果身份证号末尾多余的字符是 '0'，且长度大于有效身份证号长度，则去掉
            idNumber.chop(1);
        }
        qDebug() << "身份证号：" << idNumber;
        return QString("name=%1&idNumber=%2").arg(name).arg(idNumber);
    }
    return QString();
}
QString ESP8266::parseStationIP(const QString &response) {
    static const QRegularExpression regex(R"(\+CIFSR:STAIP,"([\d\.]+)\")");
    QRegularExpressionMatch match = regex.match(response);
    if (match.hasMatch()) {
        return match.captured(1);
    }
    return QString();
}

void ESP8266::configureAsServer() {
    // 设置为 AP+Station 模式 (模式3)
    sendCommand("AT+CWMODE=3");
    QThread::msleep(1000);

    // 设置热点名称和密码
    // 格式: AT+CWSAP="SSID","PASSWORD",<Channel>,<Encryption>
    // Encryption: 0=Open, 1=WEP, 2=WPA_PSK, 3=WPA2_PSK, 4=WPA_WPA2_PSK
    sendCommand("AT+CWSAP=\"PXY\",\"12345678\",5,3"); // 设置热点名称为 PXY，密码为 12345678，使用 WPA2_PSK 加密
    QThread::msleep(1000);

    // 启用多连接
    sendCommand("AT+CIPMUX=1");
    QThread::msleep(1000);


    // 启动 TCP Server
    sendCommand("AT+CIPSERVER=1,1234"); // 启动 TCP Server，监听端口 1234
    QThread::msleep(1000);

    sendCommand("AT+CIPCLOSE=0"); // 尝试关闭连接 0（UDP 服务）
    QThread::msleep(1000);

    // 启动 UDP 服务，绑定到广播地址
    sendCommand("AT+CIPSTART=0,\"UDP\",\"192.168.4.255\",5678,5678,0"); // 将目标 IP 设置为广播地址 (如 192.168.4.255)
    QThread::msleep(1000);
    qDebug() << "ESP8266 配置完成：AP 模式（热点名称：PXY，密码：12345678）、TCP 服务（端口 1234）、UDP 服务（端口 5678）已启动";
}
void ESP8266::findIP() {
        sendCommand("AT+CIFSR");           // 查询 IP 地址
}
