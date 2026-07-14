/*
@author: Michael Margolis
@date: 07/13/2026
@purpose: to tell if you can afford to use money for tuition
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double lastMonth = 0.00; 
    double savings = 0.00;
    double interestRate = 0.00;
    double expense = 0.00;
    double totalCost = 0.00;
    double income = 0.00;
    char costsLeft = 'y';
    int n = 1;
    char anotherMonth = 'y';
    int y = 1;

    cout << "How much savings do you currently have? $";
    cin >> savings;
    cin.ignore();

    cout << "What is the APY interest rate of your bank account? ";
    cin >> interestRate;
    cin.ignore();
    interestRate = interestRate/100;

    while (anotherMonth != 'n' && anotherMonth != 'N') {
        costsLeft = 'y';
        totalCost = 0.00;
        n = 1;

        while (costsLeft != 'n' && costsLeft != 'N') {
            cout << "What is expense number " << n << "? ";
            cin >> expense;
            cin.ignore();

            totalCost += expense;

            cout << "Any other expenses? (y/n) ";
            cin >> costsLeft;
            cin.ignore();

            n++;
        }

    cout << "Did you make any income? $";
    cin >> income;
    cin.ignore();

    lastMonth = savings;

    savings = (savings - totalCost + income) * (1 + interestRate/12);

    cout << "\n===   Month " << y << "   ===\n";
    cout << "Your current balance is $" << fixed << setprecision(2) << savings << ".\n";
    if (lastMonth < savings) {
        cout << "You earned more than you spent by $" << fixed << setprecision(2) << savings - lastMonth << ".\n";
    }
    if (lastMonth == savings) {
        cout << "You made enough to break even this month. You may want to try saving a little bit more.\n";
    }
    if (savings < lastMonth) {
        cout << "You spent more than you made by $" << fixed << setprecision(2) << lastMonth - savings << ". You should make sure you are saving more.";
    }
    
    y++;

    cout << "\nCheck through the next month? (y/n) ";
    cin >> anotherMonth;
    cin.ignore();
    }
}
