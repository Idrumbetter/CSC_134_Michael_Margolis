/*
@date: 07/15/2026
@author: Michael Margolis
@purpose: this program sets an array to take 10 grades and averages them
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const int size = 10;
    int gradeArray[size];
    int sum = 0;

    for (int n=0; n<size;++n) {
        cout << "Enter grade " << n+1 << ": ";
        cin >> gradeArray[n];
        cin.ignore();

        sum += gradeArray[n];
    }

    cout << "The gradepoint average was %" << fixed << setprecision(2) << sum/10.00 << endl;
    return 0;
}