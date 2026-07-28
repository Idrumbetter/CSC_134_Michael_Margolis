/*
@date: 07/19/2026
@author: Michael Margolis
@purpose: this program stores sales data for desired number of days
*/

// including the required c++ libraries
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string>

// using namespace std to remove needing std:: 
using namespace std;

// the main function beginning
int main() {
    // initializing variables for days and sales amounts and confirming inputs
    int daysWanted = 0;
    double salesAmount = 0.00;
    double totalSales = 0.00;
    int thisDay = 1;
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
        ofstream outfile("week9_lab2.txt", ios::app);     
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


    cout << "Data has been recieved. Now printing the sales history and the total sales to date...\n\n";

    // opening the .txt file to read the data stored in it.   
    ifstream inFile("week9_lab2.txt");

    // checking that the .txt file is opened properly and prints an error message if it failed to open
    if (inFile.is_open()) {
        // a storage variable to ne used when reading from the file
        string salesText;
        // a while loop to run through each data line in the .txt file and storing it in the temporary reading variable
        cout << "Listed View of Sales to Date:\n";
        while (getline(inFile, salesText)) {
            if (salesText.empty()) continue;
            // converting the temporary string class to a double class using stod()
            double sales = stod(salesText);
            // printing the data read from the file in a formatted table 
            cout << " - Day " << thisDay << " sales: $" << fixed << setprecision(2) << sales << endl;
            totalSales += sales;
            ++thisDay;
        }
    } else {cout << "There was trouble loading the file...\n";}
    // closing file so program can close properly without corrupting data
    inFile.close();
    cout << "\n=======================\n" <<
            " Total Sales: $" << totalSales << endl <<
            "=======================\n";

    return 0;
}