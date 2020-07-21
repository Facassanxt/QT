#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()),this,SLOT(sockReady()));
    connect(socket, SIGNAL(disconnected()),this,SLOT(sockDisc()));
    ui->groupBox->hide();
    ui->groupBoxAdd->hide();
    ui->groupBoxEd->hide();
    ui->groupBoxButton->hide();
    ui->tableView->hide();
    ui->pushButtonBD->hide();
    ui->groupBoxCom->hide();
    ui->up->hide();
    ui->down->hide();
    ui->down->hide();
    ui->Filter->hide();
    ui->Admin_3->setChecked(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sockDisc()
{
    socket->deleteLater();
}

void MainWindow::sockReady()
{

}

void MainWindow::on_LoginB_clicked()
{
    socket->connectToHost("localhost",6666);
    QString Login = ui->Login->text();
    string login = Login.toStdString();
    QString Password = ui->Password->text();
    string password = Password.toStdString();

    QString text = Login + ":" + Password;

    if(!login.empty() and !password.empty())
    {
        QByteArray temp;
        temp.append(text);
        SendCrypt(temp);


//        QFile file("./1");
//        file.open(QIODevice::WriteOnly|QFile::Text);
//        file.write(text.toUtf8().data());
//        file.close();
//        encrypt(); // Шифровать для отправки
//        //decrypt(); // Расшифровывать

//        QFile File("./2.txt");
//        if (File.open(QIODevice::ReadOnly|QFile::Text))
//        {
//            text = File.readAll();
//            qDebug()<<"Зашифрованное: "<< text;
//            qDebug()<<"Зашифрованное: "<< text.toUtf8();
//            qDebug()<<"Зашифрованное: "<< text.toLocal8Bit();
//            QByteArray Text = text.toUtf8();
//            qDebug()<<"Зашифрованное: "<< Text;
//            socket->write(Text);


//        }
//        File.close();

//        decrypt(); // Расшифровывать

//        QFile file3("./3");
//        if (file3.open(QIODevice::ReadOnly|QFile::Text))
//        {
//            text = file3.readAll();
//            qDebug()<<"Расшифрованное фаил: "<< text;
//            qDebug()<<"Расшифрованное фаил: "<< text.toUtf8();
//            qDebug()<<"Расшифрованное фаил: "<< text.toLocal8Bit();
//            qDebug()<<"Расшифрованное фаил: "<< text.toUtf8().data();
//        }
//        file3.close();
















        socket->waitForReadyRead(1000);
        QString text = socket->readAll();

        int k = 0;
        string token;
        istringstream streamS(text.toStdString());
        while(getline(streamS, token, ':'))
        {
            if(k == 0) id = QString::fromUtf8(token.c_str());
            if(k == 1) status = QString::fromUtf8(token.c_str());
            k++;
        }

//        ui->text->append(access);

        if(status == "admin")
        {
            ui->groupBoxLog->hide();
            ui->groupBox->show();
            ui->tableView->show();
            ui->pushButtonBD->show();
            ui->groupBoxButton->show();
            ui->up->show();
            ui->down->show();
        }
        else if(status == "worker")
        {
            ui->groupBoxLog->hide();
            ui->tableView->show();
            ui->pushButtonBD->show();
            ui->groupBoxEd->show();
            ui->up->show();
            ui->down->show();
            ui->id_2->setText(id);
            ui->id_2->setDisabled(1);
            ui->Admin_3->hide();
            ui->Worker_3->hide();
            ui->Cancel->hide();
        }

    }
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->groupBoxAdd->show();
    ui->groupBoxCom->hide();
    ui->Filter->hide();

}

void MainWindow::on_pushButton_3_clicked()
{
    ui->groupBoxAdd->hide();
    ui->groupBoxCom->hide();
    ui->groupBoxButton->hide();
    ui->Filter->hide();
    ui->groupBoxEd->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->groupBoxAdd->hide();
    ui->Filter->hide();
    ui->groupBoxCom->show();
}

void MainWindow::on_pushButtonCom_clicked()
{
    QString answer;
    QString text = ui->lineEdit->text();
    if(!text.toStdString().empty())
    {
        QByteArray temp;
        temp.append(text);
        SendCrypt(temp);
 //       socket->write(text.toUtf8().data());
        socket->waitForReadyRead(500);
        answer = socket->readAll();
        QMessageBox msgBox;
        msgBox.setWindowTitle("Внимание");
        if(answer == "true")
        {
            msgBox.setText("Все прошло успешно =)");
            msgBox.exec();
        }
        else{
            msgBox.setText(" =( ");
            msgBox.exec();
        }
    }
}

void MainWindow::on_Add_clicked()
{
    QString Name = ui->Name->text();
    string name = Name.toStdString();
    QString Year = ui->Year->text();
    string year = Year.toStdString();
    QString Address = ui->Address->text();
    QString Tel = ui->Tel->text();
    string tel = Tel.toStdString();
    QString access;
    if(ui->Worker->isChecked())
       {
           access = "worker";
       }
       else
       {
           access = "admin";
       }
    /* Можно сделать чтоб отправлял только команду и исключения у клиента
       или же отправлять список и парсить на сервере */

    if(!name.empty()) Name =  QString::fromUtf8(checkName(Name.toStdString()).c_str());
    if(!year.empty())Year =  QString::fromUtf8(checkYear(Year.toStdString()).c_str());
    if(!tel.empty())Tel =  QString::fromUtf8(checkTel(Tel.toStdString()).c_str());
    if (Name == "false" or Year == "false" or Tel == "false")
    {
        if(Name == "false") ui->Name->setStyleSheet("border: 5px solid red");
        else if(!name.empty()) ui->Name->setStyleSheet("border: 5px solid green");
        if(Year == "false") ui->Year->setStyleSheet("border: 5px solid red");
        else if(!year.empty()) ui->Year->setStyleSheet("border: 5px solid green");
        if(Tel == "false") ui->Tel->setStyleSheet("border: 5px solid red");
        else if(!tel.empty()) ui->Tel->setStyleSheet("border: 5px solid green");
    }
    else {
        QString text = Name + ":" + Year + ":" + Address + ":" + Tel + ":" + access;
        QByteArray temp;
        temp.append(text);
        SendCrypt(temp);
        //socket->write(text.toUtf8().data()); // Отправляем на сервер для парсинга


        ui->Name->clear();
        ui->Year->clear();
        ui->Address->clear();
        ui->Tel->clear();
        ui->Name->setStyleSheet("");
        ui->Year->setStyleSheet("");
        ui->Tel->setStyleSheet("");
    }
}

void MainWindow::on_pushButtonBD_clicked()
{
    QString text = "on_pushButtonBD_clicked()";
    QByteArray temp;
    temp.append(text);
    SendCrypt(temp);
    //socket->write(text.toUtf8().data());
    socket->waitForReadyRead(200);
    QString answer = socket->readAll();

    qDebug() << answer;

    QByteArray answerBd;
    answerBd = answer.toUtf8().data();
//    QFile file("./2.txt");
//    file.open(QIODevice::WriteOnly|QFile::Text);
//    file.write(answerBd);
//    file.close();
//    //encrypt(); // Шифровать для отправки
//    decrypt(); // Расшифровывать

//    file.setFileName("./1.txt");
//    if (file.open(QIODevice::ReadOnly|QFile::Text))
//    {
//        answer = file.readAll();
//        ui->textEdit->append(answer);

//    }
//    file.close();
    model->clear();
    ui->tableView->setSortingEnabled(false);
    QStandardItem *item;

    QStringList horizontalHeader;
    horizontalHeader.append("id");
    horizontalHeader.append("name");
    horizontalHeader.append("year");
    horizontalHeader.append("address");
    horizontalHeader.append("tel");
    horizontalHeader.append("login");
    horizontalHeader.append("password");
    horizontalHeader.append("access");

    QStringList verticalHeader;

    model->setHorizontalHeaderLabels(horizontalHeader);
    model->setVerticalHeaderLabels(verticalHeader);

    int k = 0, j = 0;
    string token;
    QString Name, Year, Address, Tel, Login, Password, access, id;


    istringstream streamS(answer.toStdString());
    while(getline(streamS, token, '$'))
    {
       text = QString::fromUtf8(token.c_str());

       k = 0;
       istringstream streamS2(text.toStdString());
       while(getline(streamS2, token, ':'))
       {
           if(k == 0) id = QString::fromUtf8(token.c_str());
           if(k == 1) Name = QString::fromUtf8(token.c_str());
           if(k == 2) Year = QString::fromUtf8(token.c_str());
           if(k == 3) Address = QString::fromUtf8(token.c_str());
           if(k == 4) Tel = QString::fromUtf8(token.c_str());
           if(k == 5) Login = QString::fromUtf8(token.c_str());
           if(k == 6) Password = QString::fromUtf8(token.c_str());
           if(k == 7) access = QString::fromUtf8(token.c_str());
           k++;
       }
       item = new QStandardItem(QString(id));
       model->setItem(j, 0, item);


       item = new QStandardItem(QString(Name));
       model->setItem(j, 1, item);

       item = new QStandardItem(QString(Year));
       model->setItem(j, 2, item);

       item = new QStandardItem(QString(Address));
       model->setItem(j, 3, item);

       item = new QStandardItem(QString(Tel));
       model->setItem(j, 4, item);

       item = new QStandardItem(QString(Login));
       model->setItem(j, 5, item);

       item = new QStandardItem(QString(Password));
       model->setItem(j, 6, item);

       item = new QStandardItem(QString(access));
       model->setItem(j, 7, item);
       j++;
    }

    QFont font = ui->tableView->font();
    font.setPixelSize(size);
    ui->tableView->setFont(font);
    ui->tableView->horizontalHeader()->setFont( font );
    ui->tableView->verticalHeader()->setFont( font );
    ui->tableView->setModel(model);
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
  //  ui->tableView->setSortingEnabled(true);


    // ПЕРЕДАТЬ МОДЕЛЬ С СЕРВЕРА
//    QSqlQuery query;
//    QSqlQueryModel *M = new QSqlQueryModel();
//    M->setQuery(query);
//    ui->tableView->setModel(M);
}

void MainWindow::on_Delete_clicked()
{
    //ТОЛЬКО ОТПРАВЛЯТЬ ЗАПРОС
    QString text = "DELETE FROM `users` WHERE `users`.`id` = " + ui->id->text();
    QString Id =  QString::fromUtf8(checkId(ui->id->text().toStdString()).c_str());
    if (Id == "false")
    {
        if(Id == "false") ui->id->setStyleSheet("border: 5px solid red");
        else ui->id->setStyleSheet("border: 5px solid green");
    }
    else
    {
        QByteArray temp;
        temp.append(text);
        SendCrypt(temp);
        QMessageBox msgBox;
        msgBox.setWindowTitle("Внимание");
        QString answer = socket->readAll();
        if(answer == "true")
        {
            msgBox.setText("Все прошло успешно =)");
            msgBox.exec();
        }
       // socket->write(text.toUtf8().data());
        ui->id->clear();
        ui->id->setStyleSheet("");
  }
}

void MainWindow::on_Edit_clicked()
{

    QString Id = ui->id_2->text();
    string id = Id.toStdString();
    QString Name = ui->Name_3->text();
    string name = Name.toStdString();
    QString Year = ui->Year_3->text();
    string year = Year.toStdString();
    QString Address = ui->Address_3->text();
    QString Tel = ui->Tel_3->text();
    string tel = Tel.toStdString();
    QString Login = ui->login->text();
    QString Password = ui->password->text();
    QString access;
    if(ui->Worker_3->isChecked()) access = "worker";
    else if(ui->Admin_3->isChecked()) access = "admin";
    else access = "";


    if(!name.empty()) Name =  QString::fromUtf8(checkName(Name.toStdString()).c_str());
    if(!year.empty()) Year =  QString::fromUtf8(checkYear(Year.toStdString()).c_str());
    if(!tel.empty()) Tel =  QString::fromUtf8(checkTel(Tel.toStdString()).c_str());
    if(!id.empty()) Id =  QString::fromUtf8(checkId(Id.toStdString()).c_str());

    if (Name == "false" or Year == "false" or Tel == "false" or Id == "false")
    {
        if(Name == "false") ui->Name_3->setStyleSheet("border: 5px solid red");
        else if (!name.empty()) ui->Name_3->setStyleSheet("border: 5px solid green");
        if(Year == "false") ui->Year_3->setStyleSheet("border: 5px solid red");
        else if (!year.empty()) ui->Year_3->setStyleSheet("border: 5px solid green");
        if(Tel == "false") ui->Tel_3->setStyleSheet("border: 5px solid red");
        else if (!tel.empty())  ui->Tel_3->setStyleSheet("border: 5px solid green");
        if(Id == "false") ui->id_2->setStyleSheet("border: 5px solid red");
        else if (!id.empty())  ui->id_2->setStyleSheet("border: 5px solid green");
    }
    else {
        QString text = Id + ":" + Name + ":" + Year + ":" + Address + ":" + Tel + ":" + Login + ":" + Password + ":" + access;
        QByteArray temp;
        temp.append(text);
        SendCrypt(temp);
      //  socket->write(text.toUtf8().data());

        ui->Name_3->clear();
        ui->Year_3->clear();
        ui->Address_3->clear();
        ui->Tel_3->clear();
        ui->login->clear();
        ui->password->clear();


        ui->Worker_3->setCheckable(false);
        ui->Admin_3->setCheckable(false);

        ui->Worker_3->setCheckable(true);
        ui->Admin_3->setCheckable(true);

        ui->id_2->setStyleSheet("");
        ui->Name_3->setStyleSheet("");
        ui->Year_3->setStyleSheet("");
        ui->Tel_3->setStyleSheet("");

        if (status == "admin")
        {
            ui->id_2->clear();
            ui->groupBoxButton->show();
            ui->groupBoxEd->hide();
        }
    }
}

void MainWindow::on_up_clicked()
{
    size++;
    QFont font = ui->tableView->font();
    font.setPixelSize(size);
    ui->tableView->setFont(font);
    ui->tableView->horizontalHeader()->setFont( font );
    ui->tableView->verticalHeader()->setFont( font );
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::on_down_clicked()
{
    size--;
    QFont font = ui->tableView->font();
    font.setPixelSize(size);
    ui->tableView->setFont(font);
    ui->tableView->horizontalHeader()->setFont( font );
    ui->tableView->verticalHeader()->setFont( font );
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::on_Cancel_clicked()
{
    ui->Name_3->clear();
    ui->Year_3->clear();
    ui->Address_3->clear();
    ui->Tel_3->clear();
    ui->login->clear();
    ui->password->clear();


    ui->Worker_3->setCheckable(false);
    ui->Admin_3->setCheckable(false);

    ui->Worker_3->setCheckable(true);
    ui->Admin_3->setCheckable(true);

    ui->id_2->clear();
    ui->groupBoxButton->show();
    ui->groupBoxEd->hide();
    ui->id_2->setStyleSheet("");
    ui->Name_3->setStyleSheet("");
    ui->Year_3->setStyleSheet("");
    ui->Tel_3->setStyleSheet("");

}

void MainWindow::on_filter_clicked()
{
    ui->groupBoxAdd->hide();
    ui->groupBoxCom->hide();
    ui->groupBoxEd->hide();
    ui->Filter->show();
}

void MainWindow::on_pushButton_clicked()
{
    QString Id = ui->id_4->text();
    QString Name = ui->Name_4->text();
    QString Year = ui->Year_4->text();
    QString Address = ui->Address_4->text();
    QString Tel = ui->Tel_4->text();
    QString Login = ui->login_4->text();

    ui->tableView->setSortingEnabled(true);


    QSortFilterProxyModel *proxyModelId = new QSortFilterProxyModel(this);
    proxyModelId->setSourceModel(model);
    proxyModelId->setFilterRegExp(QRegExp(Id, Qt::CaseInsensitive,
                                        QRegExp::FixedString));
    proxyModelId->setFilterKeyColumn(0);

    QSortFilterProxyModel *proxyModelName = new QSortFilterProxyModel(this);
    proxyModelName->setSourceModel(proxyModelId);
    proxyModelName->setFilterRegExp(QRegExp(Name, Qt::CaseInsensitive,
                                        QRegExp::FixedString));
    proxyModelName->setFilterKeyColumn(1);

    QSortFilterProxyModel *proxyModelYear = new QSortFilterProxyModel(this);
    proxyModelYear->setSourceModel(proxyModelName);
    proxyModelYear->setFilterRegExp(QRegExp(Year, Qt::CaseInsensitive,
                                        QRegExp::FixedString));
    proxyModelYear->setFilterKeyColumn(2);

    QSortFilterProxyModel *proxyModelAddress = new QSortFilterProxyModel(this);
    proxyModelAddress->setSourceModel(proxyModelYear);
    proxyModelAddress->setFilterRegExp(QRegExp(Address, Qt::CaseInsensitive,
                                        QRegExp::FixedString));
    proxyModelAddress->setFilterKeyColumn(3);

    QSortFilterProxyModel *proxyModelTel = new QSortFilterProxyModel(this);
    proxyModelTel->setSourceModel(proxyModelAddress);
    proxyModelTel->setFilterRegExp(QRegExp(Tel, Qt::CaseInsensitive,
                                        QRegExp::FixedString));
    proxyModelTel->setFilterKeyColumn(4);

    QSortFilterProxyModel *proxyModelLogin = new QSortFilterProxyModel(this);
    proxyModelLogin->setSourceModel(proxyModelTel);
    proxyModelLogin->setFilterRegExp(QRegExp(Login, Qt::CaseInsensitive,
                                        QRegExp::FixedString));
    proxyModelLogin->setFilterKeyColumn(5);

    ui->tableView->setModel(proxyModelLogin);
}
