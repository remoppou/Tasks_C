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
        char name;
        int age;
    };
    struct halls{
        struct exhibits{};
    };
    struct excursions{
        const char *nameOfExc;
        float price;
    };
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

    return 0;
}
