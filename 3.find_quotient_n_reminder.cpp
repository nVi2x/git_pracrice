#include <iostream>
using namespace std;

int main()
{
    int divisor, dividend, quotient, remainder;
    
    cout << "Enter Dividend: ";
    cin >> dividend;

    cout << "Enter Divisor: ";
    cin >> divisor;

    quotient = dividend / divisor;
    remainder = dividend % divisor;

    cout << "The quotient is: " << quotient;
    cout << "The remainder is: " << remainder;

    return 0;

}
