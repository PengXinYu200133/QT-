/********************************************************************************
** Form generated from reading UI file 'quick_reservation.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUICK_RESERVATION_H
#define UI_QUICK_RESERVATION_H

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

class Ui_quick_reservation
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QPushButton *back;
    QPushButton *queding;
    QLabel *label_5;
    QTextEdit *phonenumber;
    QLabel *label;
    QLabel *label_6;
    QTextEdit *intime;
    QLabel *label_2;
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
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *quick_reservation)
    {
        if (quick_reservation->objectName().isEmpty())
            quick_reservation->setObjectName(QString::fromUtf8("quick_reservation"));
        quick_reservation->resize(800, 480);
        centralwidget = new QWidget(quick_reservation);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 800, 480));
        frame->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        back = new QPushButton(frame);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(210, 340, 91, 51));
        queding = new QPushButton(frame);
        queding->setObjectName(QString::fromUtf8("queding"));
        queding->setGeometry(QRect(360, 340, 91, 51));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 140, 161, 61));
        QFont font;
        font.setPointSize(16);
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("border: 0px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        phonenumber = new QTextEdit(frame);
        phonenumber->setObjectName(QString::fromUtf8("phonenumber"));
        phonenumber->setGeometry(QRect(200, 140, 251, 51));
        phonenumber->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 10, 301, 91));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        font1.setPointSize(26);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("border: 0px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 210, 161, 61));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("border: 0px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */"));
        intime = new QTextEdit(frame);
        intime->setObjectName(QString::fromUtf8("intime"));
        intime->setGeometry(QRect(200, 220, 251, 51));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(580, 10, 191, 161));
        label_2->setWordWrap(true);
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(580, 170, 191, 271));
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
        pushButton_11 = new QPushButton(frame_2);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(70, 210, 51, 51));
        pushButton_12 = new QPushButton(frame_2);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setGeometry(QRect(130, 210, 51, 51));
        quick_reservation->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(quick_reservation);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        quick_reservation->setStatusBar(statusbar);

        retranslateUi(quick_reservation);

        QMetaObject::connectSlotsByName(quick_reservation);
    } // setupUi

    void retranslateUi(QMainWindow *quick_reservation)
    {
        quick_reservation->setWindowTitle(QCoreApplication::translate("quick_reservation", "MainWindow", nullptr));
        back->setText(QCoreApplication::translate("quick_reservation", "\350\277\224\345\233\236", nullptr));
        queding->setText(QCoreApplication::translate("quick_reservation", "\347\241\256\345\256\232", nullptr));
        label_5->setText(QCoreApplication::translate("quick_reservation", "\346\211\213\346\234\272\345\217\267\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("quick_reservation", "\345\277\253\346\215\267\351\242\204\347\272\246", nullptr));
        label_6->setText(QCoreApplication::translate("quick_reservation", "\345\205\245\344\275\217\346\227\266\351\227\264\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("quick_reservation", "\346\217\220\347\244\272\357\274\232\345\205\245\344\275\217\346\227\266\351\227\264\346\240\274\345\274\21700000000\344\270\200\344\272\214\344\275\215\350\241\250\347\244\272\346\234\210\344\273\275\357\274\214\344\270\211\345\233\233\344\275\215\350\241\250\347\244\272\346\227\245\346\234\237\357\274\214\344\272\224\345\205\255\344\275\215\350\241\250\347\244\272\346\227\266\357\274\214\344\270\203\345\205\253\344\275\215\350\241\250\347\244\272\345\210\206", nullptr));
        pushButton_1->setText(QCoreApplication::translate("quick_reservation", "1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("quick_reservation", "2", nullptr));
        pushButton_4->setText(QCoreApplication::translate("quick_reservation", "4", nullptr));
        pushButton_3->setText(QCoreApplication::translate("quick_reservation", "3", nullptr));
        pushButton_6->setText(QCoreApplication::translate("quick_reservation", "6", nullptr));
        pushButton_7->setText(QCoreApplication::translate("quick_reservation", "7", nullptr));
        pushButton_5->setText(QCoreApplication::translate("quick_reservation", "5", nullptr));
        pushButton_9->setText(QCoreApplication::translate("quick_reservation", "9", nullptr));
        pushButton_8->setText(QCoreApplication::translate("quick_reservation", "8", nullptr));
        pushButton_0->setText(QCoreApplication::translate("quick_reservation", "0", nullptr));
        pushButton_11->setText(QCoreApplication::translate("quick_reservation", "\345\233\236\351\200\200", nullptr));
        pushButton_12->setText(QCoreApplication::translate("quick_reservation", "\345\256\214\346\210\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class quick_reservation: public Ui_quick_reservation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUICK_RESERVATION_H