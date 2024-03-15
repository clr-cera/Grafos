#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct graph_ GRAPH;

//a 
GRAPH* MyGraph(int N);
//b 
bool exist_edge(GRAPH* G, int v1, int v2);
//c TODO
int* get_adj_vertex(GRAPH* G, int v); 
//d TODO
bool remove_edge(GRAPH* G, int v1, int v2);
//e
bool print_info(GRAPH* G);
//f TODO
int number_of_vertexs(GRAPH G);
//g TODO
bool remove_graph(GRAPH* G);
//h TODO
bool add_edge(GRAPH* G, int v1, int v2);
//i TODO
int remove_with_least_weight(GRAPH* G);
//j TODO
int** adjacency_matrix(GRAPH* G);
