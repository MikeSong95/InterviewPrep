
#include "./header_files/linked_list.h"

void reverse_linked_list(Node **head, Node *prev, Node *curr)
{
    if ((*head) == NULL || (*head)->next == NULL) return;

    if (curr->next == NULL) {
        *head = curr;  // Doesn't affect prev since prev is at a different address than head
        curr->next = prev;
        prev->next = NULL;
    } else {
        reverse_linked_list(&(*head),prev->next, curr->next);
        curr->next = prev;
        prev->next = NULL;
    }
}

// Driver function
int main (void)
{
    Node *head = init_rand_linked_list();
    Node *prev = head;  

    print_linked_list(head);
    reverse_linked_list(&head,prev,head->next);
    print_linked_list(head);

    return 0;
}