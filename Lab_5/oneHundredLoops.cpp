/*
@author: Michael Margolis 
@date: 06/21/2026
@purpose: This program is a printing 100 times!
*/

// include the iostream library for input and output
#include <iostream>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main()
{
    //initializing an integer to be used as a counter
    int count = 0;

    // a while loop that checks for a value 100 and stops
    while (count != 100)
    {
        // increases the count by 1
        count += 1;
        // prints the iteration number
        cout << "This is iteration " << count << "!\n";        
    }
    // prints a completion message that tells you the iteration we stopped on
    cout << "\nThis code successfully ran " << count << " iterations! ";
    return 0;
}