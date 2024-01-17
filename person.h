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
    string id;
    string firstname;
    string lastname;
public:
    Person();
    string getId() const;
    void setId(const string &newId);
    string getFirstname() const;
    void setFirstname(const string &newFirstname);
    string getLastname() const;
    void setLastname(const string &newLastname);

    void setTodatabase(string id, string fn, string ln);
    void delFromDatabase(string id);
    string getData();
    void getSelected(string id);
    void updateSelected(string id, string fn, string ln);
};

#endif // PERSON_H
