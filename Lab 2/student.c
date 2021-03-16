#include <stdio.h>
#include <stdlib.h>

struct date
{
    int dd;
    int mm;
    int yy;
};
struct student_record
{
    char fname[20];
    char lname[20];
    int sap;
    int enroll;
    struct date dbirth;
    struct date dregister;
    int marks[5];
};


int main(){
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    struct student_record *ptr, *curr;

    //Memory allocation
    ptr = (struct student_record *)malloc(n*sizeof(struct student_record));

    //Getting input
    for (int i = 0; i < n; i++)
    {
        printf("Enter Student %d data ->\n", i+1);
        curr = (ptr+i);
        //Name
        printf("Enter first name: ");
        scanf("%s", curr->fname);
        printf("Enter last name: ");
        scanf("%s", curr->lname);
        //SAP
        printf("Enter SAP-ID: ");
        scanf("%d", &curr->sap);
        //Enrollment
        printf("Enter enrollment number: R");
        scanf("%d", &curr->enroll);
        //Marks of 5 subjects
        printf("Enter 5 marks: ");
        scanf("%d %d %d %d %d", &curr->marks[0], &curr->marks[1], &curr->marks[2], &curr->marks[3], &curr->marks[4]);
        //Dates
        printf("\nNote: Enter date in DD MM YYYY format\n");
        printf("Enter date of birth: ");
        scanf("%d %d %d", &curr->dbirth.dd, &curr->dbirth.mm, &curr->dbirth.yy);
        printf("Enter date of registration: ");
        scanf("%d %d %d", &curr->dregister.dd, &curr->dregister.mm, &curr->dregister.yy);     
    }
    printf("\n\n");
    //Printing Report cards
    for (int i = 0; i < n; i++)
    {
        curr = ptr + i;
        printf("|\t\tReport Card\t\t\t |\n");
        printf("| Name: %s %s| SAP-ID: %d\t |\n", curr->fname, curr->lname, curr->sap);
        printf("| Enrollment No: R%d\t\t\t |\n", curr->enroll);
        printf("| Date of Birth: %d-%d-%d\t\t\t |\n", curr->dbirth.dd, curr->dbirth.mm, curr->dbirth.yy);
        printf("| Date of Registration: %d-%d-%d\t\t |\n", curr->dregister.dd, curr->dregister.mm, curr->dregister.yy);
        printf("|\t-\t-\t-\t-\t |\n");
        printf("|Subject 1\t\t\t|\t\t%d|\n", curr->marks[0]);
        printf("|Subject 2\t\t\t|\t\t%d|\n", curr->marks[1]);
        printf("|Subject 3\t\t\t|\t\t%d|\n", curr->marks[2]);
        printf("|Subject 4\t\t\t|\t\t%d|\n", curr->marks[3]);
        printf("|Subject 5\t\t\t|\t\t%d|\n", curr->marks[4]);
        printf("|\t-\t-\t-\t-\t |\n");
        printf("\n\n");
    }
    return 0; 
}