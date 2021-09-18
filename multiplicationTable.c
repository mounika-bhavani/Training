//To print multiplication table of a number.

#include<stdio.h>
int main()
{
	int number, multiplier;
	printf("Enter a number to print its multiplication number: ");
	scanf("%d\n", &number);
	for(multiplier=1; multiplier<=10; multiplier++)
	{
		printf("%d X %d = %d\n", number, multiplier ,multiplier*number);
	}
	return 0;
}
		
