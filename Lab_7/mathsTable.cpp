/*
@author: Michael Margolis 
@date: 07/05/2026
@purpose: This program gives the multiplication table for the numbers 1-10 by 1-10
*/

// include the iostream library for input and output
#include <iostream>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main() {
    // setting a for loop to run 10 times. This handles height
    for(int num1=1;num1<11;num1++) {
        // set a for loop to run 10 times. this handles width
        for (int num2=1;num2<11;num2++) {
            // formatting if for spacing
            if (num1*num2 < 10) {
                //print num1 times num2
                cout << num1*num2 << "     ";
            } else {
                //print num1 times num2
                cout << num1*num2 << "    ";
            }
        }
    // moves to next line for the height
    cout << "\n";
    }
    return 0;
}