#include "mytcpserver.h"
#include <QtDebug>
#include <QCoreApplication>
#include <string>
#include <iostream>
#include <fstream>
#include <log_in.h>
#include <database.h>
using namespace std;


mytcpserver::~mytcpserver()
{


    foreach(int i, SClients.keys())
    {
        QTextStream os(SClients[i]);
        SClients[i]->close();
        SClients.remove(i);
    }
   server_status = 0;
    mTcpServer->close();
}

mytcpserver::mytcpserver(QObject *parent) : QObject(parent) {

    mTcpServer = new QTcpServer(this);
    counter = 0;

    connect(mTcpServer, &QTcpServer::newConnection,this, &mytcpserver::slotNewConnection);
    if(!mTcpServer->listen(QHostAddress::Any, 33333))

    {
        qDebug() << "server is not started" ;
    }
    else {
        qDebug() << "ЕЕЕЕЕЕЕЕЕЕЕЕЕЕЕЕ\nЕЕЕЕЕЕЕ  ЕЕЕЕЕЕЕ\nЕЕЕЕЕЕ    ЕЕЕЕЕЕ\nЕЕЕЕЕ      ЕЕЕЕЕ\nЕЕЕЕ        ЕЕЕЕ\nЕЕЕ          ЕЕЕ\nЕЕ            ЕЕ\nЕ              Е\nЕ              Е\nЕЕ            ЕЕ\nЕЕЕ          ЕЕЕ\nЕЕЕЕ        ЕЕЕЕ\nЕЕЕЕЕ      ЕЕЕЕЕ\nЕЕЕЕЕЕ    ЕЕЕЕЕЕ\nЕЕЕЕЕЕЕ  ЕЕЕЕЕЕЕ\nЕЕЕЕЕЕЕЕЕЕЕЕЕЕЕЕ";
        server_status=1;
    }


}
void mytcpserver::slotNewConnection()
{
    if(server_status==1)
    {
        counter++;
        QTcpSocket *temp = mTcpServer->nextPendingConnection();
        int id = (int)temp->socketDescriptor();
        SClients[id] = temp;
        temp->write("Please enter your login and password\r\n");
        qDebug() << "Amount of users:" << counter << endl;
        connect(temp, &QTcpSocket::readyRead, this, &mytcpserver::slotServerReadMany);
        connect(temp, &QTcpSocket::disconnected, this, &mytcpserver::slotClientDisconnected);
    }
}


void mytcpserver::slotServerReadMany()
{
    QTcpSocket *temp = (QTcpSocket*)sender();

    Autorize obj;
    obj.read();

    QString message;

    string s_log, s_pas, pars;


    while(temp->canReadLine())
    {
    QString buffer = temp->readAll();
    message.append(buffer);
    }

    pars = message.toStdString();

    unsigned long long start = pars.find(' ');

    if(pars.find(' ') < 100)
    {
        s_log = pars.substr(0, start);
        s_pas = pars.substr(start + 1, pars.size() - start - 3);

        cout  << "Log:" << s_log << " pas:" << s_pas << endl;


        QString st; QByteArray status;
        st = QString::fromStdString(obj.autoriz(s_log, s_pas));
        status.append(st);

        if(st == "admin" or st == "user" or st == "manager" )
        {
            temp->write("Welcome,");
            temp->write(status); temp->write("\r\n");
        }

        else
        { temp->write("invalid login or password.Please try again\r\n");}

     message.clear();

    }
}



void mytcpserver::slotClientDisconnected()
{

    if(server_status==1){

        QTcpSocket *temp = (QTcpSocket*)sender();
        int id = (int)temp->socketDescriptor();
        counter --;
        qDebug() << "Amount of users:" << counter << endl;

        qDebug() << QString::fromUtf8("User is disconected!");
        temp->write("You have been disconeted");
        temp->close();

    }
}

