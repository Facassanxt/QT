#ifndef AUTORIZATION_H
#define AUTORIZATION_H

#endif // AUTORIZATION_H


#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include <iostream>
#include <QString>
#include <string>



using namespace std;



struct datastructlog
{
   int id;
   string login;
   string password;
   string status;

};


class Autorize
{

private:
    vector<datastructlog> dblog;
    fstream fulik;
    int id;


public:

    Autorize()
    {
        id = 0;
    }



    string autoriz(string login, string pas)
    {
        string temp_log, temp_pas;
        temp_log = login;
        temp_pas = pas;

        int size = dblog.size();

        for(int i = 0; i < size; i++)
        {
            if(temp_log == dblog[i].login and temp_pas == dblog[i].password)
            { return dblog[i].status; }
        }

        return "exit";

    }

    void add(datastructlog temp_data)//добавляет 1 запись
    { dblog.push_back(temp_data); }



    bool download()
    {
        string line;
        datastructlog data_to_add;
        while(!fulik.eof())
        {
            getline(fulik, line, '}');
            if(line.size() > 20)
            {
            data_to_add = parsing(line);
            data_to_add.id = id;
            add(data_to_add);
            id ++;
            }
            else break;
        }
        return true;

    }


    datastructlog parsing(string temp_line)// разбивает строку на поля
    {
        datastructlog temp_data;
        int start, end, size;

        start = temp_line.find("login") + 9;
        end = temp_line.find("password") - 4;
        size = (end - start);
        temp_data.login = temp_line.substr(start, size);

        start = temp_line.find("password") + 12;
        end = temp_line.find("status") - 4;

        size = (end - start);
        temp_data.password = temp_line.substr(start, size);


        start = temp_line.find("status") + 10;
        end = temp_line.find(";");
        size = (end - start) - 1;
        temp_data.status = temp_line.substr(start, size);

        return temp_data;
    }

    bool read() //считывает всю БД из файла
    {
        openFile();
        download();
        closeFile();
        return true;
    }

    bool openFile()
    {
        fulik.open("../Server/logins.json", ios::in | ios::out);
        if(fulik.is_open())
        {
            return true;
        }
        else
        { return false; }
    }

    bool closeFile()
    {
        if(fulik.is_open())
        {
            fulik.close();
            return true;
        }
        else
        { return false; }
    }




};
