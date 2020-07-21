#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>
#include <QDialog>
#include <QJsonObject> // Работа с Json
#include <QJsonParseError> // Вывод ошибки
#include <QFile> // Работа с файлом
#include <QFileDialog> // Выбор проводника
#include <QStandardItem> // Хранение данных
#include <QJsonArray>

namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT


public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();


private slots:

    void on_LoadButton_clicked();

    void on_SaveButton_clicked();


private:
    Ui::Admin *ui;
};


#endif // ADMIN_H
