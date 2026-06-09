/*
@author: Michael Margolis
@date: 06/03/2026
@purpose: This program finds the volume of a sphere.
*/

// include the iostream library for input and output
#include <iostream> 

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main()

{
    // setting my variables for the calculation
    float radius, pi, volume;

    //assigning pi to pi
    pi = 3.1415;

    // asssigning the radius of our sphere to radius
    radius = 7;

    // the formula for the volume of a sphere
    volume = 4/3 * pi * radius * radius * radius;

    //printing the volume of a sphere to the console
    cout << "The volume of a sphere with a radius of " << radius << " is " << volume << " units cubed!";

    return 0;
}
