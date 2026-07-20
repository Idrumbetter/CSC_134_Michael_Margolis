/*
@date: 07/15/2026
@author: Michael Margolis
@purpose: this program reorganizes a an array into ascending order
*/

// including the necessary libraries from c++
#include <iostream>
#include <iomanip>

// using the namespace std to avoid having to write std::
using namespace std;

// initializing the main function
int main() {

    // initializing a constant variable size for setting the array size
    const int SIZE = 10;
    // initializing an array and asigning values in the specified order
    int numbers[SIZE] = {10,90,2,25,44,88,0,4};

    // priting the original array before organizing it
    cout << "The original array was: ";
    for (int n=0;n<SIZE;++n) {
        if (n==SIZE-1) {
            cout << "and " << numbers[n];    
        } else {
        cout << numbers[n] << ", ";
        }
    }

    // starting the bubble sorting process
    cout << "\n\nThe newly organized array is: ";
    // you only need to run the check to before the last letter as the highest number will always end there
    for (int n=0; n<SIZE-1;++n) {

        // each loop though requires less checks as the array gets organized
        for (int y=0; y < SIZE-n-1;++y) {

            // checking if the current number is bigger than the next one in the array
            if (numbers[y] > numbers[y+1]) {
                // temporarily storing the current positions value
                int holdThis = numbers[y];
                // assigns the value of the next position to the current one
                numbers[y] = numbers[y+1];
                // assigns the temporarily held value to the next position
                numbers[y+1] = holdThis;
            }
        }
    }

    // printing the freshly organized array to the terminal 
    for (int n=0;n<SIZE;++n) {
        if (n==SIZE-1) {
            cout << "and " << numbers[n];    
        } else {
        cout << numbers[n] << ", ";
        }
    }
    return 0;
}