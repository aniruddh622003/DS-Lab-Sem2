#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node{
    int data;
    struct Node *next;
} *ptr = NULL, *table[10] = {NULL};

//Hash function
int hash(int key){
    int h, sum;
    h = key % 1000;
    LP: sum = 0;
    while (h > 0)
    {
        int dig = h % 10;
        sum += dig;
        h = h/10;
    }

    if (sum > 9)
    {
        h = sum;
        goto LP;
    }
        
    return sum;
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
    int index = hash(key);
    if (table[index] == NULL)
    {
        printf("Data Not Found\n");
        return;
    }
    int count = 1;
    for (ptr = table[index]; ptr->data != key; ptr = ptr->next, count ++){
        if (ptr->next == NULL)
        {
            printf("Data Not Found\n");
            return;
        }
    }
    printf("Element found at position %d of list in index %d\n", count, index);
}

void delete(int key){
    int index = hash(key);
    struct Node *temp;
    if (table[index] == NULL)
    {
        printf("Data Not Found\n");
        return;
    }
    if(table[index]->data == key){
        if (table[index]->next == NULL)
        {
            table[index] = NULL;
            printf("Deleted\n");
            return;
        }
        temp = table[index];
        table[index] = temp->next;
        free(temp);
        printf("Deleted\n");
        return;
    }
    
    if (table[index]->next == NULL)
    {
        printf("Data Not found\n");
        return;
    }
    for (ptr = table[index]; ptr->next->data != key; ptr = ptr->next){
        
        if (ptr->next->next == NULL)
        {
            printf("Data Not Found\n");
            return;
        }
    }
    temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
    printf("Deleted\n");
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
    insert(5000423);
    insert(5000432);
    insert(5000425);
    char choice;
    printf("Sample data inserted..\n\n");
    while(1){
        printf("Do you want to insert data (y/n): ");
        
        scanf("%c", &choice);
        switch (tolower(choice))
        {
        case 'y':
            printf("Enter Sap-ID you want to insert: ");
            int sap;
            scanf("%d", &sap);
            insert(sap);
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
    while(1){
        printf("Do you want to search data (y/n): ");
        while((getchar()) != '\n');
        scanf("%c", &choice);
        switch (tolower(choice))
        {
        case 'y':
            printf("Enter Sap-ID you want to search: ");
            int sap;
            scanf("%d", &sap);
            search(sap);
            break;
        
        case 'n':
            goto Exit_2;
            break;

        default:
            printf("Invalid selection.\n");
            break;
        }        
    }
    Exit_2:printf("\n");
    while(1){
        printf("Do you want to delete data (y/n): ");
        while((getchar()) != '\n');
        scanf("%c", &choice);
        switch (tolower(choice))
        {
        case 'y':
            printf("Enter Sap-ID you want to delete: ");
            int sap;
            scanf("%d", &sap);
            delete(sap);
            break;
        
        case 'n':
            goto Exit_3;
            break;

        default:
            printf("Invalid selection.\n");
            break;
        }        
    }
    Exit_3:printf("\n");
    print_table();
    return 0;
}