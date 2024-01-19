#include "person.h"

#include <QCoreApplication>

Person::Person() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString myFolder = "C:/codes/qt_projects/sqliteConsoleApp";
    db.setDatabaseName(myFolder + "/database/mydb.db");
}

string Person::getData() {
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
string Person::getSelected(QString id) {
    db.open();
    if (!db.open()) {
        qDebug() << "ERROR :" + db.lastError().text();
        return "No connection";
    } else {
        qDebug() << "Connection Open";
        QString row;
        QSqlQuery query;
        query.prepare("SELECT * FROM person WHERE id=:id");
        query.bindValue(":id", id);
        query.exec();

        query.next();
        row = query.value(0).toString() + " : " + query.value(1).toString() +
              " : " + query.value(2).toString() + "\n";
        db.close();
        return row.toStdString();
    }
}

void Person::setTodatabase(string id, string fn, string ln) {}

void Person::delFromDatabase(string id) {}




void Person::updateSelected(string id, string fn, string ln) {}


