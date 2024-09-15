#include <stdio.h>
#include "list_graph.h"

int main() {
    int vertices = 5;  // Example with 5 vertices
    int directed = 0;  // Undirected graph

    // Create a graph
    Graph* graph = create_list_graph(vertices);

    // Add some edges
    add_edge(graph, 0, 1, directed);
    add_edge(graph, 0, 4, directed);
    add_edge(graph, 1, 2, directed);
    add_edge(graph, 1, 3, directed);
    add_edge(graph, 1, 4, directed);
    add_edge(graph, 3, 4, directed);

    // Display the graph
    display_list_graph(graph);

    // Remove an edge
    printf("\nRemoving edge between 1 and 4...\n");
    remove_edge(graph, 1, 4, directed);

    // Display the graph again
    display_list_graph(graph);

    // bfs
    bfs_list_graph(graph, 0);

    // dfs
    dfs_list_graph(graph, 0);

    // Free the graph memory
    free_list_graph(graph);

    return 0;
}
