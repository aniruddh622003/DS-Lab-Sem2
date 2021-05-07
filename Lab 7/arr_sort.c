#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

//Determines size of generated array
int size = 5;

//Print array function
//Also can wall between sorted and unsroted parts
//No wall parameter is any number out of arrays index range
void printArr(int arr[], int wall){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
        if (i == wall)
        {
            printf("| ");
        }
    }
    printf("\n");
}

void insertion_sort(int arr[], int visualise){
    for (int i = 0; i < size; i++)
    {
        int element = arr[i];
        int j = i;
        while (j>0 && arr[j-1] > element)
        {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = element;
        if(visualise) printf("Pass %d->\n", i+1);
        if(visualise || i == size-1) printArr(arr, i);
    }    
}

void selection_sort(int arr[], int visual){
    int i;
    for (i = 0; i < size-1; i++)
    {
        int min = i;
        for (int j = i+1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }            
        }
        if (min != i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
        if(visual) printf("Pass %d (Min term: %d)->\n", i+1, arr[i]);
        if(visual) printArr(arr, i);        
    }
    if(visual) printf("Pass %d (Min term: %d)->\n", i+1, arr[i]);
    printArr(arr, i);    
}

void merge(int arr[], int left, int mid, int right, int visual){
    int len1 = mid-left+1;
    int len2 = right-mid;
    int ar1[len1], ar2[len2];
    for (int i = 0; i < len1; i++)
    {
        ar1[i] = arr[left+i];
    }
    for (int i = 0; i < len2; i++)
    {
        ar2[i] = arr[mid + i + 1];
    }
    int i=0,j=0,k=left;
    while (i < len1 && j < len2)
    {
        if (ar1[i] <= ar2[j])
        {
            arr[k] = ar1[i];
            i++;
        }
        else{
            arr[k] = ar2[j];
            j++;
        }
        k++;
    }
    while (i < len1)
    {
        arr[k] = ar1[i];
        i++;
        k++;
    }
    while (j < len2)
    {
        arr[k] = ar2[j];
        j++;
        k++;
    }
    if (visual) printf("Merge( ");
    
    if (visual){
        printf("Array 1: ");
        for (int a = 0; a < i; a++)
        {
            printf("%d ", ar1[a]);
        }
        printf(" ");
        printf("Array 2: ");
        for (int a = 0; a < j; a++)
        {
            printf("%d ", ar2[a]);
        }
        printf(")->\nMerged array: ");
        for (int a = left; a < k; a++)
        {
            printf("%d ", arr[a]);
        }
    }
}

void mergeSort(int arr[], int left, int right, int visual){
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, visual);
        
        mergeSort(arr, mid + 1, right, visual);
        if(visual) printf("\n");
        merge(arr, left, mid, right, visual); 
    }    
}

int partition(int arr[], int start, int end, int visual){
    int pivot = arr[end];
    int wall = (start - 1);
    for (int i = start; i <= end-1; i++)
    {
        if (arr[i] <= pivot)
        {
            wall++;
            int temp = arr[wall];
            arr[wall] = arr[i];
            arr[i] = temp;
        }
    }
    int temp = arr[wall + 1];
    arr[wall + 1] = arr[end];
    arr[end] = temp;
    if(visual){printf("Partition: %d\n", arr[wall+1]);
    printArr(arr, (wall+1));}
    return (wall+1);
}

void Quicksort(int arr[], int start, int end, int visual){
    if(start < end){
        int part_index = partition(arr, start, end, visual);
        Quicksort(arr, start, part_index - 1, visual);
        Quicksort(arr, part_index+1, end, visual);
    }
}

int main(){
    int visual = 0;
    //Creates random equivalent arrays
    srand(time(0));
    int arr[size], insert_sort[size], select_sort[size], merge_sort[size], quick_sort[size];
    Generate: for (int i = 0; i < size; i++)
    {
        int element = (rand() % (size+10));
        arr[i] = element;
        insert_sort[i] = element;
        select_sort[i] = element;
        merge_sort[i] = element;
        quick_sort[i] = element;
    }
    printf("Random generated array: ");
    printArr(arr,-2);
    printf("Continue with the array? (y/n): ");
    char choice;
    choice = tolower(getchar());
    printf("\n");
    while((getchar()) != '\n');
    if (choice == 'n')
    {
        goto Generate;
    }
    printf("Do you want to visauliz     e algorithms? (y/n): ");
    choice = tolower(getchar());
    while((getchar()) != '\n');
    if (choice == 'y') visual = 1;
    
    printf("\nInsertion sort -->\n");
    insertion_sort(insert_sort, visual);

    printf("\nSelection sort -->\n");
    selection_sort(select_sort, visual);

    printf("\n");
    printf("Merge sort -->\n");
    mergeSort(merge_sort, 0, size-1, visual);
    if(visual) printf("\n");
    printf("Sorted Array: ");
    printArr(merge_sort, -1);

    printf("\nQuick sort -->\n");
    Quicksort(arr , 0, 4, visual);
    printf("Sorted Array: ");
    printArr(arr, -1);
    return 0;
}