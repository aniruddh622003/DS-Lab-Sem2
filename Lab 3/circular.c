#include <stdio.h>
#include <stdlib.h>

struct block
{
    int data;
    struct block *next;
} *head = NULL, *ptr = NULL;;

//Clears the buffer memory
void clear (void) 
{    
  while ( getchar() != '\n' );
}

void display(){
    if (head == NULL)
    {
        printf("List is empty..\n");
        return;
    }
    
    printf("...-->\n%d -->\n", head->data);
    for(ptr = head->next; ptr != head; ptr = ptr->next){
        printf("%d -->\n", ptr->data);
    }
    printf("...");
}

void insert(int n){
    struct block *new;
    new = (struct block *)malloc(sizeof(struct block));
    if (new == NULL)
    {
        printf("Out of memory");
    }
    new->data = n;
    if (head == NULL)
    {
        head = new;
        new->next = head;
    }
    else{
        for(ptr = head; ptr->next != head; ptr = ptr->next);
        new->next = head;
        ptr->next = new;
    }
    printf("Node Successfully inserted.\n");
}

void delete(int n){
    if(head == NULL){
        printf("List does not exist make a list first.\n");
        return;
    }
    if (head->next == head)
    {
        printf("Single element in list.... Deleted.\n");
        head = NULL;
        return;
    }
    
    int counter = 0;
    for (ptr = head; counter < n-2; ptr = ptr->next, counter++);
    printf("Deleted Element: %d", ptr->next->data);
    struct block *temp;
    temp = ptr->next;
    ptr->next = temp->next;
    temp->next = NULL;
    free(temp);
}

int main(){
    int n;
    MAIN_MENU: system("cls");
    printf("Circular linked list\n");
    printf("--------------------\n");
    printf("1. Display list\n");
    printf("2. Insert element(s)\n");
    printf("3. Delete at a given index\n");
    printf("4. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &n);
    switch (n)
    {
    case 1:        
        display();
        printf("\n\nPress any key to continue...");
        clear();
        getchar();
        goto MAIN_MENU;
        break;

    case 2:
        system("cls");
        int num;
        printf("Enter number of elements you want to enter: ");
        clear();
        scanf("%d", &num);
        for (int i = 1; i <= num; i++)
        {
            int d;
            printf("New data %d: ", i);
            clear();
            scanf("%d", &d);
            insert(d);
        }
        printf("\n\nSuccessfully inserted. Press any key to continue...");
        clear();
        getchar();
        goto MAIN_MENU;
        break;

    case 3:
        system("cls");
        int index;
        printf("Note: In circular list, indexes are overlapped if list size is smaller than index\n");
        printf("Enter index of elements you want to delete: ");
        clear();
        scanf("%d", &index);
        delete(index);
        printf("\n\nPress any key to continue...");
        clear();
        getchar();
        goto MAIN_MENU;
        break;

    case 4:
        free(head);
        free(ptr);
        return 0;
        break;

    default:
        printf("Invalid selection. Press any key to continue..");
        clear();
        getchar();
        goto MAIN_MENU;
        break;
    }       
    return 0;
}