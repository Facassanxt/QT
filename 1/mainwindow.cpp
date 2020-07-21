#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Password = ui->Password->text();
    Username = ui->Username->text();
   openFile();
   structure();



}
void MainWindow::on_pushButton_2_clicked()
{
    hide();
    SecondWindow window;
    window.setModal(true);
    window.exec();
    show();

}

void MainWindow::on_action_triggered()
{
    QApplication::quit();
}
