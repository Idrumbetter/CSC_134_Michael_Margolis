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
    double temp=0.00;

    while (temp != 212.34)
    {
        cout << "Please input the correct temperature (212.34): ";
        cin >> temp;
    }
    cout << "The temperature has been successfully set, thank you.";
    return 0;
}