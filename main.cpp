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
    list <int> set;;
public:
    Set() {
        list <int> set;
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
            int i=0;
            list<int>::iterator it = set.begin();
            while(i <= index) {
                if (i == index) {
                    set.remove(*it);
                }
                it++;
                i++;
            }
        }
    }

    void output () {
        list<int>::iterator it = set.begin();
        for(int i = 0; i < getSize(); i++){
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
        list<int>::iterator it = set.begin();
        for(int k = 0; k < i; k++){
            ++it;
        }
        return *it;
    }
};

void operator- (Set& left, Set& right) {
    int helpCalk = 0;
    int firstSize = left.getSize();
    int secSize = right.getSize();
    Set out;
    for (int i = 0; i < firstSize; i++) {
        int num1 = left.getElement(i);
        for (int j = 0; j < secSize; j++){
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
            cout << out.getElement(i)  << ", ";
        }
    }
}

void friendFunction(Set& set1, Set& set2) {
    cout << "Size first set: " << set1.getSize() << "; Size second set: " << set2.getSize() << endl;
}

void intersection(Set& set1, Set& set2) {
    Set intersection;
    for (int i = 0; i < set1.getSize(); i++) {
        for (int j = 0; j < set2.getSize() ; j++) {
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

int main() {
    int choose = 0;
    bool work = true;
    Set set1;
    Set set2;
    while (work) {
        cout << "Choose action: \n" << "1. Add element; \n" << "2. Remove element; \n" << "3. Intersection; \n" << "4. - ;\n" <<  "5. Output;\n " << "6. Info about sets;\n"<< "7. Exit." << endl;
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
                return 0;
        }
    }
    return 0;
}