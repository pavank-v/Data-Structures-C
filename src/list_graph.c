#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list_graph.h"

AdjNode* create_list_node(int vertex){
    AdjNode* new_node = (AdjNode*)malloc(sizeof(AdjNode));
    new_node->vertex = vertex;
    new_node->next = NULL;
    return new_node;
}

Graph* create_list_graph(int vertices){
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->arr = (AdjList*)malloc(vertices * sizeof(AdjList));

    for (int i = 0;i < vertices; i++){
        graph->arr[i].head = NULL;
    }
    return graph;
}

void add_edge(Graph* graph, int src, int dest, int directed){
    AdjNode* new_node = create_list_node(dest);
    new_node->next = graph->arr[src].head;
    graph->arr[src].head = new_node;

    if (!directed){
        AdjNode* new_dest_node = create_list_node(src);
        new_dest_node->next = graph->arr[dest].head;
        graph->arr[dest].head = new_dest_node;
    }
}

void remove_node(AdjNode** head, int vertex){
    AdjNode* temp = *head;
    AdjNode* prev = NULL;

    if (temp != NULL && temp->vertex == vertex){
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp && temp->vertex != vertex){
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

void remove_edge(Graph* graph, int src, int dest, int directed){
    remove_node(&(graph->arr[src].head), dest);
    
    if(!directed){
        remove_node(&(graph->arr[dest].head), src);
    }
}

void display_list_graph(Graph* graph){
    for (int i = 0; i < graph->vertices; i++){
        AdjNode* temp = graph->arr[i].head;
        printf("Vertex %d: ", i);
        while (temp){
            printf("%d ->", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void bfs_list_graph(Graph* graph, int start_vertex){
    bool* visited = (bool*)malloc(graph->vertices * sizeof(bool));
    for (int i = 0; i < graph->vertices; i++){
        visited[i] = false;
    }
    int* queue = (int*)malloc(graph->vertices * sizeof(int));
    int front = -1, rear = -1;
    visited[start_vertex] = true;
    queue[++rear] = start_vertex;
    
    printf("Breadth First Search is: ");
    while (front < rear){
        int curr = queue[++front];
        printf("%d -> ", curr);
        AdjNode* temp = graph->arr[curr].head;
        while (temp){
            if (!visited[temp->vertex]){
                visited[temp->vertex] = true;
                queue[++rear] = temp->vertex;
            }
            temp = temp->next;
        }
    }
    printf("NULL\n");
    free(visited);
    free(queue);
}

void dfs_helper(Graph* graph, int start_vertex, bool* visited){
    visited[start_vertex] = true;
    printf("%d -> ", start_vertex);

    AdjNode* temp = graph->arr[start_vertex].head;

    while (temp){
        if (!visited[temp->vertex]){
            dfs_helper(graph, temp->vertex, visited);
        }
        temp = temp->next;
    }
}

void dfs_list_graph(Graph* graph, int start_vertex){
    bool* visited = (bool*)malloc(graph->vertices * sizeof(bool));
    for (int i = 0; i < graph->vertices; i++){
        visited[i] = false;
    }
    printf("Depth First Search: ");
    dfs_helper(graph, start_vertex, visited);
    printf("NULL\n");
    free(visited);
}

void free_list_graph(Graph* graph){
    for (int i = 0; i < graph->vertices; i++){
        AdjNode* head = graph->arr[i].head;
        while (head){
            AdjNode* temp = head;
            head = head->next;
            free(temp);
        }
    }
    free(graph->arr);
    free(graph);
}