/*
@author: Michael Margolis 
@date: 07/07/2026
@purpose: This program prints a right triangle with the number of rows gotten from the user
*/

// include the iostream library for input and output
#include <iostream>
#include <iomanip>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main() {
    // setting integers and assigning initial values
    double membership = 250000.0;
    double increaseAmount = 0.0;

    // print the initial conditions of the memberships
    cout << "Year 0: Membership fee is set at $" << fixed << setprecision(2) << membership << endl;

    // setting a for loop to run 5 times and print the increase amount and new totals
    for (int year = 0; year < 5; ++year) {
        // storing the yearly increase of 6%
        increaseAmount = (membership*0.06);
        // incrementing membership by the increase amount
        membership += increaseAmount;
        // printing the yearly update of the cost of a membership and the increase for each year.
        cout << "Year " << year + 1 << ": Membership fee increased by $" 
             << fixed << setprecision(2) << increaseAmount << " and is now set to $"
             << fixed << setprecision(2) << membership << endl;
    }
    return 0;
}