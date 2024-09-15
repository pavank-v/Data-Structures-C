#ifndef D_LINKLIST_H
#define D_LINKLIST_H

typedef struct D_Node{
    int data; 
    struct D_Node* next;
    struct D_Node* prev;
} D_Node;

D_Node* create_D_Node(int data);
void insert_D_front(D_Node** head, int data);
void insert_D_middle(D_Node** head, int data, int pos);
void insert_D_end(D_Node** head, int data);
void delete_D_Node(D_Node** head, int data);
void print_DLL(D_Node* head);
void free_DLL(D_Node* head);

#endif