#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node{
    int data;
    struct Node *next;
} *head = NULL, *ptr = NULL;

void insertbeg(int n){
    struct Node *temp = NULL;
    temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        printf("Memory full, could not add.\n");
        return;
    }
    temp->data = n;
    if (head == NULL)
    {
        temp->next = NULL;
    }
    else{temp->next = head;}
    head = temp;
}

void display(){
    printf("List: ");
    for(ptr = head; ptr != NULL; ptr = ptr->next){
        printf("%d --> ", ptr->data);
    }
    printf("END\n");
}

void deletebeg(){
    struct Node *temp = head;
    head = temp->next;
    free(temp);
    printf("Deleteion Successful\n");
}

int list_size(){
    int size = 0;
    for(ptr = head; ptr != NULL; ptr = ptr->next) size++;
    return size;
}

//(ws) enables with steps. 
// ws = 0 (no step), ws != 0 (steps will be shown)
void bubble_sort(int ws){
    if (head == NULL)
    {
        printf("Empty list");
        return;
    }
    int i, j, n = list_size();
    int swap = 1;
    while (swap){    
        for(i = 0; i < n-1; i++){
            swap = 0;
            for(j = 0, ptr=head; j < (n-1)-i; j++, ptr = ptr->next){
                if (ptr->data > ptr->next->data)
                {
                    int t = ptr->data;
                    ptr->data = ptr->next->data;
                    ptr->next->data = t;
                    swap++;
                }
                }
            if (swap == 0)
            {
                printf("\nSorted -->\n");
                display();
                break;
            }
            else {
                if (ws){
                    printf("Pass %d ->\n", i+1);
                    display();
                }
            }  
        }
    }    
}

int main(){
    insertbeg(4);
    insertbeg(2);
    insertbeg(4);
    insertbeg(7);
    insertbeg(3);
    printf("Sanmple data inserted..\n");
    display();
    int check = 1;
    char choice;
    while(check){
        printf("Do you want to insert data (y/n): ");
        scanf("%c", &choice);
        switch (tolower(choice))
        {
        case 'y':
            printf("Enter number you want to insert: ");
            int n;
            scanf("%d", &n);
            insertbeg(n);
            break;
        
        case 'n':
            check = 0;
            break;

        default:
            printf("Invalid selection.\n");
            break;
        }
        while((getchar()) != '\n');        
    }
    display();
    printf("\n");

    check = 1;
    int c;
    while(check){
        printf("Choose sort type\n");
        printf("1. Sort with steps\n");
        printf("2. Sort without steps\n");
        printf("Enter selection (1/2): ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            bubble_sort(1);
            check = 0;
            break;
        
        case 2:
            bubble_sort(0);
            check = 0;
            break;

        default:
            printf("Invalid selection.\n");
            break;
        }
                
    }
    return 0;
}