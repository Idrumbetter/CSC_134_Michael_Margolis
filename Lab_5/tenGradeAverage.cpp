/*
@author: Michael Margolis 
@date: 06/21/2026
@purpose: This program takes the average of 10 input test grades!
*/

// include the iostream library for input and output
#include <iostream>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main()
{
    // initializing variables for storing and calculating averages
    int n = 0;
    double test = 0.00, grade = 0.00, finalGrade;

    // a loop that runs 10 times
    while (n != 10)
    {
        n += 1;                                                 // increases the count by 1
                                
        cout << "What is the grade for test " << n << "? ";     // prints a question to the terminal with the specific test question in mind
        cin >> test;                                            // stores the users response

        grade += test;                                          // adds the input test score to grade and stores it
    }
    finalGrade = grade/10.00;                                   // averages the grades 
    cout << finalGrade;                                         // prints the final grade message
}