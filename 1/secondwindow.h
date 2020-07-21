#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include <QJsonObject> // Работа с Json
#include <QJsonParseError> // Вывод ошибки
#include <QFile> // Работа с файлом
#include <QFileDialog> // Выбор проводника
#include <QStandardItem> // Хранение данных
#include <QJsonArray>
#include <fstream>
#include <sstream>
#include <QMessageBox> //Вывод окна с сообщением
#include <QDebug> //Второе окно
#include <QDirIterator>
#include <QTextStream>
#include <QCoreApplication>

#include <iostream>
#include <string>

using namespace std;

namespace Ui {
class SecondWindow;
}


class SecondWindow : public QDialog
{
    Q_OBJECT


public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::SecondWindow *ui;

};


#endif // SECONDWINDOW_H
