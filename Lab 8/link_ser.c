#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

struct node{
    int data;
    struct node *next;
}*head=NULL, *ptr=NULL;

void insertbeg(int n){
    struct node *temp=NULL;
    temp = (struct node *)malloc(sizeof(struct node));
    if(temp == NULL){
        printf("Memory can't be allocated\n");
        return;
    }
    temp->data = n;
    temp->next = head;
    head = temp;
}

void search(int s){
    int index = 0;
    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        index++;
        if (ptr->data == s)
        {
            printf("Element found at position: %d\n", index);
            return;
        }        
    }
    printf("Data not found\n");
}  

void display(){
    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        printf("%d ", ptr->data);
    }
    
}

int main(){
    srand(time(0));
    printf("Number of elements to insert: ");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        insertbeg(rand() % 100);
    }
    printf("Linked list: ");
    display();
    char choice;
    printf("\nSample data inserted..\n\n");
    while(1){
        while((getchar()) != '\n');
        printf("Do you want to search data (y/n): ");
        
        scanf("%c", &choice);
        switch (tolower(choice))
        {
        case 'y':
            printf("Enter number you want to search (0-100): ");
            int data;
            scanf("%d", &data);
            search(data);
            break;
        
        case 'n':
            goto Exit_1;
            break;

        default:
            printf("Invalid selection.\n");
            break;
        }
                
    }
    Exit_1:printf("\n");
    return 0;
}