/*
@author: Michael Margolis 
@date: 06/21/2026
@purpose: This program takes the horizontal length and the vertical 
          height of a triangle to find the hypotenuse and angles of the triangle
*/

// include the iostream library for input and output
#include <iostream>
#include <cmath>


//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main()
{
    float width = 0.00, height = 0.00, hypoten = 0.00, theta = 0.00;
    int thetaForRounding;

    cout << "What is the width of the right triangle? ";
    cin >> width;

    cout << "\nWhat is the height of the right triangle? ";
    cin >> height;

    hypoten = sqrt( pow(width,2) + pow(height,2) );

    theta = (atan2(height,width))*180/3.141592*1000;

    thetaForRounding = theta;

    theta = thetaForRounding / 1000.00;

    cout << "hypotenuse = " << hypoten << "\n";
    cout << "theta = " << theta<< "\n";
    if (abs(theta - 53.13) <0.001 || abs(theta - 36.87) < 0.0015)
    {
        cout << "3,4,5 triangle";
    }
}