//Creating an userdefined function to add two numbers.

#include<stdio.h>
int add(int a, int b);
int main()
{
	int number1, number2, sum;

	printf("Enter two numbers to add: \n");
	printf("Enter 1st number: ");
	scanf("%d", &number1);

	printf("Enter 2nd number: ");
	scanf("%d", &number2);

	sum = add(number1, number2);
	printf("Addition of %d and %d is %d. ", number1, number2, sum);

	return 0;
}

int add(int a, int b)
{
	return (a + b);
}