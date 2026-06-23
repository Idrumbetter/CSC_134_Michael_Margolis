/*
@author: Michael Margolis 
@date: 06/21/2026
@purpose: This program is an infinite printing machine!
*/

// include the iostream library for input and output
#include <iostream>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main()
{
    // initializing a variable to use in the check for the loop
    int n = 1;

    // a loop statement that never ends unless n does equals 0 
    while (n != 0)
    {
        // prints "this is infinite" to the console 
        cout << "This is infinite\n";
    }
    return 0;
}