#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <iterator>

using namespace std;

class Set {
private:
    set<string> map;
    string str;

    bool falseChars(char a) {
        if ((a == 32) || (a == 33) || (a == 40) || (a == 41) || (a == 44) || (a == 46) || (a == 63)) {
            return true;
        } else return false;
    }

    string readFromFile(string string1) {
        ifstream in(string1);
        if (!in.is_open()) {
            cout << "Error of open file " << endl;
        } else {
            while (!in.eof()) {
                getline(in, str);
            }
        }
        in.close();
        return str;
    }

public:
    Set() {};

    set<string> algorithm(string path) {
        str = readFromFile(path);
        int length = str.length();
        string word;
        for (int i = 0; i < length; i++) {
            if (!falseChars(str[i])) {
                word += str[i];
            } else {
                if (word != "") {
                    map.insert(word);
                    word = "";
                }
            }
        }
        return map;
    };

    void output() {
        copy(map.begin(), map.end(), ostream_iterator<string>(cout, " "));
    }

    ~Set() {
        map.clear();
    }
};

int main() {
    string path;
    bool check = true;
    Set mySet;
    while (check) {
        int choose;
        cout << "Choose action(if you want break, enter 3): " << endl;
        cout << "1. Add text;" << endl;
        cout << "2. Output map;" << endl;
        cout << "3. Exit;" << endl;
        cin >> choose;
        if (choose > 3 || choose < 1) {
            cout << "False interval!!!" << endl;
        } else if (choose == 1) {
            cout << "Enter path to file: " << endl;
            cin >> path;
            mySet.algorithm(path);
        } else if (choose == 2) {
            mySet.output();
            cout << endl;
        } else {
            check = false;
        }
    }
    return 0;
}
