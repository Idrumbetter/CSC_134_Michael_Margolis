/*
@author: Michael Margolis
@date: 06/01/2026
@purpose: This program takes the square root of a number
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    // declaring number to be square rooted
    double num, root;

    // asking and storing the number in num
    cout << "What number would you like to know the square root of to the nearest hundredth? ";
    cin >> num;

    // taking the square root of num
    root = sqrt(num);

    // diplaying the root to the terminal
    cout << "The square root of " << num << " is " << fixed << setprecision(2) << root << " rounded to the nearest hundredth!";

    return 0;

}
