/*
@author: Michael Margolis 
@date: 06/01/2026
@purpose: This program convert fahrenheit to celcius
*/

// include the iostream library for input and output
#include <iostream>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main()
{
    //defining float points to be used in eqautions
    float celcius, fahrenheit;

    // asking and storing the temperature in fahrenheit
    cout << "What temperature is would you like to convert to celcius? (exclude the C) ";
    cin >> fahrenheit;

    //conversion from fahrenheit to cclecius
    celcius = (fahrenheit-32)*5/9;

    // printing the conversion to the terminal
    cout << "The converted temperature of " << fahrenheit << (char)248 << "F is " << celcius << (char)248 << "C!";

    return 0;
}