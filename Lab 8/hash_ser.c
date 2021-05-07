#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

struct Node{
    int data;
    struct Node *next;
} *ptr = NULL, *table[10] = {NULL};

//Hash function
int hash(int key){
    int h;
    h = key / 10;
    return h;
}

void insert(int key){
    int index = hash(key);
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data  = key;
    temp->next = NULL;
    if(table[index] == NULL){
        table[index] = temp;
    }
    else{
        for(ptr = table[index]; ptr->next != NULL; ptr = ptr->next);
        ptr->next = temp;
    }
}

void search(int key){
    int index = hash(key), comp = 0;
    if (table[index] == NULL)
    {
        printf("Data Not Found\n");
        return;
    }
    int count = 1;
    for (ptr = table[index]; ptr->data != key; ptr = ptr->next, count ++){
        comp++;
        if (ptr->next == NULL)
        {
            comp++;
            printf("Comparision made: %d\n", comp);
            printf("Data Not Found\n");
            return;
        }
        
    }
    comp++;
    printf("Comparision made: %d\n", comp);
    printf("Element found at position %d of list in index %d\n", count, index);
}

void print_table(){
    printf("Index\tData\n");
    for (int i = 0; i < 10; i++)
    {        
        printf("%d\t", i);
        for (ptr = table[i]; ptr != NULL; ptr = ptr->next)
        {
            printf("%d\t", ptr->data);
        }
        
        printf("\n");
    }
    
}

int main(){
    srand(time(0));

    for (int i = 0; i < 40; i++)
    {
        insert(rand() % 100);
    }
    print_table();
    char choice;
    printf("Sample data inserted..\n\n");
    while(1){
        printf("Do you want to search data (y/n): ");
        
        scanf("%c", &choice);
        switch (tolower(choice))
        {
        case 'y':
            printf("Enter number you want to search (0-100): ");
            int sap;
            scanf("%d", &sap);
            search(sap);
            break;
        
        case 'n':
            goto Exit_1;
            break;

        default:
            printf("Invalid selection.\n");
            break;
        }
        while((getchar()) != '\n');        
    }
    Exit_1:printf("\n");
    
    return 0;
}