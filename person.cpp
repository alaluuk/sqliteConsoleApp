#include "person.h"

#include <QCoreApplication>
#include <Qdir>

Person::Person() {
  db = QSqlDatabase::addDatabase("QSQLITE");

  //database kansio on projektikansion sisällä
  //asetetaan sen polku
  QDir dir("../database");
  myFolder = dir.absolutePath();
  //hakemisto polun tarkistus
  //qDebug()<<myFolder;
  db.setDatabaseName(myFolder+"/mydb.db");
  //avataan tietokantayhteys
  db.open();
}

Person::~Person() {
  // cout<<"Person tuhottiin"<<endl;
  QString myConnection = db.connectionName();
  db.close();
  db = QSqlDatabase();
  db.removeDatabase(myConnection);
}

string Person::getData() {

  if (!db.open()) {
    qDebug() << "ERROR :" + db.lastError().text();
    return "No connection";
  } else {
    // qDebug() << "Connection Open";
    QString row;
    QSqlQuery query;
    query.exec("SELECT * FROM person");

    while (query.next()) {
      row += query.value(0).toString() + " : " + query.value(1).toString() +
             " : " + query.value(2).toString() + "\n";
    }
    query.finish();
    query.clear();
    return row.toStdString();
  }
}
string Person::getSelected(int id) {
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
    return row.toStdString();
  }
}

string Person::addTodatabase(QString fn, QString ln) {
  if (!db.open()) {
    qDebug() << "ERROR :" + db.lastError().text();
    return "No connection";
  } else {
    // qDebug() << "Connection Open";
    QString row;
    QSqlQuery query;
    query.prepare(
        "INSERT INTO person(firstname,lastname) VALUES(:fn, :ln)");
    query.bindValue(":fn", fn);
    query.bindValue(":ln", ln);
    bool res = query.exec();
    // qDebug()<<res;
    if (res) {
      return "data added";
    } else {
      return "something went wrong";
    }
  }
}
string Person::updateSelected(int id, QString fn, QString ln) {
  if (!db.open()) {
    qDebug() << "ERROR :" + db.lastError().text();
    return "No connection";
  } else {
    // qDebug() << "Connection Open";
    QSqlQuery query;
    query.prepare(
        "UPDATE person SET firstname =:fn, lastname =:ln WHERE id =:id");
    query.bindValue(":id", id);
    query.bindValue(":fn", fn);
    query.bindValue(":ln", ln);
    // qDebug()<<query.exec();
    bool res = query.exec();
    // qDebug()<<res;
    if (res) {
      return "data updated";
    } else {
      return "something went wrong";
    }
    db.close();
  }
}

string Person::delFromDatabase(int id) {
  if (!db.open()) {
    qDebug() << "ERROR :" + db.lastError().text();
    return "No connection";
  } else {
    // qDebug() << "Connection Open";
    QString row;
    QSqlQuery query;
    query.prepare("DELETE FROM person WHERE id=:id");
    query.bindValue(":id", id);
    bool res = query.exec();
    query.finish();
    query.clear();
    if (res) {
      return "data removed";
    } else {
      return "something went wrong";
    }
  }
}
string Person::insertFromTextFile() {
  QDir dir("../database");
  myFolder = dir.absolutePath();
  QString filename=myFolder+"/persondata.txt";
  if (!db.open()) {
    qDebug() << "ERROR :" + db.lastError().text();
    return "No connection";
  } else {
    QString row;
    QSqlQuery query;
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
      qDebug() << "Error: Could not open text file!";
      return "error";
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
      QString line = in.readLine();
      QStringList parts = line.split(',');

      if (parts.size() == 2) {
        QString firstname = parts[0].trimmed();
        QString lastname = parts[1].trimmed();
        // Insert data into the database
        query.prepare("INSERT INTO person (firstname,lastname) VALUES (:firstname, :lastname)");
        query.bindValue(":firstname", firstname);
        query.bindValue(":lastname", lastname);

        if (!query.exec()) {
            return "something went wrong";
        }
      }
    }

    file.close();

    return "Data imported into SQLite database successfully!";
  }
}
