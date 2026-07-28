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










// ===========================================
//         Data structure definition
// ===========================================

// this store pantry item information in an array
struct PantryItem {
    string name;
    double quantity;
    double price;
};


// this stores ingredient information that is important to the recipe
struct Ingredient{
    string name;
    double amount;
    string unit;
};


// this stores recipe information in an array
struct Recipe {
    string title;
    vector<Ingredient> ingredients;
    vector<string> instructions;
    double cost;
    string category;
};











// ============================================
//              Functions to call
// ============================================

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
            // save data separated by spaces to newLines
            outFile << item.name << "\n";
            outFile << item.quantity << "\n";
            outFile << item.price << "\n";
        }
        outFile.close();
        cout << "Pantry saved successfully!\n";
    } else {
        cout << "Error: Could not open pantry.txt for writing.\n";
    }
}


// this function saves the information to a .txt file
void saveRecipe(const vector<Recipe>& recipeList) {
    // opens a file for writing (creates the file if it doesn't exist)
    ofstream outFile("recipe.txt");

    if (!outFile.is_open()) {
        cout << "Error: Could not open recipe.txt for writing.\n";
        return;
    }
    for (const auto& item: recipeList) {
        outFile << item.title << endl;
        outFile << item.cost << endl;
        outFile << item.ingredients.size() << endl;
        for (const auto& ing: item.ingredients) {
            outFile << ing.name << endl;
            outFile << ing.amount << endl;
            outFile << ing.unit << endl;
        }
        outFile << item.instructions.size() << endl;
        for (const auto& line: item.instructions) {
            outFile << line << endl;
        }
    }
        outFile.close();
        cout << "Recipes saved successfully!\n";
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
                double quantity = stod(qtyStr);
                double price = stod(priStr);
                loadedPantry.push_back({name, quantity, price});
            }
        }
        inFile.close();
        cout << "Pantry data loaded Successfully!\n";
    } else {
        cout << "No saved pantry data found. Starting fresh. \n";
    }

    return loadedPantry;
}


// this function reads a stored file and converts the info back into useful data types and loads them
vector<Recipe> loadRecipe() {
    vector<Recipe> loadedRecipes;
    ifstream inFile("recipe.txt");

    if (inFile.is_open()) {
        string title, costStr, ingSizeStr,insSizeStr;
    
        while (getline(inFile, title)) {
            if (getline(inFile, costStr) && getline(inFile, ingSizeStr)) {
                Recipe r;
                r.title = title;
                r.cost = stod(costStr);
                
                int ingSize = stoi(ingSizeStr);
                for (int n=0; n < ingSize;++n) {
                    string ingName, amtStr, unit;
                    getline(inFile, ingName);
                    getline(inFile, amtStr);
                    getline(inFile, unit);
                    r.ingredients.push_back({ingName, stod(amtStr),unit});
                }

                if (getline(inFile, insSizeStr)) {
                    int insSize = stoi(insSizeStr);
                    for (int n = 0; n < insSize; ++n) {
                        string line;
                        getline(inFile, line);
                        r.instructions.push_back(line);
                    }
                }
                loadedRecipes.push_back(r);
            }
        }
        inFile.close();
        cout << "Recipe data loaded Successfully!\n";
    } else {
        cout << "No saved recipe data found. Starting fresh. \n";
    }
    return loadedRecipes;
}


// this function updates the cost of a recipe based on the pantry pricing
void calculateRecipeCost(Recipe& recipe, const vector<PantryItem>& pantry) {
    double totalCost = 0.0;

    for (const auto& ing : recipe.ingredients) {
        bool found = false;

        for (const auto& item: pantry){
            if (toLowerCase(ing.name) == toLowerCase(item.name)){
                if (item.quantity > 0) {
                    double unitPrice = item.price / item.quantity;
                    totalCost += (ing.amount * unitPrice);
                }
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Warning: '" << ing.name << "' not found in the pantry. Cost calculation assumes $0 for this item.\n";
        }
    }
    recipe.cost = totalCost;
}






void displayPantry(const vector<PantryItem>& pantry) {
    // makes sure the .txt file actually loaded to ram and has any information stored in it
    if (pantry.empty()) {
        cout << "Your pantry is empty.\n";
    } else {
        cout << "Your current pantry list:\n";
        //
        for (const auto& item : pantry) {
            cout << "- " << item.name
                 << " | Qty: " << fixed << setprecision(2) << item.quantity
                 << " | Price: $" << fixed << setprecision(2) << item.price << endl;
        }
    }
}




// function to update pantry stock
void updatePantry(vector<PantryItem>& pantry) {
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

        for (auto& existingItem : pantry) {
            if (toLowerCase(existingItem.name) == toLowerCase(newItem.name)) {
                existingItem.quantity += newItem.quantity;
                existingItem.price = newItem.price;
                itemFound = true;
                cout << "Match found! Updated existing stock. \n";
                break;
            }
        }
        if (!itemFound) {
            pantry.push_back(newItem);
            cout << "New item added to the pantry. \n";
        }

        cout << "Item added! Add another? (y/n): ";
        cin >> addMore;
        cin.ignore();
        cout << "\n";
        }

    while (addMore == 'y' || addMore == 'Y');

    savePantry(pantry);
}




// a function to view current recipes
void viewRecipes(const vector<Recipe>& myRecipes) {
                    if (myRecipes.empty()) {
                    cout << "Your cookbook is empty.\n";
                }
                else {
                    cout << "Your current recipe list:\n";
                    for (const auto& recipe : myRecipes) {
                        cout << "\n===================================\n";
                        cout << "- Recipe: " << recipe.title
                             << " | Cost: $" << fixed << setprecision(2) << recipe.cost << endl;
                        for (const auto& ing: recipe.ingredients) {
                            cout << "  - " << ing.name << ": " << ing.amount << " " << ing.unit << endl;
                        }

                        cout << "Instruction:\n";
                        int stepNum = 1;
                        for (const auto& step: recipe.instructions) {
                            cout << "  " << stepNum << ". " << step << endl;
                            stepNum++;
                        }
                        }
                        cout << "===================================\n";
                    }
}





// this function adds a new recipe item to the array and .txt file
void addRecipe(vector<Recipe>& recipe, const vector<PantryItem>& pantry) {
    char addMore;
    do {
        Recipe newRecipe;

        cout << "Enter the recipe title: ";
        getline(cin, newRecipe.title);

        // gather the ingredients for the recipe
        char addIng = 'y';
        cout << "--- Add Ingredients for " << newRecipe.title << " ---\n";
        while (addIng == 'y' || addIng == 'Y') {
            Ingredient ing;
            cout << "Ingredient name: ";
            getline(cin, ing.name);
            cout << "Amount required: ";
            cin >> ing.amount;
            cin.ignore();
            cout << "Unit (e.g. cups, grams, pcs, ounces, etc): ";
            getline(cin, ing.unit);

            newRecipe.ingredients.push_back(ing);
            cout << "Add another ingredient to this recipe? (y/n): ";
            cin >> addIng;
            cin.ignore();
        }

        // ask and store recipe instructions
        char addStep = 'y';
        cout << "--- Add Instructions for " << newRecipe.title << " ---\n";
        while (addStep == 'y' || addStep == 'Y') {
            string step;
            cout << "Enter the instruction line: ";
            getline(cin, step);
            newRecipe.instructions.push_back(step);
            cout << "Add another instruction line? (y/n): ";
            cin >> addStep;
            cin.ignore();
        }

        // automatic cost calculation from pantry
        calculateRecipeCost(newRecipe, pantry);
        cout << "Automatically calculated recipe cost: $" << fixed << setprecision(2) << newRecipe.cost << endl;
                
        // looking to see if recipe currently exists
        bool recipeFound = false;
        for (auto& existingRecipe : recipe) {
            if (toLowerCase(existingRecipe.title) == toLowerCase(newRecipe.title)) {
            existingRecipe = newRecipe;
            recipeFound = true;
            cout << "Match found! Updated existing recipe. \n";
            break;
        }
    }
    if (!recipeFound) {
        recipe.push_back(newRecipe);
        cout << "New recipe added to the cookbook. \n";
    }

        cout << "Cookbook updated! Add another recipe? (y/n): ";
        cin >> addMore;
        cin.ignore();
        cout << "\n";
    }
    while (addMore == 'y' || addMore == 'Y');

    saveRecipe(recipe);
}










// ========================================
//          The Program's Runtime
// ========================================
int main() {
    //loading stored data from our pantry.txt file and our recipe.txt file
    vector<PantryItem> myPantry = loadPantry();
    vector<Recipe> myRecipes = loadRecipe();
    
    char choice = '0'; //vaiable used to choose from a menu of options

    // a while loop that breaks when the user enters 4. This will continue running and asking for new inputs. 
    while (choice != '7') {

        // pantry menu text to explain the options
        cout << "\n=== DIGITAL PANTRY MENU ===\n";
        cout << "1. View Pantry Stock\n";
        cout << "2. Add / Update Stock\n";
        cout << "3. View Cookbook\n";
        cout << "4. Add / Update Recipes\n";
        cout << "5. Ready to Make Recipies\n";
        cout << "6. Consume / Remove Stock\n";
        cout << "7. Save & Exit\n";
        cout << "Enter your choice (1-7) "; 
        cin >> choice;      // recieves input choice
        cin.ignore();       // clears any additional temporary keyboard memory
        cout << "\n";


        // switch block that runs whatever case value stored from choice
        switch (choice) {

            // this case is to view the current list of ingredients in the pantry
            case '1': {
                //calling the display pantry function block
                displayPantry(myPantry);
                break;
            }


            // add / update pantry stock
            case '2': {
            updatePantry(myPantry);
            break;
            }


            // view the list of recipes currently stored (Still need to add a terminal for sections like breakfast, lunch and dinner, and a shortcut to ready to cook meals.)
            case '3': {
                viewRecipes(myRecipes);
                break;
            }


            // this adds a Recipe/updates an existing recipe
            case '4': {
            addRecipe(myRecipes, myPantry);
            break;
            }





            //
            case '5': {
                int recipeChoice = 0;
                if (myRecipes.empty()) {
                    cout << "Your cookbook is empty. Add recipes first.\n";
                    break;
                }

                cout << "=== RECIPES YOU CAN MAKE RIGHT NOW ===\n";
                int cookableCount = 0;

                // scanning and printing recipes the user has ingredients for
                for (size_t i = 0; i< myRecipes.size(); ++i) {
                    const auto& recipe = myRecipes[i];
                    bool canCookRecipe =  true;

                    // Check if every single ingredient is available for this recipe
                    for (const auto& ing: recipe.ingredients) {
                        bool foundInPantry = false;

                        for (const auto& pantryItem: myPantry) {
                            if (toLowerCase(ing.name) == toLowerCase(pantryItem.name)) {
                                foundInPantry = true;

                                if (pantryItem.quantity < ing.amount) {
                                    canCookRecipe = false;
                                }
                                break;
                            }
                        }
                        if (!foundInPantry) {
                            canCookRecipe = false;
                        }
                        if (!canCookRecipe) break;
                    }
                    if (canCookRecipe) {
                        cout << i+1 << ") " << recipe.title << " (Cost: $" << fixed << setprecision(2) << recipe.cost << ")\n";
                        cookableCount++;
                    }
                }
                if (cookableCount == 0) {
                    cout << "Unfortunately, your pantry is insufficiently stocked to complete any reccipes as they are.\n";
                    cout << "Go to the grocery store and restock the pantry\n";
                } else {
                    bool choosingRecipe = true;
                    do {
                        cout << "0) return to the main menu\n";
                        cout << "What recipe would you like to cook? (0 - " << myRecipes.size() << ") ";
                        cin >> recipeChoice;
                        cin.ignore();

                        if (recipeChoice > 0 && recipeChoice <= myRecipes.size()){
                            char confirmChoice;
                            cout << "You selected " << myRecipes[recipeChoice-1].title << ". Are you sure? (y/n) ";
                            cin >> confirmChoice;
                            cin.ignore();

                            if (confirmChoice == 'y' || confirmChoice == 'Y') {
                                const auto& selectedRecipe = myRecipes[recipeChoice-1];
                                // removing Items from the pantry
                                for (const auto& ing: selectedRecipe.ingredients) {
                                    for (auto& pantryItem : myPantry) {
                                        if (toLowerCase(ing.name) == toLowerCase(pantryItem.name)) {
                                            cout << ing.name << " was at " << pantryItem.quantity << " and is now at ";
                                            pantryItem.quantity -= ing.amount;
                                            cout << pantryItem.quantity << endl;
                                            break;
                                        }
                                    }
                                }

                                savePantry(myPantry);
                        
                                // printing the Recipe details
                                cout << "\n=================================\n";
                                cout << "Recipe: " << selectedRecipe.title << endl;
                                cout << "-------------------------------\n";
                                cout << "Ingredients needed:\n";
                                for (const auto& ing: selectedRecipe.ingredients) {
                                    cout << " - " << ing.name << ": " << ing.amount << " " << ing.unit << endl;
                                }
                                
                                cout << "\nInstruction:\n";
                                int stepNum = 1;
                                for (const auto& step: selectedRecipe.instructions) {
                                    cout << stepNum << ") " << step << endl;
                                    stepNum++;
                                }
                                cout << endl;

                                choosingRecipe = false;
                                cout << "Enjoy the food and recipe!\n";
                            } else{ }
                        } else{break;}
                    }
                    while(choosingRecipe);
                }
                break;
            }





            // wanting to make a specific recipe, regardless of what is in the pantry
            case '6': {
                // message for if trying to access recipes but none exist
                if (myRecipes.empty()) {
                    cout << "Your cookbook is empty. Add recipes first!\n";
                    break;
                }

                //prints an itemized list of recipes as a menu prompt
                cout << "=== SELECT A RECIPE ===\n";
                for (size_t i = 0; i < myRecipes.size(); ++i) {
                    cout << i + 1 << ") " << myRecipes[i].title << endl;
                }
                cout << "0) Return to the Main Menu\n";

                int recipeChoice;
                cout << "Enter the number associated with the recipe you want: ";
                cin >> recipeChoice;
                cin.ignore();

                if (recipeChoice == 0) {
                    break;
                }

                if (recipeChoice > 0 && recipeChoice <= static_cast<int>(myRecipes.size())) {
                    const auto& selctedRecipe = myRecipes[recipeChoice - 1];

                    cout << "\n=================================\n";
                    cout << "RECIPE: " << selctedRecipe.title << endl;
                    cout << "COST:   $" << fixed << setprecision(2) << selctedRecipe.cost << endl;
                    cout << "\n---------------------------------\n";

                    cout << "Ingredients needed:\n";
                    for (const auto& ing: selctedRecipe.ingredients) {
                        cout << " -" << ing.name << ": " << ing.amount << " " << ing.unit << endl;
                    }

                    cout << "\nInstructions:\n";
                    int stepNum = 1;
                    for (const auto& step: selctedRecipe.instructions) {
                        cout << "  " << stepNum << ") " << step << endl;
                        stepNum++;
                    }
                    cout << "==================================="; 
                } else {cout << "Invalid selction. Returning to the main menu.\n";}
                break;
            }





            //
            case '7': {
            savePantry(myPantry);
            saveRecipe(myRecipes);
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