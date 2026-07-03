/*
@author: Michael Margolis 
@date: 06/30/2026
@purpose: This program counts to one hundred
*/

// include the iostream library for input and output
#include <iostream>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main()
{
    // initializing integer variables and assigning initial values
    int sumOp = 0, adder = 10;

    // a for loop that runs 50 times, incrementing count by 1
    for (int count = 0; count<50; count++)
    {
        // summing the adder and count together to be stored in sumOp
        sumOp += adder + count;

        // printing the total summed to the terminal
        cout << "The total summmed is: " << sumOp << "\n";
    }
    return 0;
}