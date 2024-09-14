#include <stdio.h>
#include "matrix_graph.h"

int main(){
    int vertices = 5, directed = 0;
    int** graph = create_mat_graph(vertices);
    
    // Add edges (you can replace these with user inputs)
    add_mat_graph(graph, 0, 1, directed);
    add_mat_graph(graph, 0, 2, directed);
    add_mat_graph(graph, 1, 2, directed);
    add_mat_graph(graph, 2, 3, directed);

    // Display the graph
    display_mat_graph(graph, vertices);

    // Remove an edge (optional)
    printf("\nRemoving edge between 1 and 2.\n");
    remove_mat_graph(graph, 1, 2, directed);

    // Display the graph again after removal
    display_mat_graph(graph, vertices);

    // BFS
    bfs_mat_graph(graph, vertices, 0);
    printf("\n");

    // DFS
    dfs_mat_graph(graph, vertices, 0);

    // Free the allocated memory
    free_mat_graph(graph, vertices);

    return 0;
}