//Printing list of marks using malloc

#include<stdio.h>
#include<stdlib.h>
void main()
{
	int counter, noOfMarks;
	int *ptrMarks;

	printf("Pointer Address: %d\n",ptrMarks);
	printf("Enter number of marks: ");
	scanf("%d", &noOfMarks);
	
	ptrMarks = (int *)malloc(sizeof(int) * noOfMarks);

	if(ptrMarks == NULL)
    {
        printf("\nError! Memory not allocated\n");
    }

	for(counter = 0; counter < noOfMarks; counter++)
	{
		printf("Enter Subject %d marks: ", counter + 1);
		scanf("%d", ptrMarks + counter);
	}
	for(counter = 0; counter < noOfMarks; counter++)
	{
		printf("Subject %d Marks are: %d\n", counter + 1, ptrMarks[counter]);
		printf("Pointer Address: %d\n", (ptrMarks + counter));

	}

}