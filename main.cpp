#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Дан текстовый файл f1, содержащий текст на английском языке.
//Отсортировать слова по возрастанию длины и полученный результат
//записать в файл f2.

bool falseChars(char a) {
    if ((a == 32) || (a == 33) || (a == 40) || (a == 41) || (a == 44) || (a == 46) || (a == 63)) {
        return true;
    } else return false;
}

void sort(int calkWord, string* array) {
    string temp;
    for (int i = 0; i <= calkWord; i++) {
        for (int j = 0; j <= calkWord; j++){
            if (array[i].size() < array[j].size()) {
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
}

int main() {
    //read text from file
    string str;
    ifstream in("D:\\C++Projects\\Task3_var6\\f1.txt");
    if(!in.is_open()) {
        cout << "Error of open f1.txt " << endl;
    } else {
        while (!in.eof()) {
            getline(in, str);
        }
    }
    in.close();
    //array with words
    int length = str.size();
    string* array = new string[length];
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
    ofstream out("D:\\C++Projects\\Task3_var6\\f2.txt");
    if(!out.is_open()) {
        cout << "Ошибка открытия файла out.txt" << endl;
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
    return 0;
}
