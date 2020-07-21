#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "admin.h"
#include "worker.h"
#include "database.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd("..//1.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    admin = new Admin();
    connect(admin, &Admin::signal_admin, this, &MainWindow::show);
    connect(this, SIGNAL(sendData(long long int)), admin, SLOT(on_recieveData_clicked(long long int))); // подключение сигнала к слоту нашей формы

    Worker = new worker();
    connect(Worker, &worker::signal_worker, this, &MainWindow::show);
    connect(this, SIGNAL(sendData(long long int)), Worker, SLOT(on_recieveData_clicked(long long int))); // подключение сигнала к слоту нашей формы

    edit = new EditPerson();
    connect(this, SIGNAL(sendData(long long int)), edit, SLOT(on_recieveData_clicked(long long int))); // подключение сигнала к слоту нашей формы
    connect(this, SIGNAL(sendAccess(QString)), edit, SLOT(on_recieveAccess(QString))); // подключение сигнала к слоту нашей формы


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Login_clicked()
{
    QString Username = ui->Username->text();
    string login = Username.toStdString();
    QString Password = ui->Password->text();
    string password = Password.toStdString();
    datastruct test;
    test.login = login;
    test.password = password;


    if(!test.login.empty() and !test.password.empty())
    {

     DataBase test1("staff");
     long long int id;
     int k = 0;
     string access,token;
     istringstream streamS(test1.authorization(test));
     while(getline(streamS, token, ':'))
     {
         cout << token << endl; //токен
         if(k == 0) id = stoi(token);
         if(k == 1) access = token;
         k++;
     }
        emit sendData(id); // вызываем сигнал, в котором передаём введённые данные
    QString ac = QString::fromStdString(access);

        emit sendAccess(ac);

        if (access == "admin"){
        admin->show();
        this->close();
        }
        else if(access == "worker"){
        Worker->show();
        this->close();
        }
     }
}
