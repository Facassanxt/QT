#ifndef THIRD_H
#define THIRD_H

#include <QDialog>
#include <QMainWindow>


namespace Ui {
class Third;
}

class Third : public QDialog, public QMainWindow
{
    Q_OBJECT

public:
    explicit Third(QWidget *parent = nullptr);
    ~Third();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::Third *ui;
};

#endif // THIRD_H
