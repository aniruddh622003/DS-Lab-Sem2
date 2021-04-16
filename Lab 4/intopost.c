#include <stdio.h>
#include <stdlib.h>

struct node{
    char c;
    struct node *next;
} *head=NULL, *ptr=NULL;

//Insert Beginning
void push(char c){
    if (c == '\n')
    {
        return;
    }
    
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory full. Not allocated.");
    }
    temp->c = c;
    
    temp->next = head;
    head = temp;
}

// Delete beginning
char pop(){
    if (head == NULL)
    {
        return ' ';
    }
    if (head->next == NULL)
    {
        char c = head->c;
        free(head);
        head = NULL;
        return c;
    }
    ptr = head->next;
    char c = head->c;
    free(head);
    head = ptr;
    return c;
}

//Priority function
int priority(char c){
    if (c == '(') return 0;
    else if (c == '+' || c == '-') return 1;
    else if (c == '*' || c == '/') return 2;
    return 0;
}

int main(){
    //Static defined variables for input
    char infix[100], *p;
    printf("Enter expression: ");
    scanf("%[^\n]s", infix);
    p = infix;

    //Travering through elements in input string
    while(*p != '\0'){

        //Print directly if number encountered
        if (*p >= '0' && *p <= '9')
        {
            printf("%c", *p);
        }

        //Push ( to stack
        else if(*p == '('){
            push(*p);
        }

        //Pop from stack till ( is encountered
        else if(*p == ')'){
            char x;
            while ((x = pop()) != '(')
            {
                printf("%c", x);
            }            
        }

        //Modify stack according to priority rule
        else{
            char stack_top;
            if (head == NULL);
            else{
                stack_top = head->c;
                while (priority(stack_top)>=priority(*p)){
                    printf("%c", pop());
                    if (head == NULL)
                    {
                        break;
                    }                                       
                    stack_top = head->c;
                }
            }
            push(*p);
        }

        //Move to next character
        p++;
    }

    //Empty the stack
    while (head != NULL)
    {
        printf("%c",pop());
    }
    
    return 0;
}