#include <iostream>
#include <cmath>
using namespace std;

bool isArmstrong(int n) {
    int sum = 0;
    int temp = n;
    int d = log10(n) + 1; // Number of digits
    
    while (temp > 0) {
        int digit = temp % 10;
        sum += pow(digit, d);
        temp /= 10;
    }
    return (sum == n);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if (isArmstrong(num)) {
        cout << num << " is an Armstrong number." << endl;
    } else {
        cout << num << " is not an Armstrong number." << endl;
    }
    return 0;
}
