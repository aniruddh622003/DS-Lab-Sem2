#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev, *next;
} *head=NULL, *ptr=NULL, *last=NULL;

//Clears the buffer memory
void clear (void) 
{    
  while ( getchar() != '\n' );
}

int listsize(){
    int size = 0;
    for(ptr = head; ptr != NULL; ptr = ptr->next){
        size++;
    }
    return size; 
}

void insertstart(int n){
    struct node *temp = NULL;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Out of memory. Can not add.");
    }
    temp->data = n;
    temp->prev = NULL;
    if (head == NULL)
    {
        head = temp;
        last = temp;
        temp->next = NULL;
    }
    else{
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertend(int n){
    struct node *temp = NULL;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Out of memory. Can not add.");
    }
    temp->data = n;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        last = temp;
        temp->prev = NULL;
    }
    else{
        temp->prev = last;
        last->next = temp;
        last = temp;
    }
}

void insertindex(int n){
    if (head == NULL)
    {
        printf("List is empty.. Use other two insert options\n");
        return;
    }
    if (head->next == NULL)
    {
        printf("Single element in list. Can not insert in middle.\n");
        return;
    }        
    int l_size = listsize();
    printf("Insert element after index (1-%d): ", l_size-1);
    int index;
    clear();
    scanf("%d", &index);
    struct node *temp = NULL;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Out of memory. Can not add.");
    }
    temp->data = n;
    if ((int)(l_size/2) >= index)
    {
        int i = 1;
        for(ptr=head; i < index ; ptr = ptr->next, i++);
    }
    else{
        int i = l_size - index;
        for(ptr = last; i > 0; ptr = ptr->prev, i--);
    }
    temp->prev = ptr;
    temp->next = ptr->next;

    ptr->next->prev = temp;
    ptr->next = temp;
}

void printlist(){
    system("cls");
    if (head == NULL)
    {
        printf("List is empty..");
        return;
    }
    for(ptr = head; ptr != NULL; ptr=ptr->next){
        printf("%d <-->\n", ptr->data);
    }    
}

void printrev(){
    system("cls");
    if (head == NULL)
    {
        printf("List is empty..");
        return;
    }
    for(ptr = last; ptr != NULL; ptr=ptr->prev){
        printf("%d <-->\n", ptr->data);
    } 
}

void deletestart(){
    if (head == NULL)
    {
        printf("List is empty..\n");
        return;
    }
    if (head->next == NULL)
    {
        printf("Single element in list. Deleted\n");
        head = NULL;
        free(last);
        last = NULL;
        return;
    }
    ptr = head->next;
    if (ptr != NULL)
    {
        ptr->prev = NULL;
    } 
    free(head);
    head = ptr;
    printf("Deletion Successful.\n");
}

void deleteend(){
   if (head == NULL)
    {
        printf("List is empty..\n");
        return;
    }
    if (head->next == NULL)
    {
        printf("Single element in list. Deleted\n");
        head = NULL;
        free(last);
        last = NULL;
        return;
    }
    ptr = last->prev;
    if (ptr != NULL)
    {
        ptr->next = NULL;
    } 
    free(last);
    last = ptr;
    printf("Deletion Successful.\n");
}

void deleteindex(){
    if (head == NULL)
    {
        printf("List is empty..\n");
        return;
    }
    if (head->next == NULL)
    {
        printf("Single element in list. Deleted\n");
        head = NULL;
        free(last);
        last = NULL;
        return;
    }
    int l_size = listsize();
    if (l_size == 2)
    {
        printf("Can not delete like this.. List too small\nUse other 2 options\n");
        return;
    }
    
    printf("Insert element after index (1-%d): ", l_size-2);
    clear();
    int ind;
    scanf("%d", &ind);
    if ((int)(l_size/2) >= ind){
        int i = 1;
        for(ptr=head; i < ind ; ptr = ptr->next, i++);
        
    }
    else{
        int i = l_size - ind;
        for(ptr = last; i > 0; ptr = ptr->prev, i--);
    }
    struct node *temp = ptr->next;
    ptr->next = temp->next;
    ptr->next->prev = ptr;
    free(temp);
    printf("Deletion Successful\n");
}

int main(){
    int n;
    insertend(1);
    insertend(2);
    insertend(3);
    insertend(4);
    insertend(5);
    insertend(6);
    MAIN_MENU: system("cls");
    printf("Doubly linked list\n");
    printf("--------------------\n");
    printf("1. Display list\n");
    printf("2. Insert element\n");
    printf("3. Delete element\n");
    printf("4. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        DISPLAY_MENU: system("cls");
        printf("Display Menu\n");
        printf("--------------------\n");
        printf("1. Display normally\n");
        printf("2. Display in reverse\n");
        printf("\nEnter your choice: ");
        clear();
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printlist();
            printf("\n\nPress any key to continue...");
            clear();
            getchar();
            goto MAIN_MENU;
            break;

        case 2:
            printrev();
            printf("\n\nPress any key to continue...");
            clear();
            getchar();
            goto MAIN_MENU;
            break;
        
        default:
            printf("Invalid selection. Press any key to continue..");
            clear();
            getchar();
            goto DISPLAY_MENU;
            break;
        }
        break;
    
    case 2:
        INSERT_MENU: system("cls");
        printf("Insert Menu\n");
        printf("--------------------\n");
        printf("1. Insert at beginning.\n");
        printf("2. Insert at end.\n");
        printf("3. Insert at after element.\n");
        printf("\nEnter your choice: ");
        clear();
        scanf("%d", &n);
        int num;
        printf("\nEnter element to insert: ");
        clear();
        scanf("%d", &num);
        switch (n)
        {
        case 1:
            insertstart(num);
            printf("Successfully inserted. Press enter to continue.");
            clear();
            getchar();
            goto MAIN_MENU;
            break;

        case 2:
            insertend(num);
            printf("Successfully inserted. Press enter to continue.");
            clear();
            getchar();
            goto MAIN_MENU;
            break;

        case 3:
            insertindex(num);
            printf("Press enter to continue.");
            clear();
            getchar();
            goto MAIN_MENU;
            break;

        default:
            printf("Invalid selection. Press any key to continue..");
            clear();
            getchar();
            goto INSERT_MENU;
            break;
        }
        break;
    case 3:
        DELETE_MENU: system("cls");
        printf("Delete Menu\n");
        printf("--------------------\n");
        printf("1. Delete element at beginning.\n");
        printf("2. Delete element at end.\n");
        printf("3. Delete element after an index.\n");
        printf("\nEnter your choice: ");
        clear();
        scanf("%d", &n);
        switch(n){
            case 1:
                deletestart();
                printf("Press any key to continue.");
                clear();
                getchar();
                goto MAIN_MENU;
                break;

            case 2:
                deleteend();
                printf("Press any key to continue.");
                clear();
                getchar();
                goto MAIN_MENU;
                break;

            case 3:
                deleteindex();
                printf("Press any key to continue.");
                clear();
                getchar();
                goto MAIN_MENU;
                break;

            default:
                printf("Invalid selection. Press enter to continue.");
                clear();
                getchar();
                goto DELETE_MENU;
                break;
        }
        break;

    case 4:
        free(head);
        free(last);
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