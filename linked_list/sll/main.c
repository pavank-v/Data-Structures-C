#include <stdio.h>
#include "sll.h"

int main() {
    Node* head = NULL;

    insert_front(&head, 10);
    insert_end(&head, 20);
    insert_front(&head, 5);
    insert_end(&head, 30);

    print_LL(head);

    insert_middle(&head, 15, 2);
    print_LL(head);

    delete_node(&head, 20);
    print_LL(head);

    free_list(head);
    return 0;
}
