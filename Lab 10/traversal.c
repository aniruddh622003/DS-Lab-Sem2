#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

//Sample graph shape
//    0
//  /  \
// 1 - 2
// |   |
// 3   4
// \  
//  5

// BFS: 0, 2, 1, 4, 3, 5
// DFS: 0 1 3 5 2 4

struct node {
  int vertex;
  bool visited;
  struct node* next;
};
struct Queue{
    struct node *vertexNode;
    struct Queue *next;
} *queueHead = NULL, *queuePtr = NULL;

struct Stack{
    struct node *vertexNode;
    struct Stack *next;
} *stackHead = NULL, *stackPtr = NULL;

struct Graph {
  int numVertices;
  struct node* vertexList;
  struct node** adjLists;
};

void enqueue(struct Graph* graph, struct node *vertexNode){
    struct Queue *temp = NULL;
    temp = (struct Queue *)malloc(sizeof(struct Queue));
    temp->vertexNode = vertexNode;
    temp->next = queueHead;
    queueHead = temp;
}

void printQueue(){
    for (queuePtr = queueHead; queuePtr; queuePtr = queuePtr->next)
    {
        printf("%d -> ", queuePtr->vertexNode->vertex);
    }    
}

int dequeue(){
    struct Queue *temp = NULL;
    if (queueHead == NULL)
    {
      return -1;
    }
    if (queueHead->next == NULL)
    {
      int id = queueHead->vertexNode->vertex;
      queueHead = NULL;
      return id;
    }
    for(temp = queueHead; temp->next->next; temp = temp->next);
    int id = temp->next->vertexNode->vertex;
    free(temp->next);
    temp->next = NULL;
    return id;
}

void push(struct Graph* graph, struct node *vertexNode){
    struct Stack *temp = NULL;
    temp = (struct Stack *)malloc(sizeof(struct Stack));
    temp->vertexNode = vertexNode;
    temp->next = stackHead;
    stackHead = temp;
}

void printStack(){
    for (stackPtr = stackHead; stackPtr; stackPtr = stackPtr->next)
    {
        printf("%d -> ", stackPtr->vertexNode->vertex);
    }    
}

int pop(){
    if(stackHead == NULL){
      return -1;
    }
    if (stackHead->next == NULL)
    {
      int id = stackHead->vertexNode->vertex;
      stackHead = NULL;
      return id;
    }
    struct Stack *temp = NULL;
    temp = stackHead;
    int id = temp->vertexNode->vertex;
    stackHead = temp->next;
    free(temp);
    return id;
}

struct node *searchVList(struct node *vlist, int id){
    struct node* vListptr = vlist;
    for(; vListptr; vListptr = vListptr->next){
      if (vListptr->vertex == id)
      {
        return vListptr;
      }      
    }
    return vListptr;
}

void bfsVisit(struct Graph* graph, int id){
    struct node* temp = graph->adjLists[id], *vertex;
    while (temp) {
      vertex = searchVList(graph->vertexList, temp->vertex);
      if(vertex->visited != 1){
        enqueue(graph, vertex);
        vertex->visited = 1;
      }
      temp = temp->next;
    }
}

void bfs(struct Graph* graph, int vertexID){
  struct node* temp = graph->adjLists[vertexID], 
  *vListPtr = searchVList(graph->vertexList, vertexID);
  vListPtr->visited = true;
  enqueue(graph, vListPtr);
  while(queueHead){
    int visitIndex = dequeue();
    printf("%d, ", visitIndex);
    bfsVisit(graph, visitIndex);
  } 
  printQueue();
}

void dfsVisit(struct Graph* graph, int id){
    struct node* temp = graph->adjLists[id], *vertex;
    while (temp) {
      vertex = searchVList(graph->vertexList, temp->vertex);
      if(vertex->visited != 1){
        push(graph, vertex);
        vertex->visited = 1;
      }
      temp = temp->next;
    }
}

void dfs(struct Graph* graph, int vertexID){
  struct node* temp = graph->adjLists[vertexID], 
  *vListPtr = searchVList(graph->vertexList, vertexID);
  vListPtr->visited = true;
  push(graph, vListPtr);
  while(stackHead){
    int visitIndex = pop();
    printf("%d, ", visitIndex);
    dfsVisit(graph, visitIndex);
  } 
  // printStack();
}

void resetVisited(struct node *vlist){
  struct node* vListptr = vlist;
    for(; vListptr; vListptr = vListptr->next){
      vListptr->visited = false;    
    }
}

// Create a node
struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->visited = false;
  newNode->next = NULL;
  return newNode;
}

// Create a graph
struct Graph* createAGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->vertexList = NULL;
  graph->adjLists = malloc(vertices * sizeof(struct node*));

  int i;
  for (i = 0; i < vertices; i++){
    struct node *temp, *vListptr;
    temp = (struct node *)malloc(vertices * sizeof(struct node));
    temp->vertex = i;
    temp->visited = false;
    temp->next = NULL;
    if (graph->vertexList == NULL)
    {
      graph->vertexList = temp;
    }
    else{
    for(vListptr = graph->vertexList; vListptr->next != NULL; vListptr = vListptr->next);
    vListptr->next = temp;
    }
    graph->adjLists[i] = NULL;
  }
  return graph;
}

// Add edge
void addEdge(struct Graph* graph, int source, int dest) {
  // Add edge from s to d
  struct node* newNode = createNode(dest);
  newNode->next = graph->adjLists[source];
  graph->adjLists[source] = newNode;

  // Add edge from d to s
  newNode = createNode(source);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

// Print the graph
void printGraph(struct Graph* graph) {
  int v;
  printf("Adjacency List :\n");
  struct node* vListptr = graph->vertexList;
  for (v = 0; v < graph->numVertices; v++) {
    struct node* adListPtr = graph->adjLists[v];    
    printf("Vertex %d: ", vListptr->vertex);
    while (adListPtr) {
      printf("%d -> ", adListPtr->vertex);
      adListPtr = adListPtr->next;
    }
    vListptr = vListptr->next;
    printf("\n");
  }
}

int main() {
    printf("Enter number of vertices: ");
    int n;
    scanf("%d", &n);
    struct Graph* graph = createAGraph(n);
    int inf = 1;
    char choice;
    while(inf){
        printf("Do you want to add edge? (y/n): ");
        while((getchar()) != '\n');
        scanf("%c", &choice);
        switch (tolower(choice))
        {
        case 'y':
            printf("Enter start vertex: ");
            int start;
            scanf("%d", &start);
            printf("Enter end vertex: ");
            int end;
            scanf("%d", &end);
            addEdge(graph, start, end);
            break;

        case 'n':
            inf = 0;
            break;
        
        default:
            printf("Invalid selection.\n");
            break;
        }
        
    }
    // addEdge(graph, 0, 1);
    // addEdge(graph, 0, 2);
    // addEdge(graph, 1, 2);
    // addEdge(graph, 1, 3);
    // addEdge(graph, 2, 4);
    // addEdge(graph, 3, 5);

    printGraph(graph);
    printf("\nBFS Traversal: ");
    bfs(graph, 0);

    resetVisited(graph->vertexList);
    printf("\nDFS Traversal: ");
    dfs(graph, 0);
    return 0;
}