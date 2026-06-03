/*
@author: Michael Margolis
@date: 06/01/2026
@purpose: This program calculates the product of two numbers
*/

// include the iostream library for input and output
#include <iostream>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main()
{
    // declaring my variables for calculating
    int num1, num2, product;

    // asking and storing the first integer in num1 from the user
    cout << "What would you like the first whole number to be? ";
    cin >> num1;

    // asking and storing the second integer in num2 from the user
    cout << "What would you like the second whole number to be? ";
    cin >> num2;

    // calculating the product of num1 and num2
    product = num1 * num2;

    // displaying the product message to the terminal
    cout << "The product of " << num1 << " and " << num2 << " is " << product << "!" ;

    //ending the program
    return 0;
}