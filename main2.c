/*FrameWork program for Create, Display, Update and Deletion of records 
using an frewind function.*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
	
#define FILE_NAME "framework.dat"
void create();
void update();
void delete();
void display();
static int count = 0;
FILE *fpField;

//main function

void main()
{
	FILE *fpMenu;
	int choice;
	fpMenu = fopen("Menu.cfg", "r");
	char menuLine[100];
	do
	{
		while(fgets(menuLine, 100, fpMenu) != NULL)
		{
			//puts(text);
			printf("%s\n", menuLine);

		}
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
	fclose(fpMenu);
}
 
//create function

void create()
{
	FILE *fpData;
	FILE *fpField;
	char fieldName[100], fieldValue[20];

	fpData = fopen(FILE_NAME, "a");
	fpField = fopen("fields.cfg", "r");
	while(fgets(fieldName, 100, fpField) != NULL)
	{
		printf("Enter %s: ", fieldName);
		scanf("%s", fieldValue);
		fwrite(fieldValue, sizeof(fieldValue), 1, fpData);
	}
	fclose(fpField);
	fclose(fpData);
}

//Display Function

void display()
{
	FILE *fpData;
	FILE *fpField;
	int count = 0;
	fpData = fopen(FILE_NAME, "r");
	fpField = fopen("fields.cfg", "r");
	char fieldName[100], fieldValue[20];
	while(fgets(fieldName, 100, fpField) != NULL && fread(&fieldValue, sizeof(fieldValue), 1, fpData))
	{
		++count;
		printf("%s : %s\n", fieldName, fieldValue);
		if(count == 3)
		{
			fseek(fpField, 0, SEEK_SET);
			count = 0;
			printf("--------------------------------------\n");
		}


	}
	
	fclose(fpData);
	fclose(fpField);
}

// update function

void update()
{
	FILE *fpData;
	FILE *fpField;
	char tempNumber[20], tempName[20];
	char fieldName[100], fieldValue[20];
	fpField = fopen("fields.cfg", "r");
	fgets(fieldName, 100, fpField);
	printf("Enter %s to be Updated: ", fieldName);
	scanf("%s", tempNumber);
	fpData = fopen(FILE_NAME, "r+");
	while(fread(fieldValue, sizeof(fieldValue), 1, fpData))
	{
		printf("%s\n", fieldValue);
	
		if(atoi(fieldValue) == atoi(tempNumber))
		{
			printf("%s\n", fieldValue);
			printf("Enter Mobile Number to be Updated: ");
			scanf("%s", tempName);
			fseek(fpData, sizeof(fieldValue), SEEK_CUR);
			fwrite(tempName, sizeof(fieldValue), 1, fpData);
			printf("Updated Successfully..");
			break;
		}
	}  //end of while
	fclose(fpField);
	fclose(fpData);

}

//Delete Function

void delete()
{
	// FILE *fpData;
	// fpData = fopen(FILE_NAME, "r+");
	// char tempNumber[20], tempFieldValue[20], fieldValue[20];
	// int counter;
	// counter = 0;
	// printf("Enter %s to be deleted: ", fieldName[counter]);
	// scanf("%s", tempNumber);
	// while(fread(&fieldValue, sizeof(fieldValue), 1, fpData))
	// {
	// 	++counter;
	// 	if(atoi(tempNumber) == atoi(fieldValue))
	// 	{
	// 		// printf("hello");
	// 		fseek(fpData, sizeof(fieldValue)* + (count - 1), SEEK_CUR);
	// 		fwrite("D", sizeof(tempFieldValue), 1, fpData);
	// 		break;
	// 	}
	// }
	// printf("Deleted Successfully..\n");
	// fclose(fpData);
	// printf("Enter any key to continue: ");
	// getch();
}
