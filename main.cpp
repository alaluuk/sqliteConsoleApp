#include "person.h"

#include <QCoreApplication>
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout<<"Start"<<endl;
    string data;
    Person objectPerson;
//    data=objectPerson.getData();
    data=objectPerson.getSelected(1);
    cout<<data;
    string resAdd=objectPerson.addTodatabase(7,"Jussi","Juonio");
    cout<<"add: "<<resAdd<<endl;
    string resDel1=objectPerson.delFromDatabase(4);
    cout<<"delete: "<<resDel1<<endl;
    resDel1=objectPerson.delFromDatabase(5);
    cout<<"delete: "<<resDel1<<endl;

    string resUpdate=objectPerson.updateSelected(7,"Matti","Mainio");
    cout<<"update: "<<resUpdate<<endl;
    return a.exec();
}
