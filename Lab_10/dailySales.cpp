/*
@date: 07/19/2026
@author: Michael Margolis
@purpose: this program stores sales data for desired number of days
*/

// including the required c++ libraries
#include <iostream>
#include <fstream>
#include <iomanip>

// using namespace std to remove needing std:: 
using namespace std;

// the main function beginning
int main() {
    // initializing variables for days and sales amounts
    int daysWanted = 0;
    double salesAmount = 0.00;

    // opening a file named week9lab1.txt in append mode or creating one by including the ios::app
    ofstream outfile("week9_lab1.txt", ios::app);   

    // asking user for the number of days they would like to update their sales book
    cout << "How many days do you want to write sales numbers for? ";
    cin >> daysWanted;

    // loops through the number of days and asks for the days sales each loop
    for (int count = 0; count < daysWanted; ++count) {
        cout << "Sales for day " << count+1 << ": $";
        cin >> salesAmount;
        
        // setting the precision of the saved information and sending the data to the file
        outfile << fixed << setprecision(2) << salesAmount << "\n";
    }
    // closing the file so the program can close properly and avoid corruption
    outfile.close();
    return 0;
}