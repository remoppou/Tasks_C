#include <iostream>
using namespace std;

/** 1) Написать абстрактный класс «Летательный аппарат». На его основе
        реализовать классы «Самолет», «Вертолет», «Крылатая ракета» и т.п.
Написать программу, демонстрирующую работу с этими классами. */

class Aircraft {  //Abstract class, because we have clear virtual function;
protected:
    string model;
    int averageSpeed;
public:
    virtual void parameters() = 0;
    virtual void show() = 0;//clear virtual function, because the body is not defined;
    void type() {
        int choose;
        cout << "Choose type (1.Civilian; 2. Military): ";
        cin >> choose;
        switch (choose) {
            case 1:
                cout << "\n Type: Civilian" << endl;
                break;
            case 2:
                cout << "\n Type: Military" << endl;
                break;
            default:
                cout << "Incorrect interval entered" << '\n';
                break;
        }
    }
};

class plane : public Aircraft  {
public:
    void parameters() override{
        cout << "\n Enter plane's model: ";
        cin >> model;
        cout << "\n Enter plane's speed: ";
        cin >> averageSpeed;
    }
    void show() override{
        cout <<"\n--------------------------------------"<<endl;
        cout << "Plane's model: " << model <<endl;
        cout << "Plane's speed: " << averageSpeed <<endl;
        cout <<"--------------------------------------"<<endl;
    }
};

class helicopter : public Aircraft {
public:
    void parameters() override{
        cout << "\n Enter helicopter's model: ";
        cin >> model;
        cout << "\n Enter helicopter's speed: ";
        cin >> averageSpeed;
    }
    void show() override{
        cout <<"\n\n--------------------------------------"<<endl;
        cout << "helicopter's model: " << model <<endl;
        cout << "helicopter's speed: " << averageSpeed <<endl;
        cout <<"--------------------------------------"<<endl;
    }
};

class cruiseMissile : public Aircraft {
public:
    void parameters() override{
        cout << "\n Enter cruise missile's model: ";
        cin >> model;
        cout << "\n Enter cruise missile's speed: ";
        cin >> averageSpeed;
    }
    void show() override{
        cout <<"\n\n--------------------------------------"<<endl;
        cout << "cruise missile's model: " << model <<endl;
        cout << "cruise missile's speed: " << averageSpeed <<endl;
        cout <<"--------------------------------------"<<endl;
    }
};

int main() {
    int choose;
    cout<< "Choose aircraft (1.Plane; 2.Helicopter; 3. Cruise missile): ";
    cin >> choose;
    if (choose < 1 || choose > 3) {
        cout << "Incorrect interval entered" << '\n';
        return 0;
    } else if (choose == 1) {
        plane plane;
        plane.parameters();
        plane.show();
        plane.type();
    } else if (choose == 2) {
        helicopter helicopter;
        helicopter.parameters();
        helicopter.show();
        helicopter.type();
    } else {
        cruiseMissile cruiseMissile;
        cruiseMissile.parameters();
        cruiseMissile.show();
        cruiseMissile.type();
    }
    return 0;
}
