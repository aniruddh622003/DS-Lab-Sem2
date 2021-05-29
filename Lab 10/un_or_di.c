#include <stdio.h>
#include <stdlib.h>
int vertices;

void printMatrix(int matrix[][vertices]){
    for (int i = 0; i < vertices; i++)
    {
        for(int j = 0; j < vertices; j++){
            printf("%d ", matrix[i][j]);
            }
        printf("\n");
    }
}

int checkMatrixEqual(int m1[][vertices], int m2[][vertices]){
    int equal = 1;
    for (int i = 0; i < vertices; ++i){
      for (int j = 0; j < vertices; ++j) {
            if(m1[i][j] != m2[i][j]) equal = 0;
        }
    }
    return equal;
}

void transpose(int matrix[][vertices], int trans[][vertices]){
    for (int i = 0; i < vertices; ++i){
      for (int j = 0; j < vertices; ++j) {
            trans[j][i] = matrix[i][j];
        }
    }
}

int main(){
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    int adj[vertices][vertices];
    int trans[vertices][vertices];
    printf("Enter Adjacency matix (with space):\n");
    for (int i = 0; i < vertices; i++)
    {
        for(int j = 0; j < vertices; j++){
            scanf("%d", &adj[i][j]);
            }
    }
    printf("\nAdjacency Matrix ->\n");
    printMatrix(adj);
    printf("Transpose ->\n");
    transpose(adj, trans);
    printMatrix(trans);
    if(checkMatrixEqual(adj, trans)){printf("\nGraph is undirected");}
    else{printf("\nGraph is directed");}
    return 0;
}