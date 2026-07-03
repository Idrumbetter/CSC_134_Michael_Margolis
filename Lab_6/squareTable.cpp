/*
@author: Michael Margolis 
@date: 06/29/2026
@purpose: This program prints a list of numbers and their squares
*/

// include the iostream library for input and output
#include <iostream>
#include <cmath>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main()
{
    // printing a table header for the multiplication table
    cout << "Number | Square\n";

    // initializing integer variables with initial values
    int minNum = 0, maxNum = 100;

    // for loops to that increments minNum by one until it matches maxNum
    for (minNum; minNum<maxNum; minNum++)
    {
        // these if statements are for indexing the table center line
        if (minNum < 10){
            
            // printing the sqaure of the index
            cout << minNum << "      |   " << pow(minNum,2) << endl;
        }

        if (minNum <= 100 && minNum >= 10 ){
            // printing the sqaure of the index
            cout << minNum << "     |   " << pow(minNum,2) << endl;
        }
    }
    return 0;
}