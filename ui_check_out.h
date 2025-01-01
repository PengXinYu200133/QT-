/********************************************************************************
** Form generated from reading UI file 'check_out.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECK_OUT_H
#define UI_CHECK_OUT_H

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

class Ui_check_out
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QTextEdit *roomid;
    QTextEdit *name;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QTextEdit *out_time;
    QTextEdit *in_time;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QFrame *frame;
    QLabel *daysStayed;
    QLabel *roomtype;
    QLabel *totalPrice;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *check_out)
    {
        if (check_out->objectName().isEmpty())
            check_out->setObjectName(QString::fromUtf8("check_out"));
        check_out->resize(800, 480);
        centralwidget = new QWidget(check_out);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(330, 10, 301, 91));
        QFont font;
        font.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        font.setPointSize(26);
        label->setFont(font);
        roomid = new QTextEdit(centralwidget);
        roomid->setObjectName(QString::fromUtf8("roomid"));
        roomid->setGeometry(QRect(240, 180, 251, 71));
        roomid->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        name = new QTextEdit(centralwidget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(240, 100, 251, 71));
        name->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 100, 101, 61));
        QFont font1;
        font1.setPointSize(16);
        label_2->setFont(font1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 180, 101, 61));
        label_3->setFont(font1);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 260, 111, 61));
        label_4->setFont(font1);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 340, 101, 61));
        label_5->setFont(font1);
        out_time = new QTextEdit(centralwidget);
        out_time->setObjectName(QString::fromUtf8("out_time"));
        out_time->setGeometry(QRect(240, 340, 251, 71));
        out_time->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        in_time = new QTextEdit(centralwidget);
        in_time->setObjectName(QString::fromUtf8("in_time"));
        in_time->setGeometry(QRect(240, 260, 251, 71));
        in_time->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(520, 340, 111, 71));
        pushButton->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(670, 340, 111, 71));
        pushButton_2->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 801, 481));
        frame->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        daysStayed = new QLabel(frame);
        daysStayed->setObjectName(QString::fromUtf8("daysStayed"));
        daysStayed->setGeometry(QRect(630, 20, 171, 41));
        roomtype = new QLabel(frame);
        roomtype->setObjectName(QString::fromUtf8("roomtype"));
        roomtype->setGeometry(QRect(630, 70, 171, 41));
        totalPrice = new QLabel(frame);
        totalPrice->setObjectName(QString::fromUtf8("totalPrice"));
        totalPrice->setGeometry(QRect(630, 130, 171, 41));
        check_out->setCentralWidget(centralwidget);
        frame->raise();
        label->raise();
        roomid->raise();
        name->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        out_time->raise();
        in_time->raise();
        pushButton->raise();
        pushButton_2->raise();
        statusbar = new QStatusBar(check_out);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        check_out->setStatusBar(statusbar);

        retranslateUi(check_out);

        QMetaObject::connectSlotsByName(check_out);
    } // setupUi

    void retranslateUi(QMainWindow *check_out)
    {
        check_out->setWindowTitle(QCoreApplication::translate("check_out", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("check_out", "\351\200\200\346\210\277", nullptr));
        label_2->setText(QCoreApplication::translate("check_out", "<html><head/><body><p><span style=\" font-size:12pt;\">\345\247\223 \345\220\215\357\274\232</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("check_out", "<html><head/><body><p><span style=\" font-size:12pt;\">\346\210\277  \351\227\264  \345\217\267\357\274\232</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("check_out", "<html><head/><body><p><span style=\" font-size:12pt;\">\345\205\245\344\275\217\346\227\266\351\227\264\357\274\232</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("check_out", "<html><head/><body><p><span style=\" font-size:12pt;\">\351\200\200\346\210\277\346\227\266\351\227\264\357\274\232</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("check_out", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("check_out", "\345\217\226\346\266\210", nullptr));
        daysStayed->setText(QString());
        roomtype->setText(QString());
        totalPrice->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class check_out: public Ui_check_out {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECK_OUT_H
