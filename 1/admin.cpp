#include "admin.h"
#include "ui_admin.h"
#include <QMessageBox> //Вывод окна с сообщением
#include <QDebug> //Второе окно
#include <QDirIterator>
#include <QTextStream>
#include <QDirIterator>
#include <QCoreApplication>
#include <QTextDocumentWriter>
#include <QFileInfo>
#include <QJsonDocument>
#include <mainwindow.h>
#include <string>
#include <QString>

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

Admin::Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
}

Admin::~Admin()
{
    delete ui;
}


void Admin::on_LoadButton_clicked()
{
    QFile inputFileJson("C:/QT/Facassanxt/person.json");
   if(inputFileJson.open(QIODevice::ReadOnly))
   {
    QString temp(inputFileJson.readAll());
    ui->textEdit->clear();
    ui->textEdit->append(temp);
    }


//    QFile inputFileJson;
//    inputFileJson.setFileName("C:/QT/Facassanxt/person.json");
//        if ( !inputFileJson.open(QIODevice::ReadOnly | QIODevice::Text ) ) {
//        qDebug() << "no json file";
//        } else {
//            QJsonDocument documentJson = QJsonDocument::fromJson( inputFileJson.readAll() );
//            QJsonObject root = documentJson.object();



//             // Очищаем текстовое поле
//             ui->textEdit->clear();
//             // И устанавливаем в проверочное текстовое поле содержимое Json объекта
//             ui->textEdit->setText(QJsonDocument(root).toJson(QJsonDocument::Compact));
//        }
//        inputFileJson.close();
}



void Admin::on_SaveButton_clicked()
{

//QFile::remove("C:/QT/Facassanxt/person.json");

//        QString fileName=QFileDialog::getSaveFileName( 0,"Сохранить файл как","C:/QT/Facassanxt","Json(*.txt)");

//        if (fileName.isEmpty()) return;

//        QTextDocumentWriter writer(fileName);

//        bool success;
//        success = writer.write(ui->textEdit->document());

//        if (success)
//        {
//            QMessageBox::information(this, "Отлично!", "Экспорт прошел успешно");
//        }
//        else
//        {
//            QMessageBox::critical(this, "Ошибка", "При сохранении файла произошла ошибка");
//        }

// QFile::rename(fileName, "C:/QT/Facassanxt/person.json");

    QFile save;
    save.setFileName("C:/QT/Facassanxt/person.json");
    if(!save.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::information(this,"Error","Path not correct");
    }
QTextStream stream(&save);
stream << ui->textEdit->toPlainText();
save.close();
}
