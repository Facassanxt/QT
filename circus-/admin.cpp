#include "admin.h"
#include "ui_admin.h"
#include <fstream>
#include <iostream>
#include<QTableWidget>
#include<QMessageBox>
using namespace std;

admin::admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin)
{   
  ui->setupUi(this);
}

admin::~admin()
{
    delete ui;
}

