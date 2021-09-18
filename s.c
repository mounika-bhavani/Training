// To prints 5 marks in an array

#include <stdio.h>
#define COUNT 5
void main()
{

    int marks[COUNT], counter, sum = 0;  
    char names[COUNT][20];
    printf("Enter name and marks: ");
   
    //read marks

    for(counter = 0; counter < COUNT; counter++)
    	{
            printf("Enter %d of %d names: ", counter + 1,COUNT);
            scanf("%s",&names[counter]);
    		printf("Enter %d of %d Marks: ", counter + 1, COUNT);
    		scanf("%d", &marks[counter]);
    	}
    printf("\nMarks of students and average is: \n ");

    //printing marks

    for(counter = 0; counter < COUNT; counter++)
    {
        printf("Student %d name: %s ;marks: %d\n ", counter + 1, names[counter], marks[counter]);
        sum += marks[counter];
        printf("Average is: %d ", sum/COUNT);
    }
}



