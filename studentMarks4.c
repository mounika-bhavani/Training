// To prints 5 marks in an array

#include <stdio.h>
#define COUNT 5
void main()
{

    int marks[COUNT], counter;  
    char names[COUNT][20];
    printf("Enter marks: ");
   
    //read marks

    for(counter = 0; counter < COUNT; counter++)
    	{
            printf("Enter %d of %d names: ", counter + 1,COUNT);
            scanf("%s",&names[markCounter]);
    		printf("Enter %d of %d Marks: ", Counter + 1, COUNT);
    		scanf("%d", &marks[counter]);
    	}
    printf("\nMarks are: ");

    //printing marks

    for(counter = 0; counter < COUNT; counter++)
    {
        printf("Mark %d: %d  ", counter, marks[counter]);
    }
}



