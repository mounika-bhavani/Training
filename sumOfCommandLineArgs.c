//To print sum of all command line arguments.

#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	int sum = 0, numbers[30];

	if(argc <= 1)
	{
		printf("Ente numbers: \n");
		exit(0);
	}
	
	for(int counter = 0; counter < argc; counter++)
		{
			//Converting string value to integer value to add to sum.
			
			sum += atoi(argv[counter]); 
			
		}
		printf("Sum of all arguments is: %d", sum);
	return 0;
}