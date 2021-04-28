#include <stdio.h>
#include <ctype.h>

int hash(int key){
    int h, sum;
    h = key % 1000;
    LP: sum = 0;
    while (h > 0)
    {
        int dig = h % 10;
        sum += dig;
        h = h/10;
    }

    if (sum > 9)
    {
        h = sum;
        goto LP;
    }
        
    return sum;
}

int main(){
    int h, k;
    h = 5000423;
    k = hash(h);
    printf("Key value: %d; Index: %d\n", h, k);
    h = 5000425;
    k = hash(h);
    printf("Key value: %d; Index: %d\n", h, k);
    int cond = 1;
    while(cond){
        printf("Do you want to enter SAP-ID: ");
        char ch;
        scanf("%c", &ch);
        switch (tolower(ch))
        {
        case 'y':
            printf("Enter SAP-ID: ");
            int sap;
            scanf("%d", &sap);
            printf("Key value: %d; Index: %d\n", sap, hash(sap));
            break;
        
        case 'n':
            cond = 0;
            break;
        
        default:
            break;
        }
        while((getchar()) != '\n');
    }
    return 0;
}