#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <QDebug>

#ifndef DATABASE_H
#define DATABASE_H

#endif // DATABASE_H

using namespace std;

struct datastruct
{
    int id;
    std::string fio;
    std::string tel;
    std::string date;
};

class DataBase
{
public:

    DataBase()
    {
        id = 0;
    }

    //~DataBase();

    string checkFio(string fio) //Используемые символы - только буквы; Если регистр не тот, меняем на правильный.
    {
        unsigned long long int size = fio.size();
        cout << fio << endl;

        for(int i = 0; i < size; i++)
        {
            if((fio[i] < 65) or ((fio[i] > 90) and (fio[i] < 97)) or (fio[i] > 122))
            {
                return "";
            }
        }

        if((fio[0] > 64 && fio[0] < 91))
        {
            return fio;
        }

        else if(fio[0] > 96 && fio[0] < 123)
        {
            fio[0] = fio[0] - 32;
            return fio;
        }
    }




    bool checkTel(string tel) //Данные строки 10 символов, все из которых цифры.
    {
       unsigned long long int size = tel.size();

       if(size != 10)
       {
           return false;
       }

       else{

           for(int i = 0; i < size; i++)
           {
               if(tel[i] < 48 or tel[i] > 57)
               {
                   return false;
               }
           }
       }

       return true;
    }


    void checkDate(string date) //Тип данных  Date
    {
//        РЕАЛИЗОВАТЬ
    //        РЕАЛИЗОВАТЬ
        //        РЕАЛИЗОВАТЬ
            //        РЕАЛИЗОВАТЬ
                //        РЕАЛИЗОВАТЬ
                      //        РЕАЛИЗОВАТЬ
                            //        РЕАЛИЗОВАТЬ
                                //        РЕАЛИЗОВАТЬ
    }

    void add(datastruct temp_data) //Добавляет 1 запись
    {
        if(!temp_data.fio.empty())
        {
            temp_data.fio = checkFio(temp_data.fio);

            if(checkTel(temp_data.tel) == false)
            {
                temp_data.tel = "";
            }

            db.push_back(temp_data);
        }
    }


    void del(int temp_id) //Удаляем данные с заданным id
    {
        read();
        vector<datastruct> temp;
        temp.resize(db.size());

        for(int i = 0; i < db.size(); i++)
        {

            if(i != temp_id)
            {
                temp[i] = db[i];
            }
            else{
                continue;
            }
        }

        for(int i = 0; i < db.size(); i++)
        {
            db[i] = temp[i];
        }
        swap();
    }


    void change(int id, datastruct temp_data)
    {
        read();
        vector<datastruct> temp;
        temp.resize(db.size());

        int findid;

        for(int i = 0; i < db.size(); i++)
        {
            if(db[i].id == id)
            {
                findid = i;
                break;
            }
        }

        for(int i = 0; i < db.size(); i++)
        {
            if(i == findid)
            {
                temp[i] = temp_data;
            }
            else{
                temp[i] = db[i];
            }
        }

        for(int i = 0; i < temp.size(); i++)
        {
            db[i] = temp[i];
        }
        swap();
    }












































    bool swap()
    {
        database.open("C:/QT/Laba/person.json", ios::out | ios::trunc);
        upload();
        closeFile();
        return true;
    }

    bool read()
    {
        openFile();
        download();
        closeFile();
        return true;
    }

    bool write()
    {
        openFile();
        upload();
        closeFile();
        return true;
    }


    bool openFile()
    {
        database.open("C:/QT/Laba/person.json", ios::in | ios::out);
        if(database.is_open())
        {
            return true;
        }
        else{
            return false;
        }
    }

    bool closeFile()
    {
        if(database.is_open())
        {
            database.close();
            return true;
        }
        else{
            return false;
        }
    }

    bool download()
    {
        //Цикл ло конца файла
        // считывает данные построчно
        string line;
        datastruct data_to_add;
        while(!database.eof())
        {
            getline(database, line, '}');
            if(line.size() > 20)
            {

                data_to_add = parsing(line);
                id+=1;
                add(data_to_add);
            }
            else break;
        }
        return true;
    }

    datastruct parsing(string temp_line)
    {
        datastruct temp_data;
        int start, end, size, razmer;
        start = temp_line.find("fio") + 7;
        end = temp_line.find(",") - 1;

        if(end < 0)
        {
            end = temp_line.find(",") -1;
        }

        size = (end - start);
        temp_data.fio = checkFio(temp_line.substr(start, size));

        start = temp_line.find("tel") + 7;
        if(start > 12)
        {
            end = start + 10;
            size = (end - start);

            if(checkTel(temp_line.substr(start, size)) == false)
            {
                temp_data.tel = "";
            }
            else{
                temp_data.tel = temp_line.substr(start, size);
            }
        }
        else{
            temp_data.tel = "";
        }

        start = temp_line.find("date") +8;
        end = temp_line.find(";");
        size = (end - start) - 1;

        if(temp_line.substr(start, size).size() != 10)
        {
            temp_data.date = "";
        }
        else{
            temp_data.date = temp_line.substr(start, size);
        }
        temp_data.id = id;


        return temp_data;
    }

    string data2string(datastruct temp)
    {
        string tempstr;

        if((temp.tel.empty() and temp.date.empty()) or temp.fio.empty())
        {
            return "";
        }
        else{

            tempstr = "{\n\t\"fio\": \"";
            tempstr.append(checkFio(temp.fio));


            if(temp.tel.empty() and temp.date.empty())
            {
                tempstr.append("\";\n}\n");
            }

            else if(temp.date.empty())
            {
                tempstr.append("\", \"tel\": \"");
                tempstr.append(temp.tel);
                tempstr.append("\";\n}\n");
            }

            else if(temp.tel.empty())
            {
                tempstr.append("\", \"date\": \"");
                tempstr.append(temp.date);
                tempstr.append("\";\n}\n");
            }
            else {
                tempstr.append("\", \"tel\": \"");
                tempstr.append(temp.tel);
                tempstr.append("\", \"date\": \"");
                tempstr.append(temp.date);
                tempstr.append("\";\n}\n");
            }

            return tempstr;

        }
    }


    bool upload()
    {
        datastruct temp_data;
        string temp_str;
        int size = db.size();

        for(int i = 0; i < size; i++)
        {
            temp_data = db[i];
            temp_str = data2string(temp_data);
            database << temp_str;
        }
        return true;
    }






private:
    int id = 0;
    vector<datastruct> db;
    fstream database;



protected:

};
