//To print 1 to given number through command Line with one variable.

#include <stdio.h>
#include<stdlib.h>
int naturalNumbers();

int main()
{
	int number;
	printf("Enter a number upto which numbers has to be printed: ");
	scanf("%d", &number);
	printf("Natural Numbers from 1 to %d are: ", number);
	printNaturalNumbers(number);  5
	return 0;
}

//Function to print 1 to given number of Natural numbers.

int printNaturalNumbers(int number)
{
	if(number == 0)
	{
		return 0;
	}
	printNaturalNumbers(number-1);
	printf("%d\n", number);
}
