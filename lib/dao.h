#ifndef DAO_H
#define DAO_H

#include <QtSql>
#include <QTableView>
#include <QVariant>


class Dao
{
public:
    Dao();
    QHash<QString, QString> singleRow(QString table,QString where);
    bool insertRow();
    bool updateRow(QString table,QStringList values,QString where);
    bool deleteRow(QString table,QString where);
    QList< QHash<QString, QString> > listRow(QString table);

private:
    QSqlDatabase db;
    void close();
};

#endif // DAO_H
