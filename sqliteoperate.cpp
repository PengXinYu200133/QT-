#include "sqliteoperate.h"
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QDebug>
#include <QtSql/QSqlError>
sqliteoperate::sqliteoperate() {}

QSqlDatabase connectToDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("User.db");

    if (!db.open()) {
        qDebug() << "无法打开数据库：" << db.lastError().text();
    }

    return db;
}
