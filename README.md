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
#include &lt;QSqlDatabase&gt;
#include &lt;QSqlError&gt;
#include &lt;QSqlQuery&gt;
</pre>
Ja koska sovelluksessa on myös mahdollisuus lisätä dataa tietokantaan tiedostosta, tarvitaan person.h tiedostoon rivit 
<pre>
#include &lt;QFile&gt;
#include &lt;QTextStream&gt;
</pre>

## Projektikansion polku

Sovelluksen tietokanta tiedosto **mydb.db** sijaitsee projektikansion alla kansiossa database.
Jotta hakemistopolkua ei tarvise kovakoodata käytin seuraavaa rakennetta 
<pre>
#include &lt;Qdir&gt;
  //database kansio on projektikansion sisällä
  //asetetaan sen polku
  QDir dir("../database");
  myFolder = dir.absolutePath();

  db.setDatabaseName(myFolder+"/mydb.db");
</pre>