/*FrameWork program for Create, Display, Update and Deletion of records 
using an array.*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define FILE_NAME "framework.dat"
void createRecord();
void updateRecord();
void deleteRecord();
void displayRecords();
char fieldName[50][100];
int count = 0;

//main function

void main()
{
	int counter = 0;
	FILE *fpField;
	fpField = fopen("fieldNames1.cfg", "r");
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
		if(feof(fpField))
		{
			break;
		}
		// counter++;
		count++;
	}
	fclose(fpField);
	int choice;
	FILE *fpMenu;
	char menuLine[100];
	do
	{
		system("cls");
		fpMenu = fopen("Menu.cfg", "r");
		while(fgets(menuLine, 100, fpMenu) != NULL)
		{
			printf("%s\n", menuLine);
		}
		printf("\nEnter your Choice: ");
		scanf("%d", &choice);

	 	switch(choice)
	 	{
	 		case 1: createRecord();
	 		break;
	 		case 2: updateRecord();
	 		break;
	 		case 3: deleteRecord();
	 		break;
	 		case 4: displayRecords();
	 		break;
	 		case 5: exit(0);
	 		break;
	 	}
	}while(choice != 5);	
	fclose(fpMenu);
}
 
//Display Function 

void displayRecords()
{
	FILE *fpData;
	fpData = fopen(FILE_NAME, "r");
	char fieldValue[20];
	int counter;
    counter = 0;
	printf("----------------------------------------\n");
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
	fclose(fpData);
	printf("Enter any key to continue: ");
	getch();
}

//create function

void createRecord()
{
	FILE *fpData;
	char fieldValue[20];
	fpData = fopen(FILE_NAME, "a");
	for(int counter =0; counter <= count - 1; counter++)
	{
		printf("Enter %s: ", fieldName[counter]);
		scanf("%s", fieldValue);
		fwrite(fieldValue, sizeof(fieldValue), 1, fpData);
	}
	//printf("hi");
	fwrite("A", sizeof(fieldValue), 1, fpData);
	printf("Created Successfully..\n");
	fclose(fpData);
	printf("Enter any key to continue: ");
	getch();
}

//update Function

void updateRecord()
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
		printf("Enter %d to update %s: \n", counter, fieldName[counter]);
	}

	scanf("%d", &choice);
	counter = 0;
	while(fread(&fieldValue, sizeof(fieldValue), 1, fpData))
	{
		++counter;
		if(atoi(tempNumber) == atoi(fieldValue))
		{
			// printf("hello");
			printf("Enter new value of %s to be updated: ", fieldName[choice]);
			scanf("%s", tempFieldValue);
			fseek(fpData, sizeof(fieldValue)* + (choice - 1), SEEK_CUR);
			fwrite(tempFieldValue, sizeof(tempFieldValue), 1, fpData);
			break;
		}
	}
	printf("Updated Successfully..\n");
	fclose(fpData);
	printf("Enter any key to continue: ");
	getch();
}

//Delete Function

void deleteRecord()
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
	printf("Deleted Successfully..\n");
	fclose(fpData);
	printf("Enter any key to continue: ");
	getch();
}