//main program.

#include<stdio.h>
#include<stdlib.h>

#define FILE_NAME "framework.dat"
void create();
void update();
void delete();
void display();
char fieldName[50][100];
static int count = 0;

//main function

void main()
{
	int counter = 0;
	FILE *fpField;
	fpField = fopen("fields.cfg", "r");
	while(1)
	{
		char tempFieldCharacter = (char)fgetc(fpField);
		int charCount = 0;
		while(tempFieldCharacter != ',' && !feof(fpField))
		{
			fieldName[counter][charCount++] = tempFieldCharacter;
			tempFieldCharacter = (char)fgetc(fpField);
		}
		fieldName[counter][charCount] = 0;
		// printf("%s", fieldName[counter]);
		if(feof(fpField))
		{
			break;
		}
		counter++;
		count++;
	}
	int choice;
	FILE *fpMenu;
	fpMenu = fopen("Menu.cfg", "r");

	char menuLine[100];
	do
	{
		while(fgets(menuLine, 100, fpMenu) != NULL)
		{
			//puts(text);
			printf("%s\n", menuLine);

		}
		fclose(fpMenu);
		fclose(fpField);
		printf("\nEnter your Choice: ");
		scanf("%d", &choice);

	 	switch(choice)
	 	{
	 		case 1: create();
	 		break;
	 		case 2: update();
	 		break;
	 		case 3: delete();
	 		break;
	 		case 4: display();
	 		break;
	 		case 5: exit(0);
	 		break;
	 	}
	}while(choice != 5);	
}
 
//Display Function 

void display()
{
	FILE *fpData;
	fpData = fopen(FILE_NAME, "r");
	char fieldValue[20];
	int counter;
	
    counter = 0;
	while(fread(&fieldValue, sizeof(fieldValue), 1, fpData))
	{
		printf("%s: ", fieldName[counter]);
		++counter;
		printf("%s\n", fieldValue);
		if(counter == count + 1)
		{

			printf("----------------------------------------\n");
			counter = 0;
		}

	}
}

//create function

void create()
{
	FILE *fpData;
	char fieldValue[20];
	fpData = fopen(FILE_NAME, "a");
	for(int counter =0; counter <= count - 1; counter++)
	{
		printf("Enter %s: ", fieldName[counter] + 1);
		scanf("%s", fieldValue);
		fwrite(fieldValue, sizeof(fieldValue), 1, fpData);
	}
	//printf("hi");
	fwrite("A", sizeof(fieldValue), 1, fpData);
	fclose(fpData);
}

//update Function

void update()
{
	FILE *fpData;
	fpData = fopen(FILE_NAME, "r+");
	char fieldValue[20];
	int counter;
	int choice;
	char tempNumber[20], tempFieldValue[20];
	
	counter = 0;
	printf("Enter %s to be updated: ", fieldName[counter]);
	scanf("%s", tempNumber);

	for(counter = 1; counter < count; counter++)
	{
		printf("Enter %d to update %s: \n", counter, fieldName[counter] + 1);
	}

	scanf("%d", &choice);
	counter = 0;
	while(fread(&fieldValue, sizeof(fieldValue), 1, fpData))
	{
		++counter;
		if(atoi(tempNumber) == atoi(fieldValue))
		{
			// printf("hello");
			printf("Enter new value of %s to be updated: ", fieldName[choice] + 1);
			scanf("%s", tempFieldValue);
			fseek(fpData, sizeof(fieldValue)* + (choice - 1), SEEK_CUR);
			fwrite(tempFieldValue, sizeof(tempFieldValue), 1, fpData);
			break;
		}
	}
	fclose(fpData);
}

//Delete Function

void delete()
{
	FILE *fpData;
	fpData = fopen(FILE_NAME, "r+");
	char tempNumber[20], tempFieldValue[20], fieldValue[20];
	int counter;
	counter = 0;
	printf("Enter %s to be deleted: ", fieldName[counter]);
	scanf("%s", tempNumber);
	while(fread(&fieldValue, sizeof(fieldValue), 1, fpData))
	{
		++counter;
		if(atoi(tempNumber) == atoi(fieldValue))
		{
			// printf("hello");
			fseek(fpData, sizeof(fieldValue)* + (count - 1), SEEK_CUR);
			fwrite("D", sizeof(tempFieldValue), 1, fpData);
			break;
		}
	}
	fclose(fpData);


}