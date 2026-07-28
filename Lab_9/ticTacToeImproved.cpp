/*
@date: 07/19/2026
@author: Michael Margolis
@purpose: this program lets two players play tic-tac-toe
*/

// including the required c++ libraries
#include <iostream>

// using namespace std to remove needing std:: 
using namespace std;

void printBoard(string board[]){
    // printing the board to the console to initate the game by running through the board array
    for (int n = 0; n < 25; ++n) {
        // this checks if we need to move to the next like so the game lines up properly
        if (n == 5 || n== 10 || n==15 || n==20) {
            cout << endl;
        }
    // printing the board based on the nth index position
    cout << board[n];
    }    
}

void checkForWin(string board[], bool &win) {
    if (board[0] != "   " && board[0]==board[2] && board[0]==board[4] && board[2]==board[4]) {
        win = true;
    }
    if (board[10] != "   " && board[10]==board[12] && board[12]==board[14] && board[10]==board[14]) {
        win = true;
    }
    if (board[22] != "   " && board[22]==board[20] && board[22]==board[24] && board[20]==board[24]) {
        win = true;
    }
    if (board[0] != "   " && board[0]==board[10] && board[0]==board[20] && board[10]==board[20]) {
        win = true;
    }
    if (board[2] != "   " && board[2]==board[12] && board[2]==board[22] && board[12]==board[22]) {
        win = true;
    }
    if (board[4] != "   " && board[4]==board[14] && board[4]==board[24] && board[14]==board[24]) {
        win = true;
    }
    if (board[0] != "   " && board[0]==board[12] && board[0]==board[24] && board[12]==board[24]) {
        win = true;
    }
    if (board[4] != "   " && board[4]==board[12] && board[4]==board[20] && board[12]==board[20]) {
        win = true;
    }
}

// the main function beginning
int main() {
    system("chcp 65001 > nul");
    // setting up a constant variable for the number of turns to lock the amount of data an array can hold
    const int SIZE = 9;
    // setting up the tic tac toe board display as an array
    string board[25] = {"   ", "|", "   ", "|", "   ",
                        "---", "+", "---", "+", "---",
                        "   ", "|", "   ", "|", "   ",
                        "---", "+", "---", "+", "---",
                        "   ", "|", "   ", "|", "   "};

    //  setting up the menu of options for the player
    string playerOptionsMenu[SIZE] = {"1. Top Left", "2. Top Middle", "3. Top Right",
                                  "4. Middle Left", "5. Middle Middle", "6. Middle Right",
                                  "7. Bottom Left", "8. Bottom Middle", "9. Bottom Right"};

    // setting up a check for the players check list for if the input already existed
    string playerChoiceCheck[SIZE] = {"1", "2", "3",
                                    "4", "5", "6",
                                    "7", "8", "9"};
    
    // setting up a character switching variable
    char player = '1';
    
    // setting up a game decision history to store the decisions of both players
    string playerChoices[SIZE] = {};
    
    bool win = false;
    
    // printing an opening statement for beginning the match
    cout << "Welcome to tic-tac-toe. Are you ready to duel!\n\n";

    printBoard(board);

    // setting a for loop for the max number of turns a game of tic tac toe can go
    for (int x=0; x<9;++x) {

        // setting a boolean variable to relay if the input is a valid choice or not
        bool validChoice = false;

        // setting a boolean variable to relay if the choice has already been used in the past
        bool spotTaken = false;

        cout << endl;

        // setting a for loop to show what options are left available for the player
        for (int y=0; y < SIZE; ++y) {
            // setting a boolean variable that stores if a match was found
            bool foundYah = false;

            // setting a for loop to run through every indexed position of the playerChoiceCheck array for comparison
            for (int z = 0; z<SIZE;++z) {
                // an if statement the sets foundYah to true if it matches any position in the playerChoices array
                if (playerChoiceCheck[y] == playerChoices[z]) {
                    foundYah = true;
                }
            }
            // prints the indexed position value if the match was never found
            if (foundYah == false) {
                cout << playerOptionsMenu[y] << endl;
            }
        }

        // checks which player's move we are on
        if (player == '1') {
            // printing a message so the players know which term it is
            cout << "\nPlayer one:\n\n";

            // setting a while loop so the game doesn't move on until a valid move is picked by the player
            while (validChoice == false) {
                // setting a varianble to hold the input until it's confirmed to be valid
                string currentInput = "";

                // resetting spotTaken to false each loop through the while loop
                spotTaken = false;

                // asking user for which move they want to make
                cout << "Where would you like to go? ";
                cin >> currentInput;

                // setting a for loop to make sure the input didn't already get used
                for (int w = 0;w<x;++w) {
                    if (currentInput == playerChoices[w]) { spotTaken = true;}
                }

                // if input was a new position value then we update the board in the specific position,   //
                // turn validChoice true to break free of the while loop, and permenantly saves the input //
                // to playerChoices                                                                       //
                if (spotTaken == false) {
                if (currentInput == "1") {board[0] = " \033[34mO\033[0m "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput == "2") {board[2] = " \033[34mO\033[0m "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput == "3") {board[4] = " \033[34mO\033[0m "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput == "4") {board[10] = " \033[34mO\033[0m "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput == "5") {board[12] = " \033[34mO\033[0m "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput == "6") {board[14] = " \033[34mO\033[0m "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput == "7") {board[20] = " \033[34mO\033[0m "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput == "8") {board[22] = " \033[34mO\033[0m "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput == "9") {board[24] = " \033[34mO\033[0m "; validChoice = true; playerChoices[x]=currentInput;}
                // this if statement is for any input that is completely out of the scope of the game
                if (currentInput != "1" && currentInput != "2" && currentInput != "3" && 
                    currentInput != "4" && currentInput != "5" && currentInput != "6" && 
                    currentInput != "7" && currentInput != "8" && currentInput != "9") {
                        cout << "Invalid choice. Please try again";
                    }
                cout << endl;
                // if the spotTaken variable is true this will be displayed
            } else {cout << "Spot was already taken. Please Try Again\n";}
        }
        // switch which player is the active one
        player = '2';
        }
        else {
            cout << "\nPlayer two:\n\n";
            while (validChoice == false) {
                string currentInput = "";
                spotTaken = false;
                cout << "Where would you like to go? ";
                cin >> currentInput;
                for (int w = 0;w<x;++w) {
                    if (currentInput == playerChoices[w]) { spotTaken = true;}
                }
                if (spotTaken == false) {
                if (currentInput == "1") {board[0] = " \033[31mX\033[0m "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput == "2") {board[2] = " \033[31mX\033[0m "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput == "3") {board[4] = " \033[31mX\033[0m "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput == "4") {board[10] = " \033[31mX\033[0m "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput == "5") {board[12] = " \033[31mX\033[0m "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput == "6") {board[14] = " \033[31mX\033[0m "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput == "7") {board[20] = " \033[31mX\033[0m "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput == "8") {board[22] = " \033[31mX\033[0m "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput == "9") {board[24] = " \033[31mX\033[0m "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput != "1" && currentInput != "2" && currentInput != "3" && 
                    currentInput != "4" && currentInput != "5" && currentInput != "6" && 
                    currentInput != "7" && currentInput != "8" && currentInput != "9") {
                        cout << "Invalid choice. Please try again";
                    }
                cout << endl;
            } else {cout << "Spot was already taken. Please Try Again\n";}
        }
            player = '1';
        }

        cout << endl;
    checkForWin(board, win);
    if (win == true) {
        if (x % 2 == 0) {
            cout << "Player 1 Wins\n";
            printBoard(board);
            return 0;
        } else {
            cout << "Player 2 Wins\n";
            printBoard(board);
            return 0;
        }
    }
    printBoard(board);
    }
    cout << "\nThe Game ended in a draw!!! Cats Game!!!";
}