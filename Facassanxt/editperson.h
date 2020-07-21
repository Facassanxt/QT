#ifndef EDITPERSON_H
#define EDITPERSON_H

#include <QDialog>

namespace Ui {
class EditPerson;
}

class EditPerson : public QDialog
{
    Q_OBJECT

public:
    explicit EditPerson(QWidget *parent = nullptr);
    ~EditPerson();

private slots:
    void on_Edit_clicked();

private:
    Ui::EditPerson *ui;
};

#endif // EDITPERSON_H
