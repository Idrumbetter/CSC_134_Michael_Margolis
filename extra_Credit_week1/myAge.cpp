/*
@author: Michael Margolis
@date: 06/02/2026
@purpose: This program concatenates strings together to make a complete sentence
*/

// include the iostream library for input and output
#include <iostream> 

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

// initializing a main function
int main()
{
    // creating variables for verbaige, age, and verbaige_end
    string verbiage, age, verbiage_end;

    // assigning verbaige a string
    verbiage = "Today I am ";

    // assigning age a string
    age = "25";

    //assigning verbiage_end a string
    verbiage_end = " years old!";

    // concatenating the strings together and printing to the terminal
    cout << verbiage + age + verbiage_end;

    return 0;
}