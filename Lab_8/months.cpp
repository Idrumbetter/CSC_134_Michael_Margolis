/*
@date: 07/15/2026
@author: Michael Margolis
@purpose: this program prints the months to the terminal with the number of days
*/

// including the iostream library from the c++
#include <iostream>

// using the namespace std to avoid needing std::
using namespace std;

// starting the main function
int main() {
    // setting a constant variable to use for the size of the array
    const int SIZE = 12;
    // initializing an integer array and assigning the days of the month in order
    int monthArray[SIZE] = {31, 28, 31, 30, 31, 30, 31, 31, 30 , 31, 30, 31};

    // for loop to run through each position of the array
    for (int n=0; n<SIZE;++n) {
        // printing the month number and the number of days the month has
        cout << "Month " << n+1 << " has " << monthArray[n] << " days.\n\n"; 
    }
    return 0;
}