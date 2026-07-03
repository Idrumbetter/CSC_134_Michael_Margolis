/*
@author: Michael Margolis 
@date: 06/29/2026
@purpose: This program prints 10 times using a for loop
*/

// include the iostream library for input and output
#include <iostream>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main()
{
    /* for loop that initializes an integer variable count with intitial value 0 and increments 
       it by one for each loop. The loop ends when count is no longer less than 10*/
    for (int count = 0; count<10; count++)    
    {
        // prints the count and a space to the terminal
        cout << count << " ";
    }
    return 0;
}