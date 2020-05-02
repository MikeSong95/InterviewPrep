/**
 * Problem 4:
 * 
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 */

#include <iostream>
#include <math.h>

using namespace std;

bool isSol(int num) {
    for (int i = 1; i < 20; i++) {
        if (num % i != 0) {
            return false;
        }
    }

    return true;
}

int main(void) {
    int num = 20;

    while (!isSol(num)) {
        num++;
    }

    cout << num << endl;
}