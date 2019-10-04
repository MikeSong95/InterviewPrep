
/* definition of linked list node */
typedef struct Node {
    int val;
    struct Node *next;
} Node;

/* initialize a linked list of size n with randomly generated values in the range [0,9] */
Node *init_rand_linked_list(int);

/* add a node to the end of the linked list */
void add_node(Node **, Node *);

/* create a new node with specified value */
Node *create_node(int);

/* prints out contents of linked list */
void print_linked_list(Node*);