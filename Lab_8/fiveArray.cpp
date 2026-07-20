/*
@date: 07/15/2026
@author: Michael Margolis
@purpose: this program sets an array to take 5 integers and sums them
*/

// including the iostream library from c++
#include <iostream>

// using namespace std to avoid needing std::
using namespace std;

// starting the main function
int main() {
    // initializing an integer array with assigned values for the 5 positions
    int sumArray[5] = {23, 14, 18, 16, 34};
    // setting up a variable to add the array positions values together
    int sum = 0;

    // a for loop to run through the array
    for (int n=0; n < 5;++n) {
        // increments sum by the value of array[n]
        sum += sumArray[n];
    }
    // printing the sum to the terminal
    cout << "The sum of the array is " << sum << endl;
    return 0;
}