#include "third.h"
#include "ui_third.h"
#include <mainwindow.h>
#include <QJsonArray>

Third::Third(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Third)
{
    ui->setupUi(this);
}

Third::~Third()
{
    delete ui;
}

void Third::on_pushButton_3_clicked()
{
    MainWindow openFile();
    QString Username;
    QString username;
    QString Password;
    QString password;
    QFile FileJson;
    QJsonDocument doc;
    QJsonDocument docError;
    QString globPath;

    FileJson.setFileName("C:/QT/Facassanxt/person.json");
    if ( !FileJson.open(QIODevice::ReadOnly | QIODevice::Text ) )
    {
       qDebug() << "JSON IS RIP";
    }
    QJsonDocument documentJson = QJsonDocument::fromJson( FileJson.readAll() );
    QJsonObject root = documentJson.object();
    QJsonArray jsonArray = root["person"].toArray();
    foreach ( const QJsonValue & value, jsonArray )
    {
            QJsonObject obj = value.toObject();
            password = obj.value("password").toString();
            username = obj.value("username").toString();


    QFile save;
    save.setFileName("C:/QT/Facassanxt/person.json");
    if(!save.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::information(this,"Error","Path not correct");
    }

QTextStream stream(&save);
stream << ui->NewUsername->text();
stream << ui->NewPassword->text();
save.close();
qDebug() << "Ok";
    }
}
