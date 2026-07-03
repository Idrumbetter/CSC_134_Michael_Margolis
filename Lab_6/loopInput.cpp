/*
@author: Michael Margolis 
@date: 06/29/2026
@purpose: This program loops the number of times entered
*/

// include the iostream library for input and output
#include <iostream>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main()
{
    // intitializing an integer variable and assigning it an intital value of 0
    int loops = 0;

    // asks the user for a number of times to loop and stores in loops
    cout << "How many times do you want loop the program? ";
    cin >> loops;

    // for loops initializing an integer variable count with an initial value of 0,
    // checks for as long as count is < loops, and increments count by 1
    for (int count = 0; count < loops; count++)
    {
        // prints the count to the terminal with a space for following numbers
        cout << count << " ";
    }
    return 0;
}