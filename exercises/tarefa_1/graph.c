#include "graph.h"

typedef struct graph_ GRAPH;

struct graph_{
  int num_vertex;
  int** matrix;
};

GRAPH* MyGraph(int N){
  GRAPH *graph = (GRAPH*)malloc(sizeof(GRAPH));
  if(graph != NULL){
    int num_vertex = 0;
    int**matrix = (int**)malloc(N*sizeof(int*));
    for(int i=0; i<N; i++){
      matrix[i] = (int*)malloc(N*sizeof(int));
    }
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        matrix[i][j] = -1; // Reset matrix
      }
    }
  }
  return graph;
}




