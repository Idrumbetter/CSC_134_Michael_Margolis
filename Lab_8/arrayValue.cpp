/*
@date: 07/15/2026
@author: Michael Margolis
@purpose: this program prints the value of an array at each position
*/

// including the required c++ libraries
#include <iostream>

// using namespace std to remove needing std:: 
using namespace std;

// the main function beginning
int main() {
    // setting a constant integer variable for the size of the Array
    const int SIZE = 7;
    // setting an integer arroay with total size SIZE and giving the initial conditions
    int array[SIZE] = {1,2,4,8};

    // printing a message for the position of the values
    cout << "The value of each position of the array are in order as such:\n";
    // setting a for loop that increments throught the array by one position
    for (int n=0; n<SIZE;++n) {
        // printing the stored value of the array for the n position
        cout << "Position " << n+1 << ": " << array[n] << endl;
    }
    return 0;
}