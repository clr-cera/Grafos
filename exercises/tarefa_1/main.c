#include "graph.h"
#include "stdio.h"

int main(void) {

  // Instructions to usage
  printf("z : Stop program\na : Create graph\nb : Check edge existence\nc : "
         "Get adjcent vertices\nd : Remove edge\ne : Print graph\nf : Get "
         "number of vertices\ng : Remove graph\nh : Add edge\ni : Remove "
         "lightest edge\nj : Get adjacency matrix");

  // Variables
  char op;
  int n, v1, v2, num_vertex, weight;
  int *array;
  int **matrix;
  Graph graph;

  // Options menu
  do {
    scanf("%c", &op);
  } while (op != 'z');
  switch (op) {
  case 'z':
    break;
  case 'a': {
    scanf("%d", &n);
    graph = MyGraph(n);
    break;
  }
  case 'b': {
    scanf("%d %d", &v1, &v2);
    if (exist_edge(graph, v1, v2)) {
      printf("Exist edge");
    } else {
      printf("Do not exist edge");
    }
    break;
  }
  case 'c':
    scanf("%d", &v1);
    {
      array = get_adj_vertex(graph, v1);
      for (int i = 0; array[i] != -1; i++) {
        printf("%d ", array[i]);
      }
      break;
    }
  case 'd': {
    scanf("%d %d", &v1, &v2);
    if (remove_edge(graph, v1, v2)) {
      printf("Remove edge completed");
    } else {
      printf("Something went wrong");
    }
    break;
  }
  case 'e': {
    print_info(graph);
    break;
  }
  case 'f': {
    num_vertex = number_of_vertexs(graph);
    printf("%d", num_vertex);
    break;
  }
  case 'g': {
    if (remove_graph(graph)) {
      printf("Remove graph completed");
    } else {
      printf("Something went wrong");
      break;
    }
  }
  case 'h': {
    scanf("%d %d %d", &v1, &v2, &weight);
    if (add_edge(graph, v1, v2, weight)) {
      printf("Add edge successful");
    } else {
      printf("Something went wrong");
    }
    break;
  }
  case 'i':
    printf("The least weight edge %d was removed",
           remove_with_least_weight(graph));
    break;
  case 'j':
    matrix = adjacency_matrix(graph);
    break;
  default:
    break;
  }
  return 0;
}