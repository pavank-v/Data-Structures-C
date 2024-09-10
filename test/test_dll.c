#include <stdio.h>
#include "dll.h"

int main(){
    D_Node* head = NULL;

    insert_D_front(&head, 10);
    insert_D_end(&head, 20);
    insert_D_front(&head, 5);
    insert_D_end(&head, 30);

    print_DLL(head);

    insert_D_middle(&head, 3, 2);
    print_DLL(head);

    delete_D_Node(&head, 20);
    print_DLL(head);

    free_DLL(head);
    return 0;
}
