// To prints 5 marks in an array

#include <stdio.h>
#define COUNT 5
void main()
{

    int marks[COUNT], markCounter;  
    printf("Enter marks: ");
   
    //read marks

    for(markCounter = 0; markCounter < COUNT; markCounter++)
    	{
    		printf("Enter %d of %d Marks: ", markCounter, COUNT);
    		scanf("%d", &marks[markCounter]);
    	}
    printf("\nMarks are: ");

    //printing marks

    for(markCounter = 0; markCounter < COUNT; markCounter++)
    {
        printf("Mark %d: %d  ", markCounter, marks[markCounter]);
    }
}



