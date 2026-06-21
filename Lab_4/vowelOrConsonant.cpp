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
    // initializing variables with values to use in comparison
    char letter;
    int equivalent, a = 97, 
                    e = 101, 
                    i = 105, 
                    o = 111, 
                    u = 117, 
                    y = 121, 
                    A = 65, 
                    E = 69, 
                    I = 73,
                    O = 79,
                    U = 85,
                    Y = 89;

    // asking for user input to recieve a letter (Upper or Lower case) to check if its a vowel or consonant
    cout << "What letter would you like to check? ";
    cin.get(letter);

    // converting a character class into an integer class
    equivalent = letter;

    // start of a descision code branch checking first if the letters are capitals or not, then going through each vowel.
    
    if (equivalent >= a)
    {
        if (equivalent != a)
        {
           if (equivalent != e)
            {
                if (equivalent != i)
                {
                    if (equivalent != o)
                    {
                        if (equivalent != u)
                        {
                            if (equivalent != y)
                                {
                                    cout << "Your letter is a lower case consonant!";
                                }
                                else
                                cout << "Your letter is lower case, and is sometimes a vowel and sometimes a consonant! " << equivalent;                            
                        }
                        else 
                        cout << "Your letter is a lower case vowel!";                    
                    }
                    else
                    cout << "Your letter is a lower case vowel!";
                }
                else
                cout << "Your letter is a lower case vowel!";
            }
            else
            cout << "Your letter is a lower case vowel!";
        }
        else
        cout << "Your letter is a lower case vowel!";
    }
    else
        if (equivalent != A)
        {
           if (equivalent != E)
        {
            if (equivalent != I)
            {
                if (equivalent != O)
                {
                    if (equivalent != O)
                    {
                        if (equivalent != Y)
                        {
                            cout << "Your letter is an upper case consonant!";
                        }
                        else
                        cout << "Your letter is upper case, and is sometimes a vowel and sometimes a consonant! " << equivalent;                            
                    }
                    else 
                    cout << "Your letter is an upper case vowel!";                    
                }
                else
                cout << "Your letter is an upper case vowel!";
            }
            else
            cout << "Your letter is an upper case vowel!";
        }
        else
        cout << "Your letter is an upper case vowel!";
    }
    else
    cout << "Your letter is an upper case vowel!";

    return 0;
}