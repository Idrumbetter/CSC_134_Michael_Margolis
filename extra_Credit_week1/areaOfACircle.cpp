/* 
@author: Michael Margolis
@date: 06/03/2026
@purpose: This program that calculates the area of a circle
 */

 // include the iostream library for input and output
#include <iostream> 

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main()
{
    // setting my variables for the calculation
    float radius, pi, area;

    //asigning pi to pi
    pi = 3.1415;

    // the radius of the circle
    radius = 19;

    // the formula for the area of a circle
    area = pi * radius * radius;

    //printing the area of a circle in the terminal with a message
    cout << "The area of a circle with a radius of " << radius << " is " << area << " squared units!";

    return 0;
}