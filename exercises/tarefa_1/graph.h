#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct graph_* Graph;

//a 
Graph MyGraph(int N);
//b 
bool exist_edge(Graph G, int v1, int v2);
//c TODO
int* get_adj_vertex(Graph G, int v); 
//d TODO
bool remove_edge(Graph G, int v1, int v2);
//e
bool print_info(Graph G);
//f TODO
int number_of_vertexs(Graph G);
//g TODO
bool remove_graph(Graph G);
//h TODO
bool add_edge(Graph G, int v1, int v2);
//i TODO
int remove_with_least_weight(Graph G);
//j TODO
int** adjacency_matrix(Graph G);
