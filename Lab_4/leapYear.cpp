/*
@author: Michael Margolis 
@date: 06/15/2026
@purpose: This program takes a year input by the user and tells the user if it is a leap year or not
*/

// include the iostream library for input and output
#include <iostream>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main()
{
    // declaring a variable and assigning an initial arbitrary value
    int year = 0;

    // asking if what year the program should use
    cout << "What year would you like to test for being a leap year? ";
    cin >> year;

    // determines if the year in question qualifies for the first test of it being a leap year
    if (year % 4 == 0)
    {
        // determines if a specific criteria that can contradict with another rule is true 
        if (year % 400 == 0)
        {cout << "The year you entered " << year << " is a leap year";}
        else
        // this rule can contradict with rule two so using it as the else of the if statement
        if (year % 100 == 0)
        {cout << "Thhe year you enter " << year << " is not a leap year";}
        else
        // this means that its a leap year and it doesn't use the other two rules 
        {cout << "The year you entered " << year << "is a leap year";}
    }
    else
    // this prints because the fundamental requirement for a leap year was not met
    cout << "The year you entered " << year << "is not a leap year";
    return 0;
}