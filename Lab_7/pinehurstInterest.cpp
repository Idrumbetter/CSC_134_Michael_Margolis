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
    double membership = 250000.0;
    double increaseAmount = 0.0;
    cout << "Year 0: Membership fee is set at $" << fixed << setprecision(2) << membership << endl;
    for (int year = 0; year < 5; ++year) {
        increaseAmount = (membership*0.06);
        membership += increaseAmount;
        cout << "Year " << year + 1 << ": Membership fee increased by $" 
             << fixed << setprecision(2) << increaseAmount << " and is now set to $"
             << fixed << setprecision(2) << membership << endl;
    }
    return 0;
}