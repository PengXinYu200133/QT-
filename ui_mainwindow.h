/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget_5;
    QWidget *widget;
    QDateTimeEdit *dateTimeEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *ip_address;
    QWidget *widget_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QPushButton *available_bigroom;
    QWidget *widget_3;
    QPushButton *pushButton_in;
    QPushButton *pushButton_out;
    QPushButton *pushButton_lost;
    QPushButton *pushButton_continue;
    QPushButton *pushButton_7;
    QPushButton *pushButton_continue_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 480);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget_5 = new QWidget(centralwidget);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(0, 0, 801, 481));
        widget = new QWidget(widget_5);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 801, 91));
        widget->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        dateTimeEdit = new QDateTimeEdit(widget);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(600, 10, 194, 41));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(500, 50, 81, 41));
        pushButton->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 20px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(410, 50, 81, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 20px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        ip_address = new QLabel(widget);
        ip_address->setObjectName(QString::fromUtf8("ip_address"));
        ip_address->setGeometry(QRect(10, 10, 231, 21));
        widget_2 = new QWidget(widget_5);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(170, 90, 631, 391));
        widget_2->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 100, 101, 21));
        QFont font;
        font.setPointSize(6);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("border: 0px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 131, 91));
        label_2->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextEditable|Qt::TextEditorInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(210, 100, 91, 21));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("border: 0px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(170, 10, 131, 91));
        label_5 = new QLabel(widget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(370, 100, 101, 21));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("border: 0px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        label_6 = new QLabel(widget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(330, 10, 131, 91));
        label_7 = new QLabel(widget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(530, 100, 91, 21));
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("border: 0px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        label_8 = new QLabel(widget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(490, 10, 131, 91));
        label_9 = new QLabel(widget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(40, 240, 101, 21));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("border: 0px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        label_10 = new QLabel(widget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 150, 131, 91));
        label_11 = new QLabel(widget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(210, 240, 101, 21));
        label_11->setFont(font);
        label_11->setStyleSheet(QString::fromUtf8("border: 0px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        label_12 = new QLabel(widget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(170, 150, 131, 91));
        label_13 = new QLabel(widget_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(360, 240, 81, 21));
        label_13->setFont(font);
        label_13->setStyleSheet(QString::fromUtf8("border: 0px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        label_14 = new QLabel(widget_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(330, 150, 131, 91));
        label_15 = new QLabel(widget_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(520, 240, 101, 21));
        label_15->setFont(font);
        label_15->setStyleSheet(QString::fromUtf8("border: 0px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        label_16 = new QLabel(widget_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(490, 150, 131, 91));
        available_bigroom = new QPushButton(widget_2);
        available_bigroom->setObjectName(QString::fromUtf8("available_bigroom"));
        available_bigroom->setGeometry(QRect(10, 10, 131, 81));
        available_bigroom->setStyleSheet(QString::fromUtf8("border: 0px solid rgba(0, 0, 0, 200); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255,0); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 20px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        widget_3 = new QWidget(widget_5);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(0, 90, 171, 391));
        widget_3->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        pushButton_in = new QPushButton(widget_3);
        pushButton_in->setObjectName(QString::fromUtf8("pushButton_in"));
        pushButton_in->setGeometry(QRect(20, 20, 131, 41));
        pushButton_out = new QPushButton(widget_3);
        pushButton_out->setObjectName(QString::fromUtf8("pushButton_out"));
        pushButton_out->setGeometry(QRect(20, 80, 131, 41));
        pushButton_lost = new QPushButton(widget_3);
        pushButton_lost->setObjectName(QString::fromUtf8("pushButton_lost"));
        pushButton_lost->setGeometry(QRect(20, 140, 131, 41));
        pushButton_continue = new QPushButton(widget_3);
        pushButton_continue->setObjectName(QString::fromUtf8("pushButton_continue"));
        pushButton_continue->setGeometry(QRect(20, 200, 131, 41));
        pushButton_7 = new QPushButton(widget_3);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(20, 320, 131, 41));
        pushButton_continue_2 = new QPushButton(widget_3);
        pushButton_continue_2->setObjectName(QString::fromUtf8("pushButton_continue_2"));
        pushButton_continue_2->setGeometry(QRect(20, 260, 131, 41));
        widget_2->raise();
        widget->raise();
        widget_3->raise();
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "wifi", nullptr));
        ip_address->setText(QCoreApplication::translate("MainWindow", "\347\255\211\345\276\205ip\343\200\202\343\200\202\343\200\202\343\200\202", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\244\247\345\272\212\346\210\277\357\274\232150\345\205\203", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/dcf.jpg\"/></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\347\224\265\345\275\261\346\210\277\357\274\232800\345\205\203</p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/dyf.jpg\"/></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\346\234\272\351\272\273\346\210\277\357\274\232150\345\205\203", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/jmf.jpg\"/></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\346\231\256\351\200\232\345\215\225\351\227\264\357\274\23280\345\205\203", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/pd.jpg\"/></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\346\231\256\351\200\232\345\217\214\344\272\272\351\227\264\357\274\23290\345\205\203", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/ps.jpg\"/></p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\345\217\214\345\272\212\346\210\277\357\274\232100\345\205\203", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/scf.jpg\"/></p></body></html>", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\350\241\214\346\224\277\346\210\277\357\274\232600\345\205\203", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/xzf.jpg\"/></p></body></html>", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "\346\200\273\347\273\237\345\245\227\346\210\277\357\274\2325000\345\205\203", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/zttf.jpg\"/></p></body></html>", nullptr));
        available_bigroom->setText(QString());
        pushButton_in->setText(QCoreApplication::translate("MainWindow", "\345\205\245\344\275\217", nullptr));
        pushButton_out->setText(QCoreApplication::translate("MainWindow", "\351\242\204\347\272\246", nullptr));
        pushButton_lost->setText(QCoreApplication::translate("MainWindow", "\346\214\202\345\244\261", nullptr));
        pushButton_continue->setText(QCoreApplication::translate("MainWindow", "\350\241\245\345\215\241", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\346\210\277\351\227\264", nullptr));
        pushButton_continue_2->setText(QCoreApplication::translate("MainWindow", "\351\200\200\346\210\277", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
