/*
@author: Michael Margolis 
@date: 06/01/2026
@purpose: This program takes an integer and divides it by zero
*/

// include the iostream library for input and output
#include <iostream>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main()
{
    // declaring the variable
    int num, result;

    // Capturing the integer to be divided by zero
    cout << "What number would you like to divide by 0? ";
    cin >> num;

    // dividing by 0
    result = num / 0;

    // displaying the result
    cout << "The result of dividing " << num << " by 0 is " << result;

    return 0;

} 