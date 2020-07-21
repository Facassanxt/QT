/********************************************************************************
** Form generated from reading UI file 'addperson.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPERSON_H
#define UI_ADDPERSON_H

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

class Ui_AddPerson
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
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
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QRadioButton *Admin;
    QRadioButton *Worker;
    QPushButton *Add;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *AddPerson)
    {
        if (AddPerson->objectName().isEmpty())
            AddPerson->setObjectName(QString::fromUtf8("AddPerson"));
        AddPerson->resize(640, 480);
        AddPerson->setMinimumSize(QSize(640, 480));
        AddPerson->setMaximumSize(QSize(640, 480));
        QFont font;
        font.setPointSize(16);
        AddPerson->setFont(font);
        gridLayout = new QGridLayout(AddPerson);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(AddPerson);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        Name = new QLineEdit(AddPerson);
        Name->setObjectName(QString::fromUtf8("Name"));
        Name->setEnabled(true);
        Name->setMinimumSize(QSize(300, 50));
        Name->setMaximumSize(QSize(300, 50));
        QFont font1;
        font1.setItalic(false);
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
        label_2 = new QLabel(AddPerson);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        Year = new QLineEdit(AddPerson);
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
        label_3 = new QLabel(AddPerson);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_3);

        Address = new QLineEdit(AddPerson);
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
        label_4 = new QLabel(AddPerson);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_4);

        Tel = new QLineEdit(AddPerson);
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


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        Admin = new QRadioButton(AddPerson);
        Admin->setObjectName(QString::fromUtf8("Admin"));
        Admin->setMinimumSize(QSize(147, 0));
        Admin->setMaximumSize(QSize(147, 16777215));

        horizontalLayout_5->addWidget(Admin);

        Worker = new QRadioButton(AddPerson);
        Worker->setObjectName(QString::fromUtf8("Worker"));
        Worker->setMinimumSize(QSize(147, 0));
        Worker->setMaximumSize(QSize(147, 16777215));
        Worker->setCheckable(true);
        Worker->setChecked(true);

        horizontalLayout_5->addWidget(Worker);


        verticalLayout_2->addLayout(horizontalLayout_5);

        Add = new QPushButton(AddPerson);
        Add->setObjectName(QString::fromUtf8("Add"));

        verticalLayout_2->addWidget(Add);


        gridLayout->addLayout(verticalLayout_2, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);


        retranslateUi(AddPerson);

        QMetaObject::connectSlotsByName(AddPerson);
    } // setupUi

    void retranslateUi(QDialog *AddPerson)
    {
        AddPerson->setWindowTitle(QApplication::translate("AddPerson", "Dialog", nullptr));
        label->setText(QApplication::translate("AddPerson", "Name:", nullptr));
#ifndef QT_NO_STATUSTIP
        Name->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        Name->setText(QString());
        label_2->setText(QApplication::translate("AddPerson", "Year:", nullptr));
        Year->setText(QString());
        label_3->setText(QApplication::translate("AddPerson", "Address:", nullptr));
        Address->setText(QString());
        label_4->setText(QApplication::translate("AddPerson", "Tel:", nullptr));
        Tel->setText(QString());
        Admin->setText(QApplication::translate("AddPerson", "Admin", nullptr));
        Worker->setText(QApplication::translate("AddPerson", "Worker", nullptr));
        Add->setText(QApplication::translate("AddPerson", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddPerson: public Ui_AddPerson {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPERSON_H
