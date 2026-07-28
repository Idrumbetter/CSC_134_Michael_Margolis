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
    // initializing variables for days and sales amounts and confirming inputs
    int daysWanted = 0;
    double salesAmount = 0.00;
    bool valid = false;
    char confirm = 'a';

    // loops until the user confirms that they are satisfied with the number of days they would like to input and that it is a valid number 
    while (confirm != 'y' && confirm != 'Y') {
        // resetting confirm for each iteration
        confirm = 'a';

        // asking user for the number of days they would like to update their sales book
        cout << "How many days do you want to write sales numbers for? ";
        cin >> daysWanted;
        cout << endl;

        // checking that the input wasn't left blank
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        // checking that the input is positive and asking for the user to confirm their days wanted
        if (daysWanted >= 0) {
            while (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N') {
                cout << "Confirm that you want to add " << daysWanted << " days: (y/n) ";
                cin >> confirm;
                cin.ignore(1000, '\n');
                // makes sure the user actually entered a valid option from the menu
                if (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N') {
                    cout << "Invalid Input Recieved...\n";
                }
            }
            // a statement if it failed all the checks
        } else {cout << "Invalid data entered. Please try again...\n";}
    }

    // if the days entered is zero we don't need to save or open a file. and can skip looping and reading this section
    if (daysWanted != 0 ) {
        // opening a file named week9lab1.txt in append mode or creating one by including the ios::app
        ofstream outfile("week9_lab1.txt", ios::app);     
        // loops through the number of days and asks for the days sales each loop
        for (int count = 0; count < daysWanted; ++count) {
            // restting valid to false each run that was failed
            valid = false;
            // looping until a valid quantity is input
            while (!valid) {
                // printing the prompt and storing input
                cout << "Sales for day " << count+1 << ": $";
                cin >> salesAmount;

                // checking if the input is blank and failing the check if so
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "INVALID DATA ATTEMPTED TO BE ENTERED. PLEASE TRY AGAIN.\n";
                } else {
                    valid = true;
                }        
            }
            // setting the precision of the saved information and sending the data to the file
            outfile << fixed << setprecision(2) << salesAmount << endl;
        }    
        // closing the file so the program can close properly and avoid corruption
        outfile.close();
    }    
    return 0;
}