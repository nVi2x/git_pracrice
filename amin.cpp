#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    srand(time(0));
    const int SIZE = 60;
    cout << "Choose a character from ur keyboard dumbass: \n";
    char x; cin >> x;
    int position = SIZE/2;

    while (true) {
        cout << "|Dev, u suck jackass :P|";
        for (int i = 0; i<SIZE;i++) {
            if (i == position)
                cout << x;
            else cout << " ";}
        cout << "|Rajdeep, u r pretty retartet :P|" << endl;

        int move = rand()%3 - 1;
        position = position + move;
        if (position <1) {cout << "Lol Dev, you really are a jackass I see..." <<endl; break;}
        if (position >SIZE-1) {cout << "Ok Raj, U really are retarted..." << endl; break;}
        for(int sleep = 0; sleep < 5000000 ; ++ sleep);
    }
    cout << "     Cool bruh were done here, type q 2 quit";
    cin >> x;
    return 0;

}