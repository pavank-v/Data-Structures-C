#include <stdio.h>
#include <stdlib.h>
#include "sll.h"

Node* create_node(int data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node){
        printf("Memory Allocation Failed\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_front(Node** head, int data){
    Node* new_node = create_node(data);
    if (!new_node)
        return;
    
    new_node->next = *head;
    *head = new_node;
}

void insert_end(Node** )