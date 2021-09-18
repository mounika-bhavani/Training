//To find power of base to base

#include <stdio.h>
int main() 
{
    int base, power, powerValue = 1;
    printf("Enter a number to find  base to the power of base: ");
    scanf("%d", &base);
    power = base;
    while (base >= 1) 
    {
        powerValue *= power;
        base = base - 1;
    }
    printf("Value of %d to the power %d is %d .",power, power , powerValue);
    return 0;
}


