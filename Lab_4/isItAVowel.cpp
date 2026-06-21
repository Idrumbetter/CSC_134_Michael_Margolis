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

    if (letter == '0' 
        || letter == '1' 
        || letter == '2' 
        || letter == '3' 
        || letter == '4' 
        || letter == '5' 
        || letter == '6' 
        || letter == '7' 
        || letter == '8' 
        || letter == '9')
    {
        cout << "The input recieved was a number and not a letter, please run this again using a letter that is capital or lowercase";
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
                cout << "This letter was a lowercase letter that could be a vowel or consonant!";
            }
            else
            cout << "This was a lowercase vowel!";
        }
        else
        if (letter == 'A' 
            || letter == 'E' 
            || letter == 'I' 
            || letter == 'O' 
            || letter == 'U' 
            || letter == 'Y')
        {
            if (letter == 'Y')
            {
                cout << "The letter was a capital letter that could be a vowel or a consonant!";
            }
            else
            cout << "This letter was a capital vowel!";
        }
        else 
        if (letter <= 90 && letter >= 65)
        {
            cout << "This letter is a capital consonant!";
        }
        if (letter <= 122 && letter >= 97)
        {
            cout << "This letter is a lower case consonant!";
        }

    return 0;
}