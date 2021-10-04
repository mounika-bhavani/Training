//Pointer to print list of Names using malloc.

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int countOfNames;

	printf("Enter count of names: ");
	scanf("%d", &countOfNames);
	
	char **namesPointer = malloc(countOfNames * sizeof(char *));

	if(namesPointer == NULL)
    {
        printf("\nError! Memory not allocated\n");
    }

	for (int counter = 0; counter < countOfNames; counter++)
	{
		namesPointer[counter] = malloc(20);
		printf("Enter Student Name %d: ", counter + 1);
		scanf("%s", namesPointer[counter]);
	}

	for(int counter = 0; counter < countOfNames; counter++)
	{
		printf("Student Name %d: %s\n", counter + 1, namesPointer[counter]);
	}
	return 0;

}