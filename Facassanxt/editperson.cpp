#include "editperson.h"
#include "ui_editperson.h"
#include "database.h"


EditPerson::EditPerson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditPerson)
{
    ui->setupUi(this);
}

EditPerson::~EditPerson()
{
    delete ui;
}

void EditPerson::on_Edit_clicked()
{
    QString Id = ui->id->text();
    QString Name = ui->Name->text();
    QString Year = ui->Year->text();
    QString Address = ui->Address->text();
    QString Tel = ui->Tel->text();
    QString Login = ui->login->text();
    QString Password = ui->password->text();


    string id = Id.toStdString();
    string name = Name.toStdString();
    string year = Year.toStdString();
    string address = Address.toStdString();
    string tel = Tel.toStdString();
    string login = Login.toStdString();
    string password = Password.toStdString();




   datastruct test;
    test._id = id;
    test.name = name;
    test.year = year;
    test.address = address;
    test.tel = tel;
    test.login = login;
    test.password = password;

    DataBase test1("test");
    test1.edit(id, test);
    hide();

}
