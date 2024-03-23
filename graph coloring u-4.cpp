#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#define V 4
bool graph[V][V];
void showColors(int color[]) {
   printf("Assigned Colors are:\n");
   for (int i = 0; i < V; i++)
      printf("%d ", color[i]);
   printf("\n");
}
bool isValid(int v, int color[], int c) {
   for (int i = 0; i < V; i++)
      if (graph[v][i] && c == color[i])
         return false;
   return true;
}
bool graphColoring(int colors, int color[], int vertex) {     
   if (vertex == V)
      return true;
   for (int col = 1; col <= colors; col++) { 
      if (isValid(vertex, color, col)) {
         color[vertex] = col;
         if (graphColoring(colors, color, vertex + 1))
            return true;
         color[vertex] = 0;
      }
   }
   return false;
}
bool checkSolution(int m) {  
   int *color = (int *)malloc(V * sizeof(int)); 
   for (int i = 0; i < V; i++)
      color[i] = 0;      
   if (graphColoring(m, color, 0) == false) {
      printf("Solution does not exist.\n");
      free(color); 
      return false;
   }
   showColors(color);
   free(color); 
   return true;
}

int main() {   
   int colors = 3,i,j;
   printf("Enter the adjacency matrix:");
   for(i=0;i<V;i++)
   {
   	for(j=0;j<V;j++)
   	{
   		scanf("%d",&graph[i][j]);
	   }
   }
   checkSolution(colors);
   return 0;
}
