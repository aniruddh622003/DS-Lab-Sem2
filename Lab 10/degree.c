#include <stdio.h>
#include <stdlib.h>

#define heading "------------------ Find degrees of graphs ------------------\n\n"
int n;

// Undirected ->
// Degree = Sum of row/column

// Diagraph -> 
// Indegree = Sum of column
// Outdegree = Som of row

void printMatrix(int matrix[][n], char vid[]){
    printf("  ");
    for (int i = 0; i < n; i++)
    {
        printf("%c ", vid[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%c ", vid[i]);
        for(int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
            }
        printf("\n");
    }
}

void degreeUndirected(int und[][n], char vid[n]){
    for(int i = 0; i < n; i++){
        int degree = 0;
        for (int j = 0; j < n; j++)
        {
            degree += und[i][j];
        }
        printf("Degree of %c: %d\n", vid[i], degree);
    } 
}

void degreeDirected(int dimat[][n], char vid[n]){
    for(int i = 0; i < n; i++){
        int indegree = 0, outdegree = 0;
        for (int j = 0; j < n; j++)
        {
            outdegree += dimat[i][j];
            indegree += dimat[j][i];
        }
        printf("In-Degree of %c -> %d | Out-Degree of %c -> %d\n", vid[i], indegree, vid[i], outdegree);
    }
}


int main(){
    system("cls");
    printf(heading);
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    char vIDs[n];
    printf("Enter vertex IDs (each ID in one line) -> \n");
    for(int i = 0; i < n; i++){
        while((getchar()) != '\n');
        scanf("%c", &vIDs[i]);
    }
    int und[n][n], diadj[n][n];
    printf("Enter adjacency matrix for undirected->\n");
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++){
            scanf("%d", &und[i][j]);
            }
    }
    printf("Enter adjacency matrix for directed->\n");
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++){
            scanf("%d", &diadj[i][j]);
            }
    }
    int choice;
    Main: system("cls");
    printf(heading);
    printf("Choose option ->\n");
    printf("1. View degree of vertices of undirected graph\n");
    printf("1. View indegrees and outdegrees of vertices of directed graph\n");
    printf("3. View adjacency matrices\n");
    printf("4. Exit");
    printf("\n\nOption: ");
    scanf("%d", &choice);
    switch (choice)
    {
    
    case 1:
        system("cls");
        printf(heading);
        degreeUndirected(und, vIDs);
        printf("\n\nPress Enter to continue..");
        while((getchar()) != '\n');
        getchar();
        goto Main;
        break;

    case 2:
        system("cls");
        printf(heading);
        degreeDirected(diadj, vIDs);
        printf("\n\nPress Enter to continue..");
        while((getchar()) != '\n');
        getchar();
        goto Main;
        break;

    case 3:
        View_matrix: system("cls");
        printf(heading);
        printf("Choose graph ->\n");
        printf("1. Undirected graph\n");
        printf("2. Directed graph");
        printf("\n\nOption: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            system("cls");
            printf(heading);
            printf("Adjacency matrix for undirected graph ->\n");
            printMatrix(und, vIDs);
            printf("\n\nPress Enter to continue..");
            while((getchar()) != '\n');
            getchar();
            goto Main;
            break;

        case 2:
            system("cls");
            printf(heading);
            printf("Adjacency matrix for directed graph ->\n");
            printMatrix(diadj, vIDs);
            printf("\n\nPress Enter to continue..");
            while((getchar()) != '\n');
            getchar();
            goto Main;
            break;
        
        default:
            printf("Invalid selection. Press Enter to continue..");
            while((getchar()) != '\n');
            getchar();
            goto View_matrix;
            break;
        }
        
        break;
    
    case 4:
        break;

    default:
        printf("Invalid selection. Press Enter to continue..");
        while((getchar()) != '\n');
        getchar();
        goto Main;
        break;
    }
    return 0;
}