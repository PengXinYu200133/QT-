#ifndef MAINWINDOWADDHOME_H
#define MAINWINDOWADDHOME_H

#include <QMainWindow>

namespace Ui {
class MainWindowaddhome;
}

class MainWindowaddhome : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowaddhome(QWidget *parent = nullptr);
    ~MainWindowaddhome();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindowaddhome *ui;
};

#endif // MAINWINDOWADDHOME_H
