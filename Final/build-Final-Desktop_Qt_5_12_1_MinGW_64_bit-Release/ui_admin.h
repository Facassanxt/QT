/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Admin
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonEdit;
    QPushButton *pushButtonDelete;
    QPushButton *pushButton1;
    QPushButton *pushButton2;
    QPushButton *pushButton3;
    QLabel *VashID;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *Id;
    QLineEdit *Search_Name;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QLineEdit *Search_Year;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLineEdit *Search_Address;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QLineEdit *Search_Login;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *grounds;
    QComboBox *plants;
    QTextEdit *Text;

    void setupUi(QDialog *Admin)
    {
        if (Admin->objectName().isEmpty())
            Admin->setObjectName(QString::fromUtf8("Admin"));
        Admin->setEnabled(true);
        Admin->resize(640, 480);
        Admin->setMinimumSize(QSize(640, 480));
        Admin->setMaximumSize(QSize(640, 480));
        Admin->setWindowTitle(QString::fromUtf8("\320\220\320\264\320\274\320\270\320\275 \320\277\320\260\320\275\320\265\320\273\321\214"));
        Admin->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 255, 236);"));
        gridLayout = new QGridLayout(Admin);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout->setContentsMargins(-1, -1, -1, 0);
        pushButtonAdd = new QPushButton(Admin);
        pushButtonAdd->setObjectName(QString::fromUtf8("pushButtonAdd"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonAdd->sizePolicy().hasHeightForWidth());
        pushButtonAdd->setSizePolicy(sizePolicy);
        pushButtonAdd->setMinimumSize(QSize(260, 80));
        pushButtonAdd->setMaximumSize(QSize(260, 80));
        pushButtonAdd->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(pushButtonAdd);

        pushButtonEdit = new QPushButton(Admin);
        pushButtonEdit->setObjectName(QString::fromUtf8("pushButtonEdit"));
        pushButtonEdit->setMinimumSize(QSize(260, 80));
        pushButtonEdit->setMaximumSize(QSize(260, 80));

        verticalLayout->addWidget(pushButtonEdit);

        pushButtonDelete = new QPushButton(Admin);
        pushButtonDelete->setObjectName(QString::fromUtf8("pushButtonDelete"));
        pushButtonDelete->setMinimumSize(QSize(260, 80));
        pushButtonDelete->setMaximumSize(QSize(260, 80));

        verticalLayout->addWidget(pushButtonDelete);

        pushButton1 = new QPushButton(Admin);
        pushButton1->setObjectName(QString::fromUtf8("pushButton1"));
        pushButton1->setMinimumSize(QSize(260, 80));
        pushButton1->setMaximumSize(QSize(260, 80));

        verticalLayout->addWidget(pushButton1);

        pushButton2 = new QPushButton(Admin);
        pushButton2->setObjectName(QString::fromUtf8("pushButton2"));
        pushButton2->setMinimumSize(QSize(260, 80));
        pushButton2->setMaximumSize(QSize(260, 80));

        verticalLayout->addWidget(pushButton2);

        pushButton3 = new QPushButton(Admin);
        pushButton3->setObjectName(QString::fromUtf8("pushButton3"));
        pushButton3->setMinimumSize(QSize(260, 80));
        pushButton3->setMaximumSize(QSize(260, 80));
        pushButton3->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(pushButton3);


        gridLayout->addLayout(verticalLayout, 0, 0, 4, 1);

        VashID = new QLabel(Admin);
        VashID->setObjectName(QString::fromUtf8("VashID"));
        VashID->setMinimumSize(QSize(0, 0));
        VashID->setMaximumSize(QSize(600, 30));
        QFont font;
        font.setPointSize(16);
        VashID->setFont(font);
        VashID->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(VashID, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        Id = new QLabel(Admin);
        Id->setObjectName(QString::fromUtf8("Id"));
        Id->setFont(font);

        verticalLayout_2->addWidget(Id);

        Search_Name = new QLineEdit(Admin);
        Search_Name->setObjectName(QString::fromUtf8("Search_Name"));

        verticalLayout_2->addWidget(Search_Name);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_3 = new QLabel(Admin);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        verticalLayout_4->addWidget(label_3);

        Search_Year = new QLineEdit(Admin);
        Search_Year->setObjectName(QString::fromUtf8("Search_Year"));

        verticalLayout_4->addWidget(Search_Year);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(Admin);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout_3->addWidget(label_2);

        Search_Address = new QLineEdit(Admin);
        Search_Address->setObjectName(QString::fromUtf8("Search_Address"));

        verticalLayout_3->addWidget(Search_Address);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label = new QLabel(Admin);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        verticalLayout_5->addWidget(label);

        Search_Login = new QLineEdit(Admin);
        Search_Login->setObjectName(QString::fromUtf8("Search_Login"));

        verticalLayout_5->addWidget(Search_Login);


        horizontalLayout->addLayout(verticalLayout_5);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        grounds = new QComboBox(Admin);
        grounds->addItem(QString());
        grounds->addItem(QString());
        grounds->addItem(QString());
        grounds->addItem(QString());
        grounds->addItem(QString());
        grounds->addItem(QString());
        grounds->addItem(QString());
        grounds->addItem(QString());
        grounds->addItem(QString());
        grounds->setObjectName(QString::fromUtf8("grounds"));

        horizontalLayout_2->addWidget(grounds);

        plants = new QComboBox(Admin);
        plants->addItem(QString());
        plants->addItem(QString());
        plants->addItem(QString());
        plants->setObjectName(QString::fromUtf8("plants"));

        horizontalLayout_2->addWidget(plants);


        gridLayout->addLayout(horizontalLayout_2, 2, 1, 1, 1);

        Text = new QTextEdit(Admin);
        Text->setObjectName(QString::fromUtf8("Text"));
        Text->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(Text, 3, 1, 1, 1);


        retranslateUi(Admin);

        QMetaObject::connectSlotsByName(Admin);
    } // setupUi

    void retranslateUi(QDialog *Admin)
    {
        pushButtonAdd->setText(QApplication::translate("Admin", "Add", nullptr));
        pushButtonEdit->setText(QApplication::translate("Admin", "Edit", nullptr));
        pushButtonDelete->setText(QApplication::translate("Admin", "Delete", nullptr));
        pushButton1->setText(QApplication::translate("Admin", "\320\222\321\213\320\262\320\276\320\264 DB", nullptr));
        pushButton2->setText(QApplication::translate("Admin", "\320\242\320\265\321\201\321\202(\"\320\236\321\202\320\274\320\265\321\202\320\270\321\202\321\214\321\201\321\217 \320\262 \320\266\321\203\321\200\320\275\320\260\320\273\320\265 \320\277\320\276\321\201\320\265\320\262\320\260\")", nullptr));
        pushButton3->setText(QApplication::translate("Admin", "\320\242\320\265\321\201\321\202(\"\320\237\320\276\320\270\321\201\320\272 \320\277\320\276 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\203\")", nullptr));
        VashID->setText(QApplication::translate("Admin", "\320\222\320\260\321\210 ID - ", nullptr));
        Id->setText(QApplication::translate("Admin", "Name", nullptr));
        label_3->setText(QApplication::translate("Admin", "Year", nullptr));
        label_2->setText(QApplication::translate("Admin", "Address", nullptr));
        label->setText(QApplication::translate("Admin", "Login", nullptr));
        grounds->setItemText(0, QApplication::translate("Admin", "\320\232\321\200\320\260\321\201\320\275\320\276\320\264\320\260\321\200\321\201\320\272\320\270\320\271 \320\272\321\200\320\260\320\271", nullptr));
        grounds->setItemText(1, QApplication::translate("Admin", "\320\242\321\203\320\273\321\214\321\201\320\272\320\260\321\217 \320\276\320\261\320\273\320\260\321\201\321\202\321\214", nullptr));
        grounds->setItemText(2, QApplication::translate("Admin", "\320\222\320\276\320\273\320\276\320\263\320\276\320\264\321\201\320\272\320\260\321\217 \320\276\320\261\320\273\320\260\321\201\321\202\321\214", nullptr));
        grounds->setItemText(3, QApplication::translate("Admin", "\320\234\320\276\321\201\320\272\320\262\320\260", nullptr));
        grounds->setItemText(4, QApplication::translate("Admin", "\320\247\321\203\320\262\320\260\321\210\320\270\321\217", nullptr));
        grounds->setItemText(5, QApplication::translate("Admin", "\320\240\320\276\321\201\321\202\320\276\320\262\321\201\320\272\320\260\321\217 \320\276\320\261\320\273\320\260\321\201\321\202\321\214", nullptr));
        grounds->setItemText(6, QApplication::translate("Admin", "\320\222\320\273\320\260\320\264\320\270\320\274\320\270\321\200\321\201\320\272\320\260\321\217 \320\276\320\261\320\273\320\260\321\201\321\202\321\214", nullptr));
        grounds->setItemText(7, QApplication::translate("Admin", "\320\221\321\200\321\217\320\275\321\201\320\272\320\260\321\217 \320\276\320\261\320\273\320\260\321\201\321\202\321\214", nullptr));
        grounds->setItemText(8, QApplication::translate("Admin", "\320\241\320\260\320\274\320\260\321\200\321\201\320\272\320\260\321\217 \320\276\320\261\320\273\320\260\321\201\321\202\321\214", nullptr));

        plants->setItemText(0, QApplication::translate("Admin", "\320\224\321\213\320\275\321\217", nullptr));
        plants->setItemText(1, QApplication::translate("Admin", "\320\242\320\276\320\274\320\260\321\202", nullptr));
        plants->setItemText(2, QApplication::translate("Admin", "\320\236\320\263\321\203\321\200\320\265\321\206", nullptr));

        Text->setHtml(QApplication::translate("Admin", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        Q_UNUSED(Admin);
    } // retranslateUi

};

namespace Ui {
    class Admin: public Ui_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
