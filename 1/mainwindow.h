#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonObject> // Работа с Json
#include <QJsonParseError> // Вывод ошибки
#include <QFile> // Работа с файлом
#include <QJsonArray>
#include <QDebug> //Второе окно
#include <QMessageBox> //Вывод окна с сообщением
#include <QDebug> //Второе окно
#include <QDirIterator>
#include <secondwindow.h>
#include <admin.h>
#include <third.h>
#include <ui_mainwindow.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString Username;
    QString username;
    QString Password;
    QString password;
    QString access;
    QFile FileJson;
    QJsonDocument doc;
    QJsonDocument docError;
    QString globPath;
    QJsonArray jsonArray;

    void authorization()
    {
        if (Username == username && Password == password)
        {
            closeFile();
            if (access == "1")
            {
                qDebug() << "Пароль совпадает!";
                Admin window;
                hide();
                window.setModal(true);
                window.exec();
                show();
            }
            else if (access == "2")
            {

            }
            else if (access == "3")
            {
                qDebug() << "Пароль совпадает!";
                Third window;
                hide();
                window.setModal(true);
                window.exec();
                show();
            }
        }
    }

    void openFile()
    {
        FileJson.setFileName("C:/QT/Facassanxt/person.json");
        if ( !FileJson.open(QIODevice::ReadOnly | QIODevice::Text ) )
        {
           qDebug() << "JSON IS RIP";
        }
        qDebug() << "fsdsf";

    }
    void structure()
    {
        QJsonDocument documentJson = QJsonDocument::fromJson( FileJson.readAll() );
        QJsonObject root = documentJson.object();
        QJsonArray jsonArray = root["person"].toArray();
        foreach ( const QJsonValue & value, jsonArray )
        {
                QJsonObject obj = value.toObject();
                password = obj.value("password").toString();
                username = obj.value("username").toString();
                access = obj.value("access").toString();
                authorization();
        }
        if (Username != username || Password != password)
        {
            qDebug() << "Логин или пароль указаны не верно";
        }
        closeFile();
    }

    void closeFile()
    {
        FileJson.close();
    }
    bool download()
        {
            //Цикл до конца файла
                //считываем данные построчно
        }
    bool upload()// записывает всю БД в файл
        {

            //Цикл по БД
                //считываем текущий объект БД в temp_data = db[текущий номер]

              //преобразуем текущую запись в строкув формате json

                //запиcь temp_str в файл
        }
    bool read() //считывает всю БД из файла
        {
            openFile();
            download();
            closeFile();
        }
        bool write() //запись всей БД в файл
        {
            openFile();
            upload();
            closeFile();
        }


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_action_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
