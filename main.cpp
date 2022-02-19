#include <iostream>
#include <valarray>

int main() {
    double x; double y; int num;
    double funAns;
    std::string function;
    std::string function1 = "x^2";
    std::string function2 = "e^x";
    std::string function3 = "sin(x)";
    std::cout << "Enter x=  ";
    std::cin >> x;
    std::cout << "Choose function(Enter num):" << '\n' << "1. "<< function1 << '\n' << "2. "<< function2 << '\n' << "3. "<< function3 << '\n';
    std::cin >> num;
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
        default: throw -1;
    }
    std::cout << "Entered  f(x) =  " << function << '\n';
    std::cout << "Answer  f(x) =  " << funAns << '\n';
    if (x > 0) {
        y = log(x) + pow(funAns,3);
    } else {
        y = 0.5 * sqrt(abs(funAns)) + sin(x);
    }
    std::cout << "Answer = " << y;
    return 0;
}
