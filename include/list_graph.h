#ifndef ADJ_LIST_GRAPH
#define ADJ_LIST_GRAPH

typedef struct AdjNode{
    int vertex;
    struct AdjNode* next;
} AdjNode;

typedef struct AdjList{
    AdjNode *head;
}AdjList;

typedef struct Graph{
    int vertices;
    AdjList* arr;
}Graph;

Graph* create_list_graph(int vertices);
void add_edge(Graph* graph, int src, int dest, int directed);
void display_list_graph(Graph* graph);
void remove_edge(Graph* graph, int src, int dest, int directed);
void free_list_graph(Graph* graph);
void bfs_list_graph(Graph* graph, int vertex);
void dfs_list_graph(Graph* graph, int vertex);

#endif