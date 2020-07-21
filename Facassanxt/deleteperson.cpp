#include "deleteperson.h"
#include "ui_deleteperson.h"
#include "database.h"

DeletePerson::DeletePerson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeletePerson)
{
    ui->setupUi(this);
}

DeletePerson::~DeletePerson()
{
    delete ui;
}

void DeletePerson::on_Delete_clicked()
{
    QString Id = ui->id->text();
    string id = Id.toStdString();
    DataBase test1("test");
    test1.del(id);
    hide();
}
