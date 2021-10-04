//main program.

#include<stdio.h>
#include<stdlib.h>
	
#define FILE_NAME "framework.dat"
void create();
void update();
void delete();
void display();
char fieldName[50][100];
int count = 0;


//main function

void main()
{
	FILE *fpMenu;
	FILE *fpField;
	int choice;
	// char tempFieldName[100];
	fpMenu = fopen("Menu.cfg", "r");
	fpField = fopen("fields.cfg", "r");
	// while(fgets(tempFieldName, 20, fpField) != NULL)
	// {
	// 	*fieldName[counter] = *(tempFieldName);
	// 	counter++;
	// 	count++;
	// }

	int counter = 0;
    while(1)
    { 
        char tempFieldCharacter = (char)fgetc(fpField); 
        int charCount = 0; 
        while(tempFieldCharacter !=',' && !feof(fpField))               
        {												
            fieldName[counter][charCount++] = tempFieldCharacter;			
            tempFieldCharacter = (char)fgetc(fpField); 
        } 
        fieldName[counter][charCount] = 0;	
        if(feof(fpField))
        {		
            break; 
        } 
        counter++; 
    } 

    for(int i = 0; i < count; i++)
    {
    	printf("%s", fieldName[i]);
    }

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
 
//create function

void create()
{
	FILE *fpData;
	char fieldValue[20];
	fpData = fopen(FILE_NAME, "a");
	for(int counter =0; counter < count - 1; counter++)
	{
		printf("Enter %s: ", fieldName[counter]);
		scanf("%s", fieldValue);
		fwrite(fieldValue, sizeof(fieldValue), 1, fpData);
	}
	fclose(fpData);
}

//Display Function

void display()
{
	FILE *fpData;
	fpData = fopen(FILE_NAME, "r");
	char fieldValue[20];
	int counter;

	for(counter = 0; counter < count; counter++)
	{
		printf("|%s\t|", fieldName[counter]);
	}
	printf("\n--------------------------------------\n");
	counter = 0;
	while(fread(&fieldValue, sizeof(fieldValue), 1, fpData))
	{
		++counter;
		printf("%s\t", fieldValue);
		if(counter == count - 1)
		{
			printf("\n");
			counter = 0;
		}

	}

	fclose(fpData);
}

// update function

void update()
{
	printf("hi");
	FILE *fpData;
	int counter = 0;
	int index;
	char tempNumber[20], tempValue[20];
	char fieldName[100], fieldValue[20];

	printf("Enter %s to be Updated: ", fieldName[1]);
	printf("ell");
	scanf("%s", tempNumber);

	fpData = fopen(FILE_NAME, "r+");
	while(fread(fieldValue, sizeof(fieldValue), 1, fpData))
	{
		// printf("%s\n", fieldValue);
	
		if(atoi(fieldValue) == atoi(tempNumber))
		{
			printf("%s\n", fieldValue);
			for(counter = 0; counter < count; counter++)
			{
				printf("Enter %d for %s: ", counter, fieldName[counter]);
			}
			scanf("%d", index);
			printf("Enter new Value: ");
			scanf("%s", tempValue);
			fseek(fpData, sizeof(fieldValue)* - index, SEEK_CUR);
			fwrite(tempValue, sizeof(tempValue), 1, fpData);
			printf("Updated Successfully..");
			break;
		}
	}  //end of while
	fclose(fpData);

}
void delete()
{

}