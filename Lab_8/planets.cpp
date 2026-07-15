/*
@date: 07/15/2026
@author: Michael Margolis
@purpose: this program prints the planets in order including pluto
*/

#include <iostream>

using namespace std;

int main() {
    const int size = 8;
    string planetArray[size] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Pluto"};

    cout << "The order of the planets from closest to the sun to furthest are as shown below:\n";
    for (int n=0; n<size;++n) {
        cout << "Planet " << n+1 << ": " << planetArray[n] << endl;
    }
}