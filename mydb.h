#ifndef MYDB_H
#define MYDB_H
#include <QDebug>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include <QDebug>
#include <QSqlError>
#include <QSqlQueryModel>


class MyDB
{
private:
    MyDB();
    static MyDB *instance;
    void init();
    QSqlDatabase db;
public:
    static MyDB* getInstance();
    static void ResetInstance();
    static void Write(QSqlQuery &query);
    static void Read(QSqlQuery &query);
    QSqlDatabase getDBInstance();
    ~MyDB();
};
#endif // MYDB_H
