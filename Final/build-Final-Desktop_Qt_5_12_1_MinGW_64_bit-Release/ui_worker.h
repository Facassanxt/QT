/********************************************************************************
** Form generated from reading UI file 'worker.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKER_H
#define UI_WORKER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_worker
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonEdit;
    QPushButton *pushButton2;
    QLabel *VashID;
    QTextEdit *Text;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *grounds;
    QComboBox *plants;

    void setupUi(QDialog *worker)
    {
        if (worker->objectName().isEmpty())
            worker->setObjectName(QString::fromUtf8("worker"));
        worker->resize(640, 480);
        worker->setWindowTitle(QString::fromUtf8("\320\240\320\260\320\261\320\276\321\207\320\260\321\217 \320\277\320\260\320\275\320\265\320\273\321\214"));
        gridLayout = new QGridLayout(worker);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout->setContentsMargins(-1, -1, -1, 0);
        pushButtonEdit = new QPushButton(worker);
        pushButtonEdit->setObjectName(QString::fromUtf8("pushButtonEdit"));
        pushButtonEdit->setMinimumSize(QSize(260, 80));
        pushButtonEdit->setMaximumSize(QSize(260, 80));

        verticalLayout->addWidget(pushButtonEdit);

        pushButton2 = new QPushButton(worker);
        pushButton2->setObjectName(QString::fromUtf8("pushButton2"));
        pushButton2->setMinimumSize(QSize(260, 80));
        pushButton2->setMaximumSize(QSize(260, 80));

        verticalLayout->addWidget(pushButton2);


        gridLayout->addLayout(verticalLayout, 2, 0, 4, 1);

        VashID = new QLabel(worker);
        VashID->setObjectName(QString::fromUtf8("VashID"));
        VashID->setMinimumSize(QSize(0, 0));
        VashID->setMaximumSize(QSize(600, 30));
        QFont font;
        font.setPointSize(16);
        VashID->setFont(font);
        VashID->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(VashID, 3, 1, 1, 1);

        Text = new QTextEdit(worker);
        Text->setObjectName(QString::fromUtf8("Text"));
        Text->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(Text, 5, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        grounds = new QComboBox(worker);
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

        plants = new QComboBox(worker);
        plants->addItem(QString());
        plants->addItem(QString());
        plants->addItem(QString());
        plants->setObjectName(QString::fromUtf8("plants"));

        horizontalLayout_2->addWidget(plants);


        gridLayout->addLayout(horizontalLayout_2, 4, 1, 1, 1);


        retranslateUi(worker);

        QMetaObject::connectSlotsByName(worker);
    } // setupUi

    void retranslateUi(QDialog *worker)
    {
        pushButtonEdit->setText(QApplication::translate("worker", "Edit", nullptr));
        pushButton2->setText(QApplication::translate("worker", "\320\242\320\265\321\201\321\202(\"\320\236\321\202\320\274\320\265\321\202\320\270\321\202\321\214\321\201\321\217 \320\262 \320\266\321\203\321\200\320\275\320\260\320\273\320\265 \320\277\320\276\321\201\320\265\320\262\320\260\")", nullptr));
        VashID->setText(QApplication::translate("worker", "\320\222\320\260\321\210 ID - ", nullptr));
        Text->setHtml(QApplication::translate("worker", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        grounds->setItemText(0, QApplication::translate("worker", "\320\232\321\200\320\260\321\201\320\275\320\276\320\264\320\260\321\200\321\201\320\272\320\270\320\271 \320\272\321\200\320\260\320\271", nullptr));
        grounds->setItemText(1, QApplication::translate("worker", "\320\242\321\203\320\273\321\214\321\201\320\272\320\260\321\217 \320\276\320\261\320\273\320\260\321\201\321\202\321\214", nullptr));
        grounds->setItemText(2, QApplication::translate("worker", "\320\222\320\276\320\273\320\276\320\263\320\276\320\264\321\201\320\272\320\260\321\217 \320\276\320\261\320\273\320\260\321\201\321\202\321\214", nullptr));
        grounds->setItemText(3, QApplication::translate("worker", "\320\234\320\276\321\201\320\272\320\262\320\260", nullptr));
        grounds->setItemText(4, QApplication::translate("worker", "\320\247\321\203\320\262\320\260\321\210\320\270\321\217", nullptr));
        grounds->setItemText(5, QApplication::translate("worker", "\320\240\320\276\321\201\321\202\320\276\320\262\321\201\320\272\320\260\321\217 \320\276\320\261\320\273\320\260\321\201\321\202\321\214", nullptr));
        grounds->setItemText(6, QApplication::translate("worker", "\320\222\320\273\320\260\320\264\320\270\320\274\320\270\321\200\321\201\320\272\320\260\321\217 \320\276\320\261\320\273\320\260\321\201\321\202\321\214", nullptr));
        grounds->setItemText(7, QApplication::translate("worker", "\320\221\321\200\321\217\320\275\321\201\320\272\320\260\321\217 \320\276\320\261\320\273\320\260\321\201\321\202\321\214", nullptr));
        grounds->setItemText(8, QApplication::translate("worker", "\320\241\320\260\320\274\320\260\321\200\321\201\320\272\320\260\321\217 \320\276\320\261\320\273\320\260\321\201\321\202\321\214", nullptr));

        plants->setItemText(0, QApplication::translate("worker", "\320\224\321\213\320\275\321\217", nullptr));
        plants->setItemText(1, QApplication::translate("worker", "\320\242\320\276\320\274\320\260\321\202", nullptr));
        plants->setItemText(2, QApplication::translate("worker", "\320\236\320\263\321\203\321\200\320\265\321\206", nullptr));

        Q_UNUSED(worker);
    } // retranslateUi

};

namespace Ui {
    class worker: public Ui_worker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKER_H
