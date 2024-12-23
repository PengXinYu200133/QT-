/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QFrame *frame;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_5;
    QPushButton *pushButton_9;
    QPushButton *pushButton_8;
    QPushButton *longin;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QPushButton *pushButton_0;
    QLabel *label_2;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(800, 480);
        LoginWindow->setMaximumSize(QSize(800, 600));
        QFont font;
        font.setPointSize(28);
        LoginWindow->setFont(font);
        LoginWindow->setIconSize(QSize(30, 30));
        LoginWindow->setAnimated(true);
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMaximumSize(QSize(1024, 600));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(-1, 0, 801, 600));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(140, 40, 521, 431));
        frame->setMouseTracking(true);
        frame->setLayoutDirection(Qt::LeftToRight);
        frame->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_1 = new QPushButton(frame);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(90, 100, 71, 61));
        pushButton_1->setFont(font);
        pushButton_1->setStyleSheet(QString::fromUtf8(" color: black; /* \350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
""));
        pushButton_1->setFlat(true);
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 100, 71, 61));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8(" color: black; /* \350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
""));
        pushButton_2->setFlat(true);
        pushButton_4 = new QPushButton(frame);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(90, 190, 71, 61));
        pushButton_4->setFont(font);
        pushButton_4->setStyleSheet(QString::fromUtf8(" color: black; /* \350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
""));
        pushButton_4->setFlat(true);
        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(290, 100, 71, 61));
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QString::fromUtf8(" color: black; /* \350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
""));
        pushButton_3->setFlat(true);
        pushButton_6 = new QPushButton(frame);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(290, 190, 71, 61));
        pushButton_6->setFont(font);
        pushButton_6->setStyleSheet(QString::fromUtf8(" color: black; /* \350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
""));
        pushButton_6->setFlat(true);
        pushButton_7 = new QPushButton(frame);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(90, 270, 71, 61));
        pushButton_7->setFont(font);
        pushButton_7->setStyleSheet(QString::fromUtf8(" color: black; /* \350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
""));
        pushButton_7->setFlat(true);
        pushButton_5 = new QPushButton(frame);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(190, 190, 71, 61));
        pushButton_5->setFont(font);
        pushButton_5->setStyleSheet(QString::fromUtf8(" color: black; /* \350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
""));
        pushButton_5->setFlat(true);
        pushButton_9 = new QPushButton(frame);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(290, 270, 71, 61));
        pushButton_9->setFont(font);
        pushButton_9->setStyleSheet(QString::fromUtf8(" color: black; /* \350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
""));
        pushButton_9->setFlat(true);
        pushButton_8 = new QPushButton(frame);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(190, 270, 71, 61));
        pushButton_8->setFont(font);
        pushButton_8->setStyleSheet(QString::fromUtf8(" color: black; /* \350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
""));
        pushButton_8->setFlat(true);
        longin = new QPushButton(frame);
        longin->setObjectName(QString::fromUtf8("longin"));
        longin->setGeometry(QRect(190, 350, 171, 61));
        longin->setFont(font);
        longin->setStyleSheet(QString::fromUtf8(" color: black; /* \350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
""));
        longin->setFlat(true);
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(90, 20, 271, 51));
        QFont font1;
        font1.setKerning(true);
        lineEdit->setFont(font1);
        lineEdit->setContextMenuPolicy(Qt::NoContextMenu);
        lineEdit->setFrame(true);
        lineEdit->setEchoMode(QLineEdit::Password);
        lineEdit->setDragEnabled(false);
        lineEdit->setClearButtonEnabled(true);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 20, 81, 41));
        QFont font2;
        font2.setPointSize(20);
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8(" color: black;  /* \350\256\276\347\275\256\346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"    background-color: transparent;  /* \350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"border: 0px solid gray;  /* \350\256\276\347\275\256\350\276\271\346\241\206 */\n"
"\n"
"\n"
"\n"
""));
        pushButton_0 = new QPushButton(frame);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setGeometry(QRect(90, 350, 71, 61));
        pushButton_0->setFont(font);
        pushButton_0->setStyleSheet(QString::fromUtf8(" color: black; /* \350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
""));
        pushButton_0->setFlat(true);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(390, 20, 101, 171));
        label_2->setStyleSheet(QString::fromUtf8("border: 0px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 0); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 20px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        LoginWindow->setCentralWidget(centralwidget);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "<html><head/><body><p><img src=\":/gif1.gif\"/></p></body></html>", nullptr));
        pushButton_1->setText(QCoreApplication::translate("LoginWindow", "1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("LoginWindow", "2", nullptr));
        pushButton_4->setText(QCoreApplication::translate("LoginWindow", "4", nullptr));
        pushButton_3->setText(QCoreApplication::translate("LoginWindow", "3", nullptr));
        pushButton_6->setText(QCoreApplication::translate("LoginWindow", "6", nullptr));
        pushButton_7->setText(QCoreApplication::translate("LoginWindow", "7", nullptr));
        pushButton_5->setText(QCoreApplication::translate("LoginWindow", "5", nullptr));
        pushButton_9->setText(QCoreApplication::translate("LoginWindow", "9", nullptr));
        pushButton_8->setText(QCoreApplication::translate("LoginWindow", "8", nullptr));
        longin->setText(QCoreApplication::translate("LoginWindow", "\347\231\273\345\275\225", nullptr));
        lineEdit->setText(QString());
        label_3->setText(QCoreApplication::translate("LoginWindow", "\345\257\206\347\240\201", nullptr));
        pushButton_0->setText(QCoreApplication::translate("LoginWindow", "0", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindow", "<html><head/><body><p><img src=\":/gif5.gif\"/></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
