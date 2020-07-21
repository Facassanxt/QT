/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *Label;
    QLabel *Label_2;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *Username;
    QLineEdit *Password;
    QPushButton *Login;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(640, 480);
        MainWindow->setMinimumSize(QSize(640, 480));
        MainWindow->setMaximumSize(QSize(640, 480));
        MainWindow->setWindowTitle(QString::fromUtf8("\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217"));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 149, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(140, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(140, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(300, 150));
        groupBox->setStyleSheet(QString::fromUtf8("font: 20px;\n"
"color: rgb(211, 255, 215);"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Label = new QLabel(groupBox);
        Label->setObjectName(QString::fromUtf8("Label"));
        Label->setMinimumSize(QSize(0, 0));
        Label->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe Script\";\n"
"color: rgb(211, 255, 215);"));

        verticalLayout->addWidget(Label);

        Label_2 = new QLabel(groupBox);
        Label_2->setObjectName(QString::fromUtf8("Label_2"));
        Label_2->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe Script\";\n"
"color: rgb(211, 255, 215);"));

        verticalLayout->addWidget(Label_2);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        Username = new QLineEdit(groupBox);
        Username->setObjectName(QString::fromUtf8("Username"));
        Username->setStyleSheet(QString::fromUtf8("color:black;"));

        verticalLayout_4->addWidget(Username);

        Password = new QLineEdit(groupBox);
        Password->setObjectName(QString::fromUtf8("Password"));
        Password->setStyleSheet(QString::fromUtf8("color:black;"));
        Password->setEchoMode(QLineEdit::Password);

        verticalLayout_4->addWidget(Password);


        horizontalLayout_3->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_3);

        Login = new QPushButton(groupBox);
        Login->setObjectName(QString::fromUtf8("Login"));
        Login->setStyleSheet(QString::fromUtf8("color: black;"));

        verticalLayout_5->addWidget(Login);


        gridLayout->addLayout(verticalLayout_5, 1, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 165, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        Label->setText(QApplication::translate("MainWindow", "Username", nullptr));
        Label_2->setText(QApplication::translate("MainWindow", "Password", nullptr));
        Login->setText(QApplication::translate("MainWindow", "Login", nullptr));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
