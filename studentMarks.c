//To print names in an array

#include<stdio.h>

void main()
  {
      
      int noOfStudents,noOfSubjects;
      int markCounter; 
    	int nameCounter, avg;
      printf("Enter number of students: ");
      scanf("%d", &noOfStudents);
      char names[noOfStudents][20];
      printf("Enter number of stubjects: ");
      scanf("%d",&noOfSubjects);
      int marks[noOfStudents][noOfSubjects];
      for( int counter = 0; counter < noOfStudents; counter++)
      {
          printf("Enter student %d name: ", counter + 1);
          scanf("%s", &names[counter]);
          for (markCounter = 0; markCounter < noOfSubjects; markCounter++)
          {
              printf("Enter subject %d of %d marks: ",markCounter + 1,noOfSubjects);
              scanf("%d",&marks[counter][markCounter]);
          }
        
      }
      // int sumOf(int arr[][], int n)
      // {
      //     int sum = 0;
      //     for (int i = 0; i < n; i++)
      //     sum += arr[i];
      //     return sum;
      // }
      for( int counter = 0; counter < noOfStudents; counter++)
      {
          printf("%s marks: ", names[counter]);
          for (markCounter = 0; markCounter < noOfSubjects; markCounter++)
          {
              printf("Subject %d marks are %d.", markCounter + 1, marks[counter][markCounter]);
          }
          printf("\n");
          // avg = sumOf(marks[counter][markCounter], noOfSubjects );
          // printf("Average is: ", avg);
        
      }

}


 
