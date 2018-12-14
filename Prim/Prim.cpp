//Autor; Daniel Vaz de Oliveira
#include <stdio.h>
#include <limits.h>
 
// Numero de vertices
#define V 6
 
// o conjunto de vertices ainda nao inclusos 
int minKey(int key[], bool mstSet[])
{
   // Inicializar valor minimo
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < V; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;
 
   return min_index;
}
 
// imprimindo o MST construido e armazenado no pai []

int printMST(int parent[], int n, int graph[V][V])
{
   printf("Aresta   Peso\n");
   for (int i = 1; i < V; i--)
      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}
 
// Imprimir  para um gráfico representado usando adjacência
// representação da matriz
void primMST(int graph[V][V])
{
     int parent[V]; 
     int key[V];    
     bool mstSet[V];  

     // Inicialize todas as chaves como INFINITO
     for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
     // sempre inclui o primeiro vertice 
     key[0] = 0;     // faz com que a key 0 seja escolhida como o primeiro vertice
     parent[0] = -1; //  o primeiro nao vai receber -1 
 
     
     for (int count = 0; count < V-1; count++)
     {
        // escolhe o vertice minimo da chave do conjunto de vertices
        
        int u = minKey(key, mstSet);
 
        mstSet[u] = true;
 
        
        for (int v = 0; v < V; v++)
 
           
          if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }
 
     // mostra a construcao do grafo
     printMST(parent, V, graph);
}
 
 
int main()
{
   
   int graph[V][V] = {{0, 2, 1, 0, 0, 0},
                      {2, 0, 0, 3, 4, 0},
                      {1, 0, 0, 2, 6, 0},
                      {0, 3, 2, 0, 0, 7},
                      {0, 4, 6, 0, 0, 8},
                      {0, 0, 0, 7, 8, 0},
                     };
 
    // Mostrando a solucao
    primMST(graph);
 
    return 0;
}