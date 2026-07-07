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
    int width = 0;

    cout << "How tall(many rows) do you want the triangle to be? ";
    cin >> width;
    cin.ignore();
    cout << endl;

    for (int h = 0; h < width;++h) {
        for (int w = 0; w < width; ++w) {
            cout << "* ";
        } 
        cout << endl;
    }
    return 0;
}