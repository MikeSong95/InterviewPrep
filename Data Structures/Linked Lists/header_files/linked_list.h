
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* definition of linked list node */
typedef struct Node {
    int val;
    struct Node *next;
} Node;

/* initialize a linked list with size in the range [1,20] with randomly generated values in the range [0,9] */
Node *init_rand_linked_list();

/* add a node to the end of the linked list */
void add_node(Node **, Node *);

/* create a new node with specified value */
Node *create_node(int);

/* prints out contents of linked list */
void print_linked_list(Node*);

/* prints out the number of nodes in the given linked list */
int num_nodes(Node*);