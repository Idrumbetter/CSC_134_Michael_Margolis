/*
@author: Michael Margolis 
@date: 06/29/2026
@purpose: This program gives the multiplication table for the users number
*/

// include the iostream library for input and output
#include <iostream>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main()
{
    // initializing an integer variable and gives it an initial value of  0
    int userNum = 0;

    // asks the user for an integer number to be
    cout << "What Number would you like the multiplication table for? ";
    cin >> userNum;

    // print a table header for the multiplication table
    cout << "\nmultiplier |  " << userNum << endl;

    // for loop printing the input number multiplied by the index number 
    for (int n = 0; n<13; n++)
    {
        cout << n << "     |  " << userNum*n << endl;
    }
}