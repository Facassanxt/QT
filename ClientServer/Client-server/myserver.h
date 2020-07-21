#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
#include "string"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include "QDebug"
#include <QtSql/QSqlError>
#include <qsqldriverplugin.h>
#include <qstringlist.h>
#include <QtSql>

#include <QCoreApplication>
#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QTextStream>
#include <QDataStream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <clocale>
#include <QDataStream>
#include <openssl/evp.h>
#include <openssl/aes.h>
#include <openssl/rsa.h>
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <QTextCodec>



#define BUFSIZE 1024


using namespace std;

class myserver: public QObject
{
    Q_OBJECT
public:
    explicit myserver(QObject *parent = 0); // конструктор

    QByteArray Data;
    bool mess;
    void con(QSqlDatabase db){
        db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("31.10.65.179");
        db.setDatabaseName("test");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("vmvcIPvB0K9TeMvp");
        db.setConnectOptions("MYSQL_OPT_RECONNECT=TRUE;");

        if(!db.open())
        {
            qDebug() << "Error = " << db.lastError().text();
        }
        else
        {
            qDebug() << "Open db!";
        }
    }
    string random_string( size_t length )
    {
        auto randchar = []() -> char
        {
            const char charset[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
            const size_t max_index = (sizeof(charset) - 1);
            return charset[ rand() % max_index ];
        };
        string str(length,0);
        generate_n( str.begin(), length, randchar );
        return str;
    }
    string random_char( size_t length )
    {
        auto randchar = []() -> char
        {
        const char charset[] =
        "0123456789";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
        };
    string str(length,0);
    generate_n( str.begin(), length, randchar );
    return str;
    }
    QString sendDB()
    {
        QString basa = "";
        QSqlQuery query;
        query.exec("SELECT * FROM users");
        QSqlRecord rec = query.record();
        const int idIndex = rec.indexOf("id");
        const int nameIndex = rec.indexOf("name");
        const int yearIndex = rec.indexOf("year");
        const int addressIndex = rec.indexOf("address");
        const int telIndex = rec.indexOf("tel");
        const int loginIndex = rec.indexOf("login");
        const int passwordIndex = rec.indexOf("password");
        const int accessIndex = rec.indexOf("access");
        while(query.next())
        {
            basa += query.value(idIndex).toString() + ":" +  query.value(nameIndex).toString() + ":" + query.value(yearIndex).toString() + ":" +   query.value(addressIndex).toString() +
                    ":" + query.value(telIndex).toString() + ":" +  query.value(loginIndex).toString() + ":" +  query.value(passwordIndex).toString() + ":" +  query.value(accessIndex).toString() + "$";
        }
        return basa;

    }
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
    string mesSSL(unsigned char *res, int crlen) //decryption
    {

        unsigned char *key = (unsigned char *) "0123456789abcdeF0123456789abcdeF";
        unsigned char *iv = (unsigned char *) "1234567887654321";

        unsigned char decrypt[256];

        EVP_CIPHER_CTX *ctx;

        ctx = EVP_CIPHER_CTX_new();
        EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
        int len = 0;

        EVP_DecryptUpdate(ctx, decrypt, &len, res, crlen);
        EVP_DecryptFinal_ex(ctx, decrypt + len, &len);

        string str = (char*)decrypt;
        int j = str.find("~");
        string decFinal  = str.substr(0, j);
        QString stri = QString::fromUtf8(decFinal.c_str());
        return  decFinal;
    }

    // do_crypt(encode_file, decode_file, 1); // 0 - decrypt расшифровывать, 1 - encrypt шифровать


public slots:
    void readyRead();
    void incomingConnection();
    void stateChanged(QAbstractSocket::SocketState state);

private:
    QMap<int, QTcpSocket*> SWorAuth;
    QMap<int, QTcpSocket*> SAdminAuth;
    QMap<int, QTcpSocket*> SClients;
    QTcpServer * mTcpServer;
    QList<QTcpSocket *> AdminSoc; // получатели данных
    QList<QTcpSocket *> WorSoc; // полвещ данных
    QList<QTcpSocket *> ClientSoc;



};

#endif // MYSERVER_H
