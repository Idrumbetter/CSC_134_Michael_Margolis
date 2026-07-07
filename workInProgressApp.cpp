/*
date: 07/05/2026
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
    string unit;
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

// Main Menu
void mainMenu(char& choice){   
    cout << "\n=== DIGITAL PANTRY MENU ===\n";
    cout << "1. View Pantry Stock\n";
    cout << "2. View Cookbook\n";
    cout << "3. View Grocery List\n";
    cout << "4. Save & Exit\n";
    cout << "Enter your choice (1-4) "; 
    cin >> choice;      // recieves input choice
    cin.ignore();       // clears any additional temporary keyboard memory
    cout << "\n";
}

// prints the pantry sub menu
void pantryMenu(char& pantryChoice) {
    char pantryMenuChoice = '0';

    cout << "\n=== PANTRY MENU ===\n";
    cout << "1. View Current Stock\n";
    cout << "2. Add/Update Ingredients or Stock\n";
    cout << "3. Remove Ingredient From Pantry\n";
    cout << "4. Return to Main Menu\n";
    cout << "\nEnter Your Choice: (1-4) ";
    cin >> pantryChoice;
    cin.ignore();
    cout << "\n";
}

// prints the recipe sub menu

// prints asking if you want to add, remove, or update stock 
void cookbookMenu(char& choice) {
    cout << "\n=== COOKBOOK MENU ===\n";
    cout << "1. View Currently Stored Recipes\n";
    cout << "2. Add/Update Recipes\n";
    cout << "3. Remove Recipes\n";
    cout << "4. Back to Pantry Menu\n";
    cout << "Pick an option: (1-4) ";
    cin >> choice;
    cin.ignore();
}

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
        cout << "Pantry saved successfully!\n";
    } else {
        cout << "Error: Could not open pantry.txt for writing.\n";
    }
}

// removes ingredients from the pantry.txt file
void deleteIngredient(vector<PantryItem>& pantry) {
    string itemName;
    bool foundIngredient = false;
    char sure = '0';
    cout << "\nWhat ingredient do you want to delete? ";
    getline(cin, itemName); 
    cout << endl;

    for (size_t i = 0; i < pantry.size(); ++i) {
        if (toLowerCase(pantry[i].name) == toLowerCase(itemName)) {
            foundIngredient = true;

            cout << "Are you sure you want to remove this ingredient from your pantry list? (y/n)";
            cin >> sure;
            cin.ignore();

            if (sure == 'y' || sure == 'Y') {
                pantry.erase(pantry.begin()+i);
                cout << itemName << " was removed from the pantry.\n\n";
            break;
            } else {
                cout << "The ingredient was not deleted. \n\n";
            }
        }
    }
    if (!foundIngredient) {
        cout << "Ingredient was not found.\n\n";
    }
    savePantry(pantry);
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
        string unitStr;
        string priStr;

        while (getline(inFile, name)) {
            if (getline(inFile, qtyStr) && 
                getline(inFile, unitStr) && 
                getline(inFile, priStr)) {

                try {
                    double quantity = stod(qtyStr);
                    double price = stod(priStr);
                
                    loadedPantry.push_back({name, quantity, unitStr, price});
                }
                catch (const exception& e) {
                    cout << "Error finding data for item '" << name << "'. Skipping line.\n";
                }
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


// prints the ingredients stored in the pantry.txt file
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
                 << " | Unit: " << item.unit
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

        cout << "Enter the unit: ";
        cin >> newItem.unit;

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

void deleteRecipe(vector<Recipe>& recipe) {
    string recipeName;
    bool foundRecipe = false;
    char sure = '0';

    if (recipe.empty()) {
        cout << "\nYour cookbook is currently empty. There are no recipes to delete.\n";
        return;
    }

    for (size_t i = 0; i < recipe.size(); ++i) {
        cout << i+1 << ") " << recipe[i].title << endl;
    }
    cout << "--------------------------------\n";

    if (cin.peek() == '\n') {
        cin.ignore();
    }
    cout <<"What recipe do you wish to delete? ";
    getline(cin, recipeName);
    cout << endl;

    for (size_t i = 0; i < recipe.size(); ++i) {
        if (toLowerCase(recipe[i].title) == toLowerCase(recipeName)) {
            foundRecipe = true;

            cout << "Are you sure you want to remove this recipe from your cookbook? (y/n) ";
            cin >> sure;
            cin.ignore();

            if (sure == 'y' || sure == 'Y') {
                recipe.erase(recipe.begin()+i);
                cout << recipeName << " was removed from your cookbook.\n\n";
            break;
            } else {
                cout << "The recipe was not deleted. \n\n";
            }
        }
    }
    if (!foundRecipe) {
        cout << "Recipe  was not found.\n\n";
    }
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
    char pantryChoice = '0';
    char cookbookChoice = '0';

    // a while loop that breaks when the user enters 4. This will continue running and asking for new inputs. 
    while (choice != '4') {

        mainMenu(choice);

        // switch block that runs whatever case value stored from choice
        switch (choice) {

            // this case is to view the current list of ingredients in the pantry
            case '1': {
                pantryChoice = '0';
                while (pantryChoice != '4') {
                    pantryMenu(pantryChoice);

                    switch (pantryChoice) {
                        case '1': {
                            displayPantry(myPantry);
                            break;
                        }

                        case '2': {
                            updatePantry(myPantry);
                            break;
                        }
                        
                        case '3': {
                            // deleting pantry ingredients from the .txt file
                            displayPantry(myPantry);
                            deleteIngredient(myPantry);
                            break;
                        }
                        case '4': {
                            // saves pantry and exits to main menu
                            savePantry(myPantry);
                            break;
                        }
                        default: {
                            cout << "Invalid Selection. Please Select From Our Menu. \n";
                        }
                    }
                }
                cout << "Returning to the Main Menu...\n";
                break;
            }

            case '2': {
                //open the cookbook menu
                cookbookChoice = '0';
                while (cookbookChoice!= '4') {
                    cookbookMenu(cookbookChoice);

                    switch (cookbookChoice) {
                        case '1': {
                            viewRecipes(myRecipes);
                            break;
                        }

                        case '2': {
                            addRecipe(myRecipes, myPantry);
                            break;
                        }

                        case '3': {
                            //remove recipes
                            deleteRecipe(myRecipes);
                            break;
                        }
                        case '4': {
                            saveRecipe(myRecipes);
                            break;
                        }
                        default: {
                            if (cookbookChoice!='4') {
                                cout << "Error. Invalid input recieved.\n";
                            }
                            break;
                        }
                    }
                }
                cout << "Returning to the Main Menu...\n";
                break;
            }

            case '3': {
                //Grocery List
                break;
            }

            case '4': {
                savePantry(myPantry);
                saveRecipe(myRecipes);
                cout << "Closing the program. Thanks for staying up to date!\n";
            }
        }
    }         
}