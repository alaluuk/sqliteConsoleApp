#include "person.h"

string Person::getId() const
{
    return id;
}

void Person::setId(const string &newId)
{
    id = newId;
}

string Person::getFirstname() const
{
    return firstname;
}

void Person::setFirstname(const string &newFirstname)
{
    firstname = newFirstname;
}

string Person::getLastname() const
{
    return lastname;
}

void Person::setLastname(const string &newLastname)
{
    lastname = newLastname;
}

void Person::setTodatabase(string id, string fn, string ln)
{

}

void Person::delFromDatabase(string id)
{

}

string Person::getData()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:\\codes\\qt_projects\\QmlSqlite\\mydb.db");
    db.open();


    if (!db.open())
    {
        qDebug() <<"ERROR :"+ db.lastError().text();
        return "No connection";
    }
    else {
        qDebug()<<"Connection Open";
        QString row="ID : Etunimi : Sukunimi\n";
        row+="____________________\n";
        QString queryString = "SELECT * FROM person";
        QSqlQuery query;
        query.exec(queryString);

        while (query.next()) {

            row+= query.value(0).toString()+" : "+ query.value(1).toString()+" : "+query.value(2).toString()+"\n";

        }
        db.close();
        return row.toStdString();

    }
}

void Person::getSelected(string id)
{

}

void Person::updateSelected(string id, string fn, string ln)
{

}

Person::Person()
{

}
