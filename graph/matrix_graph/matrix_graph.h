#ifndef MATRIX_GRAPH_H
#define MATRIX_GRAPH_H
#include <stdbool.h>

int** create_mat_graph(int vertices);
void add_mat_graph(int** graph, int v, int u, int directed);
void remove_mat_graph(int** graph, int v, int u, int directed);
void display_mat_graph(int** graph, int vertices);
void bfs_mat_graph(int** graph, int vertices, int start);
void dfs_mat_graph(int** graph, int vetices, int start);
void free_mat_graph(int** graph, int vertices);

#endif