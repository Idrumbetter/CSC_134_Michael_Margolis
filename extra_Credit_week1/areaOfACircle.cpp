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

    pi = 3.1415;

    radius = 19;

    area = pi * radius * radius;

    cout << "The area of a circle with a radius of " << radius << " is " << area << " squared units!";

    return 0;
}