#include <stdio.h>
#include <stdlib.h>

struct node{
    int coef;
    int power;
    struct node *next;
} *first = NULL, *second = NULL, *res = NULL, *ptr = NULL;

void create_node(int po, int co, struct node **head){
    //Temporary node
    struct node *add = NULL;
    add = (struct node *)malloc(sizeof(struct node));
    //Check for memory allocation
    if (add == NULL)
    {
        printf("Out of memory");
        return;
    }
    add->coef = co;
    add->power = po;
    add->next = NULL;
    //Check if list is empty or not
    if (*head == NULL)
    {
        *head = add;
    }
    //Add node to the end of list
    else{
        for (ptr = *head; ptr->next != NULL; ptr = ptr->next);
        ptr->next = add;        
    }
}

void addpoly(struct node *p1, struct node *p2, struct node *r){
 
    //Start from head pointers of both polynomials and compare their powers.
    //Move to next node if powers do not match
    while (p1 != NULL && p2 != NULL)
    {
        //Check is power is mismatched.
        //Enter into resultant directly the highest power
        if (p1->power > p2->power)
        {
            r->power = p1->power;
            r->coef = p1->coef;
            p1 = p1->next;
        }
        else if(p1->power < p2->power){
            r->power = p2->power;
            r->coef = p2->coef;
            p2 = p2->next;
        }
        //Sum the coefficients is the powers are equal
        else{
            r->power = p1->power;
            r->coef = (p1->coef) + (p2->coef);
            p1 = p1->next;
            p2 = p2->next;
        }

        if (p1 != NULL && p2 != NULL)
        {
            //Insert a node for resultant polynomial
            r->next = (struct node *)malloc(sizeof(struct node));
            r = r->next;
            r->next = NULL;
        }                    
    }
    //Entering the remaining terms to polynomial as it is.
    //Not required due to our driver code automation, still added for stability
    while (p1 != NULL || p2 != NULL)
    {
        r->next = (struct node *)malloc(sizeof(struct node));
        r = r->next;
        r->next = NULL;
        if (p1 != NULL)
        {
            r->power = p1->power;
            r->coef = p1->coef;
            p1 = p1->next;
        }
        if (p2 != NULL)
        {
            r->power = p2->power;
            r->coef = p2->coef;
            p2 = p2->next;
        }
        
    }
}

void printPoly(struct node *head){
    //Traverse through given list
    while (head != NULL)
    {
        //Print term only if coefficient in non-zero
        if (head->coef != 0)
        {
            printf("%dx^%d ",head->coef, head->power);
            //Print '+' if a next term is present
            if (head->next != NULL)
            {
                printf("+ ");
            }
        }
                
        head = head->next;
    }
}

int main(){
    int n, po1, co1;
    printf("Enter degree of polynomial 1: ");
    scanf("%d", &n);
    n++;
    // Creation of polynomial 1
    while (n--)
    {
        printf("Enter coefficient of x^%d: ", n);
        scanf("%d", &co1);
        create_node(n, co1, &first);
    }
    printf("\nPolynomial 1 ->\n");
    printPoly(first);
    printf("\n\nEnter degree of polynomial 2: ");
    scanf("%d", &n);
    n++;
    //Creation of polynomial 2
    while (n--)
    {
        printf("Enter coefficient of x^%d: ", n);
        scanf("%d", &co1);
        create_node(n, co1, &second);
    }
    printf("\nPolynomial 2 ->\n");
    printPoly(second);
    
    //Intitalise resultant polynomial
    res = (struct node *)malloc(sizeof(struct node));
    printf("\n");
    addpoly(first, second, res);
    printf("\nAddition of polynomials->\n");
    printPoly(res);
    return 0;
}