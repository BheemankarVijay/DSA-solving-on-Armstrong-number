#include <iostream>
#include <cmath>
using namespace std;

int precomputedPowers[10][10];

void precomputePowers(int maxDigits) {
    for (int digit = 0; digit <= 9; ++digit) {
        for (int power = 1; power <= maxDigits; ++power) {
            precomputedPowers[digit][power] = pow(digit, power);
        }
    }
}

bool isArmstrong(int n, int maxDigits) {
    int sum = 0;
    int temp = n;
    int d = log10(n) + 1; // Number of digits
    
    while (temp > 0) {
        int digit = temp % 10;
        sum += precomputedPowers[digit][d];
        temp /= 10;
    }
    return (sum == n);
}

int main() {
    int num;
    int maxDigits = 10; 
    precomputePowers(maxDigits);
    
    cout << "Enter a number: ";
    cin >> num;
    if (isArmstrong(num, maxDigits)) {
        cout << num << " is an Armstrong number." << endl;
    } else {
        cout << num << " is not an Armstrong number." << endl;
    }
    return 0;
}
