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
    printf("Element %d inserted at front\n", data);
}

void insert_end(Node** head, int data){
    Node* new_node = create_node(data);
    if (!new_node)
        return;
    if (*head == NULL){
        *head = new_node;
        return;
    }
    Node* temp = *head;
    while (temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = new_node;
    printf("Element %d inserted at end\n", data);
}

void insert_middle(Node** head, int data, int pos){
    Node* new_node = create_node(data);
    if (!new_node)
        return;
    if (*head == NULL && pos == 0){
        *head = new_node;
        return;
    }

    int length = 0;
    Node* temp = *head;
    while (temp){
        temp = temp->next;
        length++;
    }
    if (pos > length){
        printf("Index is greater than length\n");
        return;}
    if (pos == 0){
        new_node->next = *head;
        *head = new_node;
        printf("Element %d inserted at middle\n", data);
        return;
    }
    Node* curr = *head;
    Node* prev = NULL;
    int position = 0;

    while (position < pos && curr != NULL){
        prev = curr;
        curr = curr->next;
        position++;
    }

    new_node->next = curr;
    prev->next = new_node;
    printf("Element %d inserted at middle\n", data);
}

void delete_node(Node** head, int data){
    if (*head == NULL){
        printf("List is empty\n");
        return;}

    Node* temp = *head;
    Node* prev = NULL;
    
    if (temp != NULL && temp->data == data){
        *head = temp->next;
        free(temp);
        printf("Node with value %d deleted\n", data);
    }

    while (temp != NULL && temp->data != data){
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL){
        printf("Not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node with value %d deleted\n", data);
}

void print_LL(Node* head){
    if (head == NULL){
        printf("List is empty");
    }
    Node* temp = head;
    printf("List: ");
    while (temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void free_list(Node* head){
    Node* temp;
    
    while (head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}