/**
 * Problem 4:
 * 
 * A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include <iostream>
#include <math.h>

using namespace std;

bool isPalindrome(int n) {
    int div = 1;
    
    while (n / div >= 10) {
        div *= 10;
    }

    while (n != 0) {
        int digit_r = n % 10;
        int digit_l = n / div;

        if (digit_r != digit_l) {
            return false;
        }

        n = (n % div) / 10;
        div /= 100;
    }

    return true;
}

bool hasThreeDigitFactors(int n) {
    for(int i = 999; i >= 100; i--) {
        if (n % i == 0 && n/i >= 100 && n/i <= 999) {
            return true;
        }
    }
    return false;
}

int main(void) {
    for (int i = 998001; i > 10000; i--) {
        if (isPalindrome(i) && hasThreeDigitFactors(i)) {
            cout << i << endl;
            break;
        }
    }
}