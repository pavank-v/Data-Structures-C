#ifndef S_LINKLIST_H
#define S_LINKLIST_H

typedef struct Node{
    int data;
    Node* next;
} Node;

Node* create_node(int data);
void insert_front(Node** head, int data);
void insert_middle(Node** head, int data);
void insert_end(Node** head, int data);
void delete_node(Node** head, int data);
void print_LL(Node* head);
void free_list(Node* head);

#endif