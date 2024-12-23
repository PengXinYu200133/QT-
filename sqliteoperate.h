#ifndef SQLITEOPERATE_H
#define SQLITEOPERATE_H
#include <QSqlDatabase>
#include <QMainWindow>
namespace Ui {
class sqliteoperate;
}

class sqliteoperate: public QMainWindow
{
public:
    sqliteoperate();
    QSqlDatabase connectToDatabase();

private:
    Ui::sqliteoperate *ui;
};

#endif // SQLITEOPERATE_H
