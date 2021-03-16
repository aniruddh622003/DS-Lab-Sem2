#include <stdio.h>

struct complex{
    int real;
    int comp;
};

struct complex comp_sum(struct complex c1, struct complex c2){
    struct complex t;
    t.real = c1.real + c2.real;
    t.comp = c1.comp + c2.comp;
    return t;
}

int main(){
    
    struct complex c1, c2, sum;
    printf("Enter complex no. 1\n");
    printf("Real Part: ");
    scanf("%d", &c1.real);
    printf("Complex Part: ");
    scanf("%d", &c1.comp);
    printf("\n");
    printf("Enter complex no. 2\n");
    printf("Real Part: ");
    scanf("%d", &c2.real);
    printf("Complex Part: ");
    scanf("%d", &c2.comp);

    sum = comp_sum(c1, c2);
    printf("Addition of complex numbers is: %d + %di", sum.real, sum.comp);
    return 0;
}