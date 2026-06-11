/*
@author: Michael Margolis
@date: 06/11/2026
@purpose: This program takes the current averages and spits out what the temperature would be if they rose 2%
*/

//include the iostream library for input and output
#include <iostream>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main()
{
    float newYork = 85, denver = 88, pheonix = 106;

    cout << "The average temperature in New York City was " << newYork << (char)248 << "F but, after a 2% rise,\nwe are now seeing the average temperature at "; 
    newYork = newYork * 1.02;
    cout << newYork << (char)248 << "F!\n\n";
    
    cout << "The average temperature in Denver was " << denver << (char)248 << "F but, after a 2% rise,\nwe are now seeing the average temperature at "; 
    denver = denver * 1.02;
    cout << denver << (char)248 << "F!\n\n";

      cout << "The average temperature in Pheonix was " << pheonix << (char)248 << "F but, after a 2% rise,\nwe are now seeing the average temperature at "; 
    pheonix = pheonix * 1.02;
    cout << pheonix << (char)248 << "F!\n\n";

    cout << "I hope you all are ready for a hot summer, as this is only the beginning!";

    return 0;
}