/*
date: 07/02/2026
author: Michael Margolis
prupose: a list of ingredients and recipes that can be called to automatically balance and give suggestions
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm> // required for transform
#include <cctype>    // required for toLower
#include <iomanip>

using namespace std;

// =============================
// Data structure definition
// =============================
struct PantryItem {
    string name;
    int quantity;
    double price;
};

// =============================
// Functions to call
// =============================

//this function lowercases the string to avoid duplicates
string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
        return tolower(c);
    });
    return str;
}

// this function saves the information to a .txt file
void savePantry(const vector<PantryItem>& pantry) {
    // opens a file for writing (creates the file if it doesn't exist)
    ofstream outFile("pantry.txt");

    if (outFile.is_open()) {
        for (const auto& item : pantry) {
            // save data separated by spaces o newLines
            outFile << item.name << "\n";
            outFile << item.quantity << "\n";
            outFile << item.price << "\n";
        }
        outFile.close();
        cout << "Data saved successfully!\n";
    }
}

// this function reads a stored file and converts the info back into useful data types and loads them
vector<PantryItem> loadPantry() {
    vector<PantryItem> loadedPantry;
    ifstream inFile("pantry.txt");

    if (inFile.is_open()) {
        string name;
        string qtyStr;
        string priStr;

        while (getline(inFile, name)) {
            if (getline(inFile, qtyStr) && getline(inFile, priStr)) {
                int quantity = stoi(qtyStr);
                double price = stod(priStr);

                loadedPantry.push_back({name, quantity, price});
            }
        }
        inFile.close();
        cout << "Data loaded Successfully!\n";
    } else {
        cout << "No saved data found. Starting fresh. \n";
    }

    return loadedPantry;
}

// ==========================
// The programs runtime
// ==========================
int main() {
    //loading stored data
    vector<PantryItem> myPantry = loadPantry();
    char choice = '0';

    // a while loop that breaks when the user enters 4. This will continue running and asking for new inputs. 
    while (choice != '4') {

        // pantry menu text to explain the options
        cout << "\n=== DIGITAL PANTRY MENU ===\n";
        cout << "1. View Pantry Stock\n";
        cout << "2. Add / Update Stock\n";
        cout << "3. Consume / Remove Stock\n";
        cout << "4. Save & Exit\n";
        cout << "Enter your choice (1-4)"; 
        cin >> choice;
        cin.ignore();

        cout << "\n";

        switch (choice) {

            // this case is to view the current list of ingredients in the pantry
            case '1': {
                if (myPantry.empty()) {
                    cout << "Your pantry is empty.\n";
                }
                else {
                    cout << "Your current pantry list:\n";
                    for (const auto& item : myPantry) {
                        cout << "- " << item.name
                             << " | Qty: " << item.quantity
                             << " | Price: $" << fixed << setprecision(2) << item.price << endl;
                        }
                    }
                break;
            }

            case '2': {
                char addMore;
                do {
                PantryItem newItem;

                cout << "Enter the ingredient name: ";
                getline(cin, newItem.name);

                cout << "Enter the quantity: ";
                cin >> newItem.quantity;

                cout << "Enter the price: ";
                cin >> newItem.price;

                bool itemFound = false;

                for (auto& existingItem : myPantry) {
                    if (toLowerCase(existingItem.name) == toLowerCase(newItem.name)) {
                        existingItem.quantity += newItem.quantity;
                        existingItem.price = newItem.price;
                        itemFound = true;
                        cout << "Match found! Updated existing stock. \n";
                        break;
                    }
                }
                if (!itemFound) {
                    myPantry.push_back(newItem);
                    cout << "New item added to the pantry. \n";
                }

                cout << "Item added! Add another? (y/n): ";
                cin >> addMore;
                cin.ignore();
                cout << "\n";
                }

                while (addMore == 'y' || addMore == 'Y');

                savePantry(myPantry);
            break;
            }

            case '3': {
                break;
            }

            case '4': {
            savePantry(myPantry);
            break;
            }

            // this case covers anything not covered in the other case options
            default: {
                cout << "The input recieved is an invalid selection, please try again. \n";
                break;
            }
        }
    }
    return 0;
}