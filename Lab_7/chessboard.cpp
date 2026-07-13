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
    // initializing variable rows to capture user data
    int rows = 0;

    // asks user for data and captures it
    cout << "How many rows do you want your chessboard to be? ";
    cin >> rows;
    cin.ignore();
    cout << endl;

    //setting a for loop that increments h (height) and will move the image down a line each round
    for (int h = 0; h < rows; ++h) {
        // if check to see if the row is even or odd
        if (h%2==0) {
            // for loop that deals with width 
            for (int w = 0; w<rows; ++w) {
                // if check to see if width position is even or odd.
                if (w % 2 == 0) {
                    cout << "* ";
                } else {
                    cout << "  ";
                }
            }
        } 
        // row is odd
        else {
            // for loop that deals with width 
            for (int w = 0; w < (rows-1); ++w) {
                // checks if width position is even or odd
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