/*
@date: 07/19/2026
@author: Michael Margolis
@purpose: this program lets two players play tic-tac-toe
*/

// including the required c++ libraries
#include <iostream>

// using namespace std to remove needing std:: 
using namespace std;

// the main function beginning
int main() {
    const int SIZE = 9;
    string board[25] = {"   ", "|", "   ", "|", "   ",
                        "---", "+", "---", "+", "---",
                        "   ", "|", "   ", "|", "   ",
                        "---", "+", "---", "+", "---",
                        "   ", "|", "   ", "|", "   "
    };
    string playerOptionsMenu[SIZE] = {"1. Top Left", "2. Top Middle", "3. Top Right",
                                  "4. Middle Left", "5. Middle Middle", "6. Middle Right",
                                  "7. Bottom Left", "8. Bottom Middle", "9. Bottom Right"};

    string playerChoiceCheck[SIZE] = {"1", "2", "3",
                                    "4", "5", "6",
                                    "7", "8", "9"};
    char player = '1';
    string playerChoices[SIZE] = {};
    int choiceCount = 0;
    bool win = false;

    cout << "Welcome to tic-tac-toe. Are you ready to duel!\n\n";
    for (int n = 0; n < 25; ++n) {
        if (n == 5 || n== 10 || n==15 || n==20) {
            cout << endl;
        }
    cout << board[n];
    }


    for (int x=0; x<9;++x) {
        bool validChoice = false;
        bool spotTaken = false;
        cout << endl;
        for (int y=0; y < SIZE; ++y) {
            bool foundYah = false;
            for (int z = 0; z<SIZE;++z) {
                if (playerChoiceCheck[y] == playerChoices[z]) {
                    foundYah = true;
                }
            }
            if (foundYah == false) {
                cout << playerOptionsMenu[y] << endl;
            }
        }
        if (player == '1') {
            cout << "\nPlayer one:\n\n";
            while (validChoice == false) {
                string currentInput = "";
                spotTaken = false;
                cout << "Where would you like to go? ";
                cin >> currentInput;
                for (int w = 0;w<x;++w) {
                    if (currentInput == playerChoices[w]) { spotTaken = true;}
                }
                if (spotTaken == false) {
                if (currentInput == "1") {board[0] = " O "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput == "2") {board[2] = " O "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput == "3") {board[4] = " O "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput == "4") {board[10] = " O "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput == "5") {board[12] = " O "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput == "6") {board[14] = " O "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput == "7") {board[20] = " O "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput == "8") {board[22] = " O "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput == "9") {board[24] = " O "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput != "1" && currentInput != "2" && currentInput != "3" && 
                    currentInput != "4" && currentInput != "5" && currentInput != "6" && 
                    currentInput != "7" && currentInput != "8" && currentInput != "9") {
                        cout << "Invalid choice. Please try again";
                    }
                cout << endl;
            } else {cout << "Spot was already taken. Please Try Again\n";}
        }
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
                if (currentInput == "1") {board[0] = " X "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput == "2") {board[2] = " X "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput == "3") {board[4] = " X "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput == "4") {board[10] = " X "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput == "5") {board[12] = " X "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput == "6") {board[14] = " X "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput == "7") {board[20] = " X "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput == "8") {board[22] = " X "; validChoice = true; playerChoices[x]=currentInput;}
                if (currentInput == "9") {board[24] = " X "; validChoice = true; playerChoices[x]=currentInput;}
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
        for (int n = 0; n < 25; ++n) {
            if (n == 5 || n== 10 || n==15 || n==20) {
                cout << endl;
            }
            cout << board[n];
        }
        cout << endl;
        if (board[0] != "   " && board[0]==board[2] && board[0]==board[4] && board[2]==board[4]) {
            if (x%2==0) {cout << "\nPlayer One Wins!!!";return 0;}
            else {cout << "\nPlayer Two Wins!!!";return 0;}
        }
        if (board[10] != "   " && board[10]==board[12] && board[12]==board[14] && board[10]==board[14]) {
            if (x%2==0) {cout << "\nPlayer One Wins!!!";return 0;}
            else {cout << "\nPlayer Two Wins!!!";return 0;}
        }
        if (board[22] != "   " && board[22]==board[20] && board[22]==board[24] && board[20]==board[24]) {
            if (x%2==0) {cout << "\nPlayer One Wins!!!";return 0;}
            else {cout << "\nPlayer Two Wins!!!";return 0;}
        }
        if (board[0] != "   " && board[0]==board[10] && board[0]==board[20] && board[10]==board[20]) {
            if (x%2==0) {cout << "\nPlayer One Wins!!!";return 0;}
            else {cout << "\nPlayer Two Wins!!!";return 0;}
        }
        if (board[2] != "   " && board[2]==board[12] && board[2]==board[22] && board[12]==board[22]) {
            if (x%2==0) {cout << "\nPlayer One Wins!!!";return 0;}
            else {cout << "\nPlayer Two Wins!!!";return 0;}
        }
        if (board[4] != "   " && board[4]==board[14] && board[4]==board[24] && board[14]==board[24]) {
            if (x%2==0) {cout << "\nPlayer One Wins!!!";return 0;}
            else {cout << "\nPlayer Two Wins!!!";return 0;}
        }
        if (board[0] != "   " && board[0]==board[12] && board[0]==board[24] && board[12]==board[24]) {
            if (x%2==0) {cout << "\nPlayer One Wins!!!";return 0;}
            else {cout << "\nPlayer Two Wins!!!";return 0;}
        }
        if (board[4] != "   " && board[4]==board[12] && board[4]==board[20] && board[12]==board[20]) {
            if (x%2==0) {cout << "\nPlayer One Wins!!!";return 0;}
            else {cout << "\nPlayer Two Wins!!!";return 0;}
        }
    }
    cout << "\nThe Game ended in a draw!!! Cats Game!!!";
}