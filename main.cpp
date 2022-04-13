#include <iostream>
#include <list>
#include <iterator>

using namespace std;

/**      7) Написать класс «Множество». Реализовать конструкторы,
        деструктор, методы добавления и удаления элементов, поиска пересечения
        двух множеств. Реализовать перегрузку оператора разность (-) для
        формирования разности множеств. Предложить и реализовать
        дружественную функцию для данного класса. */

class Set {
    friend void friendFunction(Set&, Set&);
private:
    list <int> set;
public:
    Set() {
        list <int> set;
    }

    int getSize() {
        return set.size();
    }

//    int getElement(int i) {
//
//    };



    void add(int a) {       //бин.поиск + сортировка + список оформить
        set.push_back(a);
        set.unique();
        set.sort();
    }

//    void change(int a, int index) {
//        if (index < 0 || index >= numElements) {
//            cout << "Nothing change" << endl;
//        } else {
//            array[index] = a;
//        }
//    }
//
//    void remove(int index) {
//        if (index < 0 || index >= numElements) {
//            cout << "Nothing remove" << endl;
//        } else {
//            for (; index < numElements; index++) {
//                array[index] = array[index + 1];
//            }
//            numElements--;
//        }
//    }
//
    void output () {
        for (int i = 0; i < set.size(); i++) {
            set[i];
        }
    }

    ~Set() {
        set.clear();
    }
};

//void operator- (Set left, Set right) {
//    int helpCalk = 0;
//    int firstSize = left.getSize();
//    int secSize = right.getSize();
//    Set out(firstSize);
//    for (int i = 0; i < firstSize; i++) {
//        int num1 = left.getElement(i);
//        for (int j = 0; j < secSize; j++){
//            if (num1 == right.getElement(j)) {
//                helpCalk++;
//            }
//        }
//        if (helpCalk == 0) {
//            out.add(num1);
//        }
//        helpCalk = 0;
//    }
//    for (int i = 0; i < out.getSize(); i++) {
//        if (i == out.getSize() - 1) {
//            cout << out.getElement(i) << "." << endl;
//        } else {
//            cout << out.getElement(i)  << ", ";
//        }
//    }
//}

void friendFunction(Set& set1, Set& set2) {
    cout << "Size first set: " << set1.getSize()  << "; Size second set: " << set2.getSize() << endl;
}

//void intersection(Set* set1, Set* set2) {
//    int size1;
//    int size2;
//    int trueSize;
//    int calk = 0;
//    size1 = set1->getSize();
//    size2 = set2->getSize();
//    if (size1 <= size2) {
//        trueSize = size1;
//    } else {
//        trueSize = size2;
//    }
//    int* array = new int [trueSize];
//    for (int i = 0; i < size1; i++) {
//        for (int j = 0; j < size2 ; j++) {
//            if (set1->getElement(i) == set2->getElement(j)) {
//                array[calk] = set1->getElement(i);
//                calk++;
//                break;
//            }
//        }
//    }
//    for (int i = 0; i < calk - 1; i++) {
//        for (int j = i + 1; j < calk; j++){
//            if (array [i] == array[j]) {
//                for (int k = j; k < calk; k++) {
//                    array[k] = array[k + 1];
//                }
//                calk--;
//            }
//        }
//    }
//    if (calk == 0) {
//        cout << "No intersection" << endl;
//    } else {
//        for (int i = 0; i < calk; i++) {
//            if (i == calk - 1) {
//                cout << array[i] << "." << endl;
//            } else {
//                cout << array[i] << ", ";
//            }
//        }
//    }
//}

int main() {
    int choose = 0;
    bool work = true;
    Set set1;
    Set set2;
    while (work) {
        cout << "Choose action: \n" << "1. Add element (while not end); \n" << "2. Remove element; \n" << "3. Change element; \n" << "4. Intersection; \n" << "5. - ;\n" <<  "6. Output;\n " << "7. Info about sets;\n"<< "8. Exit." << endl;
        cin >> choose;
        int ch;
        int a;
        int index;
        switch (choose) {
            case 1:   //add in set ();
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
            case 2:     //remove()
                cout << "Choose set (1 or 2) :";
                cin >> ch;
                if (ch == 1) {
                    cout << "Write index: ";
                    cin >> index;
//                    set1.remove(index);
                } else if (ch == 2) {
                    cout << "Write index: ";
                    cin >> index;
//                    set2.remove(index);
                } else cout << "No Set!!!";
                break;
            case 3:     //change in set();
                cout << "Choose set for change(1 or 2) :";
                cin >> ch;
                if (ch == 1) {
                    cout << "Write num: ";
                    cin >> a;
                    cout << "Write index: ";
                    cin >> index;
//                    set1.change(a, index);
                } else if (ch == 2) {
                    cout << "Write num: ";
                    cin >> a;
                    cout << "Write index: ";
                    cin >> index;
//                    set2.change(a, index);
                } else cout << "No Set!!!";
                break;
            case 4:     //Intersection()
//                intersection(&set1, &set2);
                break;
            case 5:
//                set1 - set2;
                break;
            case 6:  //Output()
                cout << "Choose set (1 or 2) :";
                cin >> ch;
                if (ch == 1) {
                    cout << "Set1: ";
//                    set1.output();
                } else if (ch == 2) {
                    cout << "Set 2: ";
//                    set2.output();
                } else cout << "No Set!!!";
                break;
            case 7:     //friend function();
//                friendFunction(set1, set2);
                break;
            case 8:     //exit(work)
                work = false;
                break;
            default:
                cout << "Incorrect interval";
                return 0;
        }
    }
    return 0;
}