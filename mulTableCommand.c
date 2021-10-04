//Printing Multiplication table using command line argument and also through normally.

#include <stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	int number;

	if(argc <= 1)
	{
		//If we dont give number through command line ask to enter number.

		printf("Enter a number to print multiplication Table: \n");
		scanf("%d", &number);
	}
	else
	{
		//convert String to int

		number = atoi(argv[1]);
	}

	printf("Multiplication Table of %d is: ", number);

	for(int counter = 0; counter <= 20; counter++)
	{
		printf("%d X %d = %d\n", number, counter, number * counter);
	}
	
	return 0;
}