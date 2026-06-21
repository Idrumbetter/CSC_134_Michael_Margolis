/*
@author: Michael Margolis 
@date: 06/15/2026
@purpose: This program takes three integer numbers and finds the average
*/

// include the iostream library for input and output
#include <iostream>
#include <iomanip>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main()
{
    //initializing the variables and assigning them initial values
    int num1 = 0,
        num2 = 0,
        num3 = 0;
    float averageNum = 3.00,
          yourResultHere = 0.00;
    
    // collecting inputs from the user and stores them in the variables
    cout << "\nThis program finds the average of three integer numbers!\n\n";
    cout << "What is your first number? ";
    cin >> num1;
    cout << "What is the second number? ";
    cin >> num2;
    cout << "What is the third number? ";
    cin >> num3;

    // finding the averaage of the three numbers
    yourResultHere = (num1 + num2 + num3)/averageNum;

    // printing the results to the terminal using set precision to make the number round to the thousandth
    cout << "\nThe average of your three numbers is: " << fixed << setprecision(3) << yourResultHere << "\n";

    return 0;
}