/*
@date: 07/15/2026
@author: Michael Margolis
@purpose: this program sets an array to take 10 grades and averages them
*/

// including the necessary c++ libraries
#include <iostream>
#include <iomanip>

// using the namespace to not require typing std::
using namespace std;

// starting the main function
int main() {
    // setting a constant for the size of the array
    const int SIZE = 10;
    // setting a 1D integer array
    int gradeArray[SIZE];
    // initializing a variable sum to be used 
    int sum = 0;

    // for loop to loop through each position in the array
    for (int n=0; n<SIZE;++n) {
        // printing a response prompt to the terminal and capturing the subsequent response
        cout << "Enter grade " << n+1 << ": ";
        cin >> gradeArray[n];
        cin.ignore();

        // incrementing sum by the nth position in the array
        sum += gradeArray[n];
    }

    // printing the gradpoint average with the rounding of the division to the hundredth place
    cout << "The gradepoint average was %" << fixed << setprecision(2) << sum/10.00 << endl;
    return 0;
}