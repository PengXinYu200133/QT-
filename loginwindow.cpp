#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QGraphicsDropShadowEffect>
#include <QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QFile>
#include <QMainWindow>
#include <QLabel>
#include <QMovie>
#include "mainwindow.h"

bool createRootTable(QSqlDatabase &db);
void sqlite_Init();

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    sqlite_Init();

    QMovie *movie1=new QMovie(":/gif5.gif");
    ui->label_2->setMovie(movie1);
    movie1->start();
}

LoginWindow::~LoginWindow()
{
    delete ui;
}
void sqlite_Init()
{

    QString dbName = "User.db";

    // 检查数据库文件是否存在
    bool dbExists = QFile::exists(dbName);

    // 连接到 SQLite 数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","loginwindowsqlite");
    db.setDatabaseName(dbName);

    if (!db.open()) {
        qDebug() << "Error: Unable to open database" << db.lastError();

    }

    if (!dbExists) {
        qDebug() << "Database does not exist. Creating new database.";
    } else {
        qDebug() << "Database already exists.";
    }

    // 创建 root 表（如果不存在）
    if (!createRootTable(db)) {

    }
    db.close();

}

bool createRootTable(QSqlDatabase &db) {
    QSqlQuery query(db);

    // 检查 root 表是否存在
    QString checkTableExistsQuery =
        "SELECT name FROM sqlite_master WHERE type='table' AND name='root';";

    if (!query.exec(checkTableExistsQuery)) {
        qDebug() << "Error: Unable to execute query" << query.lastError();
        return false;
    }

    // 如果表不存在，则创建它
    if (!query.next()) {
        QString createTableQuery =
            "CREATE TABLE root ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "password TEXT NOT NULL)";

        if (!query.exec(createTableQuery)) {
            qDebug() << "Error: Unable to create root table" << query.lastError();
            return false;
        }

        qDebug() << "Root table created successfully.";

        // 插入初始数据
        QString insertInitialDataQuery = "INSERT INTO root (password) VALUES ('2001')";
        if (!query.exec(insertInitialDataQuery)) {
            qDebug() << "Error: Unable to insert initial data" << query.lastError();
            return false;
        }else{
            qDebug()<<"创建成功初始密码2001"<<query.lastError();
        }

        qDebug() << "Initial data inserted successfully.";
    } else {
        qDebug() << "Root table already exists.";
    }

    return true;
}

void LoginWindow::on_longin_clicked()
{
    QSqlDatabase db = QSqlDatabase::database("loginwindowsqlite");
    QSqlQuery query(db);
    QString password = ui->lineEdit->text();
    QString sql=QString("select * from root where password='%1'")
                      .arg(password);
    qDebug()<<sql;
    if(!query.exec(sql)){
        qDebug() << "lianbusahgn " << query.lastError();
    }
    //创建执行语句对象
    //判断执行结果
    if(!query.next())
    {
        qDebug()<<"Login error";
        QMessageBox::information(this,"登录认证","登录失败,账户或者密码错误");

    }
    else
    {
        db.close();
        QSqlDatabase::removeDatabase("QSQLITE");
        qDebug()<<"清除成功";
        this->close();
        MainWindow *pia = new MainWindow();
        pia->show();

    }
}


void LoginWindow::on_pushButton_1_clicked()
{

    ui->lineEdit->setText(ui->lineEdit->text() + ui->pushButton_1->text());
    qDebug()<<ui->lineEdit->text();

}


void LoginWindow::on_pushButton_2_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + ui->pushButton_2->text());
    qDebug()<<ui->lineEdit->text();
}





void LoginWindow::on_pushButton_3_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + ui->pushButton_3->text());
    qDebug()<<ui->lineEdit->text();
}


void LoginWindow::on_pushButton_4_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + ui->pushButton_4->text());
    qDebug()<<ui->lineEdit->text();
}


void LoginWindow::on_pushButton_5_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + ui->pushButton_5->text());
    qDebug()<<ui->lineEdit->text();
}


void LoginWindow::on_pushButton_6_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + ui->pushButton_6->text());
    qDebug()<<ui->lineEdit->text();
}


void LoginWindow::on_pushButton_7_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + ui->pushButton_7->text());
    qDebug()<<ui->lineEdit->text();
}


void LoginWindow::on_pushButton_8_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + ui->pushButton_8->text());
    qDebug()<<ui->lineEdit->text();
}


void LoginWindow::on_pushButton_9_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + ui->pushButton_9->text());
    qDebug()<<ui->lineEdit->text();
}


void LoginWindow::on_pushButton_0_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + ui->pushButton_0->text());
    qDebug()<<ui->lineEdit->text();
}

