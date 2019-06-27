#include <iostream>
using namespace std;

char square[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,};

int checkwin();
void board();

int main()
{
        int player = 1,i,choice;

    char mark;
    do
    {
        board();
        player = (player % 2)?1:2;

        cout << "Player " << player << ", choose a slot: ";
        cin >> choice;

        mark = (player == 1)? 'x' : '0';
        
        if (choice == 1 && square[1] == '1')
            square[1] = mark;

        else if (choice == 2 && square[2] == '2')
            square[2] = 'mark';

        else if (choice == 3 && square[3] == '3')
            square[3] = 'mark';
    }
}