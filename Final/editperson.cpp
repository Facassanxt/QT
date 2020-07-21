#include "editperson.h"
#include "ui_editperson.h"
#include "database.h"


QString qstr;
QString Access;

EditPerson::EditPerson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditPerson)
{
    ui->setupUi(this);
    if (Access == "worker")
    {
    ui->id->setText(qstr);
    ui->id->setDisabled(1);
    ui->Admin->hide();
    ui->Worker->hide();
    }
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

    string access;
    if (ui->Worker->isChecked() or ui->Admin->isChecked())
    {
        if(ui->Worker->isChecked())
        {
            access = "worker";
        }
        if(ui->Admin->isChecked())
        {
            access = "admin";
        }
    }
    else {
        access = "";
    }


   datastruct test;
    test._id = id;
    test.name = name;
    test.year = year;
    test.address = address;
    test.tel = tel;
    test.login = login;
    test.password = password;
    test.access = access;

    DataBase test1("staff");
    if (!test._id.empty())
    {
        test1.edit(id, test);
    }
    hide();

}

void EditPerson::on_recieveData_clicked(long long int id)
{
    stringstream ss;
    ss << id;
    string str = ss.str();
        cout << str;
    qstr = qstr + QString::fromStdString(str);
}

void EditPerson::on_recieveAccess(QString access)
{

    Access = access;
}
