#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include <QFile>
#include <QDebug>
#include <QByteArray>
#include <QString>

namespace Ui {
class admin;
}

class admin : public QDialog
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = nullptr);
    ~admin();

//private slots:
//    void on_pushButton_clicked();

private:
    Ui::admin *ui;
};

#endif // ADMIN_H
