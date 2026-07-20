/*
@date: 07/15/2026
@author: Michael Margolis
@purpose: this program prints the planets in order including pluto
*/

// include the iostream library for c++
#include <iostream>

// using the namespace std to avoid needing std::
using namespace std;

// starting the main function
int main() {
    // initializing a constant integer variable to use as the size of the array
    const int SIZE = 8;
    // setting a string array and assigning the planets to the new positions
    string planetArray[SIZE] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Pluto"};

    // printing a opening statement about the order of the planets
    cout << "The order of the planets from closest to the sun to furthest are as shown below:\n";
    // setting a for loop to run through each position of the array
    for (int n=0; n<SIZE;++n) {
        // printing the nth positon of the array to the terminal
        cout << "Planet " << n+1 << ": " << planetArray[n] << endl;
    }
    return 0;
}