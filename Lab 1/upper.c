#include <stdio.h>

void main(){
    char s[100];
    printf("Enter string: ");

    //Get user input
    scanf("%[^\n]%*c", s);
    for (int i = 0; s[i]; i++)
    {
        //Chack if letter in check is uppercase
        if (s[i] >= 65 && s[i] <= 90)
        {
            //If uppercase, increase ASCII value by 32
            s[i] += 32;
        }
    }

    //Print
    printf("Lowercase string: %s", s);
    
}