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
    int count = 0;

    while (count != 100)
    {
        cout << "This is iteration " << (count + 1) << "!\n";
        count += 1;
    }
    cout << "\nThis code successfully ran " << count << " iterations! ";
    return 0;
}