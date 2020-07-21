#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <QString>
#include <QDebug>
#include <QFile>





#include <QJsonObject> // Работа с Json
#include <QJsonParseError> // Вывод ошибки
#include <QFile> // Работа с файлом
#include <QFileDialog> // Выбор проводника
#include <QStandardItem> // Хранение данных
#include <QJsonArray>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{
    QFile inputFileJson;
    inputFileJson.setFileName("C:/QT/Laba/person.json");
        if ( !inputFileJson.open(QIODevice::ReadOnly | QIODevice::Text ) ) {
        qDebug() << "no json file";
        } else {
            QJsonDocument documentJson = QJsonDocument::fromJson( inputFileJson.readAll() );
            QJsonObject root = documentJson.object();
            QJsonArray jsonArray = root[""].toArray();

            QString Username;
            QString username;


            foreach ( const QJsonValue & value, jsonArray )
            {
                    QJsonObject obj = value.toObject();
                    username = obj.value("fio").toString();
            Username = ui->vvodfio->text();


            if (Username == username)
            {
                QMessageBox::information(this,"Регистрация","Данный пользователь зарегистрирован!");
            }
            }
            inputFileJson.close();




        }

        QString fio = ui->vvodfio->text();
        QString tel = ui->vvodtel->text();
        QString date = ui->vvoddate->text();

        string fios = fio.toStdString();
        string tels = tel.toStdString();
        string dates = date.toStdString();

        datastruct test;
        test.fio = fios;
        test.tel = tels;
        test.date = dates;


        DataBase obj;
        obj.read();
        obj.add(test);
        obj.write();


}
