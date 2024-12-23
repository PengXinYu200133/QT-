/********************************************************************************
** Form generated from reading UI file 'available_room_list.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AVAILABLE_ROOM_LIST_H
#define UI_AVAILABLE_ROOM_LIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_available_room_list
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QComboBox *roomtybe;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *available_room_list)
    {
        if (available_room_list->objectName().isEmpty())
            available_room_list->setObjectName(QString::fromUtf8("available_room_list"));
        available_room_list->resize(800, 482);
        centralwidget = new QWidget(available_room_list);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 149, 800, 311));
        tableView->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        roomtybe = new QComboBox(centralwidget);
        roomtybe->setObjectName(QString::fromUtf8("roomtybe"));
        roomtybe->setGeometry(QRect(10, 90, 271, 50));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(roomtybe->sizePolicy().hasHeightForWidth());
        roomtybe->setSizePolicy(sizePolicy);
        roomtybe->setMinimumSize(QSize(0, 50));
        roomtybe->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        roomtybe->setEditable(true);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(310, 90, 101, 51));
        pushButton->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, -20, 511, 91));
        QFont font;
        font.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        font.setPointSize(26);
        label->setFont(font);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(430, 90, 101, 51));
        pushButton_2->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(560, 90, 101, 51));
        pushButton_4->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(0, 0, 0, 150); /* \351\273\221\350\211\262\350\276\271\346\241\206\357\274\214150\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 200); /* \347\231\275\350\211\262\350\203\214\346\231\257\357\274\214200\344\270\272\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */"));
        available_room_list->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(available_room_list);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        available_room_list->setStatusBar(statusbar);

        retranslateUi(available_room_list);

        QMetaObject::connectSlotsByName(available_room_list);
    } // setupUi

    void retranslateUi(QMainWindow *available_room_list)
    {
        available_room_list->setWindowTitle(QCoreApplication::translate("available_room_list", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("available_room_list", "\345\205\245\344\275\217", nullptr));
        label->setText(QCoreApplication::translate("available_room_list", "\346\237\245\350\257\242\345\233\272\345\256\232\347\261\273\345\236\213\347\232\204\345\217\257\347\224\250\346\210\277\351\227\264", nullptr));
        pushButton_2->setText(QCoreApplication::translate("available_room_list", "\351\242\204\347\272\246", nullptr));
        pushButton_4->setText(QCoreApplication::translate("available_room_list", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class available_room_list: public Ui_available_room_list {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AVAILABLE_ROOM_LIST_H
