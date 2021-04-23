#include <stdio.h>
#include <stdlib.h>

struct queue{
    int n;
    struct queue *next;
} *in_r=NULL, *out_r=NULL; 

void clear_buff(){
    while((getchar())!='\n');
}

//Insert Beginning
void ins_beg(int n, struct queue **p){
    struct queue *temp = NULL;
    temp = (struct queue *)malloc(sizeof(struct queue));
    if (temp == NULL)
    {
        printf("Memory full...");
        return;
    }
    temp->n = n;
    temp->next = *p;
    *p = temp; 
}

//Insert End
void ins_end(int n, struct queue **p){
    struct queue *temp = NULL, *ptr;
    temp = (struct queue *)malloc(sizeof(struct queue));
    if (temp == NULL)
    {
        printf("Memory full...");
        return;
    }
    temp->n = n;
    temp->next = NULL;
    if (*p == NULL)
    {
        *p = temp;
        return;
    }
    for (ptr = *p; ptr->next != NULL ; ptr = ptr->next);
    ptr->next = temp;    
}

//Display
void display(struct queue *h){
    printf("Queue: ");
    struct queue *ptr;
    for (ptr = h; ptr != NULL ; ptr = ptr->next)
    {
        printf("%d ", ptr->n);  
    }
}

//Delete beginning
void delete_beg(struct queue **p){
    if (*p == NULL)
    {
        printf("List Empty.");
        return;
    }    
    struct queue *temp;
    temp = *p;
    if (temp->next == NULL)
    {
        free(temp);
        *p = NULL;
        printf("Deleted list completely.");
        return;
    }
    
    *p = temp->next;
    free(temp);
    printf("Deletion from front successful.");
}

//Delete End
void delete_end(struct queue **p){
    if (*p == NULL)
    {
        printf("List Empty.");
        return;
    }
    struct queue *temp, *ptr;
    temp = *p;
    if (temp->next == NULL)
    {
        free(temp);
        *p = NULL;
        printf("Deleted list completely.");
        return;
    }
    for(;temp->next->next != NULL; temp = temp->next);
    ptr = temp->next;
    temp->next = NULL;
    free(ptr);
    printf("Deletion from end successful.");
}

int main(){
    int n;
    Main_Menu: system("cls");
    printf("\tMain Menu\n");
    printf("-------------------------\n");
    printf("2 Queues available.\n\n");
    printf("1. Input restricted\n");
    printf("2. Output restriced\n");
    printf("3. Exit");
    printf("\nSelect Choice: ");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        In_Menu1: system("cls");
        printf("\tQueue Menu\n");
        printf("-------------------------\n");
        printf("The queue is input restricted\n");
        printf("1. Enqueue (rear)\n");
        printf("2. Display queue\n");
        printf("3. Dequeue (front)\n");
        printf("4. Dequeue (rear)\n");
        printf("5. Back\n");
        printf("\nSelect Choice: ");
        clear_buff();
        scanf("%d", &n);
        int in;
        switch (n)
        {        
        case 1:            
            printf("Enter number u want to insert: ");
            scanf("%d", &in);
            ins_end(in, &in_r);
            goto Main_Menu;
            break;
        
        case 2:
            display(in_r);
            printf("\nPress Enter to Continue..");
            clear_buff();
            getchar();
            goto Main_Menu;
            break;
        
        case 3:
            delete_beg(&in_r);
            printf("\nPress Enter to Continue..");
            clear_buff();
            getchar();
            goto Main_Menu;
            break;
            
        case 4:
            delete_end(&in_r);
            printf("\nPress Enter to Continue..");
            clear_buff();
            getchar();
            goto Main_Menu;
            break;

        case 5:
            goto Main_Menu;

        default:
            printf("Invalid Selection. Try again..");
            clear_buff();
            getchar();
            goto In_Menu1;
            break;
        }
        break;

    case 2:
        In_Menu3: system("cls");
        printf("\tQueue Menu\n");
        printf("-------------------------\n");
        printf("The queue is Output restricted\n");
        printf("1. Enqueue (rear)\n");
        printf("2. Enqueue (front)\n");
        printf("3. Display Queue\n");
        printf("4. Dequeue (front)\n");
        printf("5. Back\n");
        printf("\nSelect Choice: ");
        clear_buff();
        scanf("%d", &n);
        int in2;
        switch (n)
        {        
        case 1:            
            printf("Enter number u want to insert: ");
            scanf("%d", &in2);
            ins_end(in2, &out_r);
            goto Main_Menu;
            break;
        
        case 2:
            printf("Enter number u want to insert: ");
            scanf("%d", &in2);
            ins_beg(in2, &out_r);
            goto Main_Menu;
            break;
        
        case 3:
            display(out_r);
            printf("\nPress Enter to Continue..");
            clear_buff();
            getchar();
            goto Main_Menu;
            break;
            
        case 4:
            delete_beg(&out_r);
            printf("\nPress Enter to Continue..");
            clear_buff();
            getchar();
            goto Main_Menu;
            break;

        case 5:
            goto Main_Menu;

        default:
            printf("Invalid Selection. Try again..");
            clear_buff();
            getchar();
            goto In_Menu3;
            break;
        }
        break;

    case 3:
        free(in_r);
        free(out_r);
        break;
    
    default:
        printf("Invalid Selection. Try again..");
        clear_buff();
        getchar();
        goto Main_Menu;
        break;
    }
    return 0;
}