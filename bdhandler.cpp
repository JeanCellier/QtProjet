#include "bdhandler.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QFile>

Bdhandler::Bdhandler(){}

QSqlQuery Bdhandler::openBD()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    if(db.isValid())
    {
        db.setHostName("localhost");
        db.setUserName("root");
        db.setPassword("password");
        db.setDatabaseName("base_tmp.sqli");
        db.open();
        QSqlQuery q(db);
        return q;
    }
}

void Bdhandler::closeBD()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    if(db.isValid())
    {
        db.setHostName("localhost");
        db.setUserName("root");
        db.setPassword("password");
        db.setDatabaseName("base_tmp.sqli");
        db.close();
        db.removeDatabase("QSQLITE");
    }
}



