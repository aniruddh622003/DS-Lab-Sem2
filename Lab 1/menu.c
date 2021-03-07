#include<stdio.h>
#include <ctype.h>
#include<stdlib.h>

void clear (void) //Clears the buffer memory
{    
  while ( getchar() != '\n' );
}

int input;
int arrayA[10], arrayB[10], arrayC[20];
int countA=0, countB=0, countC=0;


void MainMenu();
void Delete(int*, int*, char);
void Copy(int*, int, int*, int*);
void Merge(int*, int, int*, int, int*, int*);
void Display(int*, int, char);
void Insert(int*, int*, char);

void Merge(int* sArray1, int sArray1Size, int* sArray2, int sArray2Size, int* dArray, int* dArraySize)
{
	system("cls");
	if(sArray1Size+sArray2Size<=0) //Checking if both array are empty or not
	{
		printf("\nBoth arrays are empty.\nPress any key to continue...");
		clear(); getchar();
		return;
	}
	int i;
	for(i=0; i<sArray1Size; i++) //Copying the contents of 1st array to 3rd array
	{
		dArray[i]=sArray1[i];
	}
	for(i=sArray1Size; i<sArray1Size+sArray2Size; i++) //Copying the contents of 2nd array to 3rd array
	{
		dArray[i]=sArray2[i-sArray1Size];
	}
	(*dArraySize)=sArray1Size+sArray2Size;
	return;
}

void Copy(int* sArray, int sArraySize, int* dArray, int* dArraySize)
{
	system("cls");
	if((*dArraySize)+sArraySize>10) //Checking for Overflow
	{
		printf("\nCannot copy! Err: Data Overflow! Press any key to continue...");
		clear(); getchar();
		return;
	}
	if(sArraySize<=0) //Checking if the source array is empty
	{
		printf("\nSource array is empty! Press any key to continue...");
		clear(); getchar();
		return;
	}
	if((*dArraySize)<=0) //If destination array is empty, copy directly
	{
		for(int i=0; i<sArraySize; i++)
		{
			dArray[i]=sArray[i];
		}
		return;
	}
	else //Otherwise ask user for following
	{
		Copy_Menu_F:
		printf("\nThere are some elements in the destination array.");
		printf("\n1) Overwrite.");
		printf("\n2) Insert to left");
		printf("\n3) Insert to right");
		printf("Input: ");
		clear();
        scanf("%d", &input);
		switch (input)
		{
			case 1:
				for(int i=0; i<sArraySize; i++) //Overwriting
				{
					dArray[i]=sArray[i];
				}
				if(sArraySize>(*dArraySize)) //Checking if there is some old data left after overwriting
				{
					(*dArraySize)=sArraySize;
				}
				return;
				break;
			case 2:
				for(int i=0; i<(*dArraySize); i++) //Shifting old data towards right
				{
					dArray[sArraySize+i]=dArray[i];
				}
				for(int i=0; i<sArraySize; i++) //Copying from source array
				{
					dArray[i]=sArray[i];
				}
				(*dArraySize)=(*dArraySize)+sArraySize; //Adjusting size parameter
				return;
				break;
			case 3:
				for(int i=0; i<sArraySize; i++) //Copying from source array
				{
					dArray[(*dArraySize)+i]=sArray[i];
				}
				(*dArraySize)=(*dArraySize)+sArraySize; //Adjusting size parameter
				return;
				break;
			default:
				printf("Wrong Input! Press any key to try again..."); //Checking for invalid input
				clear(); getchar();
				system("cls");
				goto Copy_Menu_F;
		}
	}
}

void Delete(int* array, int* arraySize, char name)
{
	int pos;
	Delete_Menu_F:
	system("cls");
	if(*arraySize<=0) //Checking for underflow
	{
		printf("Data Underflow!\nPress any key to continue...");
		clear(); getchar();
		return;
	}
	Display(array, *arraySize, name);
	printf("\nEnter the position you want to delete(1-10): ");
	scanf("%d", &pos);
	if(pos>10 || pos<1) //Checking if position is valid or not (in range of 1-10 including both)
	{
		printf("\nWrong Input!\nPress any key to try again...");
		clear(); getchar();
		goto Delete_Menu_F;
	}
	if(pos>*arraySize) //Checking if there exists any element at the position
	{
		printf("\nNo element at position %d.\nPress any key to continue...", pos);
		clear(); getchar();
		return;		
	}
	pos -= 1;
	for(int i=pos; i<*arraySize; i++) //Shifting data to overwrite the required element
	{
		array[i]=array[i+1];
	}
	(*arraySize) -= 1; //Adjusting size parameter
	system("cls");
}

void Insert(int* array, int* arraySize, char name)
{
	int position, value, i;
	printf("Current occupancy of array is: %d", countA);
	if(*arraySize>=10) //Checking for overflow
	{
		printf("\nData overflow! Cannot store more data in Array A.\nPress any key to continue...");
		clear(); getchar();
		system("cls");
		MainMenu();
	}
	Insert_Menu_F:
	printf("\nEnter the position where you want to insert the element(1-10): ");
	scanf("%d", &position);
	if(position>10 || position<1) //Checking if position is valid or not (in range of 1-10 including both)
	{
		printf("\nInvalid position entered! Press any key to try again...");
		clear(); getchar();
		system("cls");
		goto Insert_Menu_F;
	}
	position -= 1;
	printf("Enter the element to store: ");
	scanf("%d", &value);
	if(position<=*arraySize) //If user wants to add in between existing data
	{
		for(i=(*arraySize); i>position; i--) //Shifting elements
		{
			array[i]=array[i-1];
		}
		array[position]=value;
	}
	else //If user wants to add at the end or beyond existing data
	{
		position=(*arraySize);
		array[position]=value;
	}
	++(*arraySize);
	system("cls");
}

void Display(int* array, int arraySize, char name)
{
	system("cls");
	int i;
	printf("\nNumber of elements in array %c: %d", name, arraySize);
	printf("\nArray:");
	for(i=0; i<arraySize; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n\nPress any key to continue...");
	clear(); getchar();
}

void MainMenu()
{
	system("cls");
	printf("       Main Menu\n-----------------------");
	printf("\n1) Display array");
	printf("\n2) Insert an element");
	printf("\n3) Delete an element");
	printf("\n4) Copy an array");
	printf("\n5) Merge arrays");
	printf("\n6) Exit");
	printf("\n\n( Arrays available: 3 )");
	printf("\n\nInput: ");
	scanf("%d", &input);
	switch (input)
	{
		case 1:
			system("cls");
			Display_Menu: //Sub menu for display
			printf("     Display menu\n-----------------------\n   Select an array.\n-----------------------");
			printf("\n1) Array 1");
			printf("\n2) Array 2");
			printf("\n3) Array 3");
			printf("\n4) Go back.");
			printf("\n\nInput: ");
			clear();
            scanf("%d", &input);
			switch (input)
			{
				case 1:
					system("cls");
					Display(arrayA, countA, 'A');
					MainMenu();
					break;
				case 2:
					system("cls");
					Display(arrayB, countB, 'B');
					MainMenu();
					break;
				case 3:
					system("cls");
					Display(arrayC, countC, 'C');
					MainMenu();
					break;
				case 4:
					system("cls");
					MainMenu();
					break;
				default:
					system("cls");
					printf("Wrong Input!\n\n");
					goto Display_Menu;
			}
			break;
        case 2:
			Insert_Menu: //Sub menu for insert
			system("cls"); 
			printf("    Insert Menu\n-----------------------\n  Select an array.\n-----------------------");
			printf("\n1) Array 1");
			printf("\n2) Array 2");
			printf("\n3) Array 3");
			printf("\n4) Go back.");
			printf("\n\nInput: ");
			clear();
            scanf("%d", &input);
			switch (input)
			{
				case 1:
					system("cls");
					Insert(arrayA, &countA, 'A');
					Display(arrayA, countA, 'A');
					MainMenu();
					break;
				case 2:
					system("cls");
					Insert(arrayB, &countB, 'B');
					Display(arrayB, countB, 'B');
					MainMenu();
					break;
				case 3:
					system("cls");
					Insert(arrayC, &countC, 'C');
					Display(arrayC, countC, 'C');
					MainMenu();
					break;
				case 4:
					MainMenu();
					break;
				default:
					printf(" Wrong Input! Press any key to try again...");
					clear(); getchar();
					goto Insert_Menu;
			}
			break;
			case 3:
				Delete_Menu:
				system("cls"); //Sub menu for delete
				printf("     Delete Menu\n-----------------------\n  Select an arrray.\n-----------------------");
				printf("\n1) Array 1");
				printf("\n2) Array 2");
				printf("\n3) Array 3");
				printf("\n4) Go back.");
				printf("\n\nInput: ");
				clear(); 
                scanf("%d", &input);
				switch (input)
				{
					case 1:
						system("cls");
						Delete(arrayA, &countA, 'A');
						Display(arrayA, countA, 'A');
						MainMenu();
						break;
					case 2:
						system("cls");
						Delete(arrayB, &countB, 'B');
						Display(arrayB, countB, 'B');
						MainMenu();
						break;
					case 3:
						system("cls");
						Delete(arrayC, &countC, 'C');
						Display(arrayC, countC, 'C');
						MainMenu();
						break;
					case 4:
						MainMenu();
						break;
					default:
						printf(" Wrong Input! Press any key to try again...");
						clear(); getchar();
						goto Delete_Menu;
			}
			break;
			case 4:
				Copy_Menu:
				system("cls"); //Sub menu for Copy
				printf("      Copy Menu\n-----------------------\n  Select an option.\n-----------------------");
				printf("\n1) Copy Array 1 to Array 2");
				printf("\n2) Copy Array 2 to Array 1");
				printf("\n3) Go back.");
				printf("\n\nInput: ");
				clear();
                scanf("%d", &input);
				switch(input)
				{
					case 1:
						system("cls");
						Copy(arrayA, countA, arrayB, &countB);
						Display(arrayB, countB, 'B');
						MainMenu();
						break;
					case 2:
						system("cls");
						Copy(arrayB, countB, arrayA, &countA);
						Display(arrayA, countA, 'A');
						MainMenu();
						break;
					case 3:
						MainMenu();
						break;
					default:
						printf(" Wrong Input! Press any key to try again...");
						clear(); getchar();
						goto Copy_Menu;
				}
				break;
			case 5:
				Merge_Menu:
				system("cls"); //Sub menu for merge
				printf("     Merge Menu\n-----------------------\n  Select an option.\n-----------------------");
				printf("\n1) Merge Array 1 and Array 2 to Array 3");
				printf("\n2) Go back.");
				printf("\n\nInput: ");
				clear(); 
                scanf("%d", &input);
				switch (input)
				{
					case 1:
						system("cls");
						Merge(arrayA, countA, arrayB, countB, arrayC, &countC);
						Display(arrayC, countC, 'C');
						MainMenu();
						break;
					case 2:
						MainMenu();
						break;
					default:
						printf("Wrong Input! Press any key to try again...");
						clear(); getchar();
						system("cls");
						goto Merge_Menu;
				}
			case 6:
				exit(0);
			default:
				printf(" Wrong Input! Press any key to try again...");
				clear(); getchar();
				MainMenu();
	}
}

int main()
{
	MainMenu();
}
