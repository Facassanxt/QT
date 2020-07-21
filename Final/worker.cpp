#include "worker.h"
#include "ui_worker.h"
#include "database.h"
#include "mainwindow.h"
#include "editperson.h"


#include "QTime"
#include "QFile"
#include "QTextStream"
#include "QTimeZone"

worker::worker(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::worker)
{
    ui->setupUi(this);
}

worker::~worker()
{
    delete ui;
}

void worker::on_recieveData_clicked(long long int id)
{
    stringstream ss;
    ss << id;
    string str = ss.str();
    qstr = QString::fromStdString(str);
    ui->VashID->setText("Ваш Id - " + qstr);
}

void worker::on_pushButtonEdit_clicked()
{
    hide();
    EditPerson edit;
    edit.setModal(true);
    edit.exec();
    show();
}


void worker::on_pushButton2_clicked()
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
