#ifndef PERSON_H
#define PERSON_H
#include<QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<iostream>

#include <QFile>
#include <QTextStream>

using namespace std;
class Person
{
private:
    QSqlDatabase db;
    QString myFolder;
public:
    Person();
    ~Person();
    string getData();
    string getSelected(int id);
    string addTodatabase(QString fn, QString ln);
    string delFromDatabase(int id);
    string updateSelected(int id, QString fn, QString ln);
    string insertFromTextFile();
};

#endif // PERSON_H
