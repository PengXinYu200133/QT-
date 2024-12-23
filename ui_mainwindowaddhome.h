/********************************************************************************
** Form generated from reading UI file 'mainwindowaddhome.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWADDHOME_H
#define UI_MAINWINDOWADDHOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowaddhome
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindowaddhome)
    {
        if (MainWindowaddhome->objectName().isEmpty())
            MainWindowaddhome->setObjectName(QString::fromUtf8("MainWindowaddhome"));
        MainWindowaddhome->resize(513, 307);
        centralwidget = new QWidget(MainWindowaddhome);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 60, 75, 23));
        MainWindowaddhome->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindowaddhome);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindowaddhome->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindowaddhome);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 513, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindowaddhome->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());

        retranslateUi(MainWindowaddhome);

        QMetaObject::connectSlotsByName(MainWindowaddhome);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowaddhome)
    {
        MainWindowaddhome->setWindowTitle(QCoreApplication::translate("MainWindowaddhome", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindowaddhome", "\350\277\224\345\233\236", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindowaddhome", "\350\257\267\350\276\223\345\205\245\346\210\277\345\236\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowaddhome: public Ui_MainWindowaddhome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWADDHOME_H
