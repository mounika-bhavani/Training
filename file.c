//read and saving a file

#include <stdio.h>
int main()
{
   char name[10];
   FILE *fptr;

   // use appropriate location if you are using MacOS or Linux
   fptr = fopen("F:\\Training\\hi.txt","w");

   if(fptr == NULL)
   {
      printf("Nothing in the file");   
     // exit(1);             
   }

   printf("Enter name: ");
   scanf("%s",&name);

   fprintf(fptr,"%s",name);
   fclose(fptr);

   return 0;
}