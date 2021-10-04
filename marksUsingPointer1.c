//Printing marks using pointer.

#include<stdio.h>
void main()
{
	int counter, noOfMarks;
	
	printf("Enter number of marks: ");
	scanf("%d", &noOfMarks);

	int marks[noOfMarks];
	int * ptrMarks = marks;

	for(counter = 0; counter < noOfMarks; counter++)
	{
		printf("Enter subject %d Marks: ", counter + 1);
		scanf("%d", ptrMarks + counter);
		//ptrMarks++;
	}
	ptrMarks = marks;

	for(counter = 0; counter < noOfMarks; counter++)
	{
		printf("Subject %d Marks are: %d\n", counter + 1, *(ptrMarks + counter));
		

	}




}