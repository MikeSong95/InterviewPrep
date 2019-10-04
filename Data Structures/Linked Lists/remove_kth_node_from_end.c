
#include "./header_files/linked_list.h"

void remove_kth_node_from_end(Node **head, int k)
{
    if ((*head) == NULL) return;            // head is empty
    if ((*head)->next == NULL && k == 1) {  // one node in list
        free((*head));
        *head = NULL;
        return;
    } 

    Node *prev;
    Node *main = *head;
    Node *ref = *head;

    for (; k > 0; k--)
    {
        ref = ref->next;
    }

    if (ref == NULL) {          // remove first node
        main = main->next;
        free((*head));
        *head = NULL;
        *head = main;
    } else {
        while(ref != NULL)
        {
            prev = main;
            main = main->next;
            ref = ref->next;
        }

        prev->next = main->next;
        free(main);
        main = NULL;
    }
}

// Driver function
int main (void)
{

    Node *head = init_rand_linked_list();
    int k = rand() % num_nodes(head) + 1;      // generate a valid value for k

    print_linked_list(head);
    printf("k = %d\n",k);
    remove_kth_node_from_end(&head,k);
    print_linked_list(head);

    return 0;
}