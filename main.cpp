#include <iostream>
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

template<class T> class Set{
private:
    T *array;
    int sizeArray;
    int numElements;
public:
    Set(int size) {
        sizeArray = size;
        array = new T[size];
        numElements = 0;
    }

    int getSize() {
        return numElements;
    }

    T getElement(int i) {
        return array[i];
    };

    void add(T a) {
        if (numElements == sizeArray) {
            cout << "Set is full!" << endl;
        } else {
            if (numElements + 1 == sizeArray) {
                cout << "Now this set has filled up" << endl;
            }
            array[numElements] = a;
            numElements++;
        }
    }

    void change(T a, int index) {
        if (index < 0 || index >= numElements) {
            cout << "Nothing change" << endl;
        } else {
            array[index] = a;
        }
    }

    void remove(int index) {
        if (index < 0 || index >= numElements) {
            cout << "Nothing remove" << endl;
        } else {
            for (; index < numElements; index++) {
                array[index] = array[index + 1];
            }
            numElements--;
        }
    }

    void output () {
        for (int i = 0; i < numElements; i++) {
            if (i == numElements - 1) {
                cout << array[i] << "." << endl;
            } else {
                cout << array[i] << ", ";
            }
        }
    }

//    ~Set() {
//        delete[] array;
//        sizeArray = 0;
//    }
};

template<typename T> void operator- (Set<T> left, Set<T> right) {
    int helpCalk = 0;
    int firstSize = left.getSize();
    int secSize = right.getSize();
    Set<T> out(firstSize);
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
    for (int i = 0; i < out.getSize(); i++) {
        if (i == out.getSize() - 1) {
            cout << out.getElement(i) << "." << endl;
        } else {
            cout << out.getElement(i)  << ", ";
        }
    }
}

template <typename T> void intersection(Set<T> set1, Set<T> set2) {
    int size1;
    int size2;
    int trueSize;
    int calk = 0;
    size1 = set1.getSize();
    size2 = set2.getSize();
    if (size1 <= size2) {
        trueSize = size1;
    } else {
        trueSize = size2;
    }
    T* array = new T [trueSize];
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2 ; j++) {
            if (set1.getElement(i) == set2.getElement(j)) {
                array[calk] = set1.getElement(i);
                calk++;
                break;
            }
        }
    }
    for (int i = 0; i < calk - 1; i++) {
        for (int j = i + 1; j < calk; j++){
            if (array [i] == array[j]) {
                for (int k = j; k < calk; k++) {
                    array[k] = array[k + 1];
                }
                calk--;
            }
        }
    }
    if (calk == 0) {
        cout << "No intersection" << endl;
    } else {
        for (int i = 0; i < calk; i++) {
            if (i == calk - 1) {
                cout << array[i] << "." << endl;
            } else {
                cout << array[i] << ", ";
            }
        }
    }
}

int main() {
    cout << "Integer type: "<< endl;
    Set<int> setInt1(5);
    Set<int> setInt2(2);
    setInt1.add(5);
    setInt1.add(3);
    cout << "After 2 add: "; setInt1.output();
    setInt1.add(2);
    setInt1.add(6);
    setInt1.add(6);
    cout << "After 5 add: ";setInt1.output();
    setInt1.change(777, 3);
    cout << "Changed 3 index: "; setInt1.output();
    cout << "Size: " << setInt1.getSize() << endl;
    setInt1.remove(4);
    cout << "After remove 4 index: "; setInt1.output();
    setInt2.add(44);
    setInt2.add(2);
    cout << "Set2 full: "; setInt2.output();
    cout << "Operator -: "; setInt1 - setInt2;
    cout << "---------------------------------------------\n"<< endl;
    cout << "Double type: "<< endl;
    Set<double> setDouble1(5);
    Set<double> setDouble2(3);
    setDouble1.add(3.5);
    setDouble1.add(88.67);
    setDouble1.add(44.44);
    setDouble2.add(5.5);
    setDouble2.add(44.44);
    setDouble2.add(33.76);
    cout << "Set 1: ";setDouble1.output();
    cout << "Set 2: ";setDouble2.output();
    setDouble2.change(4.4, 0);
    cout << "After change in set2 0 index: ";setDouble2.output();
    setDouble2.remove(2);
    cout << "Remove 2 index: ";setDouble2.output();
    cout << "Operator -: ";setDouble1 - setDouble2;
    cout << "Intersection INT: " ;intersection(setInt1, setInt2);
    cout << "Intersection Double: ";intersection(setDouble1, setDouble2);
    return 0;
}
