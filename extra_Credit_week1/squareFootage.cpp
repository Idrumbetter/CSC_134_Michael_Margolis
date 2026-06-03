/*
@author: Michael Margolis
@date: 06/02/2026
@purpose: This program calculates the square footage of a new home
*/

// include the iostream library for input and output
#include <iostream>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main()
{
    //Setting up my variables
    int length, width, area;

    //assigning 50 to the variable length
    length = 50;

    // assigning 32 to the variable width
    width = 32;

    // taking the product of the width and length
    area = length * width;

    //printing to the terminal the area and units
    cout << "The area of a new home with length " << length << " and width " << width << " is " << area << " square feet.";

    return 0;
}
