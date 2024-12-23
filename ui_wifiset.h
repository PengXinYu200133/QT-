/********************************************************************************
** Form generated from reading UI file 'wifiset.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIFISET_H
#define UI_WIFISET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_wifiset
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QFrame *frame;
    QLabel *label_4;
    QTextEdit *wifiname;
    QFrame *frame_2;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_5;
    QPushButton *pushButton_9;
    QPushButton *pushButton_8;
    QPushButton *pushButton_0;
    QPushButton *pushButton;
    QPushButton *pushButton_10;
    QLabel *label_7;
    QTextEdit *wifipassword;
    QPushButton *pushButton_35;
    QPushButton *test;
    QPushButton *pushButton_36;
    QPushButton *test_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *wifiset)
    {
        if (wifiset->objectName().isEmpty())
            wifiset->setObjectName(QString::fromUtf8("wifiset"));
        wifiset->resize(800, 600);
        centralwidget = new QWidget(wifiset);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(280, -20, 201, 91));
        QFont font;
        font.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        font.setPointSize(26);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("border: 0px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 800, 480));
        frame->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 60, 121, 61));
        QFont font1;
        font1.setPointSize(16);
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("border: 0px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */"));
        wifiname = new QTextEdit(frame);
        wifiname->setObjectName(QString::fromUtf8("wifiname"));
        wifiname->setGeometry(QRect(130, 70, 271, 51));
        wifiname->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(610, 210, 191, 271));
        frame_2->setMouseTracking(true);
        frame_2->setLayoutDirection(Qt::LeftToRight);
        frame_2->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        pushButton_1 = new QPushButton(frame_2);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(10, 10, 51, 51));
        QFont font2;
        font2.setPointSize(28);
        pushButton_1->setFont(font2);
        pushButton_1->setStyleSheet(QString::fromUtf8(" color: black; /* \350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
""));
        pushButton_1->setFlat(true);
        pushButton_2 = new QPushButton(frame_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 10, 51, 51));
        pushButton_2->setFont(font2);
        pushButton_2->setStyleSheet(QString::fromUtf8(" color: black; /* \350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
""));
        pushButton_2->setFlat(true);
        pushButton_4 = new QPushButton(frame_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 80, 51, 51));
        pushButton_4->setFont(font2);
        pushButton_4->setStyleSheet(QString::fromUtf8(" color: black; /* \350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
""));
        pushButton_4->setFlat(true);
        pushButton_3 = new QPushButton(frame_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(130, 10, 51, 51));
        pushButton_3->setFont(font2);
        pushButton_3->setStyleSheet(QString::fromUtf8(" color: black; /* \350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
""));
        pushButton_3->setFlat(true);
        pushButton_6 = new QPushButton(frame_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(130, 80, 51, 51));
        pushButton_6->setFont(font2);
        pushButton_6->setStyleSheet(QString::fromUtf8(" color: black; /* \350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
""));
        pushButton_6->setFlat(true);
        pushButton_7 = new QPushButton(frame_2);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(10, 150, 51, 51));
        pushButton_7->setFont(font2);
        pushButton_7->setStyleSheet(QString::fromUtf8(" color: black; /* \350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
""));
        pushButton_7->setFlat(true);
        pushButton_5 = new QPushButton(frame_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(70, 80, 51, 51));
        pushButton_5->setFont(font2);
        pushButton_5->setStyleSheet(QString::fromUtf8(" color: black; /* \350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
""));
        pushButton_5->setFlat(true);
        pushButton_9 = new QPushButton(frame_2);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(130, 150, 51, 51));
        pushButton_9->setFont(font2);
        pushButton_9->setStyleSheet(QString::fromUtf8(" color: black; /* \350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
""));
        pushButton_9->setFlat(true);
        pushButton_8 = new QPushButton(frame_2);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(70, 150, 51, 51));
        pushButton_8->setFont(font2);
        pushButton_8->setStyleSheet(QString::fromUtf8(" color: black; /* \350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
""));
        pushButton_8->setFlat(true);
        pushButton_0 = new QPushButton(frame_2);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setGeometry(QRect(10, 210, 51, 51));
        pushButton_0->setFont(font2);
        pushButton_0->setStyleSheet(QString::fromUtf8(" color: black; /* \350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
""));
        pushButton_0->setFlat(true);
        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 210, 51, 51));
        pushButton_10 = new QPushButton(frame_2);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(130, 210, 51, 51));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 140, 121, 61));
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("border: 0px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */"));
        wifipassword = new QTextEdit(frame);
        wifipassword->setObjectName(QString::fromUtf8("wifipassword"));
        wifipassword->setGeometry(QRect(130, 150, 271, 51));
        wifipassword->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        pushButton_35 = new QPushButton(frame);
        pushButton_35->setObjectName(QString::fromUtf8("pushButton_35"));
        pushButton_35->setGeometry(QRect(590, 400, 91, 61));
        test = new QPushButton(frame);
        test->setObjectName(QString::fromUtf8("test"));
        test->setGeometry(QRect(650, 70, 111, 61));
        pushButton_36 = new QPushButton(frame);
        pushButton_36->setObjectName(QString::fromUtf8("pushButton_36"));
        pushButton_36->setGeometry(QRect(690, 400, 91, 61));
        test_2 = new QPushButton(frame);
        test_2->setObjectName(QString::fromUtf8("test_2"));
        test_2->setGeometry(QRect(650, 140, 111, 61));
        pushButton_36->raise();
        pushButton_35->raise();
        label_4->raise();
        wifiname->raise();
        frame_2->raise();
        label_7->raise();
        wifipassword->raise();
        test->raise();
        test_2->raise();
        wifiset->setCentralWidget(centralwidget);
        frame->raise();
        label->raise();
        statusbar = new QStatusBar(wifiset);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        wifiset->setStatusBar(statusbar);

        retranslateUi(wifiset);

        QMetaObject::connectSlotsByName(wifiset);
    } // setupUi

    void retranslateUi(QMainWindow *wifiset)
    {
        wifiset->setWindowTitle(QCoreApplication::translate("wifiset", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("wifiset", "WIFI\350\256\276\347\275\256", nullptr));
        label_4->setText(QCoreApplication::translate("wifiset", "\347\203\255\347\202\271\345\220\215\347\247\260\357\274\232", nullptr));
        pushButton_1->setText(QCoreApplication::translate("wifiset", "1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("wifiset", "2", nullptr));
        pushButton_4->setText(QCoreApplication::translate("wifiset", "4", nullptr));
        pushButton_3->setText(QCoreApplication::translate("wifiset", "3", nullptr));
        pushButton_6->setText(QCoreApplication::translate("wifiset", "6", nullptr));
        pushButton_7->setText(QCoreApplication::translate("wifiset", "7", nullptr));
        pushButton_5->setText(QCoreApplication::translate("wifiset", "5", nullptr));
        pushButton_9->setText(QCoreApplication::translate("wifiset", "9", nullptr));
        pushButton_8->setText(QCoreApplication::translate("wifiset", "8", nullptr));
        pushButton_0->setText(QCoreApplication::translate("wifiset", "0", nullptr));
        pushButton->setText(QCoreApplication::translate("wifiset", "\345\233\236\351\200\200", nullptr));
        pushButton_10->setText(QCoreApplication::translate("wifiset", "\345\256\214\346\210\220", nullptr));
        label_7->setText(QCoreApplication::translate("wifiset", "\347\203\255\347\202\271\345\257\206\347\240\201\357\274\232", nullptr));
        pushButton_35->setText(QCoreApplication::translate("wifiset", "\345\217\226\346\266\210", nullptr));
        test->setText(QCoreApplication::translate("wifiset", "\351\200\232\344\277\241\346\265\213\350\257\225", nullptr));
        pushButton_36->setText(QCoreApplication::translate("wifiset", "\347\241\256\345\256\232", nullptr));
        test_2->setText(QCoreApplication::translate("wifiset", "\346\211\223\345\274\200\351\200\217\344\274\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class wifiset: public Ui_wifiset {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIFISET_H
