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
    string getData();
    string getSelected(int id);
    string addTodatabase(int id, QString fn, QString ln);
    string delFromDatabase(int id);
    string updateSelected(int id, QString fn, QString ln);
};

#endif // PERSON_H
