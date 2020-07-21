#include <QCoreApplication>
#include "QDebug"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);



    QString strPatt = "\\b[a-z]+@[a-z]+[.]+[a-z]{2.4}\\b";
    QString email = "asteblo@gmail.com";
    QRegExp rx(strPatt);


    qDebug() << (rx.exactMatch(email));


  //  QString test = "\\b[c,p]*|[cp]|[p]*\\b";
    QString test = "\\b[c,p]*+[cp]+[p]*\\b";
    QString test1 = "cppppcp";
    QRegExp test2(test);

    qDebug() << (test2.exactMatch(test1));

//    QRegExp reg("((cp)*)|(cp)|(p*)");
//    QString str("ccpppcpc");



//    qDebug() << (str.contains(reg) > 0); // true

    return a.exec();
}
