#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QByteArray>
#include "string"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include "QDebug"
#include <QtSql/QSqlError>
#include <qstringlist.h>
#include <QCoreApplication>
#include <QVariant>
#include <QDebug>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <clocale>
#include <QDataStream>
#include "QStandardItemModel"
#include "QStandardItem"
#include <openssl/evp.h>
#include <openssl/aes.h>
#include <QSortFilterProxyModel>
#include <QTextCodec>

#define BUFSIZE 1024

using namespace std;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QStandardItemModel *model = new QStandardItemModel;
    QTcpSocket* socket;
    QByteArray Data;
    int size = 9;
    QFile news;
    QString status, id;
    int do_crypt(FILE *in, FILE *out, int do_encrypt){
        unsigned char inbuf[BUFSIZE], outbuf[BUFSIZE + EVP_MAX_BLOCK_LENGTH]; //EVP_MAX_BLOCK_LENGTH = 128 бит
        int inlen, outlen;

        unsigned char key[] = "0123456789abcdeF0123456789abcdeF"; //256 бит
        unsigned char iv[] = "1234567887654321"; //128 бит

        EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();

        EVP_CipherInit_ex(ctx, EVP_aes_256_cbc(), NULL, NULL, NULL, do_encrypt);
        OPENSSL_assert(EVP_CIPHER_CTX_key_length(ctx) == 32);
        OPENSSL_assert(EVP_CIPHER_CTX_iv_length(ctx) == 16);
        EVP_CipherInit_ex(ctx, NULL, NULL, key, iv, do_encrypt);

        for(;;){
            inlen = fread(inbuf, 1, BUFSIZE, in);
            printf("%d B, In:\n", inlen);
            if (inlen <= 0) break;
            if(!EVP_CipherUpdate(ctx, outbuf, &outlen, inbuf, inlen)){
                EVP_CIPHER_CTX_free(ctx);
                return 0;
            }
            fwrite(outbuf, 1, outlen, out);
            printf("  %d B, OutU:\n", outlen);
            //printCharsAsHex(outbuf, outlen);
        }

        if(!EVP_CipherFinal_ex(ctx, outbuf, &outlen)){
            EVP_CIPHER_CTX_free(ctx);
            return 0;
        }
        fwrite(outbuf, 1, outlen, out);
        printf("  %d B, OutF:\n", outlen);
        //printCharsAsHex(outbuf, outlen);

        EVP_CIPHER_CTX_free(ctx);
        return 1;
    }
    void encrypt()
    {
        FILE *encode_file = fopen("./1", "rb");
        FILE *decode_file = fopen("./2", "wb");
        do_crypt(encode_file, decode_file, 1); // 0 - decrypt, 1 - encrypt
        fclose(encode_file);
        fclose(decode_file);

    }
    void decrypt(){
        FILE *encode_file = fopen("./2", "rb");
        FILE *decode_file = fopen("./3", "wb");
        do_crypt(encode_file, decode_file, 0); // 0 - decrypt, 1 - encrypt
        fclose(encode_file);
        fclose(decode_file);
    }
    string checkName(string name) //Используемые символы - только буквы; Если регистр не тот, меняем на правильный.
    {
        unsigned long long int size = name.size();
        for(int i = 0; i < size; i++)
        {
            if((name[i] < 65) or ((name[i] > 90) and (name[i] < 97)) or (name[i] > 122))
            {
                return "false";
            }
        }

        if((name[0] > 64 && name[0] < 91))
        {
            return name;
        }

        else if(name[0] > 96 && name[0] < 123)
        {
            name[0] = name[0] - 32;
            return name;
        }
    }

    string checkTel(string tel)
    {
        QString str = "\\b[0-9]{10}\\b";
        QString Tel =  QString::fromUtf8(tel.c_str());
        QRegExp rx(str);
        if(rx.exactMatch(Tel))
        {
           return tel;
        }
        else {
            return "false";
        }
    }
    string checkYear(string year)
    {
        QString str = "\\b[0-9]{4}\\b";
        QString Year =  QString::fromUtf8(year.c_str());
        QRegExp rx(str);
        if(rx.exactMatch(Year))
        {
           return year;
        }
        else {
            return "false";
        }
    }
    string checkId(string id)
    {
        QString str = "\\b[0-9]{1,}\\b";
        QString Id =  QString::fromUtf8(id.c_str());
        QRegExp rx(str);
        if(rx.exactMatch(Id))
        {
           return id;
        }
        else {
            return "false";
        }
    }
    void SendCrypt(QString mes)
    {

        unsigned char *key = (unsigned char *) "0123456789abcdeF0123456789abcdeF";
        unsigned char *iv = (unsigned char *) "1234567887654321";

        unsigned char out_buf[256];
        QByteArray text = mes.toLocal8Bit();
        text.append("#");
        EVP_CIPHER_CTX *ctx;
        unsigned char *ert = reinterpret_cast<unsigned char *>(text.data());
        int t = text.size();
        int k = strlen((char*)ert);

        ctx = EVP_CIPHER_CTX_new();
        EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
        int crypLen;
        int len;
        EVP_EncryptUpdate(ctx, out_buf,&len, ert, t);
        crypLen = len;
        EVP_EncryptFinal_ex(ctx, out_buf + len, &len);
        crypLen += len;

        text = QByteArray((char*)out_buf, crypLen);

        qDebug() << "decrypted text:"<< text << endl;
        socket->write(text);

    }


    // do_crypt(encode_file, decode_file, 1); // 0 - decrypt расшифровывать, 1 - encrypt шифровать


public slots:
    void sockReady();
    void sockDisc();

private slots:

    void on_LoginB_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButtonCom_clicked();

    void on_Add_clicked();

    void on_pushButtonBD_clicked();

    void on_Delete_clicked();

    void on_Edit_clicked();

    void on_up_clicked();

    void on_down_clicked();

    void on_Cancel_clicked();

    void on_filter_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
