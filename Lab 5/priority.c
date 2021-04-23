#include <stdio.h>
#include <stdlib.h>

struct pr{
    int n;
    int priority;
} queue[1000000];
int top = -1;

void enqueue(int n, int p){
    top++;
    queue[top].n = n;
    queue[top].priority = p;
}

int findHighest(){
    int min = INT_MAX;
    int index = -1;

    for (int i = 0; i <= top; i++)
    {        
        if (min > queue[i].priority)
        {
            min = queue[i].priority;
            index = i;
        }        
    }
    return index;    
}

void dequeue(){
    int index = findHighest();
    for (int i = index; i < top; i++)
    {
        queue[i] = queue[i+1];
    }
    top--;
}

int main(){
    int arr[6] = {1,4,15,3,17,21};
    enqueue(1, 1);
    enqueue(4, 2);
    enqueue(15, 10);
    enqueue(3, 3);
    enqueue(17, 3);
    enqueue(21, 4);
    printf("Normal Queue: ");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", *(arr+i));
    }
    printf("\n");
    printf("Priority Queue: ");
    int size = top+1;
    for (int i = 0; i < size; i++)
    {
        printf("%d ", queue[findHighest()].n);
        dequeue();
    }
    
    return 0;
}