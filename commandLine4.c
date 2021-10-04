//To print given name given number of times using command line arguments.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int isString(char *name);
void input();

int main(int argc, char *argv[])
{
	char numberString[10] = "0123456789";
	int count = 0;
	char *name, *tempName, tempRepeater;
	int nameCount = 0;
	int repeater;

	for(int counter = 1; counter < argc; counter++)
	{
		if(isString(argv[counter]) && nameCount ==0)
		{
			nameCount = 1;
			name = argv[counter];
		}
		else if(isString(argv[counter]) && count == 0)
		{
			count = 1;
			repeater = atoi(argv[counter]);
		} 
		else if(nameCount == 1 && count ==1)
		{
			break;
		}
		else
		{
			continue;
		}
	}


	if(count == 0 || nameCount == 0)
	{
		input();
	}

	void input()
	{
		if(argc <= 1)
		{
			printf("Enter name and number of times to repeat? \n");
			scanf("%s %s", tempName, tempRepeater);
			if(isString(tempName) == 1) 
			{
				name = tempName;
				nameCount = 1;
			} 
			else
			{
				repeater = atoi(tempName); 
				count = 1;
			} 
			(isString(tempRepeater) == 1 && nameCount ==0 ) ? name = tempName, nameCount = 1 : repeater = atoi(tempName) , count = 1;
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
	
	// printf("Name is: %s\n", name);
	// printf("count is: %d\n", repeater);

	// for(int counter = 0; counter < repeater; counter++)
	// {
	// 	printf("%s\n", name);
	// }
	// return 0;
}

//To find whether given argument is string or not.

int isString(char *name)
{
	if(atoi(name) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}