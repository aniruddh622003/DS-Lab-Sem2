#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
int size;

int linear(int arr[], int d){
    for (int i = 0; i < size; i++)
    {
        printf("Checking %d and %d.\n", arr[i], d);
        if (arr[i] == d)
        {
            return i+1;
        }
    }
    return -1;
}

int sort(int arr[]){
    int i, j, swap = 1;
    while (swap)
    {
        for(i = 0; i < size-1; i++){
            swap = 0;
            for(j = 0; j < (size-1)-i; j++){
                printf("Comparing %d %d\n", arr[j], arr[j+1]);
                if (arr[j] > arr[j+1])
                {
                    int t = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = t;
                    swap++;
                }
            }   
        }
    }
}

int binary(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        printf("Mid: %d\n", arr[mid]);
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binary(arr, l, mid - 1, x);
 
        // Else the element can only be present
        // in right subarray
        return binary(arr, mid + 1, r, x);
    }
 
    // We reach here when element is not
    // present in array
    return -1;
}

int main(){
    srand(time(0));
    printf("Enter array size: ");
    scanf("%d", &size);
    int arr[size], sort_arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
        sort_arr[i] = arr[i];
    }
    sort(sort_arr);
    menu: system("cls");
    printf("-------------- Array Search --------------\n");    
    printf("Array:  ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Sorted array:  ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", sort_arr[i]);
    }
    printf("\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("3. Exit\n");
    int ch, index, data;
    printf("Enter choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("Enter data to search: ");
        scanf("%d", &data);
        index = linear(arr, data);
        if(index > 0) printf("Element is present in array at position: %d", index);
        else printf("Data not found");
        printf("\nPress enter to continue");
        while((getchar()) != '\n');
        getchar();
        goto menu;
        break;

    case 2:
        printf("Enter data to search: ");
        scanf("%d", &data);
        index = binary(sort_arr, 0, size, data);
        (index == -1) ? printf("Element is not present in array")
                      : printf("Element is present in sorted array at position: %d", index+1);
        printf("\nPress enter to continue..");
        while((getchar()) != '\n');
        getchar();
        goto menu;
        break;

    case 3:
        break;

    default:
        printf("Invalid selection. Press enter to continue..");
        while((getchar()) != '\n');
        getchar();
        goto menu;
        break;
    }
    return 0;
}