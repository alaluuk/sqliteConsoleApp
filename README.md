# SQLite tietokannan käyttö C++ sovelluksessa

Tässä esimerkissä käytin Qt-frameworkkiä, koska sen kirjastoista löytyy tuki SQLite tietokannoilla. 

## Esimerkin tietokanta

Tämän esimerkin tietokantatiedosto on nimeltään **mydb.db** ja se löytyy kansiosta database. Sovellusta käyttääksesi, et tarvitse **sqlite3** sovellusta, mutta voit ladata sen sivulta https://www.sqlite.org/download.html

Sovelluksen asentamiseksi riittää, että lataat tuon paketin ja purat sen koneellesi. Sitten voit halutessasi lisätä koneesi ympäristömuuttuujiin polun siihen kansioon johon tuon purit. Sen jälkeen voit käsitellä tietokantaa antamalla kansiossa database komennon 
<pre>
sqlite3 mydb.db
</pre>

Tämän esimerkin tietokanta on luotu koodilla 
<pre>
create table person(
id INTEGER PRIMARY KEY AUTOINCREMENT,
firstname varchar(45),
lastname varchar(45));
</pre>

## Sovelluksen rakenne

Sovelluksen **pro-tiedostoon** tulee lisätä rivi 
<pre>
QT += sql
</pre>

Ja sitten SQLiten vuoksi tässä tapauksessa tiedostoon **person.h** rivit 
<pre>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
</pre>
Ja koska sovelluksessa on myös mahdollisuus lisätä dataa tietokantaan tiedostosta, tarvitaan person.h tiedostoon rivit 
<pre>
#include <QFile>
#include <QTextStream>
</pre>
Ja, jos haluat että tiedostosta lisääminen toimii, luo kansioon C:/temp tiedosto nimeltään **persondata.txt**, jonka rakenne on seuraavanlainen 
<pre>
Etunimi1, Sukunimi1
Etunimi2, Sukunimi2
</pre>