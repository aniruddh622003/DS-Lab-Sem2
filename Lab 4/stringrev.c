#include <stdio.h>
#include <stdlib.h>
int size, top = -1;


void clear_buff(){
    while ((getchar()) != '\n');
}

void push(char *stack, char a){
    if (top == size-1) printf("Stack full..");
    else{
        top++;
        stack[top] = a;
    }    
}

void display(char *stack){
    if (top == -1)
    {
        printf("Stack empty.");
        return;
    }
    for (int i = top; i >= 0; i--)
    {
        printf("%c", stack[i]);
    }
    
}

char pop(char *stack){
    if (top == -1)
    {
        printf("Stack is empty.");
        return 0;
    }
    char c = stack[top];
    top--;
    return c;
}

int main(){
    printf("Enter size of string: ");
    int n;
    scanf("%d", &n);
    char *str = (char *)malloc(n*sizeof(n));
    printf("Enter string: ");
    clear_buff();
    scanf("%[^\n]%*c", str);
    printf("String entered: %s\n", str);

    size = n;
    char stack[n+1];
    for (int i = 0; i < n; i++)
    {
        push(stack,*(str + i));
    }
    for (int i = 0; i < n; i++)
    {
        *(str + i) = pop(stack);
    }
    printf("Reversed string: %s", str);
    return 0;
}