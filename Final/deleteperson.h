#ifndef DELETEPERSON_H
#define DELETEPERSON_H

#include <QDialog>

namespace Ui {
class DeletePerson;
}

class DeletePerson : public QDialog
{
    Q_OBJECT

public:
    explicit DeletePerson(QWidget *parent = nullptr);
    ~DeletePerson();

private slots:
    void on_Delete_clicked();

private:
    Ui::DeletePerson *ui;
};

#endif // DELETEPERSON_H
