/********************************************************************************
** Form generated from reading UI file 'deleteperson.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEPERSON_H
#define UI_DELETEPERSON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DeletePerson
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *id;
    QPushButton *Delete;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *DeletePerson)
    {
        if (DeletePerson->objectName().isEmpty())
            DeletePerson->setObjectName(QString::fromUtf8("DeletePerson"));
        DeletePerson->resize(640, 480);
        DeletePerson->setMinimumSize(QSize(640, 480));
        DeletePerson->setMaximumSize(QSize(640, 480));
        gridLayout = new QGridLayout(DeletePerson);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(150, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(DeletePerson);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(300, 50));
        label->setMaximumSize(QSize(300, 50));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        id = new QLineEdit(DeletePerson);
        id->setObjectName(QString::fromUtf8("id"));
        id->setMinimumSize(QSize(300, 50));
        id->setMaximumSize(QSize(300, 50));
        id->setFont(font);
        id->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(id);


        verticalLayout_2->addLayout(verticalLayout);

        Delete = new QPushButton(DeletePerson);
        Delete->setObjectName(QString::fromUtf8("Delete"));
        Delete->setFont(font);

        verticalLayout_2->addWidget(Delete);


        gridLayout->addLayout(verticalLayout_2, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);


        retranslateUi(DeletePerson);

        QMetaObject::connectSlotsByName(DeletePerson);
    } // setupUi

    void retranslateUi(QDialog *DeletePerson)
    {
        DeletePerson->setWindowTitle(QApplication::translate("DeletePerson", "Dialog", nullptr));
        label->setText(QApplication::translate("DeletePerson", "ID \320\240\320\260\320\261\320\276\321\202\320\275\320\270\320\272\320\260", nullptr));
        Delete->setText(QApplication::translate("DeletePerson", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeletePerson: public Ui_DeletePerson {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEPERSON_H
