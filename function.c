//Calling a function from main function to find sum of marks.

#include<stdio.h>

int main()
{
	int count;
	printf("Enter count of marks: ");
	scanf("%d", &count);
	int marks[count], counter, sum;
	printf("Enter %d Numbers: \n", count);
	for (int counter = 0; counter < count; counter)
	{
		printf("Enter Number %d: ", counter + 1);
		scanf("%d", &marks[counter]);
	}
	sum = sumOf(marks, count);
	printf("Sum is %d", sum);

	return 0;
}
int sumOf(int marks[], int count)
{
	int sum = 0;
	for(int counter = 0; counter < count; counter++)
	{
		sum += marks[counter];
	}
	return sum;
}