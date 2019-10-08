/*
    LEETCODE #189 [Easy]
    https://leetcode.com/problems/rotate-array/

    Given an array, rotate the array to the right by k steps, where k is non-negative.

    Example 1:
        Input: [1,2,3,4,5,6,7] and k = 3
        Output: [5,6,7,1,2,3,4]
        Explanation:
            rotate 1 steps to the right: [7,1,2,3,4,5,6]
            rotate 2 steps to the right: [6,7,1,2,3,4,5]
            rotate 3 steps to the right: [5,6,7,1,2,3,4]

    Example 2:
        Input: [-1,-100,3,99] and k = 2
        Output: [3,99,-1,-100]
        Explanation: 
            rotate 1 steps to the right: [99,-1,-100,3]
            rotate 2 steps to the right: [3,99,-1,-100]

    Note:
        Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
        Could you do it in-place with O(1) extra space?
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Not in-place
// O(2n) runtime
// O(n) memory
// Faster runtime for more memory
void rotate(int* nums, int numsSize, int k) 
{
    // 1 or 0 elements - do nothing
    if (numsSize <= 1) return;
    
    // handle wrap around k
    if (k > numsSize) k = k - numsSize;
    
    int *arr1 = nums;                    // first half of array
    int *arr2 = nums + numsSize - k;     // second half of array
    int *arr3 = malloc(sizeof(int) * numsSize);
    
    int i,j;
    for (i = 0; i < k; i++)
        arr3[i] = arr2[i];
        
    for (i = k, j = 0; i<numsSize; i++, j++)
        arr3[i] = arr1[j];
    
    for (i = 0; i < numsSize; i++)
       nums[i] = arr3[i];
}

// In-place
// O(kn) runtime, k = number of iterations (numsSize - k)
// O(1) memory
// Better memory for slower runtime
void rotate_v2(int* nums, int numsSize, int k) 
{
    // 1 or 0 elements - do nothing
    if (numsSize <= 1) return;
    
    // handle wrap around k
    if (k > numsSize) k = k - numsSize;
    
    int i, iter;
    for (iter = 0; iter < numsSize - k; iter++)
        for (i = 0; i < numsSize - 1; i++)
        {
            int temp = nums[i];
            nums[i] = nums[i+1];
            nums[i+1] = temp;
        }
}

int main(void)
{
    srand(time(0)); // Use current time as seed for random generator 

    int size = (rand() % 15)+1;     // generate a random number between 1 and 15 - this will be the length of array
    int k = (rand() % size*2)+1;    // generate a random number between 1 and size*2 - this will be k
    int *nums = malloc(size * sizeof(int));

    /* Randomly generate an array of size between [1,10000], of 0s and 1s */

    int i;
    for (i = 0; i < size; i++)
    {
        int rand_digit = rand() % 11;    // generate a random number between 0 and 10 - digits don't matter for this solution
        nums[i] = rand_digit;
    }

    printf("nums = [%d", nums[0]);
    for (i = 1; i < size; i++)
    {
        printf(", %d", nums[i]);
    }
    printf("]\n");

    printf("k = %d\n",k);

    /* Comment out one of the rotate functions below to test the other */

    rotate(nums, size, k);
    // rotate_v2(nums, size, k);

    printf("nums = [%d", nums[0]);
    for (i = 1; i < size; i++)
    {
        printf(", %d", nums[i]);
    }
    printf("]\n");
}