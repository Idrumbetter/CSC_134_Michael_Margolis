/*
@author: Michael Margolis 
@date: 06/29/2026
@purpose: This program rolls the dice
*/

// include the iostream library for input and output
#include <iostream>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main()
{
    // setting up the rand() function to generate random numbers
    srand(static_cast<unsigned int>(time(0))); 

    // initializing an integer variable for determining the number of rolls
    int rolls = 0;

    // asking the user for a number of rolls to be completed on the dies
    cout << "How many times would you like to roll the die? ";
    cin >> rolls;

    // a for loops that stores and prints the random die roll to the terminal for the number of rolls requested
    for (rolls; rolls>0; rolls--)
    {
        // random number stored in the integer variable randomNum
        int randomNum = rand() % 6 + 1;

        // prints the die roll to the terminal
        cout << "The die roll was; " << randomNum << endl;
    }
    return 0;
}