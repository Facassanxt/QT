#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>


class mytcpserver : public QObject
{
    Q_OBJECT
public:

    explicit mytcpserver(QObject *patent = nullptr);

    ~mytcpserver();

//    mytcpserver();

public slots:
    void slotNewConnection();
    void slotClientDisconnected();
    void slotServerReadMany();
private:
    QTcpServer * mTcpServer;
    QMap<int, QTcpSocket*> SClients;
    int server_status;
    int counter;
};

#endif // MYTCPSERVER_H
