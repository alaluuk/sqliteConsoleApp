#include "person.h"

#include <QCoreApplication>

Person::Person() {

}

string Person::getData() {
        db = QSqlDatabase::addDatabase("QSQLITE");
        QString myFolder = "C:/codes/qt_projects/sqliteConsoleApp";
        db.setDatabaseName(myFolder + "/database/mydb.db");
        db.open();
    if (!db.open()) {
        qDebug() << "ERROR :" + db.lastError().text();
        return "No connection";
    } else {
        qDebug() << "Connection Open";
        QString row;
        QSqlQuery query;
        query.exec("SELECT * FROM person");

        while (query.next()) {
            row += query.value(0).toString() + " : " + query.value(1).toString() +
                   " : " + query.value(2).toString() + "\n";
        }
        db.close();
        return row.toStdString();
    }
}
string Person::getSelected(int id) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString myFolder = "C:/codes/qt_projects/sqliteConsoleApp";
    db.setDatabaseName(myFolder + "/database/mydb.db");
    db.open();
    if (!db.open()) {
        qDebug() << "ERROR :" + db.lastError().text();
        return "No connection";
    } else {
        QString row;
        QSqlQuery query;
        query.prepare("SELECT * FROM person WHERE id=:id");
        query.bindValue(":id", id);
        query.exec();

        query.next();
        row = query.value(0).toString() + " : " + query.value(1).toString() +
              " : " + query.value(2).toString() + "\n";
        query.finish();
        query.clear();
        db.close();
        return row.toStdString();
    }
}

string Person::addTodatabase(int id, QString fn, QString ln) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString myFolder = "C:/codes/qt_projects/sqliteConsoleApp";
    db.setDatabaseName(myFolder + "/database/mydb.db");
    db.open();
    if (!db.open()) {
        qDebug() << "ERROR :" + db.lastError().text();
        return "No connection";
    } else {
        qDebug() << "Connection Open";
        QString row;
        QSqlQuery query;
        query.prepare("INSERT INTO person(id,firstname,lastname) VALUES(:id, :fn, :ln)");
        query.bindValue(":id",id);
        query.bindValue(":fn",fn);
        query.bindValue(":ln",ln);
        //qDebug()<<query.exec();
        bool res=query.exec();
        qDebug()<<res;
        if(res){
            return "data added";
        }
        else{
            return "something went wrong";
        }
        db.close();
    }
}
string Person::updateSelected(int id, QString fn, QString ln)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString myFolder = "C:/codes/qt_projects/sqliteConsoleApp";
    db.setDatabaseName(myFolder + "/database/mydb.db");
    db.open();
    if (!db.open()) {
        qDebug() << "ERROR :" + db.lastError().text();
        return "No connection";
    } else {
        qDebug() << "Connection Open";
        QSqlQuery query;
        query.prepare("UPDATE person SET firstname =:fn, lastname =:ln WHERE id =:id");
        query.bindValue(":id",id);
        query.bindValue(":fn",fn);
        query.bindValue(":ln",ln);
        //qDebug()<<query.exec();
        bool res=query.exec();
        qDebug()<<res;
        if(res){
            return "data updated";
        }
        else{
            return "something went wrong";
        }
        db.close();
    }
}
string Person::delFromDatabase(int id) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString myFolder = "C:/codes/qt_projects/sqliteConsoleApp";
    db.setDatabaseName(myFolder + "/database/mydb.db");
    db.open();
    if (!db.open()) {
        qDebug() << "ERROR :" + db.lastError().text();
        return "No connection";
    } else {
        qDebug() << "Connection Open";
        QString row;
        QSqlQuery query;
        query.prepare("DELETE FROM person WHERE id=:id");
        query.bindValue(":id", id);
        //qDebug()<<query.exec();
        bool res=query.exec();
        if(res){
            return "data removed";
        }
        else{
            return "something went wrong";
        }
        db.close();

    }
}



