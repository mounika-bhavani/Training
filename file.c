//writing to a file

#include <stdio.h>
int main()
{
   char name[10];
   FILE *namePointer;

   //opening a file

   namePointer = fopen("F:\\Training\\name.txt","w");
   if(namePointer == NULL)
   {
      printf("Nothing in the file");              
   }

   printf("Enter name: ");
   scanf("%s",&name);
   
   //printing into file.

   fprintf(namePointer,"%s",name);
   fclose(namePointer);

   return 0;
}