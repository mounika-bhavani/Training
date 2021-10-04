//To print student marks of many subjects in an array

#include<stdio.h>
#include<stdlib.h>

void main()
  {
      
      int countOfStudents, countOfSubjects;
      int markCounter; 
    	int nameCounter;
      printf("Enter number of students: ");
      scanf("%d", &countOfStudents);

      char **namesPointer = malloc(countOfStudents * sizeof(char *));

      printf("Enter number of stubjects: ");
      scanf("%d", &countOfSubjects);

      for( int counter = 0; counter < countOfStudents; counter++)
      {
          printf("Enter student %d name: ", counter + 1);
          scanf("%s", namesPointer[counter]);

          namesPointer[counter + 1] = malloc(countOfSubjects);

          for (markCounter = 0; markCounter < countOfSubjects; markCounter++)
          {
              printf("Enter subject %d of %d marks: ",markCounter + 1,countOfSubjects);
              scanf("%d", namesPointer[counter][markCounter]);
          }
        
      }
     
      for( int counter = 0; counter < countOfStudents; counter++)
      {
          printf("%s marks: ", namesPointer[counter]);
          for (markCounter = 0; markCounter < countOfSubjects; markCounter++)
          {
              printf("Subject %d marks are %d.", markCounter + 1, namesPointer[counter][markCounter]);
          }
          printf("\n");
          
        
      }

}


 
