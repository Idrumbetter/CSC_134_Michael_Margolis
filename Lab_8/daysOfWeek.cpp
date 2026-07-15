/*
@date: 07/15/2026
@author: Michael Margolis
@purpose: this program prints the days of the week
*/

#include <iostream>

using namespace std;

int main() {
    const int size = 7;
    string dayArray[size] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    for (int n=0; n<size;++n) {
        cout << "Day " << n+1 << ": " << dayArray[n] << endl;
    }
}