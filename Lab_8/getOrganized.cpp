/*
@date: 07/15/2026
@author: Michael Margolis
@purpose: this program reorganizes a an array into ascending order
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const int TOTAL_SIZE = 10;
    int numbers[TOTAL_SIZE] = {10,90,2,25,44,88,0,4};

    for (int n=0; n<TOTAL_SIZE;++n) {
        for (int y=0; y < TOTAL_SIZE;++y) {
            if (numbers[y] > numbers[y+1]) {
                int holdThis = numbers[y];
                numbers[y] = numbers[y+1];
                numbers[y+1] = holdThis;
            }
        }
    }
    for (int n=0;n<TOTAL_SIZE;++n) {
        cout << numbers[n] << endl;
    }
}