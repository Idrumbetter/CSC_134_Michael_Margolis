/*
@author: Michael Margolis 
@date: 06/01/2026
@purpose: This program takes avogadros number and prints it in E notation
*/

// include the iostream library for input and output
#include <iostream>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main()
{
    //assigning a float for avogadros number
    float avogadro;

    avogadro = 6.02214076E23;

    cout << avogadro;
    return 0;
}