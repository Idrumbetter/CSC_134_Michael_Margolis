/*
@author: Michael Margolis 
@date: 06/15/2026
@purpose: This program tells the user if the letter entered is a vowel or a consonant
*/

// include the iostream library for input and output
#include <iostream>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main()
{
    char letter;

    cout << "What letter would you like to check if it is a vowel or consonant? ";
    cin.get(letter);
 
    if ((letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z'))
    {
        if (letter >= 'A' && letter <= 'Z')
        {
            if (letter == 'A'
             || letter == 'E'
             || letter == 'I'
             || letter == 'O'
             || letter == 'U'
             || letter == 'Y')
                {
                    if (letter == 'Y')
                    {cout << "\nThe letter entered was a capital letter that is both a vowel and consonant!";
                    }
                    else
                    cout << "\nThe letter entered was a capital vowel!";
                }
            else
            cout << "\nThe letter was a capital consonant!";
        }
        else 
            if (letter == 'a'
             || letter == 'e'
             || letter == 'i'
             || letter == 'o'
             || letter == 'u'
             || letter == 'y')
            {
                if (letter == 'y')
                {
                    cout << "\nThe letter entered was a lower case latter that is both a consonant and a vowel!";
                }
                else
                cout << "\nThe letter entered was a lowercase vowel!";
            }
            else 
            cout << "\nThe letter was a lower case consonant!";       
    }
    else
    cout << "\nThe character entered cannot be accepted as it is outside the scope of data\nmeant to be covered, please rerun the program and enter in a valid letter";

    return 0;
}