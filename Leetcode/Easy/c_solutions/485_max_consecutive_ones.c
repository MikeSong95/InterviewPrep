/*
    LEETCODE #485 [Easy]
    https://leetcode.com/problems/max-consecutive-ones/

    Given a binary array, find the maximum number of consecutive 1s in this array.

    Example 1:
        Input: [1,1,0,1,1,1]
        Output: 3
    
    Note:
        The input array will only contain 0 and 1.
        The length of input array is a positive integer and will not exceed 10,000
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findMaxConsecutiveOnes(int* nums, int numsSize)
{
    int most_consecutive = 0;
    int curr_consecutive = 0;
    
    int i;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] == 1) {
            curr_consecutive++;
        } else {
            if (curr_consecutive > most_consecutive)
                most_consecutive = curr_consecutive;
            
            curr_consecutive = 0;
        }
    }
    
    if (curr_consecutive > most_consecutive)
        most_consecutive = curr_consecutive;
    
    return most_consecutive;
}

int main(void)
{
    srand(time(0)); // Use current time as seed for random generator 

    // array size 15 for output readability, change to 10000 if you want an array up to size 10000 (as instructions indicate)
    int size = (rand() % 15)+1; // generate a random number between 1 and 15 - this will be the length of array

    int *nums = malloc(size * sizeof(int));

    /* Randomly generate an array of size between [1,10000], of 0s and 1s */

    int i;
    for (i = 0; i < size; i++)
    {
        int rand_digit = rand() % 2;    // generate a random 0 or 1
        nums[i] = rand_digit;
    }

    printf("nums = [%d", nums[0]);
    for (i = 1; i < size; i++)
    {
        printf(", %d", nums[i]);
    }
    printf("]\n");

    printf("%d\n", findMaxConsecutiveOnes(nums, size));
}