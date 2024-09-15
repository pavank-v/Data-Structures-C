#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrix_graph.h"

int** create_mat_graph(int vertices){
    int** graph = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++){
        graph[i] = (int*)malloc(vertices * sizeof(int));
    }
    for (int i = 0; i < vertices; i++){
        for (int j = 0; j < vertices; j++){
            graph[i][j] = 0;
        }
    }
    return graph;
}

void add_mat_graph(int** graph, int v, int u, int directed){
    graph[u][v] = 1;
    if (!directed){
        graph[v][u] = 1;
    }
}

void remove_mat_graph(int** graph, int v, int u, int directed){
    graph[u][v] = 0;
    if (!directed){
        graph[v][u] = 0;
    }
}

void display_mat_graph(int** graph, int vertices){
    printf("Adjacency Matrix\n");
    for (int i = 0; i < vertices; i++){
        for (int j = 0; j < vertices; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void bfs_mat_graph(int** graph, int vertices, int start){
    if (!graph){
        printf("Graph is empty\n");
        return;
    }
    printf("Breadth First Search: ");
    bool* visited = (bool*)malloc(vertices * sizeof(bool));
    for (int i = 0; i < vertices; i++){
        visited[i] = false;
    }
    int* queue = (int*)malloc(vertices * sizeof(int));
    int front = -1, rear = -1;
    visited[start] = true;
    queue[++rear] = start;

    while (front < rear){
        int current = queue[++front];
        printf("%d ", current);
        for (int i = 0; i < vertices; i++){
            if (!visited[i] && graph[current][i] == 1){
                queue[++rear] = i;
                visited[i] = true;
            }
        }
    }
    free(queue);
    free(visited);
}
void dfs(int** graph, int vertices, int start, bool* visited){
    visited[start] = true;
    printf("%d ", start);
    
    for (int i = 0; i < vertices; i++){
        if (graph[start][i] == 1 && !visited[i]){
            dfs(graph, vertices, i, visited);
        }
    }
}

void dfs_mat_graph(int** graph, int vertices, int start){
    bool* visited = (bool*)malloc(vertices * sizeof(bool));
    for (int i = 0; i < vertices; i++){
        visited[i] = false;
    }
    printf("Depth First Search: ");
    dfs(graph, vertices, start, visited);
    printf("\n");
}


void free_mat_graph(int** graph, int vertices){
    for (int i = 0; i < vertices; i++){
        free(graph[i]);
    }
    free(graph);
}