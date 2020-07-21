#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;
#ifndef DATABASE_H
#define DATABASE_H

#endif

struct dataS
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


//    ~DataBase();



    string checkFio(string fio) //Используемые символы - только буквы; Если регистр не тот, меняем на правильный.
    {
        unsigned long long int size = fio.size();
        for(int i = 0; i < size; i++)
        {

            if((fio[i] < 65) || (fio[i] > 90 && fio[i] < 97) || (fio[i] > 122))
                 {return "false";}
        }

        if ((fio[0] > 64 && fio[0] < 91)) // Латиниица, большые буквы с 65 по 90. Маленькие с  97 по 122
            {return fio;}

        else if (fio[0] > 96 && fio[0] < 123) {
            fio[0] = fio[0] - 32;
            return fio;
        }
        else
        {return "false";}
    }

    bool checkTel(string tel)//длина строки 10 символов, все из которых цифры;
    {
        unsigned long long int size = tel.size();
        if (size !=10)
            {return false;}
        else
        {
            for(int i = 0; i < size; i++)
            {
            if(tel[i] < 48 || tel[i] > 57)
                {return false;}
            }
        }
        return true;
    }


    void add(dataS temp_data)//добавляет 1 запись
    {

        if(!temp_data.fio.empty())
        {
            temp_data.fio = checkFio(temp_data.fio);

        if(checkTel(temp_data.tel) == false)
            { temp_data.tel = "";}

            db.push_back(temp_data);
        }
    }

    void del(int temp_id)//удаляем данные с заданным id
    {
        read();
        vector<dataS> temp;
        temp.resize(db.size());

        for(int i = 0; i < db.size(); i++)
        {
            if(i != temp_id)
                {temp[i] = db[i];}
            else
                {continue;}
        }
        for(int i = 0; i < db.size(); i++)
            {db[i] = temp[i];}

        file.open("../Laba1/data.json", ios::out | ios::trunc);
        upload();
        closeFile();
    }
    void change(int id, dataS temp_data)// меняем данные с заданным id, на заданные данные temp_data
    {
        read();
        vector<dataS> temp;
        temp.resize(db.size());

        int tempid;

        for(int i = 0; i < db.size(); i++)
        {
            if(db[i].id == id)
            {
             tempid = i;
             break;
            }
        }
        for(int i = 0; i < db.size(); i++)
        {

            if(i == tempid)
                {temp[i] = temp_data;}
            else
                {temp[i] = db[i];}
        }
        for(int i = 0; i < temp.size(); i++)
            {db[i] = temp[i];}

        file.open("../Laba1//data.json", ios::out | ios::trunc);
        upload();
        closeFile();
    }




    bool read() //считывает всю БД из файла
    {
        openFile();
        download();
        closeFile();
        return true;
    }
    bool write() //запись всей БД в файл
    {
        openFile();
        upload();
        closeFile();
        return true;
    }

    bool openFile()
    {
        file.open("../Laba1/data.json", ios::in | ios::out);
        if(file.is_open())
        { return true; }
        else
        { return false; }
    }
    bool closeFile()
    {
        if(file.is_open())
        {
            file.close();
            return true;
        }
        else
        { return false; }
    }

    bool download()
    {
        //Цикл до конца файла
            //считываем данные построчно
            string line; // информация {...}
            dataS data_to_add;
            while(!file.eof())
            {
                getline(file, line, '}');
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

    dataS parsing(string line)// разбивает строку на поля
    {
        dataS temp;
        int start, end, size;
        start = line.find("fio") + 7;
        end = line.find(",") - 1;
        if(end < 0)
        { end = line.find(";") -1; }

        size = (end - start);
        temp.fio = checkFio(line.substr(start, size));

        start = line.find("tel") + 7;
        if(start > 12)
        {
            end = start + 10;
            size = (end - start);
            if(checkTel(line.substr(start, size)) == false)
            { temp.tel = ""; }
            else
            { temp.tel = line.substr(start, size);}
        }
        else
        { temp.tel = "";}
        start = line.find("date") + 8;
        end = line.find(";");
        size = (end - start) - 1;

        if(line.substr(start, size).size()!= 10)
        { temp.date = ""; }
        else
        { temp.date = line.substr(start, size);  }
        temp.id = id;
        return temp;
    }

    string data2string(dataS temp)
    {
        string tempstr;

        if(temp.tel.empty() && temp.date.empty() && temp.fio.empty())
        {return "";}
        else{
        tempstr = "{\n\t\"fio\": \"";
        tempstr.append(checkFio(temp.fio));
        if(temp.tel.empty() && temp.date.empty())
        {tempstr.append("\";\n}\n");}
        else if((!temp.tel.empty() && temp.date.empty()) && (checkTel(temp.tel) == true))
        {tempstr.append("\", \"tel\": \"");
        tempstr.append(temp.tel);
        tempstr.append("\";\n}\n");}
        else if(temp.tel.empty() && !temp.date.empty())
        {tempstr.append("\", \"date\": \"");
            tempstr.append(temp.date);
            tempstr.append("\";\n}\n");}
        else{tempstr.append("\", \"tel\": \"");
        tempstr.append(temp.tel);
        tempstr.append("\", \"date\": \"");
        tempstr.append(temp.date);
        tempstr.append("\";\n}\n");}
        return tempstr;}
}

    void upload()// записывает всю БД в файл
    {
        dataS temp;
        string temp_str;
        int size = db.size();

        for(int i = 0; i < size; i++)
        {
            temp = db[i];
            temp_str = data2string(temp);
            file << temp_str;
        }
    }

    dataS pop(int id)
    {
        return db[id];
    }
    int dbSize(){
        return db.size();
    }


private:
    int id = 0;
    vector<dataS> db;
    fstream file;

protected:

};









