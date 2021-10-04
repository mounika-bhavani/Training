//Pointer to print list of Names using malloc.

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int countOfnames;

	printf("Enter number of names: ");
	scanf("%d", &countOfnames);
	
	//char names[countOfnames][50];
	//char (*namesPointer)[countOfnames];

	//printf("Pointer Address: %d\n", namesPointer);
	
	char **namesPointer = malloc(countOfnames * sizeof(char *));

	if(namesPointer == NULL)
    {
        printf("\nError! Memory not allocated\n");
    }

	for (int counter = 0; counter < countOfnames; counter++)
	{
		printf("Enter Student Name %d: ", counter + 1);
		scanf("%s", namesPointer[counter]);
	}

	for(int counter = 0; counter < countOfnames; counter++)
	{
		printf("Student Name %d: %s\n", counter + 1, namesPointer[counter]);
		//printf("Pointer Address: %d\n",(namesPointer + counter));
	}
	return 0;

}