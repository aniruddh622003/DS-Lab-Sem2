#include <stdio.h>
#include <string.h>

union product
{
    char name[50];
    float pricePerUnit;
    int noOfItems;
};

void main(){
    union product pro, *b;
    b = &pro;
    char pname[50];
    printf("Enter product name: ");
    scanf("%s", b->name);
    strcpy(pname, b->name);
    printf("Enter price of one unit: ");
    scanf("%f", &pro.pricePerUnit);
    float x = b->pricePerUnit;
    printf("Enter number of item purchased: ");
    scanf("%d", &pro.noOfItems);
    int y = b->noOfItems;
    printf("\nTotal amount to be paid: %.2f\n\n", x*y);
    printf("Name of product: %s\n", pname);
    printf("Price per unit: Rs. %.2f\n", x);
    printf("Number of items purchased: %d", y);
}