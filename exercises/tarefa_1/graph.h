#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct graph_ GRAPH;

GRAPH* MyGraph(int N);
bool exist_edge(GRAPH* G, int v1, int v2);
void print_info(GRAPH* G);