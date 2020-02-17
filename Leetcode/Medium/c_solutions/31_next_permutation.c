/*
    LEETCODE #31 [Medium]
    https://leetcode.com/problems/next-permutation/

    Implement next permutation, which re-arranges numbers into the lexicographically next greater permutation of numbers.
    If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
    The replacement must be in-place and use only constant extra memory.
    
    Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

    1,2,3 → 1,3,2
    3,2,1 → 1,2,3
    1,1,5 → 1,5,1
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h> 

/* Mergesort implementation from https://www.geeksforgeeks.org/in-place-algorithm/ */

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
// Inplace Implmentation 
void merge(int arr[], int start, int mid, int end) 
{ 
    int start2 = mid + 1; 
  
    // If the direct merge is already sorted 
    if (arr[mid] <= arr[start2]) { 
        return; 
    } 
  
    // Two pointers to maintain start 
    // of both arrays to merge 
    while (start <= mid && start2 <= end) { 
  
        // If element 1 is in right place 
        if (arr[start] <= arr[start2]) { 
            start++; 
        } 
        else { 
            int value = arr[start2]; 
            int index = start2; 
  
            // Shift all the elements between element 1 
            // element 2, right by 1. 
            while (index != start) { 
                arr[index] = arr[index - 1]; 
                index--; 
            } 
            arr[start] = value; 
  
            // Update all the pointers 
            start++; 
            mid++; 
            start2++; 
        } 
    } 
} 
  
/* l is for left index and r is right index of the  
   sub-array of arr to be sorted */
void sort_asc(int *arr, int l, int r) 
{ 
    if (l < r) { 
  
        // Same as (l + r) / 2, but avoids overflow 
        // for large l and r 
        int m = l + (r - l) / 2; 
  
        // Sort first and second halves 
        sort_asc(arr, l, m); 
        sort_asc(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

void nextPermutation(int* nums, int numsSize)
{
    if (numsSize <= 1) return;

    int swap_pos = numsSize - 2;
    int ptr_pos = numsSize - 1;

    // pointer to last value
    int *ptr = (nums + ptr_pos);
    // pointer to second last value
    int *swap = (nums + swap_pos);

    int swapped = 0;

    while (swap_pos >= 0 && swapped == 0)
    {
        if (*ptr > *swap) {
            // move pointer back to the end of the array
            ptr = (nums + numsSize - 1);
            ptr_pos = numsSize - 1;
            
            while (*ptr <= *swap) {
                ptr--;
                ptr_pos--;
            }
            
            // swap the values
            int temp = *ptr;
            *ptr = *swap;
            *swap = temp;
            
            // sort remaining array ascending
            swap++;
            swap_pos++;
            sort_asc(swap, 0, numsSize-swap_pos-1);
            
            // flag as swapped
            swapped = 1;
        }

        // decrement pointers
        swap--;
        swap_pos--;
        ptr--;
        ptr_pos--;
    }
    
    // swapped == 0 => fully in descending order -> need to sort in ascending order
    if (!swapped) sort_asc(nums, 0, numsSize-1);
}

// Driver function
int main(void)
{
   srand(time(0)); // Use current time as seed for random generator 

    int size = (rand() % 10) + 1; // generate a random number between 1 and 10 - this will be the length of array

    int *nums = malloc(size * sizeof(int));

    /* Randomly generate an array of size between [1,10], with numbers between [0,9] */

    int i;
    for (i = 0; i < size; i++)
    {
        int rand_digit = rand() % 10;    // generate a random number between 0 and 9
        nums[i] = rand_digit;
    }

    printf("nums = [%d", nums[0]);
    for (i = 1; i < size; i++)
    {
        printf(", %d", nums[i]);
    }
    printf("]\n");

    nextPermutation(nums, size);
    
    printf("nums = [%d", nums[0]);
    for (i = 1; i < size; i++)
    {
        printf(", %d", nums[i]);
    }
    printf("]\n");

    return 0;
}