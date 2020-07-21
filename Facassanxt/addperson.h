#ifndef ADDPERSON_H
#define ADDPERSON_H

#include <QDialog>

namespace Ui {
class AddPerson;
}

class AddPerson : public QDialog
{
    Q_OBJECT

public:
    explicit AddPerson(QWidget *parent = nullptr);
    ~AddPerson();

private slots:
    void on_Add_clicked();

private:
    Ui::AddPerson *ui;
};

#endif // ADDPERSON_H
