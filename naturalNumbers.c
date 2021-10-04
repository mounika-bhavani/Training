//To print 1 to given number through command Line with one variable.

#include <stdio.h>
#include<stdlib.h>
int naturalNumbers();
int read();

int number;
int main(int argc, char *argv[])
{
	(argc > 1 && atoi(argv[1]) != 0) ? number = atoi(argv[1]) : read();

	printf("Natural Numbers from 1 to %d are: \n", number);
	naturalNumbers(number);
	return 0;
}
 
//Function to print 1 to given number of Natural numbers.

int naturalNumbers(int number)
{
	if(number == 0)
	{
		return 0;
	}
	naturalNumbers(number-1);
	printf("%d\n", number);
}

//Function to read a Number.

int read()
{
	printf("Enter a number upto which numbers has to be printed: ");
	scanf("%d", &number);
}