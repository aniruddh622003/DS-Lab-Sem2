#include <stdio.h>
#include <math.h>

struct eqn {
    float a, b, c, r1, r2;
};

void eq_make(struct eqn *p){
    p->a = 1;
    p->b = -(p->r1 + p->r2);
    p->c = (p->r1)*(p->r2);
}

void solve(struct eqn *p){
    int d = (p->b)*(p->b) - 4 * (p->a) * (p->c);
    if(d>0){
        p->r1 = (-(p->b) + sqrt(d))/2*(p->a);
        p->r2 = (-(p->b) - sqrt(d))/2*(p->a);
    }
}

int main(){
    struct eqn first, second, third, SOP, *ptr;
    int sum;
    ptr = &third;

    //Input user-defined equation
    printf("Enter a quadratic equation ->\n");
    printf("Coefficient of x^2: ");
    scanf("%f", &ptr->a);
    printf("Coefficient of x: ");
    scanf("%f", &ptr->b);
    printf("Constant: ");
    scanf("%f", &ptr->c);

    //Solve user defined equation and get two wanted roots.
    solve(&third);
    printf("Roots are: %.2f, %.2f\n", third.r1, third.r2);

    //Let r2 = r5 and r4 = r6
    first.r2 = third.r1;
    second.r2 = third.r2;

    //Getting required sum
    printf("Enter sum of product of all roots taken two at a time: ");
    scanf("%d", &sum);

    //By derivation of SOP formula we have r1^2 + 2r1(r2+r4) + (r2*r4) = sum
    SOP.a = 1;
    SOP.b = 2*((first.r2)+(second.r2));
    SOP.c = (first.r2)*(second.r2) - sum;
    solve(&SOP);
    printf("Equation formed: %.2fx^2 + %.2fx + %.2f = 0\n", SOP.a, SOP.b, SOP.c);
    float common = (SOP.r1 > SOP.r2) ? SOP.r1 : SOP.r2;
    printf("Chosen common root is %f\n\n", common);  
    first.r1 = common;
    second.r1 = common;
    eq_make(&first);
    eq_make(&second);
    printf("Equation 1: %.2fx^2 + %.2fx + %.2f = 0\n", first.a, first.b, first.c);
    printf("Equation 2: %.2fx^2 + %.2fx + %.2f = 0\n", second.a, second.b, second.c);  
    printf("Sum of all four roots is %.2f", first.r1 + first.r2 + second.r1 + second.r2);
}