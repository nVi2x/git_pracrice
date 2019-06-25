#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 10, temp;
    cout << "Before swap: " << endl;
    cout << "a = " << a << "and b = " << b << endl;

    temp = a;
    a = b;
    b = temp;

    cout << "\nAfter swap " << endl;
    cout << "a = " << a << "and b = " << b << endl;

    int c = 15, d = 20;
    cout << "Before swap: " << endl;
    cout << "c = " << c << "and d = " << d << endl;

    c = c + d;
    d = c - d;
    c = c - d;

    cout << "\nAfter swap: " << endl;
    cout << "c = " << c << " and d = " << d << endl;

    return 0;
}