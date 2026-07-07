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
    for(int num1=1;num1<11;num1++) {
        for (int num2=1;num2<11;num2++) {
            if (num1*num2 < 10) {
                cout << num1*num2 << "     ";
            } else {
                cout << num1*num2 << "    ";
            }
        }
    cout << "\n";
    }
    return 0;
}