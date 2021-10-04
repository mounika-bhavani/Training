//To print given name given number of times using command line arguments.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void input();
int nameCount = 0;
int repeater = 0;
int count = 0;
char *name, *tempRepeater;

int main(int argc, char *argv[])
{

	// printf("%d", argc);

	for(int counter = 1; counter < argc; counter++)
	{
		if(atoi(argv[counter]) == 0 && nameCount == 0)
		{
			//printf("oif");
			nameCount = 1;
			name = argv[counter];
		}
		else if(atoi(argv[counter]) != 0 && count == 0)
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

	if(nameCount == 0 || count == 0)
	{
		input();
	}
	printf("Name is: %s\n", name);
	printf("count is: %d\n", repeater);

	for(int counter = 0; counter < repeater; counter++)
	{
		printf("%s\n", name);
	}
	return 0;
}

//Function to input.

	void input()
	{
		if(nameCount == 0 && count == 0)
		{
			printf("Enter name and number of times to repeat? \n");
			scanf("%s %s", name, &tempRepeater);
			if(atoi(name) == 0)
			{
				nameCount = 1;
			}
			else
			{
				count =1;
			}
			if(atoi(tempRepeater) == 0 && nameCount ==0)
			{
				name = tempRepeater;
				nameCount = 1;
			}
			else if()

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
	}
	