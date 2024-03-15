#include "graph.h"

typedef struct graph_ GRAPH;

struct graph_{
  int num_vertex;
  int** matrix;
};


GRAPH* MyGraph(int N){
  GRAPH *graph = (GRAPH*)malloc(sizeof(GRAPH));
  if(graph != NULL){
    graph->num_vertex = N;
    graph->matrix = (int**)malloc(N*sizeof(int*));
    for(int i=0; i<N; i++){
       graph->matrix[i] = (int*)malloc(N*sizeof(int));
    }
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
         graph->matrix[i][j] = -1; // Reset matrix
      }
    }
  }
  return graph;
}

bool exist_edge(GRAPH* G, int v1, int v2){
  if(G != NULL){
    if((v1 < G->num_vertex) && (v2 < G->num_vertex)){
      if((G->matrix[v1][v2]!=-1)){
      return true;
      }
    }
  }
    return false;
}

bool print_info(GRAPH* G){
  if(G == NULL) return false;

  for(int i=0; i<G->num_vertex; i++){
    for(int j=0; j<G->num_vertex; j++){
        printf("|%d|",G->matrix[i][j]);
    }
    printf("\n");
  }
  return true;
}

int number_of_vertexs(GRAPH* G) {
  return G->num_vertex;
}

int** adjacency_matrix(GRAPH* G) {
  return G->matrix;
}

