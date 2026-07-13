/*
@date: 07/08/2026
@author: Michael Margolis
@purpose: This program takes a users budget and subtracts their expenses to tell the amount saved or is in debt
*/

// include the iostream library for input and output
#include <iostream>
#include <iomanip>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main() {
    // declaring initial global variables
    double budget = 0.00;
    double expense = 0.00;
    double totalExpense = 0.00;
    int n = 1;
    char anotherCost = 'y';

    // asking the user for a budget amount and stores it
    cout << "How much money are you able to budget for this month? ";
    cin >> budget;
    cin.ignore();

    // while loop to continue checking if another expense needs to be added
    while (anotherCost != 'n' && anotherCost != 'N') {

        // ask user for the amount of the expense and stores it
        cout << "How much is expense " << n << "? ";
        cin >> expense;
        cin.ignore();

        // increments totalExpense by expense
        totalExpense += expense;

        // checks if you want to break out of the while loop
        cout << "Do you have another expense to add? (y/n) ";
        cin >> anotherCost;
        cin.ignore();
        cout << endl;

        // increments n to track which expense number we are on
        n++;
    }

    // print the budget and total expense amount to the terminal
    cout << "Budget: $" << fixed << setprecision(2) << budget << endl;
    cout << "Total Expenses: $" << fixed << setprecision(2) << totalExpense << endl;

    // if checks that let you know if you are under budget, over budget, or right on it and prints the case to the terminal
    if (totalExpense > budget) {
        cout << "You are over budget by $" << fixed << setprecision(2) << (totalExpense-budget) << ". You need to save money ASAP!\n";
    }
    if (totalExpense == budget) {
        cout << "You are exactly on your budget. You may want to find ways to save money.\n";
    }
    if (totalExpense < budget) {
        cout << "You are under your budget by $" << fixed << setprecision(2) << (budget - totalExpense) << ". Awesome job saving your money!\n"; 
    }
    return 0;
}