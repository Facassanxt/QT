/********************************************************************************
** Form generated from reading UI file 'editperson.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITPERSON_H
#define UI_EDITPERSON_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EditPerson
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *id;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *Name;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *Year;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *Address;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *Tel;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLineEdit *login;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLineEdit *password;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_3;
    QRadioButton *Admin;
    QRadioButton *Worker;
    QPushButton *Edit;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *EditPerson)
    {
        if (EditPerson->objectName().isEmpty())
            EditPerson->setObjectName(QString::fromUtf8("EditPerson"));
        EditPerson->resize(640, 480);
        EditPerson->setMinimumSize(QSize(640, 480));
        EditPerson->setMaximumSize(QSize(640, 480));
        gridLayout = new QGridLayout(EditPerson);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(EditPerson);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font;
        font.setPointSize(16);
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_5);

        id = new QLineEdit(EditPerson);
        id->setObjectName(QString::fromUtf8("id"));
        id->setMinimumSize(QSize(300, 50));
        id->setMaximumSize(QSize(300, 50));
        QFont font1;
        font1.setPointSize(16);
        font1.setItalic(false);
        id->setFont(font1);
        id->setContextMenuPolicy(Qt::DefaultContextMenu);
        id->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        id->setMaxLength(50);
        id->setEchoMode(QLineEdit::Normal);
        id->setAlignment(Qt::AlignCenter);
        id->setDragEnabled(false);

        horizontalLayout_5->addWidget(id);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(EditPerson);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        Name = new QLineEdit(EditPerson);
        Name->setObjectName(QString::fromUtf8("Name"));
        Name->setEnabled(true);
        Name->setMinimumSize(QSize(300, 50));
        Name->setMaximumSize(QSize(300, 50));
        Name->setFont(font1);
        Name->setCursor(QCursor(Qt::IBeamCursor));
        Name->setTabletTracking(false);
        Name->setContextMenuPolicy(Qt::DefaultContextMenu);
        Name->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        Name->setMaxLength(50);
        Name->setEchoMode(QLineEdit::Normal);
        Name->setAlignment(Qt::AlignCenter);
        Name->setDragEnabled(false);

        horizontalLayout->addWidget(Name);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(EditPerson);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        Year = new QLineEdit(EditPerson);
        Year->setObjectName(QString::fromUtf8("Year"));
        Year->setMinimumSize(QSize(300, 50));
        Year->setMaximumSize(QSize(300, 50));
        Year->setFont(font1);
        Year->setContextMenuPolicy(Qt::DefaultContextMenu);
        Year->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        Year->setMaxLength(50);
        Year->setEchoMode(QLineEdit::Normal);
        Year->setAlignment(Qt::AlignCenter);
        Year->setDragEnabled(false);

        horizontalLayout_2->addWidget(Year);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(EditPerson);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_3);

        Address = new QLineEdit(EditPerson);
        Address->setObjectName(QString::fromUtf8("Address"));
        Address->setMinimumSize(QSize(300, 50));
        Address->setMaximumSize(QSize(300, 50));
        Address->setFont(font1);
        Address->setContextMenuPolicy(Qt::DefaultContextMenu);
        Address->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        Address->setMaxLength(50);
        Address->setEchoMode(QLineEdit::Normal);
        Address->setAlignment(Qt::AlignCenter);
        Address->setDragEnabled(false);

        horizontalLayout_3->addWidget(Address);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(EditPerson);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_4);

        Tel = new QLineEdit(EditPerson);
        Tel->setObjectName(QString::fromUtf8("Tel"));
        Tel->setMinimumSize(QSize(300, 50));
        Tel->setMaximumSize(QSize(300, 50));
        Tel->setFont(font1);
        Tel->setContextMenuPolicy(Qt::DefaultContextMenu);
        Tel->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        Tel->setMaxLength(50);
        Tel->setEchoMode(QLineEdit::Normal);
        Tel->setAlignment(Qt::AlignCenter);
        Tel->setDragEnabled(false);

        horizontalLayout_4->addWidget(Tel);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(EditPerson);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_7);

        login = new QLineEdit(EditPerson);
        login->setObjectName(QString::fromUtf8("login"));
        login->setMinimumSize(QSize(300, 50));
        login->setMaximumSize(QSize(300, 50));
        login->setFont(font1);
        login->setContextMenuPolicy(Qt::DefaultContextMenu);
        login->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        login->setMaxLength(50);
        login->setEchoMode(QLineEdit::Normal);
        login->setAlignment(Qt::AlignCenter);
        login->setDragEnabled(false);

        horizontalLayout_6->addWidget(login);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_6 = new QLabel(EditPerson);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_6);

        password = new QLineEdit(EditPerson);
        password->setObjectName(QString::fromUtf8("password"));
        password->setMinimumSize(QSize(300, 50));
        password->setMaximumSize(QSize(300, 50));
        password->setFont(font1);
        password->setContextMenuPolicy(Qt::DefaultContextMenu);
        password->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        password->setMaxLength(50);
        password->setEchoMode(QLineEdit::Normal);
        password->setAlignment(Qt::AlignCenter);
        password->setDragEnabled(false);

        horizontalLayout_7->addWidget(password);


        verticalLayout->addLayout(horizontalLayout_7);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        Admin = new QRadioButton(EditPerson);
        Admin->setObjectName(QString::fromUtf8("Admin"));
        Admin->setMinimumSize(QSize(147, 0));
        Admin->setMaximumSize(QSize(147, 16777215));
        Admin->setFont(font);

        horizontalLayout_8->addWidget(Admin);

        Worker = new QRadioButton(EditPerson);
        Worker->setObjectName(QString::fromUtf8("Worker"));
        Worker->setMinimumSize(QSize(147, 0));
        Worker->setMaximumSize(QSize(147, 16777215));
        Worker->setFont(font);
        Worker->setCheckable(true);
        Worker->setChecked(false);

        horizontalLayout_8->addWidget(Worker);


        verticalLayout_2->addLayout(horizontalLayout_8);

        Edit = new QPushButton(EditPerson);
        Edit->setObjectName(QString::fromUtf8("Edit"));
        Edit->setFont(font);

        verticalLayout_2->addWidget(Edit);


        gridLayout->addLayout(verticalLayout_2, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(102, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(102, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);


        retranslateUi(EditPerson);

        QMetaObject::connectSlotsByName(EditPerson);
    } // setupUi

    void retranslateUi(QDialog *EditPerson)
    {
        EditPerson->setWindowTitle(QApplication::translate("EditPerson", "Dialog", nullptr));
        label_5->setText(QApplication::translate("EditPerson", "Id", nullptr));
        id->setText(QString());
        label->setText(QApplication::translate("EditPerson", "Name:", nullptr));
#ifndef QT_NO_STATUSTIP
        Name->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        Name->setText(QString());
        label_2->setText(QApplication::translate("EditPerson", "Year:", nullptr));
        Year->setText(QString());
        label_3->setText(QApplication::translate("EditPerson", "Address:", nullptr));
        Address->setText(QString());
        label_4->setText(QApplication::translate("EditPerson", "Tel:", nullptr));
        Tel->setText(QString());
        label_7->setText(QApplication::translate("EditPerson", "Login", nullptr));
        login->setText(QString());
        label_6->setText(QApplication::translate("EditPerson", "Password", nullptr));
        password->setText(QString());
        Admin->setText(QApplication::translate("EditPerson", "Admin", nullptr));
        Worker->setText(QApplication::translate("EditPerson", "Worker", nullptr));
        Edit->setText(QApplication::translate("EditPerson", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditPerson: public Ui_EditPerson {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITPERSON_H
