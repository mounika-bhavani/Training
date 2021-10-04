//To print given name given number of times using command line arguments.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{

	char numberString[10] = "0123456789";
	int count = 0;
	char *name;
	int nameCount = 0;
	int repeater, tempRepeater;
	// printf("%d", argc);

	for(int counter = 1; counter < argc; counter++)
	{
		if((strcspn(argv[counter], numberString) == strlen(argv[counter])) && nameCount == 0)
		{
			//printf("oif");
			nameCount = 1;
			name = argv[counter];
		}
		else if((strcspn(argv[counter], numberString) != strlen(argv[counter])) && count == 0)
		{
			// printf("jdlk");
			count = 1;
			repeater = atoi(argv[counter]);
		} 
		else if(nameCount == 1 && count ==1)
		{
			// printf("3");
			break;
		}
		else
		{
			// printf("45");
			continue;
		}
	}

	// printf("%s %d", name,count);

	if(argc <= 1)
	{
		printf("Enter name and number of times to repeat? \n");
		scanf("%s %d", name, &repeater);
	}
	else if(nameCount == 1 && count == 0)
	{
		printf("Enter number of times to repeat: ");
		scanf("%d", &repeater);
	}
	else if(nameCount == 0 && count ==1)
	{
		printf("Enter name to be repeat: ");
		scanf("%s", name);
	}
	else
	{
		// printf("nono");
	}
	
	printf("Name is: %s\n", name);
	printf("count is: %d\n", repeater);

	for(int counter = 0; counter < repeater; counter++)
	{
		printf("%s\n", name);
	}
	return 0;
}