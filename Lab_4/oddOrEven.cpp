/*
@author: Michael Margolis 
@date: 06/15/2026
@purpose: This program takes an integer and returns whether it is even or odd
*/

// include the iostream library for input and output
#include <iostream>
#include <cmath>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main()
{
    // initializing variables to store the integer
    long double num = 1.7e308;

    // ask for an input of an integer number and store it in num
    cout << "What number do you want to know if it is even or odd? ";
    cin >> num;

    // decision coding starts and compares the numbers remainder after dividing by 2 is zero or not. even will be zero
    if (remainder(num,2)==0)
        cout << num << " is an even number";

    else 
        cout << num << " is an odd number";

    return 0;
}
