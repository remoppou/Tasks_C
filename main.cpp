#include <iostream>
#include <fstream>
#include <valarray>
#include <string>
#include <list>
#include <iterator>

using namespace std;

/**
 * Methods for 1 task;
 * */
void forFirstTask(double x, double funAns,string function) {
    double y;
    cout << "Entered  f(x) =  " << function << '\n';
    cout << "Answer  f(x) =  " << funAns << '\n';
    if (x > 0) {
        y = log(x) + funAns * funAns * funAns;
    } else {
        y = 0.5 * sqrt(abs(funAns)) + sin(x);
    }
    cout << "Answer = " << y << endl;
}
/**
 * Methods for 1 task - end;
 * */

void task1_var1() { //A small transformation of the code
    double x, funAns;
    int num;
    string function, function1 = "x^2", function2("e^x"), function3{"sin(x)"}; //Unified initialization syntax
    cout << "Enter x =  "; cin >> x;
    cout << "Choose function(Enter num):" << '\n' << "1. " << function1 << '\n' << "2. " << function2 << '\n' << "3. " << function3 << '\n';
    cin >> num;
    if (num < 1 || num > 3) {
        cout << "Incorrect interval entered" << endl;
    } else {
        if (num == 1) {
            function = function1;
            funAns = x * x;
        } else if (num == 2) {
            function = function2;
            funAns = exp(x);
        } else {
            function = function3;
            funAns = sin(x);
        }
        forFirstTask(x, funAns, function);
    }
}

/**
 * Methods for 2 task
 * */
void input(double **array, int size) {
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            printf("\n Enter a[%d][%d]: ", r, c);
            cin >> array[r][c];
        }
    }
}

void output(double **array, int size) {
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            cout << array[r][c];
            cout << " ";
        }
        printf("\n");
    }
}

// Получение матрицы без i-й строки и j-го столбца
void getMatr(double **arr, double **p, int i, int j, int m) {
    int ki, kj, di, dj;
    di = 0;
    for (ki = 0; ki < m - 1; ki++) { // проверка индекса строки
        if (ki == i) di = 1;
        dj = 0;
        for (kj = 0; kj < m - 1; kj++) { // проверка индекса столбца
            if (kj == j) dj = 1;
            p[ki][kj] = arr[ki + di][kj + dj];
        }
    }
}

// Рекурсивное вычисление определителя
int determinant(double **arr, int m) {
    int i, j, d, k, n;
    double **p;
    p = new double *[m];
    for (i = 0; i < m; i++)
        p[i] = new double[m];
    j = 0;
    d = 0;
    k = 1; //(-1) в степени i
    n = m - 1;
    if (m < 1) cout << "Определитель вычислить невозможно!";
    if (m == 1) {
        d = arr[0][0];
        return d;
    }
    if (m == 2) {
        d = arr[0][0] * arr[1][1] - (arr[1][0] * arr[0][1]);
        return d;
    }
    if (m > 2) {
        for (i = 0; i < m; i++) {
            getMatr(arr, p, i, 0, m);
            d = d + k * arr[i][0] * determinant(p, n);
            k = -k;
        }
    }
    delete p;
    return d;
}

void algDop(double **arr, int m) {
    int i, j, d, k, n;
    double **p, **z;
    p = new double *[m];
    z = new double *[m];
    for (i = 0; i < m; i++) {
        p[i] = new double[m];
        z[i] = new double[m];
    }
    if (m >= 2) {
        if (m == 2) {
            for (int r = 0; r < m; r++) {
                for (int c = 0; c < m; c++) {
                    z[r][c] = pow(-1, r + c) * arr[m - r - 1][m - c - 1];
                }
            }
        }
        if (m > 2) {
            for (int r = 0; r < m; r++) {
                for (int c = 0; c < m; c++) {
                    getMatr(arr, p, r, c, m);
                    int det = determinant(p, m - 1);
                    z[r][c] = pow(-1, r + c) * det;
                    if (z[r][c] == -0) {
                        z[r][c] = 0;
                    }
                }
            }
        }
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < m; c++) {
                arr[r][c] = z[r][c];
            }
        }
    }
    delete p; delete z;
}

void transpose(double **arr, int size) {
    double t;
    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            t = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = t;
        }
    }
}

void inverceMatrix(double **arr, int size, int det) {
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            arr[r][c] = arr[r][c] / det;
        }
    }
}

/**
 * Methods for 2 task - end;
 * */

void task2_var7() { //Added several array cleanups
    int size;
    cout << "Enter size: "; cin >> size;
    cout << '\n';
    double **array;
    array = new double *[size];
    for (int r = 0; r < size; r++) {
        array[r] = new double[size];
    }
    input(array, size);
    int det = determinant(array, size);
    if (det != 0) {
        cout << "det = " << det << "\n";
        if (size > 1) {
            algDop(array, size);
            transpose(array, size);
            inverceMatrix(array, size, det);
        }
        output(array, size);
    } else {
        cout << "det = 0, => there is no inverse matrix" << "\n";
    }
    delete array;
}

/**
 * Methods for 3 task;
 * */
bool falseChars(char a) {
    if ((a == 32) || (a == 33) || (a == 40) || (a == 41) || (a == 44) || (a == 46) || (a == 63)) {
        return true;
    } else return false;
}

void sort(int calkWord, string *array) {
    string temp;
    for (int i = 0; i <= calkWord; i++) {
        for (int j = 0; j <= calkWord; j++) {
            if (array[i].size() < array[j].size()) {
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
}

/**
 * Methods for 3 task - end;
 * */

void task3_var6() {
    //read text from file
    string str;
    ifstream in("D:\\C++Projects\\C_Task8\\task3Input.txt");
    if (!in.is_open()) {
        cout << "Error of open task3Input.txt" << endl;
    } else {
        while (!in.eof()) {
            getline(in, str);
        }
    }
    in.close();
    //array with words
    int length = str.size();
    string *array = new string[length];
    string word = "";
    //splitting into words into an array
    int calkWord = -1;
    for (int i = 0; i < length; i++) {
        if (!falseChars(str[i])) {
            word += str[i];
        } else {
            if (word != "") {
                calkWord++;
                array[calkWord] = word;
                word = "";
            }
        }
    }
    //sort in array
    if (calkWord > 0) {
        sort(calkWord, array);
    }
    //write words in file
    ofstream out("D:\\C++Projects\\C_Task8\\task3Output.txt");
    if (!out.is_open()) {
        cout << "Error of open task3Output.txt" << endl;
    } else {
        for (int i = 0; i <= calkWord; i++) {
            if (i != calkWord) {
                out << array[i] << ", ";
            } else {
                out << array[i] << ".";
            }
        }
    }
    out.close();
    delete[] array;
}

/**
 * Methods for 4 task;
 * */

//param input
/*
First 200 2
Sec 154 1
Third 30 3
*/

int firstHall = 0;
int secHall = 0;
int thirdHall = 0;

struct museum {
    char *nameMuseum;
    float coast; //price
    enum workDays {
        Monday, Tuesday, Thursday, Friday, Saturday
    };
    int timeOfWork[2];//1-open;2-close
    const char *adress;
    struct workers {
        const char *name;
        int age;
    };
    workers workers[5];
    struct halls {
        struct exhibits {
            string nameEx;
            int age;
            int hall;
        };
        exhibits exhibits[3];
    };
    halls halls[3];
    struct excursions {
        const char *nameOfExc;
        float price;
    };
    excursions excursions[2];
};

museum mus;

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
    fstream file("D:\\C++Projects\\C_Task8\\task4.txt", std::ios::out | std::ios::app);
    file << '\n' << str;
    file.close();
}

void outputHall(int hallNeed) {
    int size = 0;
    if (hallNeed == 1) {
        size = firstHall;
    }
    if (hallNeed == 2) {
        size = secHall;
    }
    if (hallNeed == 3) {
        size = thirdHall;
    }
    for (int i = 0; i < size; i++) {
        cout << mus.halls[hallNeed - 1].exhibits[i].nameEx << " " << mus.halls[hallNeed - 1].exhibits[i].age << " "
             << mus.halls[hallNeed - 1].exhibits[i].hall << endl;
    }
}

/**
 * Methods for 4 task - end;
 * */

void task4_var10() {
//info about museum
    cout << "Info about museum \n";
    mus.nameMuseum = "Voronezh Museum";
    mus.coast = 100;
    mus.timeOfWork[0] = 8;
    mus.timeOfWork[1] = 14;
    mus.adress = "Plekhanovskaya str.,29";
    cout << mus.nameMuseum << ", Price:" << mus.coast << ", Open:" << mus.timeOfWork[0] << ", Close:"
         << mus.timeOfWork[1] << ", Adress:" << mus.adress << "\n";
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
    ifstream in("D:\\C++Projects\\C_Task8\\task4.txt");
    if (!in.is_open()) {
        cout << "Error of open input.txt" << endl;
    } else {
        while (!in.eof()) {
            int i = 0;
            string a;
            int age;
            int hall;
            getline(in, str);
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
    cout << "Hall 1: \n";
    outputHall(1);
    cout << "\n";
    cout << "Hall 2: \n";
    outputHall(2);
    cout << "\n";
    cout << "Hall 3: \n";
    outputHall(3);
    cout << "\n";
    cout << "Halls with new Ex: \n";
    //addNewEx
    addExp(2, "Pushkin", 100);
    addExp(3, "Roman", 300);
    //getHalls
    cout << "Hall 1: \n";
    outputHall(1);
    cout << "\n";
    cout << "Hall 2: \n";
    outputHall(2);
    cout << "\n";
    cout << "Hall 3: \n";
    outputHall(3);
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
}

/**
 * Methods for 5 task;
 * */
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

class plane : public Aircraft {
private:
    string name;
    int speed;

    void parameters() override {
        setModel(name);
        setSpeed(speed);
    }

    void show() override {
        cout << "\n--------------------------------------" << endl;
        cout << "Plane's model: " << getModel() << endl;
        cout << "Plane's speed: " << getSpeed() << endl;
        cout << "--------------------------------------" << endl;
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

    void parameters() override {
        setSpeedAndModel(name, speed);
    }

    void show() override {
        cout << "\n\n--------------------------------------" << endl;
        cout << "helicopter's model: " << getModel() << endl;
        cout << "helicopter's speed: " << getSpeed() << endl;
        cout << "--------------------------------------" << endl;
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
        cout << "\n\n--------------------------------------" << endl;
        cout << "cruise missile's model: " << getModel() << endl;
        cout << "cruise missile's speed: " << getSpeed() << endl;
        cout << "--------------------------------------" << endl;
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

/**
 * Methods for 5 task - end;
 * */

void task5_var1() {
    int choose;
    string name;
    int speed;
    cout << "Choose aircraft (1.Plane; 2.Helicopter; 3.Cruise missile): ";
    cin >> choose;
    if (choose < 1 || choose > 3) {
        cout << "Incorrect interval entered" << '\n';
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
        cruiseMissile cruiseMissile(name, speed);
        cruiseMissile.output();
    }
}

/**
 * Methods for 6 task;
 * */
class Set {
    friend void friendFunction(Set &, Set &);

private:
    list<int> set;
    list<int>::iterator it;
public:
    Set() {
    }

    void add(int a) {
        set.push_back(a);
        set.unique();
        set.sort();
    }

    void remove(int index) {
        if (index < 0 || index >= getSize()) {
            cout << "Nothing remove" << endl;
        } else {
            int i = 0;
            it = set.begin();
            while (i <= index) {
                if (i == index) {
                    set.remove(*it);
                }
                it++;
                i++;
            }
        }
    }

    void output() {
        it = set.begin();
        for (int i = 0; i < getSize(); i++) {
            if (i == set.size() - 1) {
                cout << *it << "\n";
                ++it;
            } else {
                cout << *it << ", ";
                ++it;
            }
        }
    }

    ~Set() {
        set.clear();
    }

    int getSize() {
        return set.size();
    }

    int getElement(int i) {
        it = set.begin();
        for (int k = 0; k < i; k++) {
            ++it;
        }
        return *it;
    }
};

void operator-(Set &left, Set &right) {
    int helpCalk = 0;
    int firstSize = left.getSize();
    int secSize = right.getSize();
    Set out;
    for (int i = 0; i < firstSize; i++) {
        int num1 = left.getElement(i);
        for (int j = 0; j < secSize; j++) {
            if (num1 == right.getElement(j)) {
                helpCalk++;
            }
        }
        if (helpCalk == 0) {
            out.add(num1);
        }
        helpCalk = 0;
    }
    for (int i = 0; i < out.getSize(); i++) {
        if (i == out.getSize() - 1) {
            cout << out.getElement(i) << "." << endl;
        } else {
            cout << out.getElement(i) << ", ";
        }
    }
}

void friendFunction(Set &set1, Set &set2) {
    cout << "Size first set: " << set1.getSize() << "; Size second set: " << set2.getSize() << endl;
}

void intersection(Set &set1, Set &set2) {
    Set intersection;
    for (int i = 0; i < set1.getSize(); i++) {
        for (int j = 0; j < set2.getSize(); j++) {
            if (set1.getElement(i) == set2.getElement(j)) {
                intersection.add(set1.getElement(i));
                break;
            }
        }
    }
    if (intersection.getSize() == 0) {
        cout << "No intersection" << endl;
    } else {
        intersection.output();
    }
}

/**
 * Methods for 6 task - end;
 * */

void task6_var7() {
    int choose = 0;
    bool work = true;
    Set set1;
    Set set2;
    while (work) {
        cout << "Choose action: \n" << "1. Add element; \n" << "2. Remove element; \n" << "3. Intersection; \n"
             << "4. - ;\n" << "5. Output;\n " << "6. Info about sets;\n" << "7. Exit." << endl;
        cin >> choose;
        int ch;
        int a;
        int index;
        switch (choose) {
            case 1:
                cout << "Choose set (1 or 2) :";
                cin >> ch;
                if (ch == 1) {
                    cout << "Write num: ";
                    cin >> a;
                    set1.add(a);
                } else if (ch == 2) {
                    cout << "Write num: ";
                    cin >> a;
                    set2.add(a);
                } else cout << "No Set!!!";
                break;
            case 2:
                cout << "Choose set (1 or 2) :";
                cin >> ch;
                if (ch == 1) {
                    cout << "Write index: ";
                    cin >> index;
                    set1.remove(index);
                } else if (ch == 2) {
                    cout << "Write index: ";
                    cin >> index;
                    set2.remove(index);
                } else cout << "No Set!!!";
                break;
            case 3:
                intersection(set1, set2);
                break;
            case 4:
                set1 - set2;
                break;
            case 5:
                cout << "Choose set (1 or 2) :";
                cin >> ch;
                if (ch == 1) {
                    cout << "Set1: ";
                    set1.output();
                } else if (ch == 2) {
                    cout << "Set 2: ";
                    set2.output();
                } else cout << "No Set!!!";
                break;
            case 6:
                friendFunction(set1, set2);
                break;
            case 7:
                work = false;
                break;
            default:
                cout << "Incorrect interval";
        }
    }
}

/**
 * Methods for 7 task;
 * */
template<class T>
class Set7Task {
private:
    list<T> set;
    T min;
    T max;
    int size;
    typename list<T>::iterator it;
public:
    Set7Task() {
        size = 0;
    }

    int getSize() const {
        return size;
    }

    T getElement(int i) {
        if (i <= size / 2) {
            it = set.begin();
            for (int k = 0; k < i; k++) {
                ++it;
            }
        } else {
            it = set.end();
            for (int k = size; k > i; k--) {
                --it;
            }
        }
        return *it;
    };

    void add(T a) {
        if (size == 0) {
            set.push_back(a);
            min = a;
            max = a;
            size++;
        } else {
            if (a < min) {
                set.push_front(a);
                size++;
                min = a;
            } else if (a > max) {
                set.push_back(a);
                size++;
                max = a;
            } else if (a > min && a < max) {
                it = set.begin();
                while (*it < a) {
                    it++;
                }
                if (*it != a) {
                    set.insert(it, a);
                    size++;
                }
            }
        }
    }

    void remove(T a) {
        if (a < min || a > max) {
            cout << "There are no this element!" << endl;
        } else {
            it = set.begin();
            while (*it <= a) {
                if (*it == a) {
                    set.remove(*it);
                    size--;
                }
                it++;
            }
        }
    }

    void output() {
        it = set.begin();
        for (int i = 0; i < getSize(); i++) {
            if (i == getSize() - 1) {
                cout << *it << "." << endl;
            } else {
                cout << *it << ", ";
            }
            *it++;
        }
    }

    ~Set7Task() {
        set.clear();
        size = 0;
    }
};

template<typename T>
void operator-(Set7Task<T> &left, Set7Task<T> &right) {
    int helpCalk = 0;
    int firstSize = left.getSize();
    int secSize = right.getSize();
    Set7Task<T> out;
    for (int i = 0; i < firstSize; i++) {
        T num1 = left.getElement(i);
        for (int j = 0; j < secSize; j++) {
            if (num1 == right.getElement(j)) {
                helpCalk++;
            }
        }
        if (helpCalk == 0) {
            out.add(num1);
        }
        helpCalk = 0;
    }
    out.output();
}

template<typename T>
void intersection7Task(Set7Task<T> &set1, Set7Task<T> &set2) {
    Set7Task<T> intersection;
    for (int i = 0; i < set1.getSize(); i++) {
        for (int j = 0; j < set2.getSize(); j++) {
            if (set1.getElement(i) == set2.getElement(j)) {
                intersection.add(set1.getElement(i));
                break;
            }
        }
    }
    if (intersection.getSize() == 0) {
        cout << "No intersection" << endl;
    } else {
        intersection.output();
    }
}

/**
 * Methods for 7 task - end;
 * */
void task7_var7() {
    cout << "Integer type: " << endl;
    Set7Task<int> setInt1;
    Set7Task<int> setInt2;
    setInt1.add(5);
    setInt1.add(3);
    cout << "After 2 add: ";
    setInt1.output();
    setInt1.add(2);
    setInt1.add(6);
    setInt1.add(6);
    cout << "After 5 add(I wrote 2 six): ";
    setInt1.output();
    cout << "Size: " << setInt1.getSize() << endl;
    setInt1.remove(1);
    cout << "After remove 1: ";
    setInt1.output();
    setInt1.remove(6);
    cout << "After remove 6: ";
    setInt1.output();
    setInt2.add(44);
    setInt2.add(2);
    cout << "Set2: ";
    setInt2.output();
    cout << "Operator -: ";
    setInt1 - setInt2;
    cout << "Intersection: ";
    intersection7Task(setInt1, setInt2);
    cout << "---------------------------------------------\n" << endl;
    cout << "Double type: " << endl;
    Set7Task<double> setDouble1;
    Set7Task<double> setDouble2;
    setDouble1.add(3.5);
    setDouble1.add(88.67);
    setDouble1.add(44.44);
    setDouble2.add(5.5);
    setDouble2.add(44.44);
    setDouble2.add(33.76);
    cout << "Set1: ";
    setDouble1.output();
    cout << "Set2: ";
    setDouble2.output();
    setDouble2.remove(1);
    cout << "After remove 1: ";
    setDouble2.output();
    cout << "Operator -: ";
    setDouble1 - setDouble2;
    cout << "Intersection: ";
    intersection7Task(setDouble1, setDouble2);
}


int main() {
    bool exit = true;
    int var;
    while (exit) {
        cout << "TASK 8" << endl;
        cout << "Variants of tasks: " << endl;
        cout << "1. Task1_var1(system);" << endl;
        cout << "2. Task2_var7(Inverse matrix);" << endl;
        cout << "3. Task3_var6" << endl;
        cout << "4. Task4_var10" << endl;
        cout << "5. Task5_var1" << endl;
        cout << "6. Task6_var7" << endl;
        cout << "7. Task7_var7" << endl;
        cout << "8. Exit." << endl;
        cout << "Choose task you want to run(1-7):";
        cin >> var;
        switch (var) {
            case 1:
                task1_var1();
                cout << "\n-----------------------------------" << endl;
                break;
            case 2:
                task2_var7();
                cout << "\n-----------------------------------" << endl;
                break;
            case 3:
                task3_var6();
                cout << "\n-----------------------------------" << endl;
                break;
            case 4:
                task4_var10();
                cout << "\n-----------------------------------" << endl;
                break;
            case 5:
                task5_var1();
                cout << "\n-----------------------------------" << endl;
                break;
            case 6:
                task6_var7();
                cout << "\n-----------------------------------" << endl;
                break;
            case 7:
                task7_var7();
                cout << "\n-----------------------------------" << endl;
                break;
            case 8:
                exit = false;
                break;
            default:
                cout << "Incorrect interval entered, rewrite or choose 8" << endl;
        }
    }
    return 0;
}
