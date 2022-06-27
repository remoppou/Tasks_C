#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <map>

using namespace std;

/**
 * Дан текстовый файл f1, содержащий текст на английском языке.
 * Подсчитать частоту вхождений в файл каждого слова (регистр значения не
 * имеет). Результат в виде таблицы записать в файл f2
 */

bool falseChars(char a) { //Метод, для проверки на допустимые символы
    if ((a == 32) || (a == 33) || (a == 40) || (a == 41) || (a == 44) || (a == 46) || (a == 63)) {
        return true;
    } else return false;
}

int main() {
    //Чтение текста из файла
    string str;
    ifstream in("D:\\C++Projects\\Task3_var3\\f1.txt");
    if (!in.is_open()) {
        cout << "Error of open f1.txt " << endl;
    } else {
        while (!in.eof()) {
            getline(in, str);
        }
    }
    in.close();
    map <string, int> map; //map, где ключ-слово, значение-кол-во его повторений
    int length = str.size();
    string word = "";
    //splitting into words into a map
    for (int i = 0; i < length; i++) {
        if (!falseChars(str[i])) {
            word += tolower(str[i]); //tolower меняет заглавные на строчные
        } else {
            if (word != "") {
                if (map.count(word)) { //если есть в мапе, получаем ключ и меняем значение
                    int calk = map[word] + 1;
                    map[word] = calk;
                } else {
                    map[word] = 1;
                }
                word = "";
            }
        }
    }
    //запись в файл
    ofstream out("D:\\C++Projects\\Task3_var3\\f2.txt");
    if (!out.is_open()) {
        cout << "Error of open f2.txt" << endl;
    } else {
        for(auto& item : map)
        {
            out << item.first << " : " << item.second << "\n";
        }
    }
    out.close();
    map.clear();
    return 0;
}
