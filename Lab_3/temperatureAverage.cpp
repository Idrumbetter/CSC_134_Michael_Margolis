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
    // declaring float variables and assigning them initial values
    float newYork = 85, denver = 88, pheonix = 106;

    // printing a message of the previous average temperature for New York
    cout << "The average temperature in New York City was " << newYork << (char)248 << "F but, after a 2% rise,\nwe are now seeing the average temperature at "; 
    // assigning a new value to the variable newYork
    newYork = newYork * 1.02;
    // printing the new value to the terminal attached in line with the previous statement, and starting two new lines
    cout << newYork << (char)248 << "F!\n\n";
    

    // printing a message of the previous average temperature for denver
    cout << "The average temperature in Denver was " << denver << (char)248 << "F but, after a 2% rise,\nwe are now seeing the average temperature at "; 
    // assigning a new value to the variable denver
    denver = denver * 1.02;
    // printing the new value to the terminal attached in line with the previous statement, and starting two new lines
    cout << denver << (char)248 << "F!\n\n";


    // printing a message of the previous average temperature for pheonix
    cout << "The average temperature in Pheonix was " << pheonix << (char)248 << "F but, after a 2% rise,\nwe are now seeing the average temperature at "; 
    // assigning a new value to the variable pheonix
    pheonix = pheonix * 1.02;
    // printing the new value to the terminal attached in line with the previous statement, and starting two new lines
    cout << pheonix << (char)248 << "F!\n\n";


    //printing a send off message as a nicety
    cout << "I hope you all are ready for a hot summer, as this is only the beginning!";

    //return statement to end the main function
    return 0;
}