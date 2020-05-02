/**
 * Problem 3:
 * 
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143 ?
 */

#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int n) {
    bool isPrime = true;

    for (int i = 2; i < n/2; i++) {
        if (n % i == 0) {
            isPrime = false;
        }
    }

    return isPrime;
}

int main(void) {
    double num = sqrt(600851475143);

    for (int i = num; i > 0; i--) {
        if (600851475143 % i == 0) {
            if (isPrime(i)) {
                cout << i << endl;
                break; 
            }
        }
    }
}