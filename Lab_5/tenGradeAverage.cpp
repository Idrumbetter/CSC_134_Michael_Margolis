/*
@author: Michael Margolis 
@date: 06/21/2026
@purpose: This program is an infinite printing machine!
*/

// include the iostream library for input and output
#include <iostream>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main()
{
    int n = 1;
    float test = 0.00, grade = 0.00, finalGrade;

    while (n != 11)
    {
        cout << "What is the grade for test " << n << "? ";
        cin >> test;

        grade += test;

        n += 1;
    }
    finalGrade = grade/10.00;
    cout << finalGrade;
}