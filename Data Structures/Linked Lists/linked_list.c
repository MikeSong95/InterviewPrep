
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./header_files/linked_list.h"

Node *init_rand_linked_list(int n)
{
    if (n <= 0) return NULL;

    srand(time(0)); // Use current time as seed for random generator 

    Node *head = NULL;

    int i;
    for (i = 0; i < n; i++)
    {
        int digit = rand() % 10;   
        Node *new_node = create_node(digit);
        add_node(&head, new_node);
    }

    return head;
}

Node *create_node(int val)
{
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    return node;
}

void add_node(Node **head, Node *new_node)
{
    if (*head == NULL) {    // Empty list
        *head = new_node;
    } else {
        Node *curr = *head;
      
        // Find end of linked list
        while(curr->next != NULL) {
            curr = curr->next;
        }

        curr->next = new_node;
    }
}

void print_linked_list(Node *head)
{
    while (head != NULL)
    {
        printf("%d->",head->val);
        head = head->next;
    }

    printf("null\n");
}