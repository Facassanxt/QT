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



   datastruct test;
    test.name = name;
    test.year = year;
    test.address = address;
    test.tel = tel;

    DataBase test1("test");
    test1.fileToVector();
    test1.add(test);
    test1.swap();
    hide();
}
