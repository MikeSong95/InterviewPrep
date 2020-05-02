#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int l, int m, int r)
{

}

void mergesort(int *arr, int l,  int r)
{
    if (l < r) {
        int middle = (l + r) / 2;

        // mergesort on first half
        mergesort(arr, l, middle);
        // mergesort on second half
        mergesort(arr, middle+1, r);
        // merge
        merge(arr, l, middle, r); 
    }
}
