#include "admin.h"
#include "ui_admin.h"
#include "database.h"
#include "addperson.h"
#include "mainwindow.h"
#include "deleteperson.h"
#include "editperson.h"
#include "QTime"
#include "QFile"
#include "QTextStream"
#include "QTimeZone"


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


void Admin::on_pushButtonAdd_clicked()
{

    hide();
    AddPerson add;
    add.setModal(true);
    add.exec();
    show();
}

void Admin::on_pushButtonEdit_clicked()
{
    hide();
    EditPerson edit;
    edit.setModal(true);
    edit.exec();
    show();
}

void Admin::on_pushButtonDelete_clicked()
{
    hide();
    DeletePerson del;
    del.setModal(true);
    del.exec();
    show();

//    DataBase test1("staff");
//    test1.fileToVector();
//    test1.search("id",2);
//    test1.search("address","Moscow");
}

void Admin::on_pushButton1_clicked()
{
    DataBase test1("staff");
    test1.fileToVector();
    QString qstr = QString::fromStdString(test1.TextRead());
    ui->Text->clear();
    ui->Text->append(qstr);

}

void Admin::on_pushButton2_clicked()
{

    QString Grounds = ui->grounds->currentText();

    QString Plants = ui->plants->currentText();



    QDateTime dt = QDateTime::currentDateTime();
   ui->Text->setText(qstr + " -> " + Grounds + " -> " + Plants + " -> " + dt.toString("dd/MM/yyyy hh:mm:ss"));



        QFile save;
        save.setFileName("../plantinglog.txt");
        if (save.open(QIODevice::Append | QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream stream(&save);
            stream<<qstr + " -> " + Grounds + " -> " + Plants + " -> " + dt.toString("dd/MM/yyyy hh:mm:ss") + "\n";
            save.close();
        }
}

void Admin::on_pushButton3_clicked()
{

//    QString ComboBox = ui->comboBox->currentText();
//    string comboBox = ComboBox.toStdString();

//    QString ComboBox_2 = ui->comboBox_2->currentText();
//    string comboBox_2 = ComboBox_2.toStdString();


    QString Search_Name = ui->Search_Name->text();
    string search_Name = Search_Name.toStdString();

    QString Search_Year = ui->Search_Year->text();
    string search_Year = Search_Year.toStdString();

    QString Search_Address = ui->Search_Address->text();
    string search_Address = Search_Address.toStdString();

    QString Search_Login = ui->Search_Login->text();
    string search_Login = Search_Login.toStdString();

    DataBase test1("staff");
    test1.fileToVector();

    QString qstr;

    if (search_Name.empty() and search_Year.empty() and search_Address.empty() and search_Login.empty())
    {
        qstr = "Искать нечего";
    }
    else {

       if(!search_Name.empty() and !search_Year.empty() and search_Address.empty() and search_Login.empty()){
            qstr = QString::fromStdString((test1.search("name", search_Name)).ssearch("year",search_Year));
        }

    }
    ui->Text->clear();
    ui->Text->append(qstr);
}


void Admin::on_recieveData_clicked(long long int id)
{
    stringstream ss;
    ss << id;
    string str = ss.str();
    qstr = QString::fromStdString(str);
    ui->VashID->setText("Ваш Id - " + qstr);
}
