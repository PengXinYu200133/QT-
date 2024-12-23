#include "mainwindowaddhome.h"
#include "ui_mainwindowaddhome.h"

MainWindowaddhome::MainWindowaddhome(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowaddhome)
{
    ui->setupUi(this);
}

MainWindowaddhome::~MainWindowaddhome()
{
    delete ui;
}

void MainWindowaddhome::on_pushButton_clicked()
{
    this->close();
}

