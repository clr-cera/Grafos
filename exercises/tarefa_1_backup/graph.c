#include "graph.h"
#include "limits.h"
#include <stdlib.h>

typedef struct graph_ GRAPH;

struct graph_ {
  int num_vertex;
  int ***matrix;
};

GRAPH *MyGraph(int N) {
  GRAPH *graph = (GRAPH *) malloc(sizeof(GRAPH));
  if (graph == NULL || N < 1) return NULL;
  
  graph->num_vertex = N;

  // Aloca matrix
  graph->matrix = (int ***) malloc(N * sizeof(int **));
  if (graph->matrix == NULL) {free(graph); return NULL;}

  //Aloca linhas da matrix
  for (int i = 0; i < N; i++) {
    graph->matrix[i] = (int **)malloc(N * sizeof(int *));
    if(graph->matrix[i] == NULL) {
      remove_graph(graph); return NULL;
    }
  }

  return graph;
}

bool exist_edge(GRAPH *G, int v1, int v2) {
  if (G == NULL || v1 < 0 || v1 >= G->num_vertex ||v2 < 0 || v2 >= G->num_vertex ) {
    return false;
  }

  return (G->matrix[v1][v2] != NULL);
}

bool remove_edge(Graph G, int v1, int v2) {
  if (G == NULL || v1 < 0 || v1 >= G->num_vertex ||v2 < 0 || v2 >= G->num_vertex ) {
    return false;
  }
  
  free(G->matrix[v1][v2]);
  G->matrix[v1][v2] = G->matrix[v2][v1] = NULL;
  return true;
}

bool print_info(GRAPH *G) {
  if (G == NULL) {
    return false;
  }

  printf("  |");
  for(int i = 0; i < G->num_vertex; i++){
    printf("%3d |", i);
  }printf("\n");

  for(int i = 0; i < G->num_vertex*5 + 5; i++){
    if ((i+3)%5 == 0)
      printf("+");
    else
      printf("-");
  }printf("\n");

  for (int i = 0; i < G->num_vertex; i++) {
    printf("%d ", i);
    for (int j = 0; j < G->num_vertex*2 + 1; j++) {
      if (j % 2 == 0)
        printf("|");
      else
        if (G->matrix[i][j/2] == NULL)
          printf("    ");
        else
          printf(" %3d", *(G->matrix[i][j/2]));
    }printf(" %d\n", i);
  }
  
  for(int i = 0; i < G->num_vertex*5 + 5; i++){
    if ((i+3)%5 == 0)
      printf("+");
    else
      printf("-");
  }printf("\n");
  
  printf("  |");
  for(int i = 0; i < G->num_vertex; i++){
    printf("%3d |", i);
  }printf("\n");

  return true;
}

int number_of_vertexs(GRAPH *G) {
  if (G == NULL) {
    return -1;
  }
  return G->num_vertex;
}

int ***adjacency_matrix(GRAPH *G) {
  if (G == NULL) {
    return NULL;
  }
  return G->matrix;
}

bool remove_graph(Graph G) {
  if (G == NULL) return false;

  for (int line = 0; line < G->num_vertex; line++){
    for (int column = 0; column < G->num_vertex; column++){
      if (G->matrix[line][column] != NULL) free(G->matrix[line][column]);
    }

    if (G->matrix[line] != NULL) free(G->matrix[line]);
  }
  free(G->matrix);
  free(G);

  return true;
}

bool add_edge(Graph G, int v1, int v2, int weight) {
  if (G == NULL || v1 < 0 || v1 >= G->num_vertex ||v2 < 0 || v2 >= G->num_vertex ) {
    return false;
  }
  if (G->matrix[v1][v2] == NULL) 
    G->matrix[v1][v2] = G->matrix[v2][v1] = (int *) malloc(sizeof(int));
  *(G->matrix[v1][v2]) = *(G->matrix[v2][v1]) = weight;
  return true;
}

// Retorna vetor de vertices que tem adjacência com vertice v
int *get_adj_vertex(Graph G, int v) {
  if (G == NULL || v < 0 || v >= G->num_vertex) {
    return NULL;
  }

  int *arr = (int *) malloc((G->num_vertex + 1) * sizeof(int));
  int arr_size = 0;
  for (int i = 0; i < G->num_vertex; i++) {
    if (G->matrix[v][i] != NULL) {
      arr[arr_size] = i;
      arr_size++;
    }
  }
  // Para indicar fim do array
  arr[arr_size] = -1; 
  arr = realloc(arr, arr_size + 1);
  return arr;
}

int remove_with_least_weight(Graph G){
  if (G == NULL) return -2;

  int menor = INT_MAX, n;
  //percorre a matriz para achar o menor peso
  for(int i = 0;i<G->num_vertex;i++){
    for(int j = 0;j<i+1;j++){
      if (G->matrix[i][j] != NULL) {
        n = *(G->matrix[i][j]);
        if(n < menor){
          menor = n;
        }
      }
    }
  }

  //remove todas as arestas com peso igual ao menor
  for(int i = 0;i<G->num_vertex;i++){
    for(int j = 0;j<i+1;j++){
      if (G->matrix[i][j] != NULL) {
        n = *(G->matrix[i][j]);
        if(n == menor){
          remove_edge(G,i,j);
        }
      }
    }
  }  

  return menor;
}
