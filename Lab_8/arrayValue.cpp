/*
@date: 07/15/2026
@author: Michael Margolis
@purpose: this program prints the value of an array at each position
*/

#include <iostream>

using namespace std;

int main() {
    const int size = 7;
    int array[size] = {1,2,4,8};

    cout << "The value of each position of the array are in order as such:\n";
    for (int n=0; n<size;++n) {
        cout << "Position " << n+1 << ": " << array[n] << endl;
    }
    return 0;
}