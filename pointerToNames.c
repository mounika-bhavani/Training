//Pointer to print list of Names

#include<stdio.h>
int main()
{
	int noOfnames;

	printf("Enter number of names: ");
	scanf("%d", &noOfnames);
	
	char names[noOfnames][50];
	char (*namespointer)[noOfnames];
	namespointer = names;

	for (int counter = 0; counter < noOfnames; counter++)
	{
		printf("Enter Student Name %d: ", counter + 1);
		scanf("%s", namespointer + counter);
	}

	for(int counter = 0; counter < noOfnames; counter++)
	{
		printf("Student Name %d: %s\n", counter + 1, *(namespointer + counter));
		printf("Pointer Address: %d\n",(namespointer + counter));
	}
	return 0;

}