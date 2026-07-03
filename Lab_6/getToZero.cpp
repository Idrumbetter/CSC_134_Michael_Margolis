/*
@author: Michael Margolis 
@date: 06/29/2026
@purpose: This program counts down from 100 to zero
*/

// include the iostream library for input and output
#include <iostream>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main()
{
    // a for loop that starts at 100 and decrements by 1 each loop. it check for when n no longer is greater than -1
    for (int n=100; n>-1; n--)
    {
        //prints the number of itereations left until the check is done
        cout <<  "Iterations left: " << n << endl;
    }
}