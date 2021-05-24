#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int space_diff = 10;

struct node{
    int data;
    struct node *left, *right;
};

struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    // Since every inserted node will be a leaf node
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int key)
{
    if (node == NULL)
        return newNode(key);
 
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
 
    /* return the (unchanged) node pointer */
    return node;
}

void printTree(struct node *root, int space)
{
    if (root == NULL)
        return;
  
    space += space_diff;
    printTree(root->right, space);
  
    // Print current node after space
    // count
    printf("\n");
    for (int i = space_diff; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
  
    // Process left child
    printTree(root->left, space);
}

void printInOrder(struct node *root){
    if (root == NULL) return;
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

void printPreOrder(struct node *root){
    if (root == NULL) return;
    printf("%d ", root->data);
    printPreOrder(root->left);    
    printPreOrder(root->right);
}

void printPostOrder(struct node *root){
    if (root == NULL) return;
    printPostOrder(root->left);    
    printPostOrder(root->right);
    printf("%d ", root->data);
}

int main(){
    srand(time(0));
    printf("Binary Search tree using linked lists\n\n");
    int root_num = rand() % 100;
    struct node* root = NULL;
    root = insert(root, root_num);  
    printf("Root: %d\n", root_num); 
    int inf = 1;
    char choice;
    while(inf){        
        printf("Do you want to insert node: ");
        scanf("%c", &choice);
        switch (tolower(choice))
        {
        case 'y': ;
            int data;
            printf("Enter node data: ");
            scanf("%d", &data);
            insert(root, data);
            break;
        case 'n':
            inf = 0;
            break;
        default:
            printf("Invalid selection\n");
            getchar();
            break;
        }
        while((getchar()) != '\n');
    }
    printf("\nFinal Tree -> \n");
    printTree(root, 0);
    printf("\nIn-order traversal: ");
    printInOrder(root);
    printf("\nPre-order traversal: ");
    printPreOrder(root);
    printf("\nPost-order traversal: ");
    printPostOrder(root);
    return 0;
}