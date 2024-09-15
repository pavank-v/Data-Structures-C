# Adjacency Matrix Graph Library in C

This library implements a graph using an adjacency matrix in C. It provides functions for creating, manipulating, and traversing graphs through Breadth-First Search (BFS) and Depth-First Search (DFS).

## Features

- **Graph Representation**: Uses an adjacency matrix to represent graphs.
- **Directed and Undirected Graphs**: Supports both directed and undirected graphs.
- **Graph Operations**:
  - Add an edge
  - Remove an edge
  - Display the graph structure
- **Graph Traversal**:
  - Breadth-First Search (BFS)
  - Depth-First Search (DFS)

## File Structure

- **matrix_graph.h**: Header file defining the function prototypes for the graph operations.
- **matrix_graph.c**: Implementation of the functions for graph manipulation and traversal.
- **main.c**: Example usage of the graph functions.

## How to Use

1. **Include the Header**: Include `matrix_graph.h` in your project to use the graph functions.

2. **Create a Graph**: Call `create_mat_graph(vertices)` to create a graph with the specified number of vertices.

3. **Add/Remove Edges**:
   - Use `add_mat_graph(graph, src, dest, directed)` to add an edge between `src` and `dest`. Set `directed` to `1` for directed graphs or `0` for undirected graphs.
   - Use `remove_mat_graph(graph, src, dest, directed)` to remove an edge between `src` and `dest`.

4. **Graph Traversal**:
   - Call `bfs_mat_graph(graph, vertices, start_vertex)` to perform a BFS traversal starting from `start_vertex`.
   - Call `dfs_mat_graph(graph, vertices, start_vertex)` to perform a DFS traversal starting from `start_vertex`.

5. **Display the Graph**: Use `display_mat_graph(graph, vertices)` to print the graph as an adjacency matrix.

6. **Free Memory**: Once done, free the memory allocated for the graph by calling `free_mat_graph(graph, vertices)`.

## Example

```c
#include "matrix_graph.h"

int main() {
    int vertices = 5;
    int** graph = create_mat_graph(vertices);
    
    add_mat_graph(graph, 0, 1, 0);  // Add undirected edge between 0 and 1
    add_mat_graph(graph, 0, 4, 0);  // Add undirected edge between 0 and 4
    add_mat_graph(graph, 1, 2, 0);  // Add undirected edge between 1 and 2
    
    display_mat_graph(graph, vertices);  // Display graph structure
    
    bfs_mat_graph(graph, vertices, 0);  // Perform BFS from vertex 0
    dfs_mat_graph(graph, vertices, 0);  // Perform DFS from vertex 0
    
    free_mat_graph(graph, vertices);  // Free allocated memory
    return 0;
}
```