#include<stdio.h>
#include <stdlib.h>

//Defining 3x3 matrix
#define ROW 3
#define COL 3

//Get matrix data 
void matrixInput(int *mat, int n , int m)
{
    int row, col;

    for (row = 0; row < n; row++)
    {
        for (col = 0; col < m; col++)
        {
            scanf("%d", (mat + row*m + col));
        }
    }
}

//Function to multiply Matrices mat1 * mat2 = res
void matrixMultiply(int *mat1, int *mat2, int *res, int n1, int n2, int m1, int m2)
{
    int row, col, i;
    int sum;

    for (row = 0; row < n1; row++)
    {
        for (col = 0; col < m2; col++)
        {
            sum = 0;
            for (int e = 0; e < m1; e++)
            {
                sum += (*(mat1 + row*m1 + e))*(*(mat2 + col + e*(n2)));
            }
            *(res + row*m2 + col) = sum;
        }
        
    }
}

int main()
{
    system("cls"); 
    L1: printf("Enter dimentsions of matrix 1: ");
    int n1, m1;
    scanf("%d %d", &n1, &m1);
    printf("Enter dimentsions of matrix 2: ");
    int n2, m2;
    scanf("%d %d", &n2, &m2);
    //check if multiplication is possible, 1st matrix rows must be equal to 
     //Second matrix columns
    if (m1 != n2)
    {
        system("cls");
        printf("Matrices can not be multiplied.\nTry again..\n");
        goto L1;
    }
    int *mat1 = (int *)malloc(n1*m1*sizeof(int));
    int *mat2 = (int *)malloc(n2*m2*sizeof(int));
    int *res = (int *)malloc(n1*m2*sizeof(int));
    
    printf("Enter First matrix\n");
    matrixInput(mat1, n1, m1);
    printf("Enter Second matrix\n");
    matrixInput(mat2, n2, m2);
    
    matrixMultiply(mat1, mat2, res, n1, n2, m1, m2);
    //print the resultant matrices
    printf("Resultant Matrix\n");
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            printf("%d\t", *(res + i*m2 + j));
        }
        printf("\n");
    }
    
     
     
    // if(n1==m2)
    // {
        
       
    //     printf("\nEnter Second matrix\n");
    //     matrixInput(Second);

         
    //     matrixMultiply(First,Second,Result);

    //     printf("Product of entered matrices :-\n");

    //     //print the resultant matrices
    //     for(int i=0;i<m1;i++)
    //     {
    //         for(int j=0;j<n2;j++)
    //             printf("%d\t",*(*(Result + i) + j));
    //         printf("\n");
    //     }


    // }
    // else
    // {
    //    printf("Sorry ! Multiplication is not possible");
    // }
    // return 0;
}