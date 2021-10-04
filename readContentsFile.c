//Reading names in the file and printing on the monitor. 

#include<stdio.h>
int main()
{
	
	char name[50], temp;

	FILE *fptr;

	fptr = fopen("F:\\Training\\names.txt", "r");

	if(fptr == NULL)
	{
		printf("File not openning...\n");
		return 0;
	}
		
		//reading file contents.

	temp = fscanf(fptr, "%s", name);

	while(temp != EOF)
	{
		printf("%s\n", name);
		temp = fscanf(fptr, "%s", name);
	}
	fclose(fptr);
	return 0;
}