/*
@date: 07/15/2026
@author: Michael Margolis
@purpose: this program prints the months to the terminal with the number of days
*/

#include <iostream>

using namespace std;

int main() {
    const int size = 12;
    int monthArray[size] = {31, 28, 31, 30, 31, 30, 31, 31, 30 , 31, 30, 31};

    for (int n=0; n<size;++n) {
        cout << "Month " << n+1 << " has " << monthArray[n] << " days.\n\n"; 
    }
}