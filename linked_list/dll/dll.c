#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

D_Node* create_D_Node(int data){
    D_Node* new_node = (D_Node*)malloc(sizeof(D_Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void insert_D_front(D_Node** head, int data){
    D_Node* new_node = create_D_Node(data);
    if (!new_node){
        printf("Memory Allocation Failed\n");
        return;
    }
    if (*head == NULL){
        *head = new_node;
        printf("%d is inserted at front\n", data);
        return;
    }
    new_node->next = *head;
    (*head)->prev = new_node;
    *head = new_node;
    printf("%d is inserted at front\n", data);
}

void insert_D_end(D_Node** head, int data){
    D_Node* new_node = create_D_Node(data);
    if (!new_node){
        printf("Memory Allocation Failed\n");
        return;
    }
    if (*head == NULL){
        *head = new_node;
        printf("%d is inserted\n", data);
        return;
    }
    D_Node* temp = *head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
    printf("%d is inserted at end\n", data);
}

void insert_D_middle(D_Node** head, int data, int pos){
    D_Node* new_node = create_D_Node(data);
    if (!new_node){
        printf("Memory Allocation Failed\n");
        return;
    }
    if (pos == 0){
        if (*head == NULL){
            *head = new_node;
            printf("%d is inserted at %d position\n", data, pos);
            return;
        }
        else{
            new_node->next = *head;
            (*head)->prev = new_node;
            *head = new_node;
            printf("%d is inserted at %d position\n", data, pos);
            return;
        }
    }

    int length = 0;
    D_Node* temp = *head;
    while (temp){
        temp = temp->next;
        length++;
    }
    
    if (length < pos){
        printf("The given position is greater than the length of the List\n");
        return;
    }

    int position = 0;
    temp = *head;
    D_Node* previous = NULL;
    while (pos > position){
        previous = temp;
        temp = temp->next;
        position++;
    }

    new_node->next = temp;
    previous->next = new_node;
    if (temp) {
        temp->prev = new_node;
    }
    new_node->prev = previous;

    printf("%d is inserted at %d position\n", data, pos);
}

void delete_D_Node(D_Node** head, int data){
    if (*head == NULL){
        printf("List is empty\n");
        return;
    }
    
    D_Node* temp = *head;

    // Case: node to delete is the head node
    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        if (temp->next) {
            temp->next->prev = NULL;
        }
        free(temp);
        printf("Node %d is deleted\n", data);
        return;
    }

    D_Node* previous = NULL;
    while (temp && temp->data != data){
        previous = temp;
        temp = temp->next;
    }

    if (temp == NULL){
        printf("%d is not found\n", data);
        return;
    }

    previous->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = previous;
    }
    free(temp);
    printf("Node %d is deleted\n", data);
}

void print_DLL(D_Node* head){
    D_Node* temp = head;
    printf("List: ");
    while (temp){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void free_DLL(D_Node* head){
    D_Node* temp;
    while (head){
        temp = head;
        head = head->next;
        free(temp);
    }
}
