#include <stdio.h>
#include <string.h>
 
#define SiZE 40
 
int main(void)
{
  char string[SiZE] = "0123456789";
  char * substring = "Mouni";
 
  printf( "The first %d %dcharacters in the string \"%s\" "
          "are not in the string \"%s\" \n",
            strcspn(substring, string), strlen(substring), substring, string);
 
}
 
/**********  Output should be similar to:  **************
 
The first 10 characters in the string "This is the source string"
are not in the string "axle"
*/