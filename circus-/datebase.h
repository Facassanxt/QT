#include <QCoreApplication>

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include "QDir"
#include "QDebug"

#ifndef DATABASE_H
#define DATABASE_H

#endif // DATABASE_H

using namespace std;

struct datastruct
{
    string _id;
    string tel; //0
    string year; //2
    string name; //1
    string address; //3
    string login; //4
    string password; //5
    string access; //6

};

class DataBase
{

private:
    vector<datastruct> _db;
    fstream streamF;
    string _tableName;
    string shet_id;

    string checkName(string name) //Используемые символы - только буквы; Если регистр не тот, меняем на правильный.
    {
        unsigned long long int size = name.size();
        for(int i = 0; i < size; i++)
        {
            if((name[i] < 65) or ((name[i] > 90) and (name[i] < 97)) or (name[i] > 122))
            {
                return "";
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




    string checkTel(string tel) //Данные строки 10 символов, все из которых цифры.
    {
       unsigned long long int size = tel.size();

       if(size != 10)
       {
           return "";
       }

       else{

           for(int i = 0; i < size; i++)
           {
               if(tel[i] < 48 or tel[i] > 57)
               {
                   return "";
               }
           }
       }

       return tel;
    }


    string chechAccess(string access)
    {
        return access;
    }

    string checkLogin(string login)
    {

   return login;
    }

    string checkPassword(string password)
    {

   return password;
    }


    string checkDate(string year) //Тип данных  year
    {


            return year;


//        РЕАЛИЗОВАТЬ
    //        РЕАЛИЗОВАТЬ
        //        РЕАЛИЗОВАТЬ
            //        РЕАЛИЗОВАТЬ
                //        РЕАЛИЗОВАТЬ
                      //        РЕАЛИЗОВАТЬ
                            //        РЕАЛИЗОВАТЬ
                                //        РЕАЛИЗОВАТЬ
    }


            string  checkAddress(string address)
            {
            unsigned long long int size = address.size();


            for (unsigned long long int i=0; i < size; i++)
            {
                if(((address[i] < 65) || (address[i] > 90 && address[i] < 97) || (address[i]) > 122))
                {
                    return "";
                }

            }
            if((address[0] > 64 && address[0] < 91))
            {
                return address;
            }
            else if (address [0] > 96 && address[0] < 123)
            {
                address[0] = address[0] - 32;
                return address;
            }


            return address;
        }

public:
        DataBase(){}
        DataBase(string tableName)
        {
            _tableName = tableName;
        }

        void add(datastruct data_to_add)
        {
                 _db.push_back(data_to_add);
        }


    void del(string temp_id) //Удаляем данные с заданным id
    {

        fileToVector();
        vector<datastruct> temp;
        temp.resize(_db.size());
        search("id", temp_id);

        for(int i = 0; i < _db.size(); i++)
        {
            datastruct item = _db.at(i);
                if(item._id == temp_id){
                    continue;
                }
                else{
                    temp[i] = _db[i];
                }

        }

        for(int i = 0; i < _db.size(); i++)
        {
            _db[i] = temp[i];
        }
        swap();
    }

    void edit(string temp_id, datastruct temp_data) //Удаляем данные с заданным id
    {

        fileToVector();
        vector<datastruct> temp;
        temp.resize(_db.size());
        search("id", temp_id);
        for(int i = 0; i < _db.size(); i++)
        {
            datastruct item = _db.at(i);
                if(item._id == temp_id)
                {
                    temp_data._id = item._id;
                    if (temp_data.name.empty())
                    {
                        temp_data.name = item.name;
                    }
                    if (temp_data.year.empty())
                    {
                        temp_data.year = item.year;
                    }
                    if (temp_data.address.empty())
                    {
                        temp_data.address = item.address;
                    }
                    if (temp_data.tel.empty())
                    {
                        temp_data.tel = item.tel;
                    }
                    if (temp_data.login.empty())
                    {
                        temp_data.login = item.login;
                    }
                    if (temp_data.password.empty())
                    {
                        temp_data.password = item.password;
                    }
                    if (temp_data.access.empty())
                    {
                        temp_data.access = item.access;
                    }

                    temp[i] = temp_data;

                    continue;
                }
                else{
                    temp[i] = _db[i];
                }

        }

        for(int i = 0; i < _db.size(); i++)
        {
            _db[i] = temp[i];
        }
        swap();
    }


    bool swap()
    {
        streamF.open("../database.txt", ios::out | ios::trunc);
        upload();
        closeFile();
        return true;
    }

    bool closeFile()
    {
        if(streamF.is_open())
        {
            streamF.close();
            return true;
        }
        else{
            return false;
        }
    }

    string data2string(datastruct temp)
    {
        stringstream ss;
        string tempstr;
        if (temp.name != "")
        {
            if (temp._id != "")
            {
                shet_id = temp._id;
               tempstr.append(temp._id);
            }
            else
            {
                int id = stoi(shet_id);
                id++;
                ss << id;
                string str = ss.str();
                tempstr.append(str);
            }
                tempstr.append(":");
                tempstr.append(checkName(temp.name));
                tempstr.append(":");
                tempstr.append(checkDate(temp.year));
                tempstr.append(":");
                tempstr.append(checkAddress(temp.address));
                tempstr.append(":");
                tempstr.append(checkTel(temp.tel));
                tempstr.append(":");

                if (temp.login != "")
                {
                tempstr.append(checkLogin(temp.login));
                }
                else {
                    temp.login = random_string(5) + shet_id;
                    tempstr.append(checkLogin(temp.login));
                }
                tempstr.append(":");

                if (temp.password != "")
                {
                tempstr.append(checkPassword(temp.password));
                }
                else {
                    temp.password = random_char(4);
                    tempstr.append(checkLogin(temp.password));
                }
                tempstr.append(":");
                tempstr.append(chechAccess(temp.access));
                tempstr.append("\n");
        }
        return tempstr;
    }


    bool upload()
    {
        datastruct temp_data;
        string temp_str;
        for(unsigned long long int i = 0; i < _db.size(); i++)
        {
            temp_data = _db[i];
            temp_str = data2string(temp_data);
            streamF << temp_str;
        }
        return true;

    }

    string TextRead()
    {
        datastruct temp_data;
        string temp_str;
        string text;
        for(unsigned long long int i = 0; i < _db.size(); i++)
        {
            temp_data = _db[i];
            temp_str = data2string(temp_data);
            text += temp_str;
        }
        return text;
    }


    void fileToVector()
    {

        // _tableName
  //  ifstream streamF("./staff.txt");
        ifstream streamF("C:/QT/circus-/database.txt");
        //"C:\\QT\\Final\\"
       if(!streamF){exit(1);}

        while(!streamF.eof()){//while(streamF)
            {
            string str, token;
            getline(streamF, str); //строка
            cout << str << endl;

                datastruct item; //запись таблицы

                int k = 0;
                istringstream streamS(str);

                while(getline(streamS, token, ':')){
                    cout << token << endl; //токен
                    if(k == 0) item._id = token;
                    if(k == 1) item.name = token;
                    if(k == 2) item.year = token;
                    if(k == 3) item.address = token;
                    if(k == 4) item.tel = token;
                    if(k == 5) item.login = token;
                    if(k == 6) item.password = token;
                    if(k == 7) item.access = token;

                    k++;
                }

                _db.push_back(item);
            }

        }

        streamF.close();
    }


    void push_back(datastruct item){
        _db.push_back(item);
    }


    int testk;

//    DataBase search(string k, int v){ //тип значения поля - int
//        stringstream ss;
//        ss << v;
//        string str = ss.str();
//        DataBase select;
//        for (unsigned i = 0; i < _db.size(); i++){
//            datastruct item = _db.at(i);

//            if(k == "id" && item._id == str){
//                select.push_back(item);
//                cout << item.name << ":" << item.year << endl;
//                testk = stoi(item._id);
//            }

//            if(k == "year" && item.year == str){
//                select.push_back(item);
//                cout << item.name << ":" << item.year << endl;
//            }
//        }
//        return select;
//    }

string rez;

    DataBase search(string k, string v){ //тип значения поля - string
        DataBase select;
        for (unsigned i = 0; i < _db.size(); i++)
        {
            datastruct item = _db.at(i);
            if(k == "name" && item.name == v){
                select.push_back(item);
            }
            if(k == "address" && item.address == v){
                select.push_back(item);
            }
            if(k == "id" && item._id == v){
                select.push_back(item);
                testk = stoi(item._id);
            }
            if(k == "year" && item.year == v){
                select.push_back(item);
            }
            if(k == "login" && item.login == v){
                select.push_back(item);
            }
        }
        return select;
    }


    string ssearch(string k, string v){ //тип значения поля - string
        DataBase select;
        for (unsigned i = 0; i < _db.size(); i++)
        {
            datastruct item = _db.at(i);

            if(k == "name" && item.name == v){
                select.push_back(item);
                rez = rez + item._id +":"+ item.name +":"+ item.year +":"+ item.address +":"+ item.tel +":"+ item.login +":"+ item.password +":"+ item.access +"\n";
            }

            if(k == "address" && item.address == v){
                select.push_back(item);
                rez = rez + item._id +":"+ item.name +":"+ item.year +":"+ item.address +":"+ item.tel +":"+ item.login +":"+ item.password +":"+ item.access +"\n";
            }
            if(k == "id" && item._id == v){
                select.push_back(item);
                rez = rez + item._id +":"+ item.name +":"+ item.year +":"+ item.address +":"+ item.tel +":"+ item.login +":"+ item.password +":"+ item.access +"\n";
                testk = stoi(item._id);
            }

            if(k == "year" && item.year == v){
                select.push_back(item);
                rez = rez + item._id +":"+ item.name +":"+ item.year +":"+ item.address +":"+ item.tel +":"+ item.login +":"+ item.password +":"+ item.access +"\n";
            }

            if(k == "login" && item.login == v){
                select.push_back(item);
                rez = rez + item._id +":"+ item.name +":"+ item.year +":"+ item.address +":"+ item.tel +":"+ item.login +":"+ item.password +":"+ item.access +"\n";
            }
        }
        return rez;
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


    string authorization(datastruct temp_data)
    {
        string access;
            fileToVector();
            vector<datastruct> temp;
            temp.resize(_db.size());
            for(int i = 0; i < _db.size(); i++)
            {
                datastruct item = _db.at(i);
                        temp_data._id = item._id;
                        if ( temp_data.login == item.login and temp_data.password == item.password)
                        {
                            access = item._id  + ":" + item.access;
                        }

            }

            return access;
    }

};






//#ifndef DATEBASE_H
//#define DATEBASE_H

//#endif // DATEBASE_H
//#include "string"
//#include <QString>
//#include <QMessageBox>
//#include <fstream>
//#include <sstream>
//#include <cstdlib>
//#include <vector>
//#include <iostream>
//#include "authorization.h"
//using namespace std;

//struct datastruct
//{
//    string _id;
//    string tel; //0
//    string year; //2
//    string name; //1
//    string address; //3
//    string login; //4
//    string password; //5
//    string access; //6

//};

