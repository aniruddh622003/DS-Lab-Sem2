#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int tab_size;
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

void insert(int key, int *arr){
    int init_index = hash(key);
    int index = init_index;
    while(1){ //Endless Loop
        if (index == tab_size){
            index = 0;
        } 
        

        if (arr[index] == 0)
        {
            arr[index] = key;
            printf("Inserted succesfully.\n");
            return;
        }
        else{            
            index++;
            if (index == init_index)
            {
                printf("Table full can not insert.\n");
                return;   
            }                       
        }
    }
}

int search(int key, int *arr){
    int init_index = hash(key);
    int index = init_index;
    while(1){ //Endless Loop
        if (index == tab_size){
                index = 0;
        }
        if (arr[index] == key)
        {
            printf("Element found.\n");
            return index;
        }
        else{
            index++;
            if (index == init_index)
            {
                printf("Element does not exist.\n");
                return -1;   
            }
        }
    }  
}

void delete(int key, int *arr){
    int in = search(key, arr);
    if (in != -1)
    {
        arr[in] = 0;
        printf("Data Deleted\n");
    }   
}

int main(){    
    printf("Enter size of has table you want to create(Min: 10): ");
    scanf("%d", &tab_size);
    if (tab_size < 10){
        tab_size = 10;
        printf("Table size too small. Automatically made table of size 10\n");
    }
    int table[tab_size];
    for (int i = 0; i < tab_size; i++)
    {
        table[i] = 0;
    }
    insert(5000423, table);
    insert(5000425, table);
    char choice;
    printf("Sample data inserted..\n\n");
    while(1){
        printf("Do you want to insert data (y/n): ");
        while((getchar()) != '\n');
        scanf("%c", &choice);
        switch (tolower(choice))
        {
        case 'y':
            printf("Enter Sap-ID you want to insert: ");
            int sap;
            scanf("%d", &sap);
            insert(sap, table);
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
            int in = search(sap, table);
            if (in != -1)
            {
                printf("Element at index: %d\n", in);
            }            
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
            delete(sap, table);
            break;
        
        case 'n':
            goto Exit_3;
            break;

        default:
            printf("Invalid selection.\n");
            break;
        }
    }
    Exit_3:printf("\n\n");
    //Print Table
    printf("Final Table Map --------->\n");
    printf("Indexes:");
    for (int i = 0; i < tab_size; i++)
    {
        printf("\t%d", i);
    }
    printf("\nData:\t");
    for (int i = 0; i < tab_size; i++)
    {
        printf("\t%d", table[i]);
    }
    
}