#include "addperson.h"
#include "ui_addperson.h"
#include "database.h"
#include "admin.h"

AddPerson::AddPerson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPerson)
{
    ui->setupUi(this);
}

AddPerson::~AddPerson()
{
    delete ui;
}

void AddPerson::on_Add_clicked()
{
    QString Name = ui->Name->text();
    QString Year = ui->Year->text();
    QString Address = ui->Address->text();
    QString Tel = ui->Tel->text();


    string name = Name.toStdString();
    string year = Year.toStdString();
    string address = Address.toStdString();
    string tel = Tel.toStdString();
    string access;


    if(ui->Worker->isChecked())
    {
        access = "worker";
    }
    else
    {
        access = "admin";
    }


   datastruct test;
    test.name = name;
    test.year = year;
    test.address = address;
    test.tel = tel;
    test.access = access;

    DataBase test1("staff");
    test1.fileToVector();
    test1.add(test);
    test1.swap();
    hide();
}
