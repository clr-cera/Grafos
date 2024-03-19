#include "graph.h"
#include "stdio.h"

int main(void) {

  // Instruções
  printf("z : Parar programa\na : Criar Grafo\nb : Checar existência de aresta\nc : "
         "Pegar vértices adjacentes\nd : Remover aresta\ne : Imprimir grafo\nf : Pegar "
         "número de vértices\ng : Remover grafo\nh : Adicionar aresta\ni : Remover "
         "aresta com menor peso\nj : Pegar matriz de adjacência\n");

  // Variáveis
  char op;
  int n, v1, v2, num_vertex, weight;
  int *array;
  int ***matrix;
  Graph graph;

  // Parser de Instruções
  do {
    scanf("%c", &op);

    switch (op) {
      case 'z':
        break;

      case 'a': {
        printf("Digite o número de vértices: ");
        scanf("%d", &n);
        graph = MyGraph(n);
        break;
      }

      case 'b': {
        printf("Digite os vértices da aresta, com um espaço os separando: ");
        scanf("%d %d", &v1, &v2);
        if (exist_edge(graph, v1, v2)) {
          printf("Existe aresta.\n");
        } else {
          printf("Não existe aresta ou houve um problema.\n");
        }
        break;
      }

      case 'c': {
        printf("Digite o vértice: ");
        scanf("%d", &v1);
        array = get_adj_vertex(graph, v1);
        for (int i = 0; array[i] != -1; i++) {
          printf("%d ", array[i]);
        }printf("\n");

        break;
      }

      case 'd': {
        printf("Digite vértices da aresta a ser removida, com um espaço os separando: ");
        scanf("%d %d", &v1, &v2);
        if (remove_edge(graph, v1, v2)) {
          printf("Remoção concluída.\n");
        } else {
          printf("Houve um problema.\n");
        }
        break;
      }
      case 'e': {
        print_info(graph);
        break;
      }
      case 'f': {
        num_vertex = number_of_vertexs(graph);
        printf("%d\n", num_vertex);
        break;
      }
      case 'g': {
        if (remove_graph(graph)) {
          printf("Grafo foi removido.\n");
        } else {
          printf("Grafo não existia.\n");
        }
        break;
      }
      case 'h': {
        printf("Digite os vertices a serem conectados e o peso da conexão, com espaços entre os dados: ");
        scanf("%d %d %d", &v1, &v2, &weight);
        if (add_edge(graph, v1, v2, weight)) {
          printf("Adicionou aresta.\n");
        } else {
          printf("Houve um problema.\n");
        }
        break;
      }
      case 'i': {
        int returnal = remove_with_least_weight(graph);
        if (returnal == -2) printf("Não há grafo\n");
        else if (returnal == -1) printf("Não há arestas\n");
        else printf("A aresta com menor peso %d foi removida.\n", returnal);
        break;
      }
      case 'j': {
        matrix = adjacency_matrix(graph);

        for (int i = 0; i < number_of_vertexs(graph); i++) {
          for (int j = 0; j < number_of_vertexs(graph)*2 + 1; j++) {
            if (j % 2 == 0)
              printf("|");
            else
              if (matrix[i][j/2] == NULL)
                printf("    ");
              else
                printf(" %3d", *(matrix[i][j/2]));
          }printf(" \n");
        }
        
        break;
      }
      default:
        break;
    }
  } while (op != 'z');
  return 0;
}
