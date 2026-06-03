/*
@author: Michael Margolis
@date: 06/02/2026
@purpose: This program finds the velocity of an object given the distance traveled and the time it took
*/

// include the iostream library for input and output
#include <iostream>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main()
{
    // Setting up variables for velocity, distance, and time
    int velocity, distance, time;

    // assigning distance to equate to 400 miles
    distance = 400;

    // assigning time to equate to 4 hours
    time = 4;

    // assigning the quotient of distance and time to velocity
    velocity = distance / time;

    cout << "The velocity of an object that has traveled " << distance << " miles in "  << time << " hours is " << velocity << " mph!";

    return 0;
}