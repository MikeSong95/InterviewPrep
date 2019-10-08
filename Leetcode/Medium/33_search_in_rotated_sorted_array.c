/*
    LEETCODE #33 [Medium]
    https://leetcode.com/problems/search-in-rotated-sorted-array/

    Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

    (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

    You are given a target value to search. If found in the array return its index, otherwise return -1.

    You may assume no duplicate exists in the array.

    Your algorithm's runtime complexity must be in the order of O(log n).

    Example 1:
        Input: nums = [4,5,6,7,0,1,2], target = 0
        Output: 4

    Example 2:
        Input: nums = [4,5,6,7,0,1,2], target = 3
        Output: -1
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h> 

#define N 100   // number range of array

// modified binary search
// O(log n) runtime
int search(int* nums, int numsSize, int target)
{
    int l = 0;
    int r = numsSize - 1;
    
    // side cases
    if (numsSize == 1) {
        if (target == nums[0]) return 0;
        else return -1;
    } else if (numsSize == 0) {
        return -1;
    }

    while (l < r && l >= 0 && r >= 0 && l < numsSize  && r < numsSize)
    {
        if (target == nums[l]) {
            return l;
        } else if (target == nums[r]) {
            return r;
        } 
    
        int mid = (l + r) / 2;

        if (target == nums[mid]) {
            return mid;
        }
    
        if (nums[mid] > nums[r]) {          // pivot is on right half
            if (target > nums[mid]) {               // target is on right half
                l = mid + 1; 
            } else if (target > nums[r]) {          // target is on left half
                r = mid - 1;   
            } else if (target < nums[r]) {          // target is on right half
                l = mid + 1; 
            }
        } else if (nums[mid] < nums[r]) {   // pivot is on left half
            if (target < nums[mid]) {               // target is on left half
                r = mid - 1; 
            } else if (target < nums[r]) {          // target is on right half
                l = mid + 1;   
            } else if (target > nums[r]) {          // target is on left half
                r = mid - 1; 
            }
        } 
 
    }
    
    return -1;
}

// helper function to rotate array
// from ../Easy/189_rotate_array.c
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

int main (void)
{
    srand(time(0)); // Use current time as seed for random generator 

    int size = (rand() % 15) + 1; // generate a random number between 1 and 15 - this will be the length of array
    int k = (rand() % size*2);    // generate a random number between 0 and size*2 - 1: this will be rotation amount
    
    int *nums = malloc(size * sizeof(int));

    /* Implementation of the Knuth Algorithm for random number generation from https://stackoverflow.com/a/1608585 */
    int in, im;
    im = 0;
    for (in = 0; in < N && im < size; ++in) {
        int rn = N - in;
        int rm = size - im;
        if (rand() % rn < rm)    
            /* Take it */
            nums[im++] = in + 1; /* +1 since your range begins from 1 */
    }

    // either pick an existing value to target or a random value (50/50)
    int target = (rand() % 2) ? nums[rand() % size] : rand() % size;

    // rotate by a random amount
    rotate_v2(nums, size, k);

    int i;
    printf("nums = [%d", nums[0]);
    for (i = 1; i < size; i++)
    {
        printf(", %d", nums[i]);
    }
    printf("]\n");

    printf("target = %d\n", target);
    printf("%d\n", search(nums, size, target));

    return 0;
}