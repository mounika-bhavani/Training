//main program.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// #define FILE_NAME "framework.dat"
// char fieldName[50][100];
// static int count = 0;
void main()
{
	// int counter = 0;
	FILE *fpField;
	int sizeofField;
	char tempFieldName[100];
	fpField = fopen("fields.cfg", "r");
	while(fgets(tempFieldName, 100,fpField))
	{
		printf("%s", tempFieldName);

		sizeofField = strlen(tempFieldName);
		printf("%s", tempFieldName);

		tempFieldName[sizeofField] = ’\0’;

		// tempFieldName[strlen(tempFieldName) -1] = ’\0’;
		printf("%s\n", tempFieldName);
	}
}