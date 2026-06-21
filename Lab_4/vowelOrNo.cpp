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
    // declaring a variable to capture user input
    char letter;

    // prints a message to the terminal to ask for a letter and stores it in a variable
    cout << "What letter would you like to check if it is a vowel or consonant? ";
    cin.get(letter);

    // Figuring out if the letter is one of the vowels using the or operator
    if (letter == 'a' || letter == 'A'|| letter == 'e' || letter == 'E'
     || letter == 'i' || letter == 'I'|| letter == 'o' || letter == 'O'
     || letter == 'u' || letter == 'U'|| letter == 'y' || letter == 'Y')
    {
        // determines if the vowel is capitalized or lower case
        if (letter <= 'z' && letter >= 'a')
        {
            // determines if the vowel is a lower case y or not
            if (letter == 'y')
            cout << letter << " is a lower case letter that can ve a vowel or a consonant!";
            else
            cout << letter << " is a lower case vowel";
        }
        else 
        // determines if the vowel is a capitalized y or not
        if (letter == 'Y')
        cout << letter << "is a capitalized letter that can be a vowel or a consonant";
        else 
        cout << letter << " is a capitalized vowel";
    }
    else
    // makes sure the character entered is a letter
    if ((letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z'))
    {
        // determines if the letter is lower case or not
        if (letter >= 'a' && letter <= 'z')
        {
            cout << letter << " is a lower case consonant";
        }
        else cout << " is a capitalized consonant";
    }
    // this is output when anything but a letter is entered as an input
    else cout << "Your input is invalid, please try again";

    return 0;
}    