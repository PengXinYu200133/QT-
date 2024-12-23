/********************************************************************************
** Form generated from reading UI file 'card_replacement.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARD_REPLACEMENT_H
#define UI_CARD_REPLACEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_card_replacement
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *card_replacement)
    {
        if (card_replacement->objectName().isEmpty())
            card_replacement->setObjectName(QString::fromUtf8("card_replacement"));
        card_replacement->resize(800, 480);
        centralwidget = new QWidget(card_replacement);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 150, 801, 321));
        tableView->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(350, 20, 91, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        font.setPointSize(26);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("border: 0px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(510, 80, 111, 51));
        pushButton->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(660, 80, 111, 51));
        pushButton_2->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        card_replacement->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(card_replacement);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        card_replacement->setStatusBar(statusbar);

        retranslateUi(card_replacement);

        QMetaObject::connectSlotsByName(card_replacement);
    } // setupUi

    void retranslateUi(QMainWindow *card_replacement)
    {
        card_replacement->setWindowTitle(QCoreApplication::translate("card_replacement", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("card_replacement", "\350\241\245\345\215\241", nullptr));
        pushButton->setText(QCoreApplication::translate("card_replacement", "\350\241\245\345\215\241", nullptr));
        pushButton_2->setText(QCoreApplication::translate("card_replacement", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class card_replacement: public Ui_card_replacement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARD_REPLACEMENT_H
