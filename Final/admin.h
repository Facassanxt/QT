#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>

namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();
    QString qstr;

public slots:
    void on_recieveData_clicked(long long int id);

signals: signal_admin();

private slots:

    void on_pushButtonAdd_clicked();

    void on_pushButtonEdit_clicked();

    void on_pushButtonDelete_clicked();

    void on_pushButton1_clicked();

    void on_pushButton3_clicked();

    void on_pushButton2_clicked();

private:
    Ui::Admin *ui;
};

#endif // ADMIN_H
