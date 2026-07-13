/*
@author: Michael Margolis 
@date: 07/07/2026
@purpose: This program prints a square with the width gotten from the user
*/

// include the iostream library for input and output
#include <iostream>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main() {
    // setting initial condition for width
    int width = 0;

    // ask user how wide the square should be. then store the response
    cout << "How tall(many rows) do you want the triangle to be? ";
    cin >> width;
    cin.ignore();
    cout << endl;

    // setting a for loop for height to run the users input number of times
    for (int h = 0; h < width;++h) {
        // setting a for loop for width to run the user input number of times
        for (int w = 0; w < width; ++w) {
            // printing the formatted stars
            cout << "* ";
        } 
        // moving to the next time
        cout << endl;
    }
    return 0;
}