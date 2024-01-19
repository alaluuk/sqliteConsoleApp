#ifndef PERSON_H
#define PERSON_H
#include<QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<iostream>
using namespace std;
class Person
{
private:
    QSqlDatabase db;
public:
    Person();
    void setTodatabase(string id, string fn, string ln);
    void delFromDatabase(string id);
    string getData();
    string getSelected(QString id);
    void updateSelected(string id, string fn, string ln);
};

#endif // PERSON_H
