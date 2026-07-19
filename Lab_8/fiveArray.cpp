/*
@date: 07/15/2026
@author: Michael Margolis
@purpose: this program sets an array to take 5 integers and sums them
*/

#include <iostream>

using namespace std;

int main() {
    
    int sumArray[5] = {23, 14, 18, 16, 34};
    int sum = 0;

    for (int n=0; n < 5;++n) {
        sum += sumArray[n];
    }
    cout << "The sum of the array is " << sum << endl;
    return 0;
}