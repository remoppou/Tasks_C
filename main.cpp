#include <iostream>
#include <valarray>
using namespace std;

int main() {
    double x; double y; int num;
    double funAns;
    string function;
    string function1 = "x^2";
    string function2 = "e^x";
    string function3 = "sin(x)";
    cout << "Enter x=  ";
    cin >> x;
    cout << "Choose function(Enter num):" << '\n' << "1. "<< function1 << '\n' << "2. "<< function2 << '\n' << "3. "<< function3 << '\n';
    cin >> num;
    switch (num) {
        case 1:
            function = function1;
            funAns = pow(x,2);
            break;
        case 2:
            function = function2;
            funAns = exp(x);
            break;
        case 3:
            function = function3;
            funAns = sin(x);
            break;
        default:
            cout << "Incorrect interval entered" << '\n';
            return 0;
    }
    cout << "Entered  f(x) =  " << function << '\n';
    cout << "Answer  f(x) =  " << funAns << '\n';
    if (x > 0) {
        y = log(x) + pow(funAns,3);
    } else {
        y = 0.5 * sqrt(abs(funAns)) + sin(x);
    }
    cout << "Answer = " << y;
    return 0;
}
