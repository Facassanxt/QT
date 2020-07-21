#include <QCoreApplication>

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

struct Data{
    int id;
    string tel; //0
    string year; //2
    string name; //1
    string address; //3
	string login;
	string password;
};

template<typename T1>
class DataBase{
private:
    int id;
    fstream streamF;
    string _tableName;
    vector<Data> _db;


    void fileToVector()
    {
        openFile();

        if(!streamF)
        {
            exit(1);
        }

        while(!streamF.eof()){//while(streamF){
            string str, token;

            getline(streamF, str); //строка
            cout << str << endl << endl;

            if(typeid(T1) == typeid(Data)){ //+проверка формата строки и ее составляющих
                Data item; //запись таблицы

                int k = 0;
                istringstream streamS(str);



                while(getline(streamS, token, ':')){
                    //cout << "#" << k << ": " << token << endl; //токен
                    cout << "#" << k << ": " << token << endl; //токен
                    if(k == 0) item.tel = token;
                    if(k == 1) item.name = token;
                    if(k == 2) item.year = token;
                    if(k == 3) item.address = token;
                    k++;
                    id++;
                }

                cout << endl;

                _db.push_back(item);

            }

        }
        //closeFile();
    }





    bool checkTel(string tel){

        if(tel.size() != 11)
        {
            return false;
        }
        else
        {
            for (unsigned long long int i = 0; i < tel.size(); i++)
            {
                if (tel[i] < 40 || tel[i] > 57)
                {
                    return false;
                }
            }
        }
        return true;
    }





    string checkName(string fio){
        unsigned long long int size = fio.size();

        cout << fio << endl;

        for (unsigned long long int i=0; i < size; i++)
        {
            if(((fio[i] < 65) || (fio[i] > 90 && fio[i] < 97) || (fio[i]) > 122))
            {
                return "";
            }

        }

        if((fio[0] > 64 && fio[0] < 91))
        {
            return fio;
        }
        else if (fio [0] > 96 && fio[0] < 123)
        {
            fio[0] = fio[0] - 32;
            return fio;
        }

        return fio;
        }


        string checkYear(string year){

            cout << year << endl;

            return year;
        }


        string  checkAddress(string address){
            unsigned long long int size = address.size();

            cout << address << endl;

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
        DataBase(){

        }

        DataBase(string tableName)
        {
            _tableName = tableName;
            fileToVector();
        }

        void push_back(T1 item){
            _db.push_back(item);

           cout << endl << item.tel << ":" << item.name << ":" << item.year << ":" << item.address << ";" << endl << endl;
        }




        template<typename T2>
        DataBase<T1> search(string k, T2 Tel){
            cout << "Enter user phone number:" << endl;
            cin >> Tel;

            DataBase<T1> select;
            for(unsigned int i = 0; i < _db.size(); i++)
            {
               T1 item = _db.at(i);
               if(k == "Tel" && item.tel == Tel){
                   select.push_back(item);
               }

            }
            return select;
          }

        void add(Data temp_data)
        {
    //        DataBase<T1> flag;
            if(!(temp_data.name.empty() && temp_data.address.empty()))
            {
                temp_data.name = checkName(temp_data.name);

                temp_data.address = checkName(temp_data.address);

                temp_data.year = checkYear(temp_data.year);

                 _db.push_back(temp_data);
            }

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

        bool skip(){
                streamF.open("C:\\GitHub\\181_352_Chikishev\\181_352_QTChikishev\\DataBaseQT\\" + _tableName +".txt", ios::out | ios::trunc);
                upload();
                closeFile();
                return true;
            }

        bool openFile()
        {
            streamF.open("C:\\GitHub\\181_352_Chikishev\\181_352_QTChikishev\\DataBaseQT\\" + _tableName +".txt", ios::in | ios::out);// указываем путь к файлу
            if (streamF.is_open())
            {
                return true;
            }
            else {
                return false;
            }

        }

        bool closeFile()
        {
            if (streamF.is_open())
            {
                streamF.close();
                return true;
            }
            else
            {
                return false;
            }

        }

        bool download()
            {
                string line;
                Data data_to_add;

                while (!streamF.eof())
                {

                    int k = 0;

                    while(getline(streamF, line, ':')){
                        if(k == 0) data_to_add.tel = line;
                        if(k == 1) data_to_add.name = line;
                        if(k == 2) data_to_add.year = line;
                        if(k == 3) data_to_add.address = line;
                        k++;
                        id++;
                       // add(data_to_add);
                    }

                    add(data_to_add);

//79164569774
                }

                return true;

            }


        bool upload(){
            Data temp_data;
            string temp_str;

            for (unsigned long long int i = 0; i < _db.size(); i++) {

               temp_data = _db[i];
                temp_str = data2string(temp_data);
               streamF << temp_str;
            }
            return true;
        }

        string data2string(Data temp){
            string temp_str;
            if(temp.name.empty() && temp.year.empty() && temp.address.empty()){
                return "";
            }else{

                temp_str.append("\n");
                if(checkTel(temp.tel) == true){
                temp_str.append(temp.tel);
                }
                temp_str.append(":");
                temp_str.append(checkName(temp.name));
                temp_str.append(":");
                temp_str.append(checkYear(temp.year));
                temp_str.append(":");
                temp_str.append(checkAddress(temp.address));
            }

            return temp_str;
        }

        void del(unsigned long long int temp_id){
               read();
               vector<Data> temp;
               temp.resize(_db.size());

               for(unsigned long long int i = 0; i < _db.size(); i++){
                   if(i != temp_id){
                       temp[i] = _db[i];
                   } else {
                       continue;
                   }
               }

               for(unsigned long long int i = 0; i < _db.size(); i++){
                   _db[i] = temp[i];
               }

               skip();

           }



    };

    int main(int argc, char *argv[])
    {
        setlocale(0, "rus");
        QCoreApplication a(argc, argv);

        DataBase<Data> test("test");

        string name, address, year, tel, token;


        cin >> token;
    while(token == "add"){
        cout << "Enter name, year, address:" << endl;
        cin >> tel >> name >> year >> address;

        Data x;
        x.tel = tel;
        x.name = name;
        x.address = address;
        x.year = year;

        DataBase<Data> obj("test");

        obj.read();
        obj.add(x);
        obj.write();

        break;

    }


    while(token == "delete"){
        cout << "Enter phone:" << endl;
        unsigned long long int id;
        cin >> id;
        DataBase<Data> obj("test");
        obj.del(id);

        break;

    }


    cin >> token;
        while (token == "search") {
             test.search("Tel", tel);
                 break;

        }



       // return a.exec();
    }
