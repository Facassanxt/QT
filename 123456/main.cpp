#include <QtSql>
#include <QCoreApplication>
#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <iostream>
#include <QSqlRecord>

static bool createConnection()
{
 QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
 db.setDatabaseName("C:/QT/SQL/addressbook");

// db.setUserName("elton");
// db.setHostName("epica");
// db.setPassword("password");

 if (!db.open())
 {
     qDebug() << "Cannot open database:" << db.lastError();
     return false;
 }

 return true;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    setlocale(LC_ALL, "Rus");

    // Соединяемся с менеджером баз данных
     if (!createConnection()) {
     return -1;
     }
     // Создаем базу
     QSqlQuery query;

     QString str = "CREATE TABLE IF NOT EXISTS addressbook ( number INTEGER PRIMARY KEY NOT NULL AUTOINCREMENT,  name VARCHAR(15),  phone VARCHAR(12),  email VARCHAR(15));";

//      if (!query.exec(str)) {
//          qDebug() << "Unable to create a table";
//      }
//      // Добавляем данные в базу
//      QString strF ="INSERT INTO addressbook (name, phone, email) VALUES('%1', '%2', '%3');";
//      str = strF.arg("Piggy")
//      .arg("+49 631322187")
//      .arg("piggy@mega.de");
//      if (!query.exec(str)) {
//      qDebug() << "Unable to make insert operation";
//      }
//      str = strF.arg("Kermit")
//      .arg("+49 631322181")
//      .arg("kermit@mega.de");
//      if (!query.exec(str)) {
//      qDebug() << "Unable to make insert operation";
//      }

//      if (!query.exec("SELECT * FROM addressbook;")) {
//      qDebug() << "Unable to execute query — exiting";
//      return 1;
//      }

      // Считываем данные из базы
      QSqlRecord rec = query.record();
      int nNumber = 0;
      QString strName;
      QString strPhone;
      QString strEmail;
      while (query.next()) {
      nNumber = query.value(rec.indexOf("number")).toInt();
      strName = query.value(rec.indexOf("name")).toString();
      strPhone = query.value(rec.indexOf("phone")).toString();
      strEmail = query.value(rec.indexOf("email")).toString();


      qDebug() << nNumber << " " << strName << ";\t"
      << strPhone << ";\t" << strEmail;
      }

//      if (!query.exec("SELECT email FROM addressbook WHERE name = 'Piggy';")){}
//      QSqlRecord resc = query.record();
//int i = 0;
//      while(query.next()){
//   i++;
//      strEmail = query.value(resc.indexOf("email")).toString();
//      qDebug() << strEmail;
//      }

//qDebug() << i;
      return a.exec();
     }




//    //  QString str = "CREATE TABLE addressbook ( number INTEGER PRIMARY KEY NOT NULL AUTO_INCREMENT,  name VARCHAR(15),  phone VARCHAR(12),  email VARCHAR(15));";

//#include <QCoreApplication>
//#include <QVariant>
//#include <QDebug>
//#include <QSqlDatabase>
//#include <QSqlQuery>
//#include <QSqlError>
//#include <QSqlRecord>

//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);


//    // создаем базу данных типа QSQLite
//    // QSQLite - встроенный драйвер в QT
//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("C:/GitHub/181_352_2Term_Chikishev/test");
//    if(!db.open())
//        qDebug()<<db.lastError().text();

//    // добавить запись путем SQL запроса
//    // создать запрос к БД
//   /*
//    создание таблицы

//    Название: User
//    Поля: login, password - хранятся значениия типа char[20] (массив символов длины 20)

//    CREATE TABLE User(login VARCHAR(20) NOT NULL, password VARCHAR(20) NOT NULL)

//    Зачем нужны типы данных?
//        Пример: в поле age типа INTEGER в разных записях БД (строках таблицы) записано
//                "123"
//                34
//                "a"
//        Вопрос: как сравнивать? преобразуем к заданному типу INTEGER:
//                    "123" -> 123
//                    34 -> 34
//                    "a" -> 65 (код символа)

//    Вставить запись в таблицу

//    Название таблицы: User
//    login: "admin"
//    password: "123"

//    INSERT INTO User(login, password) VALUES ("admin", "123")
//*/
//    QSqlQuery query(db);
//    //создали таблицу
//    query.exec("CREATE TABLE User("
//               "login VARCHAR(20) NOT NULL, "
//               "password VARCHAR(20) NOT NULL"
//               ")");

//    //добавить запись в таблицу
//    /*query.prepare("INSERT INTO User(login, password) "
//                  "VALUES (\"admin\", \"123\")");

//*/
//    query.prepare("INSERT INTO User(login, password) "
//                      "VALUES (:login, :password)");

//    query.bindValue(":password","123");
//    query.bindValue(":login","admin");

//    query.exec();// выполнить запрос


//    /*
//    Выбрать все записи БД
//    SELECT * FROM User

//    Выбрать все записи БД с условием
//    SELECT * FROM User WHERE .......
//   */
//    query.exec("SELECT * FROM User");


//    // вывести на экран
//    QSqlRecord rec = query.record();
//    const int loginIndex = rec.indexOf("login");//номер "столбца"
//    const int passwordIndex = rec.indexOf("password");

//    while(query.next())
//        qDebug()<<query.value(loginIndex)<<"\t"<<query.value(passwordIndex)<<"\n";

//    //закрыть соединение
//    //удалить таблицу
//    query.exec("DROP TABLE User");
//    //закрываем базу данных
//    db.close();
//    return a.exec();
//}


