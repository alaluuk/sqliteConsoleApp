#include "person.h"

#include <QCoreApplication>
#include<iostream>
using namespace std;

int menu();
void allRows();
void oneRow();
void addData();
void updateData();
void deleteData();

int main(int argc, char *argv[])
{
    int choice=1;
    QCoreApplication a(argc, argv);
    while (choice!=6){
          choice=menu();
    if(choice==1){
        allRows();
    }
    else if(choice==2){
        oneRow();
    }
    else if(choice==3){
        addData();
    }
    else if(choice==4){
        updateData();
    }
    else if(choice==5){
        deleteData();
    }
    else{
        cout<<"Loppu"<<endl;
    }
    }

    return a.exec();
}
int menu(){
    int choice;
    cout<<"Valitse toiminto"<<endl;
    cout<<"(1) kaikki tietueet"<<endl;
    cout<<"(2) valittu tietue"<<endl;
    cout<<"(3) lisaa uusi"<<endl;
    cout<<"(4) muokkaa tietue"<<endl;
    cout<<"(5) poista tietue"<<endl;
    cout<<"(6) LOPETA"<<endl;
    cin>>choice;
    return choice;
}
void allRows(){
    string data;
    Person objectPerson;
    data=objectPerson.getData();
    cout<<data;
}
void oneRow(){
    string data;
    Person objectPerson;
    cout<<"Anna id"<<endl;
    int id;
    cin>>id;
    data=objectPerson.getSelected(id);
    cout<<data;
}
void addData(){
    string data;
    Person objectPerson;
    int id;
    QString fname;
    QString lname;
    QTextStream qtin(stdin);
    cout<<"Anna id"<<endl;
    cin>>id;
    cout<<"Anna etunimi"<<endl;
    fname=qtin.readLine();
    cout<<"Anna sukunimi"<<endl;
    lname=qtin.readLine();
    data=objectPerson.addTodatabase(id,fname,lname);
    cout<<data;
}
void updateData(){
    string data;
    Person objectPerson;
    int id;
    QString fname;
    QString lname;
    QTextStream qtin(stdin);
    cout<<"Anna id"<<endl;
    cin>>id;
    cout<<"Anna etunimi"<<endl;
    fname=qtin.readLine();
    cout<<"Anna sukunimi"<<endl;
    lname=qtin.readLine();
    data=objectPerson.updateSelected(id,fname,lname);
    cout<<data;
}
void deleteData(){
    string data;
    Person objectPerson;
    cout<<"Anna id"<<endl;
    int id;
    cin>>id;
    data=objectPerson.delFromDatabase(id);
    cout<<data;
}
