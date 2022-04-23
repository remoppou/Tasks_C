#include <iostream>
#include <list>
#include <iterator>
using namespace std;

    /** 7) Написать класс «Множество». Реализовать конструкторы,
        деструктор, методы добавления и удаления элементов, поиска пересечения
        двух множеств. Реализовать перегрузку оператора разность (-) для
        формирования разности множеств. Предложить и реализовать
        дружественную функцию для данного класса.
        /////   определить шаблоны
        соответствующих классов. Написать тестовую программу,
        демонстрирующую работу шаблонных классов с различными типами
        данных. */


template<class T> class Set {
    private:
        list <T> set;
        T min;
        T max;
        int size;
        typename list<T>::iterator it;
    public:
        Set() {
            size = 0;
        }

        int getSize() const {
            return size;
        }

        T getElement(int i) {
            if (i <= size/2) {
                it = set.begin();
                for(int k = 0; k < i; k++){
                    ++it;
                }
            } else {
                it = set.end();
                for(int k = size; k > i; k--){
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
                while(*it <= a) {
                    if (*it == a) {
                        set.remove(*it);
                        size--;
                    }
                    it++;
                }
            }
        }

        void output () {
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

        ~Set() {
            set.clear();
            size = 0;
        }
    };

template<typename T> void operator- (Set<T>& left, Set<T>& right) {
    int helpCalk = 0;
    int firstSize = left.getSize();
    int secSize = right.getSize();
    Set<T> out;
    for (int i = 0; i < firstSize; i++) {
        T num1 = left.getElement(i);
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
    out.output();
}

template <typename T> void intersection(Set<T>& set1, Set<T>& set2) {
    Set<T> intersection;
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
    cout << "Integer type: "<< endl;
    Set<int> setInt1;
    Set<int> setInt2;
    setInt1.add(5);
    setInt1.add(3);
    cout << "After 2 add: "; setInt1.output();
    setInt1.add(2);
    setInt1.add(6);
    setInt1.add(6);
    cout << "After 5 add(I wrote 2 six): "; setInt1.output();
    cout << "Size: " << setInt1.getSize() << endl;
    setInt1.remove(1);
    cout << "After remove 1: "; setInt1.output();
    setInt1.remove(6);
    cout << "After remove 6: "; setInt1.output();
    setInt2.add(44);
    setInt2.add(2);
    cout << "Set2: "; setInt2.output();
    cout << "Operator -: "; setInt1 - setInt2;
    cout << "Intersection: "; intersection(setInt1, setInt2);
    cout << "---------------------------------------------\n"<< endl;
    cout << "Double type: "<< endl;
    Set<double> setDouble1;
    Set<double> setDouble2;
    setDouble1.add(3.5);
    setDouble1.add(88.67);
    setDouble1.add(44.44);
    setDouble2.add(5.5);
    setDouble2.add(44.44);
    setDouble2.add(33.76);
    cout << "Set1: "; setDouble1.output();
    cout << "Set2: "; setDouble2.output();
    setDouble2.remove(1);
    cout << "After remove 1: "; setDouble2.output();
    cout << "Operator -: "; setDouble1 - setDouble2;
    cout << "Intersection: "; intersection(setDouble1, setDouble2);
    return 0;
}