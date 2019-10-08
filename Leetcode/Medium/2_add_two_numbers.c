/*
    LEETCODE #2 [Medium]
    https://leetcode.com/problems/add-two-numbers/

    You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.
    
    Example:
        Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
        Output: 7 -> 0 -> 8
        Explanation: 342 + 465 = 807.
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h> 

// Definition for singly-linked list.
struct ListNode 
{
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int carry = 0;

    struct ListNode *head = malloc(sizeof (struct ListNode));
    struct ListNode *ptr = head;

    while (l1 != NULL || l2 != NULL)
    {
        int value = 0;
        if (l1 == NULL) {
            value += l2->val + carry;
            /* compute carry */
            if (l2->val + carry >= 10) {
                carry = 1;
                value -= 10;
            } else {
                carry = 0;
            }
            l2 = l2->next;
        } else if (l2 == NULL) {
            value += l1->val + carry; 
            /* compute carry */
            if (l1->val + carry >= 10) {
                carry = 1;
                value -= 10;
            } else {
                carry = 0;
            }
            l1 = l1->next;
        }
        else {
            value += l1->val + l2->val + carry;
            /* compute carry */
            if (l1->val + l2->val + carry >= 10) {
                carry = 1;
                value -= 10;
            } else {
                carry = 0;
            }
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        ptr->val = value;

        /* don't allocate memory if we're done */
        if (l1 != NULL || l2 != NULL) {
            ptr->next = malloc(sizeof (struct ListNode));
            ptr = ptr->next;
        } else {
            /* check for extranneous carry value */
            if (carry == 1) {
                ptr->next = malloc(sizeof (struct ListNode));
                ptr = ptr->next;
                ptr->val = carry;
            }

            ptr->next = NULL;
        }
    }

    return head;
}

// Driver function
int main(void)
{
    srand(time(0)); // Use current time as seed for random generator 

    struct ListNode *l1 = malloc(sizeof (struct ListNode));
    struct ListNode *l1_ptr = l1;
    
    struct ListNode *l2 = malloc(sizeof (struct ListNode));
    struct ListNode *l2_ptr = l2;

    /* Randomly generate l1 and l2 to be numbers with 1 - 12 digits */

    int i1, i2;
    int num_digits_1 = (rand() % 20) + 1; // generate a random number between 1 and 20
    int num_digits_2 = (rand() % 20) + 1; // generate a random number between 1 and 20

    printf("L1 = ");

    for (i1 = 0; i1 < num_digits_1; i1++)
    {
        /* make last node->next point to NULL */
        if (i1 + 1 != num_digits_1) {
            int rand_digit = rand() % 10;    // generate a random number between 0 and 9
            l1_ptr->val = rand_digit;
            l1_ptr->next = malloc(sizeof (struct ListNode));
            l1_ptr = l1_ptr->next;

            printf("%d -> ", rand_digit);
        } else {
            /* no leading 0's for last digit */
            int rand_digit = (rand() % 9) + 1;    // generate a random number between 1 and 9
            l1_ptr->val = rand_digit;
            l1_ptr->next = NULL;

            printf("%d -> ", rand_digit);
        }
        
    }

    printf("null\n");

    printf("L2 = ");

    for (i2 = 0; i2 < num_digits_2; i2++)
    {
        /* make last node->next point to NULL and make sure no leading 0s */
        if (i2 + 1 != num_digits_2) {
            int rand_digit = rand() % 10;    // generate a random number between 0 and 9
            l2_ptr->val = rand_digit;
            l2_ptr->next = malloc(sizeof (struct ListNode));
            l2_ptr = l2_ptr->next;

            printf("%d -> ", rand_digit);
        } else {
            /* no leading 0's for last digit */
            int rand_digit = (rand() % 9) + 1;    // generate a random number between 1 and 9
            l2_ptr->val = rand_digit;
            l2_ptr->next = NULL;

            printf("%d -> ", rand_digit);
        }
    }

    printf("null\n");

    struct ListNode *out = addTwoNumbers(l1, l2);
    printf("O1 = ");
    while (out != NULL)
    {
        printf("%d -> ", out->val);
        out = out->next;
    }

    printf("null\n");

    return 0;
}