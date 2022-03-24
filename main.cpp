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

struct museum{
    char *nameMuseum;
    float coast; //price
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
        exhibits exhibits;
    };
    halls halls[3];
    struct excursions{
        const char *nameOfExc;
        float price;
    };
    excursions excursions[2];
};


int main() {
    museum mus;
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
    int size = 0;
    ifstream in("D:\\C++Projects\\C_Task4_var10\\input.txt");
    if(!in.is_open()) {
        cout << "Error of open input.txt" << endl;
    } else {
        int i = 0;
        while (!in.eof()) {
            string a;
            int age;
            int hall;
            getline(in , str);
            in >> a >> age >> hall;
            switch (hall) {
                case 1:
                    in >> mus.halls[0].exhibits.nameEx >> mus.halls[0].exhibits.age >> mus.halls[0].exhibits.age;
                case 2 :
                    in >> mus.halls[1].exhibits.nameEx >> mus.halls[1].exhibits.age >> mus.halls[1].exhibits.hall;
                case 3 :
                    in >> mus.halls[2].exhibits.nameEx >> mus.halls[2].exhibits.age >> mus.halls[2].exhibits.hall;
            }
            i++;
            size++;
        }
    }
    in.close();
    cout << "\n";
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
