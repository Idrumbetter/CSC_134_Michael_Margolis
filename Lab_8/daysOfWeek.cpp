/*
@date: 07/15/2026
@author: Michael Margolis
@purpose: this program prints the days of the week
*/

// including the iostream library from c++
#include <iostream>

// using the namespace std to remove the required std::
using namespace std;

// the start of the main function
int main() {
    // a constant variable for the size of the array set to 7
    const int SIZE = 7;
    // setting a string array and giving the initial values to be used
    string dayArray[SIZE] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    // setting a for loop to increment through the array
    for (int n=0; n<SIZE;++n) {
        // printint the stored string in position n of the array
        cout << "Day " << n+1 << ": " << dayArray[n] << endl;
    }
    return 0;
}