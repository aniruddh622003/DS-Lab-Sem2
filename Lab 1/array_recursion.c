#include <stdio.h>
#include <stdlib.h>

//Function returns the recived value + current array element
int findsum(int arr[], int n){

    //If array is empty return 0
    if(n <= 0){
        return 0;
    }

    //Recursive call
    return (findsum(arr, n-1) + arr[n-1]);
}

int main(){
    printf("Enter number of elements: ");

    //Get size of array and create an array with the entered size
    int n;
    scanf("%d", &n);
    int *arr = (int*)malloc(n*sizeof(int));
    printf("Enter elements:\n");

    //Get elements
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    int sum = findsum(arr, n);
    printf("Sum of all elements: %d", sum);
    return 0;
}