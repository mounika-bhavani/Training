//To print names in an array

#include<stdio.h>
#define COUNT 5
void main()
  {
    	char names[COUNT][20];
    	int nameCounter;
    	//printf("Enter names: ");

      //reading names

    	for(nameCounter = 0; nameCounter < COUNT; nameCounter++)
      {
          printf("Enter %d of %d names: ", nameCounter + 1,COUNT);
          scanf("%s", names[nameCounter]);
      }
      printf("Names are: ");

      // printing names

      for (nameCounter = 0; nameCounter < COUNT; nameCounter++)
      {
          printf("Name %d: %s  ", nameCounter + 1, names[nameCounter]);
      }
  		
  }

 
