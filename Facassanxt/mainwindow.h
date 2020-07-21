#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "admin.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
      Admin admin;

private slots:
    void on_Login_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
