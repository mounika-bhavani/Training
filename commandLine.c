//To print given name given number of times using command line arguments.

#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	//Checking whether we entered any command line arguments or not.

	if(argc <= 1)
	{
		printf("Enter name and number of times to repeat? \n");
		exit(0);
	}
		
	for(int counter = 0; counter <= argc; counter++)
	{
		printf("%s\n", argv[counter]);


	}
}