#include "dao.h"
#include "mainwindow.h"
#include <QDir>
#include <iostream>
#include <typeinfo>
#include <QDebug>

Dao::Dao()
{
    QString path = "./db";
    //QString path = "/etc/atm/db";
    qDebug() << "apro db " << path;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    db.open();

}
QHash<QString, QString> Dao::singleRow(QString table,QString where)
{

    QHash<QString,QString> tmpHash;

    QSqlQuery query(db);

    if(where.length())
        where = " WHERE "+where;

    query.exec("SELECT * FROM "+table+where);
    QSqlRecord record = query.record();
    int fieldcount = record.count();

    if(fieldcount>0){
        query.next();
        for (int i = 0; i < fieldcount; i++) {

            tmpHash.insert(record.fieldName(i),query.value(i).toString());

        }

    }
    close();
    return tmpHash;

}
QList< QHash<QString, QString> > Dao::listRow(QString table){

    QList< QHash<QString, QString> > list;

    QSqlRecord record = db.record(table);
    int fieldcount = record.count();

    QSqlQuery query(db);
    query.exec("SELECT * FROM "+table);


    while ( query.next() ) {


        QHash<QString,QString> tmpHash;

        for (int i = 0; i < fieldcount; i++) {

            tmpHash.insert(record.fieldName(i),query.value(i).toString());

        }
        list.append(tmpHash);


    }
    close();
    return list;

}
bool Dao::updateRow(QString table,QStringList values,QString where){

    bool ret = false;
    QSqlQuery qry;

    QString sql = "UPDATE "+table+" SET "+values.join(",");

    if(where!=NULL)
        sql += " WHERE "+where;

    qry.prepare(sql);

    if(qry.exec())
        ret = true;

    close();

    return ret;

}
void Dao::close()
{

    QString connection;
    connection = db.connectionName();
    db.close();
    db = QSqlDatabase();
    db.removeDatabase(connection);


}
