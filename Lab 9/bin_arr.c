#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
int size, space_diff = 10;

void printTree(int tree[], int rootIndex, int space){
    if(rootIndex >= size) return;

    space += space_diff;
    printTree(tree, (2*rootIndex + 2), space);

    printf("\n");
    for (int i = 0; i < space; i++) printf(" ");    
    printf("%d\n", tree[rootIndex]);

    printTree(tree, (2*rootIndex + 1), space);
}

void identifyRelatives(int tree[], int index){
    int lchild = ((2*index + 1) < size)?(2*index + 1):-1;
    int rchild = ((2*index + 2) < size)?(2*index + 2):-1;
    int parent = ((int)ceil(((float)index)/2)) - 1;
    printf("\nCurrent: %d\n", tree[index]);
    (parent == -1)?printf("Parent: Does Not Exist\n"):printf("Parent: %d\n", tree[parent]);
    (lchild == -1)?printf("Left Child: Does Not Exist\n"):printf("Left Child: %d\n", tree[lchild]);
    (rchild == -1)?printf("Right Child: Does Not Exist\n"):printf("Right Child: %d\n", tree[rchild]);
}

void printCombos(int tree[], int index){
    if((2*index + 1) >= size) return;
    if((2*index + 2) >= size) return;
    printf("P: %d -> L: %d -> R: %d\n", tree[index], tree[(2*index + 1)], tree[(2*index + 2)]);
    //Go to left subtree
    printCombos(tree, (2*index + 1));
    //Go to right subtree
    printCombos(tree, (2*index + 2));
}

void printLeaves(int tree[], int index){
    if(index >= size)return;
    if((2*index + 1) >= size && (2*index + 2) >= size){
        printf("%d ", tree[index]);
    }
    if((2*index + 1) < size) printLeaves(tree, (2*index + 1));
    if((2*index + 2) < size) printLeaves(tree, (2*index + 2));
}

int main(){
    printf("Enter Size of tree: ");
    scanf("%d", &size);
    int tree[size];
    printf("Enter traversal: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &tree[i]);
    }
    printf("\n");
    printTree(tree, 0, -10);
    int inf = 1;
    char choice;
    while(inf){
        while((getchar()) != '\n');
        printf("Do you want to find relatives of a node: ");
        scanf("%c", &choice);
        switch (tolower(choice))
        {
        case 'y': ;
            int indx;
            printf("Enter node index: ");
            scanf("%d", &indx);
            identifyRelatives(tree, indx);
            break;
        case 'n':
            inf = 0;
            break;
        default:
            printf("Invalid selection\n");
            getchar();
            break;
        }
        
    }
    printf("Possible Parent-Left-Right combinations -> \n");
    printCombos(tree, 0);
    printf("Leaf Nodes: ");
    printLeaves(tree, 0);
    return 0;
}