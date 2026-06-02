/*
@author: Michael Margolis
@date: 06/02/2026
@purpose: This program takes the velocity and time and returns how far the object has gone
*/

#include <iostream>

using namespace std;

int main()
{
    // declaring variables to be used (distance, velocity, and time)
    int distance, velocity, time;

    // setting velocity equal to 80mph
    velocity = 80;

    // setting time equal to 2 hours
    time = 2;

    //taking the product of v and t to get distance
    distance = velocity * time;

    cout << "The distance the object travels after " << time << " hours of going " << velocity << "mph is " << distance << " miles!";

    return 0;
}