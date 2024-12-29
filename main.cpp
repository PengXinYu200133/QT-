#include "loginwindow.h"
#include <QApplication>
#include <QTextCodec>
#include <QFont>
#include <QDebug>
#include <QThread>
#include "esp8266.h"
// 声明全局变量


ESP8266 *globalESP = nullptr;
QThread *globalESPThread = nullptr;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setFont(QFont("Microsoft Yahei", 9));
    a.setOverrideCursor(Qt::BlankCursor);
// 设置中文编码
#if (QT_VERSION <= QT_VERSION_CHECK(5, 0, 0))
    QTextCodec *codec = QTextCodec::codecForName("GBK");
    QTextCodec::setCodecForLocale(codec);
#else
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
#endif
    globalESP = new ESP8266("/dev/ttySAC2", 115200);
    globalESPThread = new QThread();
    globalESP->moveToThread(globalESPThread);
    globalESPThread->start();
    QObject::connect(globalESPThread, &QThread::started, globalESP, &ESP8266::configureAsServer);


    LoginWindow w;
    w.show();
    return a.exec();
    globalESPThread->quit();
    globalESPThread->wait();
    delete globalESPThread;
    delete globalESP;
}

