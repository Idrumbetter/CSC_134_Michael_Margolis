/*
@author: Michael Margolis 
@date: 06/29/2026
@purpose: This program counts to one hundred
*/

// include the iostream library for input and output
#include <iostream>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main()
{
    int count = 0;
    // initializing a for loop that checks for count < 100 and increments by 1 every loop
    for (count; count<100; count++){}
    
    // prints the total of the count after it has run 100 times
    cout << "The accumulator value is: " << count;
    
}