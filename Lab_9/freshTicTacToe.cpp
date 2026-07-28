/*



*/

#include <iostream>

using namespace std;

void printBoard(string board[]) {
    // printing the board to the console to initate the game by running through the board array
    for (int n = 0; n < 25; ++n) {
        // this checks if we need to move to the next like so the game lines up properly
        if (n == 5 || n== 10 || n==15 || n==20) {
            cout << endl;
        }
    // printing the board based on the nth index position
    cout << board[n];
    }
    cout << endl;    
}

void storeMove(string currentInput, string board[], bool &validChoice, string playerChoices[], int x) {
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
        currentInput != "7" && currentInput != "8" && currentInput != "9") {cout << "Invalid choice. Please try again";}
    cout << endl;
}

void availableChoices(string playerChoiceCheck[], string playerChoices[], string playerOptionsMenu[]) {
    // setting a for loop to show what options are left available for the player
    for (int y=0; y < 9; ++y) {
        // setting a boolean variable that stores if a match was found
        bool foundYah = false;

        // setting a for loop to run through every indexed position of the playerChoiceCheck array for comparison
        for (int z = 0; z<9;++z) {
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
}

void makingDecision(int x, string playerChoices[], string board[], string activePlayer) {
    int boardIndices[] = {0,2,4,10,12,14,20,22,24};
    bool validChoice = false;
    bool spotTaken = false;

    // if input was a new position value then we update the board in the specific position,   //
    // turn validChoice true to break free of the while loop, and permenantly saves the input //
    // to playerChoices                                                                       //    
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

        if (spotTaken == false) {
            if (currentInput >= "1" && currentInput <= "9") {
                int choiceIndex = currentInput[0] - '1';
                int boardPos = boardIndices[choiceIndex];

                if (activePlayer == "Player One:") {
                    board[boardPos] = "\033[34m O \033[0m";
                } else {
                    board[boardPos] = "\033[31m X \033[0m";
                }

                validChoice = true;
                playerChoices[x] = currentInput;
            } else {cout << "Invalid choice. Please try again.\n";}
        } else {cout << "This spot is already take. Try another spot.\n";}
    }
}

void winCheck(string board[], bool &win) {
    string highlightStart = "\033[7m";
    if (board[0] != "   " && board[0]==board[2] && board[0]==board[4] && board[2]==board[4]) {
        board[0] = highlightStart + board[0]; board[2] = highlightStart + board[2]; board[4] = highlightStart + board[4];
        win = true;}
    if (board[10] != "   " && board[10]==board[12] && board[12]==board[14] && board[10]==board[14]) {
        board[10] = highlightStart + board[10]; board[12] = highlightStart + board[12]; board[14] = highlightStart + board[14];
        win = true;}
    if (board[22] != "   " && board[22]==board[20] && board[22]==board[24] && board[20]==board[24]) {
        board[20] = highlightStart + board[20]; board[22] = highlightStart + board[22]; board[24] = highlightStart + board[24];
        win = true;}
    if (board[0] != "   " && board[0]==board[10] && board[0]==board[20] && board[10]==board[20]) {
        board[0] = highlightStart + board[0]; board[10] = highlightStart + board[10]; board[20] = highlightStart + board[20];
        win = true;}
    if (board[2] != "   " && board[2]==board[12] && board[2]==board[22] && board[12]==board[22]) {
        board[2] = highlightStart + board[2]; board[22] = highlightStart + board[22]; board[12] = highlightStart + board[12];
        win = true;}
    if (board[4] != "   " && board[4]==board[14] && board[4]==board[24] && board[14]==board[24]) {
        board[4] = highlightStart + board[4]; board[14] = highlightStart + board[14]; board[24] = highlightStart + board[24];
        win = true;}
    if (board[0] != "   " && board[0]==board[12] && board[0]==board[24] && board[12]==board[24]) {
        board[0] = highlightStart + board[0]; board[12] = highlightStart + board[12]; board[24] = highlightStart + board[24];
        win = true;}
    if (board[4] != "   " && board[4]==board[12] && board[4]==board[20] && board[12]==board[20]) {
        board[4] = highlightStart + board[4]; board[12] = highlightStart + board[12]; board[20] = highlightStart + board[20];
        win = true;}
}

int main()  {
    string board[25] = {"   ", "|", "   ", "|", "   ",
                        "---", "+", "---", "+", "---",
                        "   ", "|", "   ", "|", "   ",
                        "---", "+", "---", "+", "---",
                        "   ", "|", "   ", "|", "   "};

    string playerOptionsMenu[9] = {"1. Top Left", "2. Top Middle", "3. Top Right",
                                   "4. Middle Left", "5. Middle Middle", "6. Middle Right",
                                   "7. Bottom Left", "8. Bottom Middle", "9. Bottom Right"};

    // setting up a check for the players check list for if the input already existed
    string playerChoiceCheck[9] = {"1", "2", "3",
                                   "4", "5", "6",
                                   "7", "8", "9"};

    string activePlayer = "Player One:";

    string playerChoices[9] = {};
    bool win = false;

    int x = 0;
    while (x<9 && !win) {
        // 1. Force VS Code terminal to clear completely
        #ifdef _WIN32
            system("cls");  
        #else
            system("clear"); 
        #endif

        cout << endl << activePlayer << endl;
        printBoard(board);
        availableChoices(playerChoiceCheck, playerChoices, playerOptionsMenu);
        makingDecision(x, playerChoices, board, activePlayer);
        if (activePlayer == "Player One:") {
            activePlayer = "Player Two:";
        } else {activePlayer = "Player One:";}
        winCheck(board, win);
        x++;
    }
    // 1. Force VS Code terminal to clear completely
    #ifdef _WIN32
        system("cls");  
    #else
        system("clear"); 
    #endif

    printBoard(board);
    if (win) {
        if (activePlayer == "Player One:") {cout << "Player Two Wins!!!\n";} 
        else {cout << "Player One Wins!!!\n";}
    } else {
        cout << "The game ended in a Cat's Game!\n";
    }
    return 0;
}