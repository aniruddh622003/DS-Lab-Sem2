#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct vertex{
    int id;
    struct vertex *next;
} *vertexHead = NULL, *vertexPtr = NULL;

struct Edge{
    int from;
    int to;
    struct Edge *next;
} *edgeHead = NULL, *edgePtr = NULL;

void addVertex(int id){
    for(vertexPtr = vertexHead; vertexPtr != NULL; vertexPtr = vertexPtr->next){
        if (vertexPtr->id == id)
        {
            printf("Vertex already exist.\n");
            return;
        }        
    }
    struct vertex *temp = NULL;
    temp = (struct vertex *)malloc(sizeof(struct vertex));
    if(temp == NULL){
        printf("Out of memory. Returning..\n");
        return;
    }
    temp->id = id;
    temp->next = vertexHead;
    vertexHead = temp;
    printf("Vertex entered successfully.\n");
}

void displayVertexList(){
    if (vertexHead == NULL)
    {
        printf("No vertices found.\n");
        return;
    }
    for(vertexPtr = vertexHead; vertexPtr != NULL; vertexPtr = vertexPtr->next){
        printf("%d -> ", vertexPtr->id);
    }
    printf("END\n");
}

void addEdge(int start, int end){
    //Check if terminals of edge are in the vertex list
    int startinlist = 0, endinlist = 0;
    for(vertexPtr = vertexHead; vertexPtr != NULL; vertexPtr = vertexPtr->next){
        if (vertexPtr->id == start)
        {
            startinlist = 1;
        }
        if (vertexPtr->id == end)
        {
            endinlist = 1;
        }                
    }
    if(!(startinlist)){
        printf("Start node doesn't exist.\n");
        return;
    }
    if(!(endinlist)){
        printf("End node doesn't exist.\n");
        return;
    }
    for(edgePtr = edgeHead; edgePtr; edgePtr = edgePtr->next){
        if(edgePtr->from == start && edgePtr->to == end){
            printf("Edge already exist.\n");
            return;
        }
    }
    struct Edge *temp = NULL;
    temp = (struct Edge *)malloc(sizeof(struct Edge));
    if(temp == NULL){
        printf("Out of memory. Returning..");
        return;
    }
    temp->from = start;
    temp->to = end;
    temp->next = edgeHead;
    edgeHead = temp;
    printf("Edge entered successfully.\n");
}

void displayEdgeList(){
    if (edgeHead == NULL)
    {
        printf("No edges found.");
        return;
    }    
    for(edgePtr = edgeHead; edgePtr != NULL; edgePtr = edgePtr->next){
        printf("%d->%d\n", edgePtr->from, edgePtr->to);
    }
}

int main(){ 
    int inf = 1;
    char choice;
    while(inf){
        printf("Do you want to enter vertex? (y/n): ");
        scanf("%c", &choice);
        switch (tolower(choice))
        {
        case 'y':
            printf("Enter vertex ID: ");
            int vid;
            scanf("%d", &vid);
            addVertex(vid);
            break;

        case 'n':
            inf = 0;
            break;
        
        default:
            printf("Invalid selection.\n");
            break;
        }
        while((getchar()) != '\n');
    }
    printf("Vertex List: ");
    displayVertexList();
    printf("\n");
    inf = 1;
    while(inf){
        printf("Do you want to enter edge? (y/n): ");
        scanf("%c", &choice);
        switch (tolower(choice))
        {
        case 'y':
            printf("Enter start vertex: ");
            int start, end;
            scanf("%d", &start);
            printf("Enter end vertex: ");
            scanf("%d", &end);
            addEdge(start, end);
            break;

        case 'n':
            inf = 0;
            break;
        
        default:
            printf("Invalid selection.\n");
            break;
        }
        while((getchar()) != '\n');
    }
    printf("\nEdge List (start -> end) ->\n");
    displayEdgeList();
    return 0;
}