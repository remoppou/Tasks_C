#include <iostream>
using namespace std;

/** 1) Написать абстрактный класс «Летательный аппарат». На его основе
        реализовать классы «Самолет», «Вертолет», «Крылатая ракета» и т.п.
Написать программу, демонстрирующую работу с этими классами. */

class Aircraft {  //Abstract class, because we have clear virtual function;
private:
    string model;
    int averageSpeed;
protected:
    virtual void output() = 0;
    virtual void parameters() = 0;
    virtual void show() = 0;//clear virtual function, because the body is not defined;
    virtual void type() = 0;
    void setSpeedAndModel(string name, int speed) {
        model = name;
        averageSpeed = speed;
    }
    void setSpeedAndModel(int speed, string name) {
        model = name;
        averageSpeed = speed;
    }
    string getModel() {
        return model;
    }
    int getSpeed() {
        return averageSpeed;
    }
    void setModel(string name) {
        model = name;
    }
    void setSpeed(int speed) {
        averageSpeed = speed;
    }
};

class plane : public Aircraft  {
private:
    string name;
    int speed;

    void parameters() override {
        setModel(name);
        setSpeed(speed);
    }

    void show() override{
        cout <<"\n--------------------------------------"<<endl;
        cout << "Plane's model: " << getModel() <<endl;
        cout << "Plane's speed: " << getSpeed() <<endl;
        cout <<"--------------------------------------"<<endl;
    }

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
public:
    plane(string name1, int speed1) {
        name = name1;
        speed = speed1;
    }

    void output() override {
        parameters();
        show();
        type();
    }
};

class helicopter : public Aircraft {
private:
    string name;
    int speed;

    void parameters() override{
        setSpeedAndModel(name, speed);
    }

    void show() override{
        cout <<"\n\n--------------------------------------"<<endl;
        cout << "helicopter's model: " << getModel() <<endl;
        cout << "helicopter's speed: " << getSpeed() <<endl;
        cout <<"--------------------------------------"<<endl;
    }

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
public:
    helicopter(string name1, int speed1) {
        name = name1;
        speed = speed1;
    }

    void output() override {
        parameters();
        show();
        type();
    }
};

class cruiseMissile : public Aircraft {
private:
    string name;
    int speed;

    void parameters() override {
        setSpeedAndModel(name, speed);
    }

    void show() override {
        cout <<"\n\n--------------------------------------"<<endl;
        cout << "cruise missile's model: " << getModel() <<endl;
        cout << "cruise missile's speed: " << getSpeed() <<endl;
        cout <<"--------------------------------------"<<endl;
    }

    void type() {
        cout << "\n Type: Military" << endl;
    }
public:
    void output() override {
        parameters();
        show();
        type();
    }

    cruiseMissile(string name1, int speed1) {
        name = name1;
        speed = speed1;
    }
};

int main() {
    int choose;
    string name;
    int speed;
    cout<< "Choose aircraft (1.Plane; 2.Helicopter; 3. Cruise missile): ";
    cin >> choose;
    if (choose < 1 || choose > 3) {
        cout << "Incorrect interval entered" << '\n';
        return 0;
    } else if (choose == 1) {
        cout << "\n Enter plane's model: ";
        cin >> name;
        cout << "\n Enter plane's speed: ";
        cin >> speed;
        plane plane(name, speed);
        plane.output();
    } else if (choose == 2) {
        cout << "\n Enter helicopter's model: ";
        cin >> name;
        cout << "\n Enter helicopter's speed: ";
        cin >> speed;
        helicopter helicopter(name, speed);
        helicopter.output();
    } else {
        cout << "\n Enter cruise missile's model: ";
        cin >> name;
        cout << "\n Enter cruise missile's speed: ";
        cin >> speed;
        cruiseMissile cruiseMissile(name,speed);
        cruiseMissile.output();
    }
    return 0;
}