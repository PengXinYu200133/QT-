/********************************************************************************
** Form generated from reading UI file 'newroom.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWROOM_H
#define UI_NEWROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newroom
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QFrame *frame;
    QPushButton *pushButton_on;
    QPushButton *pushButton_back;
    QComboBox *comboBox_2;
    QTextEdit *roomid;
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
    QLabel *label_4;
    QLabel *label_5;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *newroom)
    {
        if (newroom->objectName().isEmpty())
            newroom->setObjectName(QString::fromUtf8("newroom"));
        newroom->resize(816, 491);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(50);
        sizePolicy.setVerticalStretch(50);
        sizePolicy.setHeightForWidth(newroom->sizePolicy().hasHeightForWidth());
        newroom->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(newroom);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(320, -10, 301, 91));
        QFont font;
        font.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        font.setPointSize(26);
        label->setFont(font);
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 800, 460));
        frame->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_on = new QPushButton(frame);
        pushButton_on->setObjectName(QString::fromUtf8("pushButton_on"));
        pushButton_on->setGeometry(QRect(350, 340, 131, 61));
        pushButton_on->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */\n"
""));
        pushButton_back = new QPushButton(frame);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        pushButton_back->setGeometry(QRect(190, 340, 131, 61));
        comboBox_2 = new QComboBox(frame);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(180, 200, 301, 51));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox_2->sizePolicy().hasHeightForWidth());
        comboBox_2->setSizePolicy(sizePolicy1);
        comboBox_2->setMinimumSize(QSize(0, 50));
        comboBox_2->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        comboBox_2->setEditable(true);
        roomid = new QTextEdit(frame);
        roomid->setObjectName(QString::fromUtf8("roomid"));
        roomid->setGeometry(QRect(180, 100, 301, 51));
        roomid->setSizeIncrement(QSize(0, 0));
        roomid->setStyleSheet(QString::fromUtf8("\n"
"border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */\n"
""));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(570, 150, 191, 271));
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
        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 210, 51, 51));
        pushButton_10 = new QPushButton(frame_2);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(130, 210, 51, 51));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 90, 101, 61));
        QFont font2;
        font2.setPointSize(16);
        label_4->setFont(font2);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 190, 101, 61));
        label_5->setFont(font2);
        newroom->setCentralWidget(centralwidget);
        frame->raise();
        label->raise();
        label_4->raise();
        label_5->raise();
        statusbar = new QStatusBar(newroom);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        newroom->setStatusBar(statusbar);

        retranslateUi(newroom);

        QMetaObject::connectSlotsByName(newroom);
    } // setupUi

    void retranslateUi(QMainWindow *newroom)
    {
        newroom->setWindowTitle(QCoreApplication::translate("newroom", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("newroom", "\346\226\260\345\273\272\346\210\277\351\227\264", nullptr));
        pushButton_on->setText(QCoreApplication::translate("newroom", "\344\277\235\345\255\230\346\210\277\351\227\264", nullptr));
        pushButton_back->setText(QCoreApplication::translate("newroom", "\350\277\224\345\233\236", nullptr));
        pushButton_1->setText(QCoreApplication::translate("newroom", "1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("newroom", "2", nullptr));
        pushButton_4->setText(QCoreApplication::translate("newroom", "4", nullptr));
        pushButton_3->setText(QCoreApplication::translate("newroom", "3", nullptr));
        pushButton_6->setText(QCoreApplication::translate("newroom", "6", nullptr));
        pushButton_7->setText(QCoreApplication::translate("newroom", "7", nullptr));
        pushButton_5->setText(QCoreApplication::translate("newroom", "5", nullptr));
        pushButton_9->setText(QCoreApplication::translate("newroom", "9", nullptr));
        pushButton_8->setText(QCoreApplication::translate("newroom", "8", nullptr));
        pushButton_0->setText(QCoreApplication::translate("newroom", "0", nullptr));
        pushButton->setText(QCoreApplication::translate("newroom", "\345\233\236\351\200\200", nullptr));
        pushButton_10->setText(QCoreApplication::translate("newroom", "\345\256\214\346\210\220", nullptr));
        label_4->setText(QCoreApplication::translate("newroom", "\346\210\277\345\217\267\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("newroom", "\346\210\277\345\236\213\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newroom: public Ui_newroom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWROOM_H
