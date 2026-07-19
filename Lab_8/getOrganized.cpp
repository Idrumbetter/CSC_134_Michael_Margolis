/*
@date: 07/15/2026
@author: Michael Margolis
@purpose: this program reorganizes a an array into ascending order
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const int SIZE = 10;
    int numbers[SIZE] = {10,90,2,25,44,88,0,4};

    cout << "The original array was: ";
    for (int n=0;n<SIZE;++n) {
        if (n==SIZE-1) {
            cout << "and " << numbers[n];    
        } else {
        cout << numbers[n] << ", ";
        }
    }

    cout << "\n\nThe newly organized array is: ";
    for (int n=0; n<SIZE-1;++n) {
        for (int y=0; y < SIZE-n-1;++y) {
            if (numbers[y] > numbers[y+1]) {
                int holdThis = numbers[y];
                numbers[y] = numbers[y+1];
                numbers[y+1] = holdThis;
            }
        }
    }
    for (int n=0;n<SIZE;++n) {
        if (n==SIZE-1) {
            cout << "and " << numbers[n];    
        } else {
        cout << numbers[n] << ", ";
        }
    }
    return 0;
}