#include<stdio.h>
#include<string.h>
#define FILE_NAME "framework.dat"
#define FILE_MENU "Menu.cfg"
#define FILE_FIELDS "fields.cfg"
void create();
void read();
void update();
void delete();


void main()
{
	int option;
	char fieldName[100];
	FILE *fpFields;
	fpFields = fopen(FILE_MENU, "r");
	if(fpFields == NULL)
	{
		printf("File creation failed\n");
		return;
	}
	while(fgets(fieldName, 100, fpFields) != NULL)
	{
		puts(fieldName);
	}
	fclose(fpFields);

	do
	{
	printf("Choose your option and press enter: ");
	scanf("%d", &option);

		switch(option)
		{
			case 1: create();
			break;
			case 2: read();
			break;
			case 3: update();
			break;
			case 4: delete();
			break;
			case 5: ;
			break;
			default: printf("Choose only available options:\n");
			break;
		}
	}while(option != 5);

}

void read()
{
	char fieldValue[20], fieldName[100], status[20], status1[20];
	FILE *fpData;
	FILE *fpFields;
	strcpy(status, "Activated");
	strcpy(status1, "Deactivated");
	
	fpFields = fopen(FILE_FIELDS, "r");
	fpData = fopen(FILE_NAME, "r");
	if(fpData == NULL || fpFields == NULL)
	{
		printf("File creation failed\n");
		return;
	}
	
	while(fread(fieldValue, 20, 1, fpData))
	{

		if(strcmp(status, fieldValue) == 0 || strcmp(status1, fieldValue) == 0)
		{
			printf("status: ");
			printf("%s\n", fieldValue);
			printf("---------\n");
		}
		else
		{
			fgets(fieldName, 100, fpFields);
			printf("%s", fieldName);
			printf("%s\n", fieldValue);
			printf("--------\n");
			if(feof(fpFields))
			{
				fseek(fpFields, 0, SEEK_SET);
			}
		}
	}
	fclose(fpData);
	fclose(fpFields);
}
void update()
{
	char fieldValue[20], fieldName[100];
	FILE *fpData;
	FILE *fpFields;
	fpFields = fopen(FILE_FIELDS, "r+");
	fpData = fopen(FILE_NAME, "r+");
	if(fpData == NULL || fpFields == NULL)
	{
		printf("File creation failed\n");
		return;
	}

	char tempFieldValue[20];
	
	fgets(fieldName, 20, fpFields);
	
	printf("To change your details enter your %s", fieldName);
	scanf("%s", tempFieldValue);
	
	while(fread(fieldValue, sizeof(fieldValue), 1, fpData))
	{
		if(strcmp(tempFieldValue, fieldValue) == 0)
		{
			// printf("%s\n", fieldValue);
			fseek(fpData, 20, SEEK_CUR);
			fread(fieldValue, sizeof(fieldValue), 1, fpData);
			printf("%s should be changed to: ", fieldValue);
			scanf("%s", fieldValue);
			fseek(fpData, -20, SEEK_CUR);
			fwrite(fieldValue, sizeof(fieldValue), 1, fpData);
			printf("Changed to %s.\n", fieldValue);
			break;
		}
	}
	fclose(fpData);
	fclose(fpFields);
}


void create()
{
	char fieldName[100];
	char fieldValue[20];
	char status[20];
	
	FILE *fpData;
	FILE *fpFields;
	fpData = fopen(FILE_NAME, "a");
	fpFields = fopen(FILE_FIELDS, "r");

	if(fpData == NULL)
	{
		printf("File creation failed\n");
		return;
	}
	strcpy(status, "Activated");
	fwrite(&status, sizeof(status), 1, fpData);

	while(fgets(fieldName, 100, fpFields) != NULL)
	{
		printf("Enter %s ", fieldName);
		scanf("%s", fieldValue);
		fwrite(fieldValue, sizeof(fieldValue), 1, fpData);
	}

	printf("Ticket is booked successful.\n");
	
	fclose(fpFields);
	fclose(fpData);

}
void delete()
{
	char fieldValue[20], fieldName[100];
	
	FILE *fpData;
	FILE *fpFields;
	fpFields = fopen(FILE_FIELDS, "r");
	fpData = fopen(FILE_NAME, "r+");
	if(fpData == NULL || fpFields == NULL)
	{
		printf("File creation failed\n");
		return;
	}

	char tempFieldValue[20];
	
	fgets(fieldName, 20, fpFields);
	
	printf("To delete your details enter your %s", fieldName);
	scanf("%s", tempFieldValue);

	while(fread(fieldValue, sizeof(fieldValue), 1, fpData))
	{
		if(strcmp(tempFieldValue, fieldValue) == 0)
		{
			fseek(fpData, -40, SEEK_CUR);
			fread(fieldValue, sizeof(fieldValue), 1, fpData);
			printf("%s should be changed to: ", fieldValue);
			scanf("%s", fieldValue);
			fseek(fpData, -20, SEEK_CUR);
			fwrite(fieldValue, sizeof(fieldValue), 1, fpData);
			printf("Changed to %s.\n", fieldValue);
			break;
		}	
	}
	fclose(fpData);
	fclose(fpFields);
}