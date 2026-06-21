/*
@author: Michael Margolis 
@date: 06/15/2026
@purpose: This program takes three test grades, finds the average, and gives the letter grade recieved
*/

// include the iostream library for input and output
#include <iostream>
#include <iomanip>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main()
{
    //initializing the variables
    double test1 = 0.00,
           test2 = 0.00,
           test3 = 0.00,
           averageNum = 3.00,
           yourResultHere = 0.00;
    
    // ask for test grades and stores them in variables       
    cout << "\nThis program gives the letter grade for the course from the average of the three test grades!\n\n";
    cout << "What is your first test grade? ";
    cin >> test1;
    cout << "What is the second number? ";
    cin >> test2;
    cout << "What is the third number? ";
    cin >> test3;

    // takes the average of the test scores and stores them in youResultHere
    yourResultHere = (test1 + test2 + test3)/averageNum;

    // compares how high the grade is and gives the specific grade for each final "gate"
    if (yourResultHere >= 60)
    {
        if (yourResultHere >= 70)
        {
            if (yourResultHere >= 80)
            {
                if (yourResultHere >= 90)
                {
                    cout << "You scored a " << fixed << setprecision(2) << yourResultHere << "% average on your overall score, landing you an A!";
                }
                else 
                cout << "You scored a " << fixed << setprecision(2) << yourResultHere << "% average on your overall score, finding you at a B!";    
            }
        else 
        cout << "You scored a " << fixed << setprecision(2) << yourResultHere << "% average on your overall score, landing you on a C!";    
    }
    else 
    cout << "You scored a " << fixed << setprecision(2) << yourResultHere << "% average on your overall score, getting you on a D!";
    }
    // this is for all numbers below 60, resulting in a fail
    else
        cout << "You scored a " << fixed << setprecision(2) << yourResultHere << "% average on your overall score, getting you on an F!";
    
    return 0;
}