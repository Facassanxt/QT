#include "authorization.h"
#include "ui_authorization.h"
#include "admin.h"
#include "datebase.h"
#include "string"
#include <QString>
#include <QMessageBox>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <iostream>
#include "QDebug"
using namespace std;


authorization::authorization(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::authorization)
{
    ui->setupUi(this);
}

authorization::~authorization()
{
    delete ui;
}

void authorization::on_input_clicked()
{
    QString Username = ui->login->text();
    string login = Username.toStdString();
    QString Password = ui->pass->text();
    string password = Password.toStdString();
    datastruct test;
    test.login = login;
    test.password = password;
    cout << test.login + test.password;

    if(!test.login.empty() and !test.password.empty())
    {

        DataBase test1("database");
        long long int id;
        int k = 0;
        string access,token;
        cout << "--------------------------------";
        istringstream streamS(test1.authorization(test));
        while(getline(streamS, token, ':'))
         {
            cout << token << endl; //токен
            if(k == 0) id = stoi(token);
            if(k == 1) access = token;
            k++;
         }
//emit sendData(id); // вызываем сигнал, в котором передаём введённые данные
//QString ac = QString::fromStdString(access);

//emit sendAccess(ac);

        if (access == "admin"){
         awindow = new admin(this);
                      awindow->show();
//admin -> show();
//this->close();
        }
        else if(access == "user"){
        uwindow = new user(this);
        uwindow->show();
//user->show();
//this->close();
        }
       }
}


//void authorization::on_input_clicked()
//{
//    QString login = ui->login->text();
//    string Login = login.toStdString();
//    QString pass = ui->pass->text();
//    string Pass = pass.toStdString();
//    cout << access;

//    ifstream streamF("F:\\qt\\123\\circus-\\database.txt");

//    if(!streamF){exit(1);}
//    string str, token;
//    while(!streamF.eof())
//    {//while(streamF)

//        //string str, token, slogin;
//        getline(streamF, str); //строка
//        cout << str << endl;

//            datastruct item; //запись таблицы

//            int k = 0;
//            istringstream streamS(str);

//            while(getline(streamS, token, ':'))
//                {
////                cout << token << endl; //токен
////                if(k == 0) if(token == Login){
////                if(k == 1) if(token == Pass){
////                    hide();
////                    awindow = new admin(this);
////                    awindow->show();
////                    break;
//                if(k == 0) item.login = token;
//                if(k == 1) item.password = token;
//                if(k == 2) item.access= token;
//                k++;
//                }


//            if (item.login == Login and item.password == Pass)
//            {
//                if(item.access == "admin"){
//                  //  hide();
//                    awindow = new admin(this);
//                    awindow->show();
//                }else{
//                   //hide(); - спрятать
//                    //this->close(); - закрыть полностью
//                    //add.exec();- пока открыто окно, быть скрытым
//                    uwindow = new user(this);
//                    uwindow->show();
//                }

//            }

//            _db.push_back(item);
//     }
//streamF.close();
//}



