#include<stdio.h>
#include<stdlib.h>

void main()
{
	int countOfSubjects, countOfStudents, nameCounter, marksCounter;

	printf("Enter the number Students: ");
	scanf("%d", &countOfStudents);

	printf("Enter number of Subjects: ");
	scanf("%d", &countOfSubjects);

	int **ptrMarks = malloc(countOfSubjects * sizeof(int*));
	char **ptrNames = malloc(countOfStudents * sizeof(char*));

	for(nameCounter = 0; nameCounter < countOfStudents; nameCounter++)
	{
		ptrNames[nameCounter] = malloc(30);
		printf("Enter name of Student %d: ", nameCounter + 1);
		scanf("%s", ptrNames[nameCounter]);
		ptrMarks[nameCounter] = malloc(countOfSubjects * sizeof(int));
		for(marksCounter = 0; marksCounter < countOfSubjects; marksCounter++)
		{
			printf("Enter Marks of subject %d: ", marksCounter + 1);
			scanf("%d", &ptrMarks[marksCounter]); 
		}
	}

	printf("\nStudents Name and Marks are: \n");
	for(nameCounter = 0; nameCounter < countOfStudents; nameCounter++)
	{
		printf("Marks of %s: \n", ptrNames[nameCounter]);
		for (marksCounter = 0; marksCounter < countOfSubjects; marksCounter++)

		{
			/* code */
			printf("Marks of the Subject are %d: ", marksCounter + 1);
			printf("%d\n", ptrMarks[marksCounter]);
		}
	}
}