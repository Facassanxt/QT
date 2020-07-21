
#include <QCoreApplication>

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

struct Test1{
    string id; //0
    string year; //2
    string name; //1
    string address; //3
};

struct Test2{
    int id;
    string year;
    string name;
    string address;
};

class DB_Test1{
private:
    string _tableName;
    vector<Test1> _db;

    void fileToVector(){
        ifstream streamF("C:\\QT\\Final\\test.txt");

        if(!streamF){exit(1);}

        while(!streamF.eof()){
            string str, token;

            getline(streamF, str); //строка
            cout << str << endl;

            Test1 item; //запись таблицы

            int k = 0;
            istringstream streamS(str);

            while(getline(streamS, token, ':')){
                //cout << token << endl; //токен
                if(k == 0) item.id = token;
                if(k == 1) item.name = token;
                if(k == 2) item.year = token;
                if(k == 3) item.address = token;
                k++;
            }

            _db.push_back(item);
        }
        //streamF.close();
    }

public:
    DB_Test1(){}

    DB_Test1(string tableName){
        _tableName = tableName;
        fileToVector();
    }

    void push_back(Test1 item){
        _db.push_back(item);
    }

    //template <typename T>
    DB_Test1 search(string k, string v){ //тип значения поля - int
        DB_Test1 select;
        for (unsigned i = 0; i < _db.size(); i++){
            Test1 item = _db.at(i);

            if(k == "id" && item.id == v){
                select.push_back(item);
                cout << item.name << ":" << item.year << endl;
            }

            if(k == "year" && item.year == v){
                select.push_back(item);
                cout << item.name << ":" << item.year << endl;
            }
            if(k == "address" && item.address == v){
                            select.push_back(item);
                           cout << item.name << ":" << item.year << endl;
                        }
        }
        return select;
    }

//    DB_Test1 search(string k, string v){ //тип значения поля - string
//        DB_Test1 select;
//        for (unsigned i = 0; i < _db.size(); i++){
//            Test1 item = _db.at(i);

//            if(k == "name" && item.name == v){
//                select.push_back(item);
//                cout << item.name << ":" << item.year << endl;
//            }

//            if(k == "address" && item.address == v){
//                select.push_back(item);
//                cout << item.name << ":" << item.year << endl;
//            }
//        }
//        return select;
//    }
};

//class DB_Test2{
//private:
//    string _tableName;
//    vector<Test2> _db;

//    void fileToVector(){
//        ifstream streamF("C:\\Users\\ELENA\\Documents\\untitled3\\" + _tableName + ".txt");

//        if(!streamF){exit(1);}

//        while(!streamF.eof()){
//            string str, token;

//            getline(streamF, str); //строка
//            cout << str << endl;

//            Test2 item; //запись таблицы

//            int k = 0;
//            istringstream streamS(str);

//            while(getline(streamS, token, ':')){
//                //cout << token << endl; //токен
//                if(k == 0) item.id = stoi(token);
//                if(k == 1) item.name = token;
//                if(k == 2) item.year = token;
//                if(k == 3) item.address = token;
//                k++;
//            }

//            _db.push_back(item);
//        }
//        //streamF.close();
//    }

//public:
//    DB_Test2(){}

//    DB_Test2(string tableName){
//        _tableName = tableName;
//        fileToVector();
//    }
//};

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);

    //############

    DB_Test1 test1("test1");
    cout << "--------" << endl;
 //   DB_Test2 test2("test1");

  test1.search("id","2");
   cout << "--------" << endl;
 (test1.search("id","2")).search("address","ala");
    cout << "########" << endl;

  (test1.search("address","Moscow").search("id","22"));
   // (test1.search("year", 2000));
  //  (test1.search("year", 2000)).search("address", "ccc");

    //############


    return a.exec();
}
