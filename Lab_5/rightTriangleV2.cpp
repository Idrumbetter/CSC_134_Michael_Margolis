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
    double width = 0.00, height = 0.00, hypoten = 0.00, theta = 0.00;
    int thetaForRounding;

    cout << "What is the width of the right triangle? ";
    cin >> width;

    cout << "\nWhat is the height of the right triangle? ";
    cin >> height;

    hypoten = sqrt( pow(width,2) + pow(height,2) );

    theta = (atan2(height,width))*180/( 3.1415926 );



   
    thetaForRounding = theta*1000; 
    if (thetaForRounding % 10 < 5)
{
    theta = floor(theta*100)/100;
}

if (thetaForRounding % 10 >= 5)
{
    ceil(theta*100)/100;
}

if (theta == 53.13 || theta == 36.87)
{
    cout << "This is a 3, 4, 5 triangle\n";
}
else 
    cout << "This is not a 3, 4, 5 triangle";
    cout << "hypotenuse = " << hypoten << "\n";
    cout << "theta = " << theta<< "\n";
}