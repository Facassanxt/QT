#ifndef WORKER_H
#define WORKER_H

#include <QDialog>

namespace Ui {
class worker;
}

class worker : public QDialog
{
    Q_OBJECT

public:
    explicit worker(QWidget *parent = nullptr);
    ~worker();
        QString qstr;

public slots:
    void on_recieveData_clicked(long long int id);

signals: signal_worker();

private slots:
    void on_pushButtonEdit_clicked();

    void on_pushButton2_clicked();

private:
    Ui::worker *ui;
};

#endif // WORKER_H
