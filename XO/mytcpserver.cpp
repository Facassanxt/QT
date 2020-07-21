#include "mytcpserver.h"
#include <QCoreApplication>
#include <conio.h>
#include <random>
#include <time.h>
#include <iostream>

#include <QDebug>













using namespace std;

char table[3][3];//00 01 02
                //10 11 12
                //20 21 22
bool step, rez = false, win = false;
int shet = 0, l = 0, q = 0;
QString test;
string test1;
int pers = 0;

MyServer::MyServer(QObject *parent) :
    QObject(parent),
    firstSocket(NULL),
    SecondSocket(NULL)
{
     setlocale(LC_ALL, "Rus");
    server = new QTcpServer(this);
    qDebug() << "server listen = " << server->listen(QHostAddress::Any, 6666);
    connect(server, SIGNAL(newConnection()), this, SLOT(incommingConnection())); // подключаем сигнал "новое подключение" к нашему обработчику подключений

    qDebug() << "Вид поля:\n";
    int l = 0;

    for(int i(0); i < 3; i++)
    {
        for(int j(0); j < 3; j++)
        {
            cout << "| " << l+1 << ' ';
            table[i][j] = char(49+l);
            l++;
        }
        cout << '|'<<endl;
    }
    srand(time(NULL));
    if(rand() & 1)//
        step = true;
    else step = false;
}
void MyServer::incommingConnection() // обработчик подключений
{
    QTcpSocket * socket = server->nextPendingConnection(); // получаем сокет нового входящего подключения
    connect(socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(stateChanged(QAbstractSocket::SocketState))); // делаем обработчик изменения статуса сокета
    if (!firstSocket) { // если у нас нет "вещающего", то данное подключение становится вещающим
        connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead())); // подключаем входящие сообщения от вещающего на наш обработчик
        socket->write("Игрок 1"); // говорим ему что он "вещает"
        firstSocket = socket; // сохраняем себе"
        qDebug() << "Игрок 1";
        Asockets << socket;
    }
    else {

        if (!SecondSocket) { // если у нас нет "вещающего", то данное подключение становится вещающим
            connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead())); // подключаем входящие сообщения от вещающего на наш обработчик
            socket->write("Игрок 2"); // говорим ему что он "вещает"
            SecondSocket = socket; // сохраняем себе"
            qDebug() << "Игрок 2";
            Asockets << socket;
        }
        else { // иначе говорим подключенному что он "получатель"
            socket->write("client");
            sockets << socket;
        }
    }
}

int i = 0;

void MyServer::readyRead() // обработчик входящих сообщений от "вещающего"
{
    QObject * object = QObject::sender(); // далее и ниже до цикла идет преобразования "отправителя сигнала" в сокет, дабы извлечь данные
    if (!object)
        return;

    QTcpSocket * socket = static_cast<QTcpSocket *>(object);

    while(socket->canReadLine())
       {
        QByteArray arr;
        QByteArray arr1;

        if(pers%2 == 0  && socket == firstSocket)
        {

        arr1 =  firstSocket->readAll();
        arr = arr1;
        qDebug() << arr;
        }
        else if(pers%2 == 1 && socket == SecondSocket){
            arr1 =  SecondSocket->readAll();
            arr = arr1;
            qDebug() << arr;
        }
        else{
            arr1 =  socket->readAll();
        }
             int n;

            if ((arr == "1\r\n" || arr == "2\r\n" || arr == "3\r\n" || arr == "4\r\n" || arr == "5\r\n" || arr == "6\r\n" || arr == "7\r\n" || arr == "8\r\n" || arr == "9\r\n") && rez == false)
            {
                if(arr == "1\r\n") n=1;
                if(arr == "2\r\n") n=2;
                if(arr == "3\r\n") n=3;
                if(arr == "4\r\n") n=4;
                if(arr == "5\r\n") n=5;
                if(arr == "6\r\n") n=6;
                if(arr == "7\r\n") n=7;
                if(arr == "8\r\n") n=8;
                if(arr == "9\r\n") n=9;


            int i,j;

            if(n%3 == 0)
            {
                i = n/3-1;
                j = 2;
            }
            else
            {
                j = n%3-1;
                i = n/3;
            }

            if(table[i][j] != 'O' && table[i][j] != 'X')
            {
                if(step)
                {
                    table[i][j] = 'X';
                    step = false;
                }
                else
                {
                    table[i][j] = 'O';
                    step = true;
                }
                pers++;
                shet++;
            }

            for(int i(0); i < 3; i++)
                if((table[i][0] == table[i][1]) && (table[i][0] == table[i][2]))
                    win = true;

                else
                    if((table[0][i] == table[1][i]) && (table[0][i] == table[2][i]))
                        win = true;

                    else if((table[0][0] == table[1][1] && table[0][0] == table[2][2]) || (table[0][2] == table[1][1] && table[0][2] == table[2][0]))
                        win = true;

            for(int i(0); i < 3; i++)
            {
                for(int j(0); j < 3; j++)
                {
                    cout << "| " << table[i][j] << ' ';
                }
                cout << '|'<<endl;
            }

            if(shet == 9)
            {
            qDebug() << "Ничья!!";
            rez = true;
            arr = "============= Ничья!! =============\r\n";
            }

            if(win == true)
            {
                if(step)
                {
                    qDebug() << "Победил " << 'O' << endl;
                    arr = "=============Победил O =============\r\n";
                    rez = true;
                }
                else
                {
                    qDebug() << "Победил " << 'X' << endl;
                    arr = "=============Победил X =============\r\n";
                    rez = true;
                }

            }
            else {
                qDebug() << endl;
                if(step)
                    qDebug() << "Ходит " << 'X'  << " : ";
                else qDebug() << "Ходит " << 'O' << " : ";
            }

            }
       if(l == shet){
           test1 = "";
            for(int i = 0; i < 3; i++)
                       {
                           for(int j = 0; j < 3; j++)
                           {
                               test1 += "| ";
                               test1.push_back(table[i][j]);
                               test1 += " ";
                           }

                           test1 += "|\r\n";
                       }
                        QString qstr = QString::fromStdString(test1);
                        arr.append(qstr);
                        l++;
            test1 = "";

    foreach(QTcpSocket *socket, Asockets) { // пишем входящие данные от "вещающего" получателям
      if (socket->state() == QTcpSocket::ConnectedState)
      {
          socket->write(arr);
      }
     }
    }
   }
}
void MyServer::stateChanged(QAbstractSocket::SocketState state) // обработчик статуса, нужен для контроля за "вещающим"
{
    QObject * object = QObject::sender();
    if (!object)
        return;
    QTcpSocket * socket = static_cast<QTcpSocket *>(object);
    qDebug() << state;
    if (socket == firstSocket && state == QAbstractSocket::UnconnectedState)
        firstSocket = NULL;
    if (socket == SecondSocket && state == QAbstractSocket::UnconnectedState)
        SecondSocket = NULL;
}
