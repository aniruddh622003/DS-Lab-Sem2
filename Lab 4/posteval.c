#include <stdio.h>
#include <stdlib.h>
int size, top = -1;

void push(int *stack, int c){
    if (top == size-1) printf("Stack full..");
    else{
        top++;
        stack[top] = c;
    }
}

int pop(int *stack){
    if (top == -1)
    {
        printf("Stack is empty.");
        return 0;
    }
    int c = stack[top];
    top--;
    return c;
}

int main(){
    printf("Note enter expression with spaces.\n");
    printf("Enter statement size: ");
    scanf("%d", &size);
    char *str, *p;
    int *stack;
    str = (char *)malloc(size*sizeof(char));    
    printf("Enter expression: ");
    while ((getchar())!='\n');
    scanf("%[^\n]s", str);
    p = str;
    stack = (int *)malloc(size*sizeof(int));
    p--;
    while (*p != '\0')
    {
        p++;
        if(*p == ' ') continue;
        else if (*p >= '0' && *p <= '9')
        {
            int n = 0;
            while (*p >= '0' && *p <= '9')
            {
                n = n*10 + (int)(*p - '0');
                p++;
            }            
            push(stack, n);
        }
        else if(*p == '+' || *p == '-' || *p == '/' || *p == '*'){
            
            int n1, n2;
            n1 = pop(stack);
            n2 = pop(stack);
            switch (*p)
            {
            case '+':
                n1 += n2;
                push(stack, n1);
                break;
            
            case '-':
                n1 = n2 - n1;
                push(stack, n1);
                break;

            case '*':
                n1 *= n2;
                push(stack, n1);
                break;

            case '/':
                n1 = (int)n2/n1;
                push(stack, n1);
                break;
            
            default:
                break;
            }            
        }
        
    }

    printf("Answer: %d", pop(stack));
    
    return 0;
}