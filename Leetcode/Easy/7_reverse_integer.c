/*
    LEETCODE #7 [Easy]
    https://leetcode.com/problems/reverse-integer/

    Given a 32-bit signed integer, reverse digits of an integer.

    Example 1:
        Input: 123
        Output: 321

    Example 2:
        Input: -123
        Output: -321
    
    Example 3:
        Input: 120
        Output: 21
    
    Note:
        Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. 
        For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h> 
#include <limits.h>

int reverse(int x) 
{
    // reversed integer init to 0
    int reversed = 0;
    
    while (x != 0)
    {
        int digit = x % 10; // get next digit (right to left)
        x /= 10;            // pop digit off

        // check if it's going to cause an overflow
        if (reversed > INT_MAX/10) return 0;
        if (reversed < INT_MIN/10) return 0;

        // add digit to reversed integer
        reversed = reversed * 10 + digit;
    }
    
    return reversed;
}

// Helper funtion to generate a random 32-bit signed integer between INT_MIN and INT_MAX
// Fill each byte of a union memory space of size int with a rand value, then read the entire memory space as an integer
int rand_int(void) 
{
    union {
        int i;
        unsigned char uc[sizeof (int)];
    } u;

    for (size_t i = 0; i < sizeof u.uc; i++) 
        u.uc[i] = rand();

    return u.i;
}

// Driver function
int main (void) 
{
    srand(time(0)); // Use current time as seed for random generator 

    int num = rand_int();
    int num_reversed = reverse(num);

    printf("Number: %d\n", num);
    printf("Reverse: %d\n", num_reversed);

    return 0;
}