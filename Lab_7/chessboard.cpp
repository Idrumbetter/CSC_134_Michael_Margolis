/*
@author: Michael Margolis 
@date: 07/07/2026
@purpose: This program prints a chessboard with the number of rows gotten from the user
*/

// include the iostream library for input and output
#include <iostream>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main() {
    int rows = 0;

    cout << "How many rows do you want your chessboard to be? ";
    cin >> rows;
    cin.ignore();
    cout << endl;

    for (int h = 0; h < rows; ++h) {
        if (h%2==0) {
            for (int w = 0; w<rows; ++w) {
                if (w % 2 == 0) {
                    cout << "* ";
                } else {
                    cout << "  ";
                }
            }
        } else {
            for (int w = 0; w < (rows-1); ++w) {
                if (w % 2 == 0) {
                    cout << "  ";
                } else {
                    cout << "* ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}