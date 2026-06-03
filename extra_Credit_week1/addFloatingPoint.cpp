/*
@author: Michael Margolis
@date: 06/02/2026
@purpose: This program takes two numbers (can have decimals) and adds them together
*/

// include the iostream library for input and output
#include <iostream> 

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main()
{
    //defining the floats number variables
    double num1, num2, result;

    //asking user for any number and storing it in num1
    cout << "What is the first number you would like to add? ";
    cin >> num1;

    //asking user for any number and storing it in num2
    cout << "What is the second number you would like to add? ";
    cin >> num2;

    //adding the two numbers together
    result = num1 + num2;

    //printing the result to the terminal
    cout << "The sum of " << num1 << " and " << num2 << " is " << result << "!";
    
    //return statement to end the function main
    return 0;
}