#include "graph.h"
#include "stdio.h"

int main(void){
  GRAPH* grafo = MyGraph(3);
  if(exist_edge(grafo, 4, 4)){
    printf("Existe a aresta!\n");
  }
  else{
    printf("Não existe a aresta!\n");
  }
  print_info(grafo);
  return 0;
}