//Observing a character array before and after scanf using pointer.

#include<stdio.h>
#include<stdlib.h>
int main()
{
	char *ptrName, name;
	int counter;
	ptrName = malloc(20);
	for(counter = 0; counter < 20; counter++)
	{
		printf("%c \t %d\n", ptrName[counter], ptrName[counter]);
	}
	printf("Enter the name: ");
	scanf("%s", ptrName);
	for(counter = 0; counter < 20; counter++)
	{
		printf("%c \t %d\n", ptrName[counter], ptrName[counter]);
	}
}
ll