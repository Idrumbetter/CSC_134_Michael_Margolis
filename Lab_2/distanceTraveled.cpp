/*
@author: Michael Margolis
@date: 06/02/2026
@purpose: This program takes the velocity and time and returns how far the object has gone
*/

#include <iostream>

using namespace std;

int main()
{
    // declaring variables to be used (distance is x, velocity is v, time is t)
    int x, v, t;

    // setting velocity equal to 80mph
    v = 80;

    // setting time equal to 2 hours
    t = 2;

    //taking the product of v and t to get distance
    x = v * t;

    cout << "The distance the object travels after " << t << " hours of going " << v << "mph is " << x << " miles!";

    return 0;
}