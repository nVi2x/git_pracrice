#include <iostream>
using namespace std;

int main() {
    int FirstNumber, SecondNumber, SumOfBoth;
    
    cout << "Enter two integers: ";
    cin >> FirstNumber >> SecondNumber;

    SumOfBoth = FirstNumber + SecondNumber;

    cout << "Sum of both the numbers u gave r: " << SumOfBoth;

    return 0;
}