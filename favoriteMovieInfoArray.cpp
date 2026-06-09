/*
@author: Michael Margolis
@date: 06/01/2026
@purpose: This program prints a clean layout of my favorite movie and it's main characters
*/

// include the iostream library for input and output
#include <iostream>

//use the standard namespace to avoid having to use std:: before every standard library function
using namespace std;

int main()
{
    //Defining Variables
    string movieTitle, characters, description, barLine, blankLine, blankSplit, tableHead, headerSplit;
    
    //A blank collumn to use to space out when needed
    blankLine =  "#                                            #\n";
    
    //A blank bar to divide the page across it's length
    barLine =     "##############################################\n";

    //A blank split on a table 
    blankSplit =  "#                      |                     #\n";

    //a cross divider for under the header of the table
    headerSplit = "#----------------------|---------------------#\n";

    //A Actor/Actresses table header assigned to tableHead
    tableHead = "#   Characters         |   Actors/Actresses  #\n";

    //The title of the movie assigned to the variable movieTitle
    movieTitle = "#             Project Hail Mary              #\n";

    //The character and actor data assigned to the variable characters
    characters = {"#   Ryland Grace       |   Ryan Gosling      #\n"
                  "#   Eva Strat          |   Sandra Hüller    #\n"
                  "#   Rocky              |   James Ortiz       #\n"
                  "#   Officer Carl       |   Lionel Boyce      #\n"
                  "#   Olesya Ilyukhina   |   Milana Vayntrub   #\n"
    };          

    //An overview of the moview assigned to the variable description
    description = {"#                  Overview                  #\n"
                   "#   Science teacher Ryland Grace wakes up    #\n"
                   "#   on a spaceship with no recollection      #\n" 
                   "#   of who he is or how he got there. As     #\n"
                   "#   his memory slowly returns, he soon       #\n"
                   "#   discovers he must solve the riddle       #\n"
                   "#   behind a mysterious substance that's     #\n"
                   "#   causing the sun to die out. As details   #\n" 
                   "#   of the mission unravel, he calls on      #\n"
                   "#   his scientific training and sheer        #\n"
                   "#   ingenuity -- but he may not have to      #\n"
                   "#               do it alone.                 #\n"
    };

    // printing the "poster" of the my favorite movie 
    cout << barLine << blankLine << movieTitle << blankLine << barLine << blankSplit << tableHead << headerSplit << characters << barLine << blankLine << description << blankLine << barLine;

    return 0;
}