#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <iterator>
using namespace std;

bool falseChars(char a) {
    if ((a == 32) || (a == 33) || (a == 40) || (a == 41) || (a == 44) || (a == 46) || (a == 63)) {
        return true;
    } else return false;
}

string readFromFile(string string1, string str) {
    ifstream in(string1);
    if(!in.is_open()) {
        cout << "Error of open file " << endl;
    } else {
        while (!in.eof()) {
            getline(in, str);
        }
    }
    in.close();
    return str;
}

set<string> algorithm(set<string> set1, string& string1) {
    int length = string1.length();
    string word;
    for (int i = 0; i < length; i++) {
        if (!falseChars(string1[i])) {
            word += string1[i];
        } else {
            if (word != "") {
                set1.insert(word);
                word = "";
            }
        }
    }
    return set1;
};

void output(set<string> set1) {
    copy(set1.begin(), set1.end(), ostream_iterator<string>(cout, " "));
}

//D:\C++Projects\Task3_var6\f1.txt
int main() {
    string str;
    string path;
    bool check = true;
    set<string> set;
    while (check) {
        int choose;
        cout << "Choose action(if you want break, enter 3): " << endl;
        cout << "1. Add text;"<< endl;
        cout << "2. Output map;"<< endl;
        cout << "3. Exit;"<< endl;
        cin >> choose;
        if (choose > 3 || choose < 1) {
            cout <<"False interval!!!"<<endl;
        } else if (choose == 1){
            cout << "Enter path to file: "<< endl;
            cin >> path;
            str = readFromFile(path, str);
            set = algorithm(set, str);
        } else if (choose == 2) {
            output(set);
            cout << endl;
        } else {
            check = false;
        }
    }
    return 0;
}
