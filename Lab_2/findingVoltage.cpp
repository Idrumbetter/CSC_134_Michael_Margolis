/*
@author: Michael Margolis
@date: 06/02/2026
@purpose: This program takes the current and resistance and returns the voltage
*/

// include the iostream library for input and output
#include <iostream>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main()
{
    // declaring variables to be used (voltage, current, and resist)
    int voltage, current, resist;

    // letting the current be assigned 10 amps
    current = 10;

    // letting the resistance be assigned 2 ohms
    resist = 2;

    //taking the product of current and resist to get the voltage
    voltage = current * resist;

    cout << "The voltage of the circuit is " << voltage << " Volts given " << resist << " ohms of resistance and " << current << " amps of current!";

    return 0;
}