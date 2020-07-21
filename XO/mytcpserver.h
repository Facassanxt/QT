#ifndef MYSERVER_H
#define MYSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QByteArray>
#include <QDataStream>
class MyServer : public QObject
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = 0); // конструктор
signals:
public slots:
    void incommingConnection(); // обработчик входящего подключения
    void readyRead(); // обработчик входящих данных
    void stateChanged(QAbstractSocket::SocketState stat); // обработчик изменения состояния вещающего сокета (он нам важен, дабы у нас всегда был кто-то, кто будет вещать
    void connect(QSqlDatabase db){
        db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("31.10.65.179");
        db.setDatabaseName("test");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("vmvcIPvB0K9TeMvp");
        db.setConnectOptions("MYSQL_OPT_RECONNECT=TRUE;");

        if(!db.open())
        {
            qDebug() << "Error = " << db.lastError().text();
        }
        else
        {
            qDebug() << "Open db!";
        }
private:
    QTcpServer *server; // указатель на сервер
    QList<QTcpSocket *> sockets; // получатели данных
    QList<QTcpSocket *> Asockets; // полвещ данных
    QTcpSocket *firstSocket; // вещатель
    QTcpSocket *SecondSocket; // вещатель
};
#endif // MYSERVER_H
