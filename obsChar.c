//Observing character array 

#include<stdio.h>
#include<string.h>
void printChars(char *);

void main()
{
	char name[20];
	
	printf("\nEnter a name: ");
	scanf("%s", &name);
	printChars(name);
}

//Function to Print Chars

void printChars(char *string)
{

	for(int counter = 0; counter < strlen(string); counter++)
	{
		printf("%c \t %d\n", string[counter], string[counter]);
	}
} 
