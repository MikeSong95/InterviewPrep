/*
    LEETCODE #19 [Medium]
    https://leetcode.com/problems/remove-nth-node-from-end-of-list/

    Given a linked list, remove the n-th node from the end of list and return its head.

    Example:
        Given linked list: 1->2->3->4->5, and n = 2.
        After removing the second node from the end, the linked list becomes 1->2->3->5.
    
    Note:
        Given n will always be valid.

    Follow up:
        Could you do this in one pass?
*/


#include <stdlib.h>
#include <stdio.h>
#include <time.h> 
#include <limits.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
 
int count = 0;

/* recursively traverse until the end, then count as recursion unravels */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{    
    // base case
    if (head == NULL) {
        return head;
    } else {
        head->next = removeNthFromEnd(head->next, n);
        count++;
        
        // found node to remove
        if (count == n) {
            return head->next;
        }  else {
            return head;
        }
    }
}

// Driver function
int main (void)
{
    srand(time(0)); // Use current time as seed for random generator 

    struct ListNode *l1 = malloc(sizeof (struct ListNode));
    struct ListNode *l1_ptr = l1;

    /* Randomly generate a linked list of size [1,10], with numbers between [0,9] */

    int i1;
    int size = (rand() % 10) + 1; // generate a random number between 1 and 10

    // generate a random number representing n
    int n = (rand() % size) + 1;

    printf("n = %d\nL1 = ", n);

    for (i1 = 0; i1 < size; i1++)
    {
        /* make last node->next point to NULL */
        if (i1 + 1 != size) {
            int rand_digit = rand() % 10;    // generate a random number between 0 and 9
            l1_ptr->val = rand_digit;
            l1_ptr->next = malloc(sizeof (struct ListNode));
            l1_ptr = l1_ptr->next;

            printf("%d -> ", rand_digit);
        } else {
            /* no leading 0's for last digit */
            int rand_digit = rand() % 10;   
            l1_ptr->val = rand_digit;
            l1_ptr->next = NULL;

            printf("%d -> ", rand_digit);
        }
    }

    printf("NULL \n");

    struct ListNode *l2 = removeNthFromEnd(l1, n);

    /* print list with nth element removed */

    printf("L1 = ");
    while(l2 != NULL)
    {
        printf("%d -> ", l2->val);
        l2 = l2->next;
    }
    printf("NULL\n");

    return 0;
}