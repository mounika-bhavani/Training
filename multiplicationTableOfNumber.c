//To print multiplication table of a number.

#include<stdio.h>
int main()
{
	int tableNumber, multiplier;
	printf("Enter a number to print its multiplication number: ");
	scanf("%d", &tableNumber);
	for(multiplier = 1; multiplier <= 10; multiplier++)
	{
		printf("%d X %d = %d\n", tableNumber, multiplier ,multiplier * tableNumber);
	}
	return 0;
}	
		
