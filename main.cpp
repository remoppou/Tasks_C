#include <iostream>
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
    const char *nameMuseum;
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
            const char *nameEx;
            int age;
            int hall;
        };
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
    mus.nameMuseum = "Voronezh Museum";
    mus.coast = 100;
    mus.timeOfWork[0] = 8;
    mus.timeOfWork[1] = 14;
    mus.adress = "Plekhanovskaya str., 29";
    //workers
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
    //halls

    //excursion
    mus.excursions[0].nameOfExc = "History";
    mus.excursions[0].price = 100;
    mus.excursions[1].nameOfExc = "OtherName";
    mus.excursions[1].price = 400;
    return 0;
}
