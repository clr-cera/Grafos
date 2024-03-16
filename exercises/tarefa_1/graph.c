#include "graph.h"
#include <stdlib.h>

typedef struct graph_ GRAPH;

struct graph_ {
  int num_vertex;
  int **matrix;
};

GRAPH *MyGraph(int N) {
  GRAPH *graph = (GRAPH *) malloc(sizeof(GRAPH));
  if (graph == NULL || N < 1) return NULL;
  
  graph->num_vertex = N;

  // Aloca matrix
  graph->matrix = (int **) malloc(N * sizeof(int *));
  if (graph->matrix == NULL) {free(graph); return NULL;}

  //Aloca linhas da matrix
  for (int i = 0; i < N; i++) {
    graph->matrix[i] = (int *)malloc(N * sizeof(int));
    if(graph->matrix[i] == NULL) {
      remove_graph(graph); return NULL;
    }
  }

 // Reseta matrix 
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      graph->matrix[i][j] = -1; 
    }
  }

  return graph;
}

bool exist_edge(GRAPH *G, int v1, int v2) {
  if (G == NULL) {
    return false;
  }
  if ((v1 > G->num_vertex) || (v1 < 0) || (v2 > G->num_vertex)  || (v2 < 0)) {
    return false;
  }
  return (G->matrix[v1][v2] != -1);
}

bool remove_edge(Graph G, int v1, int v2) {
  if (G == NULL) {
    return false;
  }
  
  G->matrix[v1][v2] = G->matrix[v2][v1] = -1;
  return true;
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

bool remove_graph(Graph G) {
  if (G == NULL) return false;

  for (int line = 0; line < G->num_vertex; line++){
    if (G->matrix[line] != NULL) free(G->matrix[line]);
  }
  free(G->matrix);
  free(G);

  return true;
}

bool add_edge(Graph G, int v1, int v2, int weight) {
  if (G == NULL) {
    return false;
  }
  G->matrix[v1][v2] = G->matrix[v2][v1] = weight;
  return true;
}

// Retorna vetor de vertices que tem adjacência com vertice v
int *get_adj_vertex(Graph G, int v) {
  if (G == NULL) {
    return NULL;
  }

  int *arr = (int *) malloc((G->num_vertex + 1) * sizeof(int));
  int arr_size = 0;
  for (int i = 0; i < G->num_vertex; i++) {
    if (G->matrix[v][i] != -1) {
      arr[arr_size] = i;
      arr_size++;
    }
  }
  // Para indicar fim do array
  arr[arr_size] = -1; 
  arr = realloc(arr, arr_size + 1);
  return arr;
}
