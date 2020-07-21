#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QMessageBox> //Вывод окна с сообщением
#include <QDebug> //Второе окно
#include <QDirIterator>
#include <QTextStream>
#include <QCoreApplication>

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::on_pushButton_3_clicked()
{

    QFile inputFileJson;
    inputFileJson.setFileName("C:/QT/Facassanxt/person.json");
        if ( !inputFileJson.open(QIODevice::ReadOnly | QIODevice::Text ) ) {
        qDebug() << "no json file";
        } else {
            QJsonDocument documentJson = QJsonDocument::fromJson( inputFileJson.readAll() );
            QJsonObject root = documentJson.object();
            QJsonArray jsonArray = root["person"].toArray();

            QString Username;
            QString username;
            QString Password;


            foreach ( const QJsonValue & value, jsonArray )
            {
                    QJsonObject obj = value.toObject();
                    username = obj.value("username").toString();
            Password = ui->Password_2->text();
            Username = ui->Username_2->text();


            if (Username == username)
            {
                QMessageBox::information(this,"Регистрация","Данный пользователь зарегистрирован!");
            }
            }
            inputFileJson.close();
            if (Username != username)
            {
                fstream logins("C:\\QT\\Facassanxt\\person.json");
                logins.seekg(-7,ios_base::end);
                logins << ",\n\t\t{\"username\":\"" << Username.toStdString() << "\",\"password\":\"" << Password.toStdString() << "\",\"access\":\"3\"}\n\t]\n}";
                logins.close();
            }



        }
    hide();
}
