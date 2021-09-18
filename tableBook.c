//To print tables in a book.

#include <stdio.h>
int main() 
{
  int noOfTables, counter = 1, tableNumber = 1;
  printf("How many tables you want in book:\n ");
  scanf("%d", &noOfTables);
  while(noOfTables != 0)
  {
      printf("table %d\n", tableNumber);
      for (counter = 1; counter <= 10; counter++ )
      {
      
        printf("%d X %d = %d \n", tableNumber, counter, tableNumber * counter);
      }
      noOfTables -= 1;
      tableNumber +=1;
  }
  return 0;
}
