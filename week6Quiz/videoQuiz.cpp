/*
date: 7/2/2026
author: Mr. Talbert (Comments by Michael Margolis)
purpose: 
*/

// including the iostream library in c++
#include <iostream>

// using the namespace std to avoid needing to use std:: in front of code blocks
using namespace std;

// initializing a main function to run when the program is called
int main()
{
    int score;                      // initializing an integer variable without an assigned value
    int count = 0;                  // initializing an integer variable and assigning it a value of 0
    int passingScores = 0;          // initializing an integer variable and assigning it a value of 0
    float total = 0.0f;             // initializing a float variable and assigning it a value of 0.0f, which is strictly a float number and to use siingle precision
    bool continueEntering = true;   // intitializing a boolean variable to store the value of true

    // starting a while loop that loops while continue entering is true
    while (continueEntering)
    {
        // prints a prompt for the user to respond to and stores the response in the integer variable score
        cout << "Enter a test score (0 - 100): ";
        cin >> score;

        //adding score to the float variable total
        total += score;
        // increases the count vaiable by one, storing number of times the score was added to total
        count++;

        // an if statement to check if the score entered was a pass or a fail. if it was a pass, it increments passingScores by one
        if (score >= 70)
        {
            passingScores++;
        }

        // prints a question to either enter more scores or to exit the while loop by changing continueEntering to false or 0
        cout << "Enter another score? (1 for true, 0 for false): ";
        cin >> continueEntering;
    }

    float average = 0.0f;       // initializing a float variable and assigning it a value of 0.0f, which is strictly a float number and to use siingle precision

    // tests that count or number of times through the while loop was not more than 0 times
    if (count > 0)
    {
        // averages the summed up scores by the number of scores
        average = total / count;
    }

    // prints the final statements about the scores entered, the number of passing scores, and the overall average
    cout << "\nResults" << endl;
    cout << "-------" << endl;
    cout << "Scores Entered: " << count << endl;
    cout << "Passing Scores: " << passingScores << endl;
    cout << "Average Score: " << average << endl;

    // assignes a boolean variable the value of the comparison of the variable average is greater than or equal to 70.0f
    bool classPassed = average >= 70.0f;

    // prints if the class passed as a whole with the average of the scores entered
    cout << "Class Average Passing: " << classPassed << endl;

    // ends the main function
    return 0;
}
