/*
@author: Michael Margolis
@date: 06/02/2026
@purpose: This program calculates the Force on an object given it's acceleration and mass
*/

// include the iostream library for input and output
#include <iostream>

// include the iomanip library to add manipulators to the formatting of inputs and outputs
#include <iomanip>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main()
{
    // declaring my variables for calculating
    double force, mass, accel;

    // storing 10kg of mass in mass;
    mass = 10;

    // storing 9.81m/s^2 of acceleration in accel
    accel = 9.81;

    // calculating the product of mass and accel to find force
    force = mass * accel;

    // displaying the product message to the terminal
    cout << "The force on our object with a mass of " << mass << "kg and and acceleration of " << accel << "m/s^2 is " << fixed << setprecision(1) << force << "N!" ;

    //ending the program
    return 0;
}