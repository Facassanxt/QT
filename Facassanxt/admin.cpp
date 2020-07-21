#include "admin.h"
#include "ui_admin.h"
#include "database.h"
#include "addperson.h"
#include "mainwindow.h"
#include "deleteperson.h"
#include "editperson.h"


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

//    DataBase test1("test");
//    test1.fileToVector();
//    test1.search("id",2);
//    test1.search("address","Moscow");
}

void Admin::on_pushButton1_clicked()
{
    DataBase test1("test");
    test1.fileToVector();
    QString qstr = QString::fromStdString(test1.TextRead());
    ui->Text->clear();
    ui->Text->append(qstr);

}

void Admin::on_pushButton2_clicked()
{

}

void Admin::on_pushButton3_clicked()
{

    QString ComboBox = ui->comboBox->currentText();
    string comboBox = ComboBox.toStdString();

    QString ComboBox_2 = ui->comboBox_2->currentText();
    string comboBox_2 = ComboBox_2.toStdString();


    QString Search = ui->Search->text();
    string search = Search.toStdString();

    QString Search_2 = ui->Search_2->text();
    string search_2 = Search_2.toStdString();

    DataBase test1("test");
    test1.fileToVector();

    QString qstr = QString::fromStdString((test1.search(comboBox, search)).ssearch(comboBox_2,search_2));
    ui->Text->clear();
    ui->Text->append(qstr);


}
