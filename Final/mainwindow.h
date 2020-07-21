#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "admin.h"
#include "worker.h"
#include "string"
#include "editperson.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void sendData(long long int id);
    void sendAccess(QString access);


private slots:
    void on_Login_clicked();

private:
    Ui::MainWindow *ui;
    Admin *admin;
    worker * Worker;
    EditPerson *edit;
};

#endif // MAINWINDOW_H
