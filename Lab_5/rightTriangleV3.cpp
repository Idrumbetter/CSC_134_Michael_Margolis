/*
@author: Michael Margolis 
@date: 06/26/2026
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
    
    cout << "What is the width of the right triangle? ";    // askes and stores data from user for the triangles width
    cin >> width;

    cout << "\nWhat is the height of the right triangle? "; // asks and stores data from user for the triangles height
    cin >> height;

    hypoten = sqrt( pow(width,2) + pow(height,2) );         // pythgorean theorem

    theta = (atan2(height,width))*180/( 3.1415926 );        // taking the tangent and converting to degrees
    theta = round(theta*100)/100;                           // rounding theta to the hundredth
    
    cout << "hypotenuse = " << hypoten << "\n";             // final ouputs for user to view
    cout << "theta = " << theta<< "\n";       
if (theta == 53.13 || theta == 36.87)                       // checking if the triangle is a 3,4,5 triangle
{
    cout << "This is a 3, 4, 5 triangle\n";
}
else 
    cout << "This is not a 3, 4, 5 triangle";       
      
    return 0;
}
/*
I figured out how to force it to round and store a specific number of digits of precision!!!
*/