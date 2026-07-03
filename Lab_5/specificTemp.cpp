/*
@author: Michael Margolis 
@date: 06/21/2026
@purpose: This program asks for a specific temperatue until it is entered!
*/

// include the iostream library for input and output
#include <iostream>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main()
{
    // variable to store user input
    double temp=0.00;

    // loop to continue to check value the user entered
    while (temp != 212.34)
    {
        // prompting and storing a response from the user
        cout << "Please input the correct temperature (212.34): ";
        cin >> temp;
    }
    // printing the final statement when the loop is successfully completed
    cout << "The temperature has been successfully set, thank you.";
    return 0;
}