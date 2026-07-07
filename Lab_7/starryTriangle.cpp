/*
@author: Michael Margolis 
@date: 06/29/2026
@purpose: This program prints a right triangle with the number of rows gotten from the user
*/

// include the iostream library for input and output
#include <iostream>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main() {
    string triangleStars = "";
    int rows = 0;

    cout << "How tall(many rows) do you want the triangle to be? ";
    cin >> rows;
    cin.ignore();
    cout << endl;

    for (int n = 0; n<rows;n++) {
        if (n<9) {
            triangleStars += "*";
            cout << "row " << n+1 << ")     " << triangleStars << endl;
        } 
        if (n>=9 && n < 99) {
            triangleStars += "*";
            cout << "row " << n+1 << ")    " << triangleStars << endl; 
        }
        if (n >= 99 && n < 999) {
            triangleStars += "*";
            cout << "row " << n+1 << ")   " << triangleStars << endl;
        }
    }
    return 0;
}