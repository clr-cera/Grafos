#include "graph.h"
#include <stdlib.h>

typedef struct graph_ GRAPH;

struct graph_ {
  int num_vertex;
  int **matrix;
};

GRAPH *MyGraph(int N) {
  GRAPH *graph = (GRAPH *)malloc(sizeof(GRAPH));
  if (graph != NULL) {
    graph->num_vertex = N;
    graph->matrix = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
      graph->matrix[i] = (int *)malloc(N * sizeof(int));
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        graph->matrix[i][j] = -1; // Reset matrix
      }
    }
  }
  return graph;
}

bool exist_edge(GRAPH *G, int v1, int v2) {
  if (G == NULL) {
    return false;
  }
  if ((v1 > G->num_vertex) || (v2 > G->num_vertex)) {
    return false;
  }
  return (G->matrix[v1][v2] != -1);
}

bool print_info(GRAPH *G) {
  if (G == NULL) {
    return false;
  }
  for (int i = 0; i < G->num_vertex; i++) {
    printf("| ");
    for (int j = 0; j < G->num_vertex; j++) {
      printf(" % 3d ", G->matrix[i][j]);
    }
    printf(" |\n");
  }
  return true;
}

int number_of_vertexs(GRAPH *G) {
  if (G == NULL) {
    return -1;
  }
  return G->num_vertex;
}

int **adjacency_matrix(GRAPH *G) {
  if (G == NULL) {
    return NULL;
  }
  return G->matrix;
}

bool add_edge(Graph G, int v1, int v2, int weight) {
  if (G == NULL) {
    return false;
  }
  G->matrix[v1][v2] = G->matrix[v2][v1] = weight;
  return true;
}

// Return an array of vertices that have adj edge with vertex v
int *get_adj_vertex(Graph G, int v) {
  if (G == NULL) {
    return NULL;
  }
  int *arr = (int *)malloc((G->num_vertex + 1) * sizeof(int));
  int arr_size = 0;
  for (int i = 0; i < G->num_vertex; i++) {
    if (G->matrix[v][i] != -1) {
      arr[arr_size] = i;
      arr_size++;
    }
  }
  arr[arr_size] = -1; // To indicate the end of the array
  arr = realloc(arr, arr_size + 1);
  return arr;
}
