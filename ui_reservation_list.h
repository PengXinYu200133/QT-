/********************************************************************************
** Form generated from reading UI file 'reservation_list.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESERVATION_LIST_H
#define UI_RESERVATION_LIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reservation_list
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QLabel *label;
    QPushButton *pushButton;
    QTextEdit *numberinput;
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
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *new_2;
    QPushButton *pushButton_search;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *reservation_list)
    {
        if (reservation_list->objectName().isEmpty())
            reservation_list->setObjectName(QString::fromUtf8("reservation_list"));
        reservation_list->resize(800, 480);
        centralwidget = new QWidget(reservation_list);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 160, 801, 301));
        tableView->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(330, -10, 511, 91));
        QFont font;
        font.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        font.setPointSize(26);
        label->setFont(font);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(410, 90, 101, 51));
        pushButton->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        numberinput = new QTextEdit(centralwidget);
        numberinput->setObjectName(QString::fromUtf8("numberinput"));
        numberinput->setGeometry(QRect(40, 90, 241, 51));
        numberinput->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
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
        QFont font1;
        font1.setPointSize(28);
        pushButton_1->setFont(font1);
        pushButton_1->setStyleSheet(QString::fromUtf8(" color: black; /* \350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
""));
        pushButton_1->setFlat(true);
        pushButton_2 = new QPushButton(frame_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 10, 51, 51));
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QString::fromUtf8(" color: black; /* \350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
""));
        pushButton_2->setFlat(true);
        pushButton_4 = new QPushButton(frame_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 80, 51, 51));
        pushButton_4->setFont(font1);
        pushButton_4->setStyleSheet(QString::fromUtf8(" color: black; /* \350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
""));
        pushButton_4->setFlat(true);
        pushButton_3 = new QPushButton(frame_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(130, 10, 51, 51));
        pushButton_3->setFont(font1);
        pushButton_3->setStyleSheet(QString::fromUtf8(" color: black; /* \350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
""));
        pushButton_3->setFlat(true);
        pushButton_6 = new QPushButton(frame_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(130, 80, 51, 51));
        pushButton_6->setFont(font1);
        pushButton_6->setStyleSheet(QString::fromUtf8(" color: black; /* \350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
""));
        pushButton_6->setFlat(true);
        pushButton_7 = new QPushButton(frame_2);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(10, 150, 51, 51));
        pushButton_7->setFont(font1);
        pushButton_7->setStyleSheet(QString::fromUtf8(" color: black; /* \350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
""));
        pushButton_7->setFlat(true);
        pushButton_5 = new QPushButton(frame_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(70, 80, 51, 51));
        pushButton_5->setFont(font1);
        pushButton_5->setStyleSheet(QString::fromUtf8(" color: black; /* \350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
""));
        pushButton_5->setFlat(true);
        pushButton_9 = new QPushButton(frame_2);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(130, 150, 51, 51));
        pushButton_9->setFont(font1);
        pushButton_9->setStyleSheet(QString::fromUtf8(" color: black; /* \350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
""));
        pushButton_9->setFlat(true);
        pushButton_8 = new QPushButton(frame_2);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(70, 150, 51, 51));
        pushButton_8->setFont(font1);
        pushButton_8->setStyleSheet(QString::fromUtf8(" color: black; /* \350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
""));
        pushButton_8->setFlat(true);
        pushButton_0 = new QPushButton(frame_2);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setGeometry(QRect(10, 210, 51, 51));
        pushButton_0->setFont(font1);
        pushButton_0->setStyleSheet(QString::fromUtf8(" color: black; /* \350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
""));
        pushButton_0->setFlat(true);
        pushButton_10 = new QPushButton(frame_2);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(70, 210, 51, 51));
        pushButton_11 = new QPushButton(frame_2);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(130, 210, 51, 51));
        pushButton_12 = new QPushButton(centralwidget);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setGeometry(QRect(660, 90, 101, 51));
        pushButton_12->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        new_2 = new QPushButton(centralwidget);
        new_2->setObjectName(QString::fromUtf8("new_2"));
        new_2->setGeometry(QRect(530, 90, 101, 51));
        new_2->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        pushButton_search = new QPushButton(centralwidget);
        pushButton_search->setObjectName(QString::fromUtf8("pushButton_search"));
        pushButton_search->setGeometry(QRect(300, 90, 91, 51));
        pushButton_search->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        reservation_list->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(reservation_list);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        reservation_list->setStatusBar(statusbar);

        retranslateUi(reservation_list);

        QMetaObject::connectSlotsByName(reservation_list);
    } // setupUi

    void retranslateUi(QMainWindow *reservation_list)
    {
        reservation_list->setWindowTitle(QCoreApplication::translate("reservation_list", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("reservation_list", "\351\242\204\347\272\246\350\241\250", nullptr));
        pushButton->setText(QCoreApplication::translate("reservation_list", "\345\205\245\344\275\217", nullptr));
        pushButton_1->setText(QCoreApplication::translate("reservation_list", "1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("reservation_list", "2", nullptr));
        pushButton_4->setText(QCoreApplication::translate("reservation_list", "4", nullptr));
        pushButton_3->setText(QCoreApplication::translate("reservation_list", "3", nullptr));
        pushButton_6->setText(QCoreApplication::translate("reservation_list", "6", nullptr));
        pushButton_7->setText(QCoreApplication::translate("reservation_list", "7", nullptr));
        pushButton_5->setText(QCoreApplication::translate("reservation_list", "5", nullptr));
        pushButton_9->setText(QCoreApplication::translate("reservation_list", "9", nullptr));
        pushButton_8->setText(QCoreApplication::translate("reservation_list", "8", nullptr));
        pushButton_0->setText(QCoreApplication::translate("reservation_list", "0", nullptr));
        pushButton_10->setText(QCoreApplication::translate("reservation_list", "\345\233\236\351\200\200", nullptr));
        pushButton_11->setText(QCoreApplication::translate("reservation_list", "\345\256\214\346\210\220", nullptr));
        pushButton_12->setText(QCoreApplication::translate("reservation_list", "\350\277\224\345\233\236", nullptr));
        new_2->setText(QCoreApplication::translate("reservation_list", "\346\226\260\345\242\236\351\242\204\347\272\246", nullptr));
        pushButton_search->setText(QCoreApplication::translate("reservation_list", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reservation_list: public Ui_reservation_list {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESERVATION_LIST_H
