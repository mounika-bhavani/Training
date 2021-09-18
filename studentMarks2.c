// To prints student marks and their average.

#include <stdio.h>
#define COUNT 2
void main()
{

    int marks[COUNT], counter, sum = 0;  
    char names[COUNT][20];
    printf("Enter name and marks: \n");
   
    //read marks

    for(counter = 0; counter < COUNT; counter++)
	{
        printf("Enter name %d of %d: ", counter + 1,COUNT);
        scanf("%s",&names[counter]);
		printf("Enter Marks of %s: ",names[counter]);
		scanf("%d", &marks[counter]);
	}
    printf("\nMarks of students and average is: \n");

    //printing marks

    for(counter = 0; counter < COUNT; counter++)
    {
        printf("Student name %d: %s; Marks: %d\n", counter + 1, names[counter], marks[counter]);
        sum += marks[counter];
        
    }
    printf("Average is: %d ", sum/COUNT);
}



