#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Queue{
    char c;
    struct Queue *next;
} *head=NULL, *ptr=NULL;

//Insert Beginning
void enqueue(char x){
    struct Queue *temp = NULL;
    temp = (struct Queue *)malloc(sizeof(struct Queue));
    if (temp == NULL)
    {
        printf("Memory full.");
        return;
    }
    temp->c = x;
    if(head == NULL){
        temp->next = NULL;
        head = temp;
        return;
    }
    temp->next = head;
    head = temp;
}

char findFirst(){
    for(ptr = head; ptr->next != NULL; ptr = ptr->next);
    return ptr->c;
}

//Delete End
void dequeue(){
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        head = NULL;
        return;
    }        
    for(ptr = head; ptr->next->next != NULL; ptr = ptr->next);
    struct Queue *temp = ptr->next;
    ptr->next = NULL;
    free(temp);
}

int main(){
    printf("Enter string size: ");
    int n;
    scanf("%d", &n);
    while((getchar())!='\n');
    printf("Enter input string: ");
    for (int i = 0; i < n; i++)
    {
        char t;\
        scanf("%c", &t);
        enqueue(t);
    }
    char str1[n], str2[n];

    for (int i = 0; i < n; i++)
    {
        str1[i] = findFirst();
        *(str2 + n - i - 1) = findFirst();
        dequeue();
    }
    if(!(strcmp(str1, str2))){
        printf("Given word is a Pallindrome.");
    }
    else{
        printf("Given word is not a Pallindrome.");
    }
}