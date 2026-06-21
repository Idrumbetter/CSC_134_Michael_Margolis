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

    cout << "What letter would you like to check? ";
    cin.get(letter);

    equivalent = letter;

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
                            if (equivalent != A)
                            {
                                if (equivalent != E)
                                {
                                    if (equivalent != I)
                                    {
                                        if (equivalent != O)
                                        {
                                            if (equivalent != U)
                                            {
                                                if (equivalent != Y)
                                                {
                                                    cout << "Your letter is a consonant";
                                                }
                                                else 
                                                cout << "Your letter is a sometimes a vowel and sometimes a consonant!";
                                            }
                                            else 
                                            cout << "Your letter is a vowel!";
                                        }
                                        else
                                        cout << "Your letter is a vowel!";
                                    }
                                    else
                                    cout << "Your letter is a vowel!";
                                }
                                else
                                cout << "Your letter is a vowel!";
                            }
                            else
                            cout << "Your letter is a vowel!";
                        }
                        else 
                        cout << "Your letter is a sometimes a vowel and sometimes a consonant!";
                    }
                    else 
                    cout << "Your letter is a vowel!";
                }
                else 
                cout << "Your letter is a vowel!";
            }
            else 
            cout << "Your letter is a vowel!";
        }
        else 
        cout << "Your letter is a vowel!";
    }
    else 
    cout << "Your letter is a vowel!";
    
    return 0;
}