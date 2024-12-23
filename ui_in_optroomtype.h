/********************************************************************************
** Form generated from reading UI file 'in_optroomtype.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IN_OPTROOMTYPE_H
#define UI_IN_OPTROOMTYPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_in_optroomtype
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTableView *tableView;
    QFrame *frame;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *in_optroomtype)
    {
        if (in_optroomtype->objectName().isEmpty())
            in_optroomtype->setObjectName(QString::fromUtf8("in_optroomtype"));
        in_optroomtype->resize(800, 480);
        centralwidget = new QWidget(in_optroomtype);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(300, 10, 211, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(26);
        label->setFont(font);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(540, 410, 141, 41));
        pushButton->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 410, 141, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(75, 61, 651, 331));
        tableView->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
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
        in_optroomtype->setCentralWidget(centralwidget);
        frame->raise();
        label->raise();
        pushButton->raise();
        pushButton_2->raise();
        tableView->raise();
        statusbar = new QStatusBar(in_optroomtype);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        in_optroomtype->setStatusBar(statusbar);

        retranslateUi(in_optroomtype);

        QMetaObject::connectSlotsByName(in_optroomtype);
    } // setupUi

    void retranslateUi(QMainWindow *in_optroomtype)
    {
        in_optroomtype->setWindowTitle(QCoreApplication::translate("in_optroomtype", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("in_optroomtype", "\346\210\277\351\227\264\351\200\211\346\213\251", nullptr));
        pushButton->setText(QCoreApplication::translate("in_optroomtype", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("in_optroomtype", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class in_optroomtype: public Ui_in_optroomtype {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IN_OPTROOMTYPE_H
