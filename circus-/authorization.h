#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QMainWindow>
#include "admin.h"
#include "user.h"
#include <QFile>
#include <QDebug>
#include <QByteArray>
#include <QString>

namespace Ui {
class authorization;
}

class authorization : public QMainWindow
{
    Q_OBJECT

public:
    explicit authorization(QWidget *parent = nullptr);
    ~authorization();
    void readFile();

private slots:
    void on_input_clicked();

private:
    Ui::authorization *ui;
    admin *awindow;
    user *uwindow;
};

#endif // AUTHORIZATION_H
