#include "dao.h"
#include <QDir>
#include <iostream>
#include <typeinfo>
#include <QDebug>

Dao::Dao()
{
    QString path = QDir::currentPath()+"/db";
    qDebug() << "apro db " << path;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    db.open();

}
BeanDaoGen *Dao::singleRow(QString table)
{

    QSqlQuery query(db);
    query.exec("SELECT * FROM "+table);
    QSqlRecord record = query.record();
    BeanTram *bt = NULL;
    int cnt = record.count();
    if(cnt>0){
        query.next();
        bt = new BeanTram();
        bt->numeroTram = query.value(0).toString();
        //std::cout << typeid(bt->numeroTram).name() << "\n";
        //cout << "my function name is: " << bt->numeroTram. << "\n";
        //typeof(bt)->;


    }
    close();
    return bt;

}
void Dao::close()
{

    db.close();

}
