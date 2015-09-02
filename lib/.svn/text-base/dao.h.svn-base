#ifndef DAO_H
#define DAO_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QVariant>


#include "bean/beandaogen.h"
#include "bean/beantram.h"

class Dao
{
public:
    Dao();
    QList<BeanDaoGen> listRow();
    BeanDaoGen *singleRow(QString table);
    bool insertRow();
    bool updateRow();
    bool deleteRow();

private:
    QSqlDatabase db;
    void close();
};

#endif // DAO_H
