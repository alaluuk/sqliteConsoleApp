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
    data=objectPerson.getData();
    cout<<data;

    return a.exec();
}
