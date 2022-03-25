#include <iostream>
#include <fstream>
using namespace std;

//10) Описать структуру, содержащую информацию о деятельности
//        музея. Поля структуры должны включать информацию о сотрдниках, залах,
//экспонатах, экскурсиях и т.п. Создать файл данных, содержащий сведения о
//        нескольких экспонатах. Написать программу, позволяющую добавлять
//        новые экспонаты (с сохранением данных в файл), а также выбирать и
//выводить необходимую информацию об имеющихся экспонатах на экран.
//Например, вывести список всех экспонатов второго зала. Формы запросов
//придумать самостоятельно.

////param input /*
/*
First 200 2
Sec 154 1
Third 30 3
*/

int firstHall = 0;
int secHall = 0;
int thirdHall = 0;

struct museum{
    char *nameMuseum;
    float coast; //price
    enum workDays {
        Monday, Tuesday, Thursday, Friday, Saturday
    };
    int timeOfWork[2];//1-open;2-close
    const char *adress;
    struct workers{
        const char *name;
        int age;
    };
    workers workers[5];
    struct halls{
        struct exhibits{
            string nameEx;
            int age;
            int hall;
        };
        exhibits exhibits[3];
    };
    halls halls[3];
    struct excursions{
        const char *nameOfExc;
        float price;
    };
    excursions excursions[2];
};

museum mus;
fstream in("D:\\C++Projects\\C_Task4_var10\\input.txt");

void addExp(int hall, string name, int age) {
    switch (hall) {
        case 1:
            mus.halls[0].exhibits[firstHall].nameEx = name;
            mus.halls[0].exhibits[firstHall].age = age;
            mus.halls[0].exhibits[firstHall].hall = hall;
            firstHall++;
            break;
        case 2 :
            mus.halls[1].exhibits[secHall].nameEx = name;
            mus.halls[1].exhibits[secHall].age = age;
            mus.halls[1].exhibits[secHall].hall = hall;
            secHall++;
            break;
        case 3 :
            mus.halls[2].exhibits[thirdHall].nameEx = name;
            mus.halls[2].exhibits[thirdHall].age = age;
            mus.halls[2].exhibits[thirdHall].hall = hall;
            thirdHall++;
            break;
    }
    string str = name + " " + to_string(age) + " " + to_string(hall);
    fstream file("D:\\C++Projects\\C_Task4_var10\\input.txt", std::ios::out | std::ios::app);
    file << str;
    file.close();
}

void outputHall(int hall) {
}

int main() {

    //info about museum
    cout << "Info about museum \n";
    mus.nameMuseum = "Voronezh Museum";
    mus.coast = 100;
    mus.timeOfWork[0] = 8;
    mus.timeOfWork[1] = 14;
    mus.adress = "Plekhanovskaya str.,29";
    cout << mus.nameMuseum << ", Price:" <<mus.coast << ", Open:" << mus.timeOfWork[0] << ", Close:" << mus.timeOfWork[1] << ", Adress:" << mus.adress << "\n";
    cout << "\n";
    //workers
    cout << "Info about workers \n";
    mus.workers[0].name = "Evgeny";
    mus.workers[1].name = "Olga";
    mus.workers[2].name = "Arseniy";
    mus.workers[3].name = "Vladimir";
    mus.workers[4].name = "Max";
    mus.workers[0].age = 25;
    mus.workers[1].age = 30;
    mus.workers[2].age = 48;
    mus.workers[3].age = 57;
    mus.workers[4].age = 29;
    for (int w = 0; w < 5; w++) {
        cout << mus.workers[w].name << ", Age:" << mus.workers[w].age << "\n";
    }
    cout << "\n";
    cout << "Info about halls \n";
    //halls
    string str;
    if(!in.is_open()) {
        cout << "Error of open input.txt" << endl;
    } else {
        while (!in.eof()) {
            int i = 0;
            string a;
            int age;
            int hall;
            getline(in , str);
            for (int s = 0; s < 3; s++) {
                string word;
                while (str[i] != ' ' && i < str.length()) {
                    word += str[i];
                    i++;
                }
                i++;
                if (s == 0) {
                    a = word;
                } else if (s == 1) {
                    age = stoi(word);
                } else if (s == 2) {
                    hall = stoi(word);
                }
                word = "";
            }
            switch (hall) {
                case 1:
                    mus.halls[0].exhibits[firstHall].nameEx = a;
                    mus.halls[0].exhibits[firstHall].age = age;
                    mus.halls[0].exhibits[firstHall].hall = hall;
                    firstHall++;
                    break;
                case 2 :
                    mus.halls[1].exhibits[secHall].nameEx = a;
                    mus.halls[1].exhibits[secHall].age = age;
                    mus.halls[1].exhibits[secHall].hall = hall;
                    secHall++;
                    break;
                case 3 :
                    mus.halls[2].exhibits[thirdHall].nameEx = a;
                    mus.halls[2].exhibits[thirdHall].age = age;
                    mus.halls[2].exhibits[thirdHall].hall = hall;
                    thirdHall++;
                    break;
            }
        }
    }
    in.close();
    cout << "\n";
    //addNewEx
    addExp(2, "Pushkin", 100);
    //getHalls

    //excursion
    cout << "Info about excursions \n";
    mus.excursions[0].nameOfExc = "History";
    mus.excursions[0].price = 100;
    mus.excursions[1].nameOfExc = "OtherName";
    mus.excursions[1].price = 400;
    for (int e = 0; e < 2; e++) {
        cout << mus.excursions[e].nameOfExc << ", Price:" << mus.excursions[e].price << "\n";
    }
    return 0;
}
