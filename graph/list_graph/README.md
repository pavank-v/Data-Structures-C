# Adjacency List Graph Library in C

This library implements a graph using an adjacency list in C. It provides functions for creating, manipulating, and traversing graphs through Breadth-First Search (BFS) and Depth-First Search (DFS).

## Features

- **Graph Representation**: Uses adjacency list to represent graphs.
- **Directed and Undirected Graphs**: Supports both directed and undirected graphs.
- **Graph Operations**:
  - Add an edge
  - Remove an edge
  - Display the graph structure
- **Graph Traversal**:
  - Breadth-First Search (BFS)
  - Depth-First Search (DFS)

## File Structure

- **list_graph.h**: Header file defining the graph data structure and function prototypes.
- **list_graph.c**: Implementation of the functions for graph manipulation and traversal.
- **main.c**: Example usage of the graph functions.

## How to Use

1. **Include the Header**: Include `list_graph.h` in your project to use the graph functions.

2. **Create a Graph**: Call `create_list_graph(vertices)` to create a graph with the specified number of vertices.

3. **Add/Remove Edges**:
   - Use `add_edge(graph, src, dest, directed)` to add an edge between `src` and `dest`. Set `directed` to `1` for directed graphs or `0` for undirected graphs.
   - Use `remove_edge(graph, src, dest, directed)` to remove an edge between `src` and `dest`.

4. **Graph Traversal**:
   - Call `bfs_list_graph(graph, start_vertex)` to perform a BFS traversal starting from `start_vertex`.
   - Call `dfs_list_graph(graph, start_vertex)` to perform a DFS traversal starting from `start_vertex`.

5. **Display the Graph**: Use `display_list_graph(graph)` to print the graph structure.

6. **Free Memory**: Once done, free the memory allocated for the graph by calling `free_list_graph(graph)`.

## Example

```c
#include "list_graph.h"

int main() {
    int vertices = 5;
    Graph* graph = create_list_graph(vertices);
    
    add_edge(graph, 0, 1, 0);  // Add undirected edge between 0 and 1
    add_edge(graph, 0, 4, 0);  // Add undirected edge between 0 and 4
    add_edge(graph, 1, 2, 0);  // Add undirected edge between 1 and 2
    
    display_list_graph(graph);  // Display graph structure
    
    bfs_list_graph(graph, 0);  // Perform BFS from vertex 0
    dfs_list_graph(graph, 0);  // Perform DFS from vertex 0
    
    free_list_graph(graph);  // Free allocated memory
    return 0;
}
```

## Compilation
```bash
    gcc main.c list_graph.c -o list_graph_program
````