/*FrameWork program for Create, Display, Update and Deletion of records 
using rewind function.*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

#define FILE_NAME "framework.dat"
void createRecord();
void updateRecord();
void deleteRecord();
void displayRecords();
int count = 0;
FILE *fpField;

//main function

void main()
{
    int counter = 0;
    fpField = fopen("fieldNames.cfg", "r");
    int choice;
    FILE *fpMenu;
    // clrscr();
    char menuLine[100], fieldName[20];
    while(fgets(fieldName, 100, fpField) != NULL)
    {
         count++;
    }
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
    fclose(fpField);
}
 
//Display Function 

void displayRecords()
{
    FILE *fpData;
    FILE *fpField;
    int counter = 0;
    fpData = fopen(FILE_NAME, "r");
    fpField = fopen("fields.cfg", "r");
    char fieldName[100], fieldValue[20];
    rewind(fpField);
    while(fgets(fieldName, 100, fpField) != NULL && fread(&fieldValue, sizeof(fieldValue), 1, fpData))
    {
        ++counter;
        fieldName[strlen(fieldName) - 1] = '\0';
        printf("%s : %s\n", fieldName, fieldValue);
        if(counter == count)
        {
            counter = 0;
            printf("--------------------------------------\n");
            rewind(fpField);
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
    char fieldValue[20], fieldName[20];
    fpData = fopen(FILE_NAME, "a");
    rewind(fpField);
    int counter = 0;
    while((fgets(fieldName, 100, fpField) != NULL ) && counter < count - 1)
    { 
        fieldName[strlen(fieldName) - 1] = '\0';
        printf("Enter %s: ", fieldName);
        scanf("%s", fieldValue);
        fwrite(fieldValue, sizeof(fieldValue), 1, fpData);
        ++counter;
    }
    counter = 0;
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
    int counter;
    int choice;
    char tempNumber[20], tempName[20];
    char fieldName[100], fieldValue[20];
    rewind(fpField);
    char tempFieldValue[20];
    fgets(fieldName, 100, fpField);
    fieldName[strlen(fieldName) - 1] = '\0';

    printf("Enter %s to be updated: ", fieldName);
    scanf("%s", tempNumber);
    fpData = fopen(FILE_NAME, "r+");
    counter = 1;

    while(fread(fieldValue, sizeof(fieldValue), 1, fpData))
    {
        if(atoi(fieldValue) == atoi(tempNumber))
        {
            printf("Enter value of last field to be Updated: ");
            scanf("%s", tempName);
            fseek(fpData, sizeof(fieldValue)* + (count - 3), SEEK_CUR);
            fwrite(tempName, sizeof(fieldValue), 1, fpData);
            printf("Updated Successfully..\n");
            break;
        }
    }  //end of while
    rewind(fpField);
  fclose(fpData);
  printf("Enter any key to continue: ");
  getch();
}

//Delete Function

void deleteRecord()
{

    FILE *fpData;
    fpData = fopen(FILE_NAME, "r+");
    char tempNumber[20], tempFieldValue[20], fieldValue[20], fieldName[20];
    rewind(fpField);
    fgets(fieldName, 100, fpField);
    fieldName[strlen(fieldName) - 1] = '\0';

    printf("Enter %s to be deleted: ", fieldName);
    scanf("%s", tempNumber);
    while(fread(&fieldValue, sizeof(fieldValue), 1, fpData))
    {
        if(atoi(tempNumber) == atoi(fieldValue))
        {
            fseek(fpData, sizeof(fieldValue)* + (count - 2), SEEK_CUR);
            fwrite("D", sizeof(tempFieldValue), 1, fpData);
            break;
        }
    }
    printf("Deleted Successfully..\n");
    fclose(fpData);
    printf("Enter any key to continue: ");
    getch();
}