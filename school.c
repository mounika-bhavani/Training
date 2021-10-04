 //To create, update, delete and displaying Student data.

#include<stdio.h>
#include<stdlib.h>
#define FiLE_NAME "StudentFile.dat"

void updateRecord();
void createNewRecord();
void deleteRecord();
void displayAll();

//Student Structure

struct Student
{
	int rollNo;
	char name[30];
	int standard;
	char status;
}Student;

//main function

void main()
{
	int choice;
	do
	{
		printf("\n------------------Welcome -----------------------\n");
        printf("1. CREATE\n2. DiSPLAY\n3. DELETE\n4. UPDATE\n5. EXiT");
        printf("\n------------------------------------------\n");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
            case 1:
            createNewRecord();
            break;
            case 2:
            displayAll();
            break;
            case 3:
            deleteRecord();
            break;
            case 4:
            updateRecord();
            break;
            case 5:
            exit(1);
            break;
            default:
            printf("\nPlease enter one of the above choices only...\n");
            break;
        }
    } while (choice != 5);
}

//Function to update.

void updateRecord()
{
	FiLE *fpStudent;
	int tempRoll;
	printf("Enter Roll number to update: ");
	scanf("%d", &tempRoll);
	fpStudent = fopen(FiLE_NAME, "r+");
	while(fread(&Student, sizeof(Student), 1, fpStudent))
	{
		if(tempRoll == Student.rollNo)
		{
			printf("Enter standard to update: ");
			scanf("%d", &Student.standard);
			fseek(fpStudent, sizeof(Student)* -1, SEEK_CUR);
			fwrite(&Student, sizeof(Student), 1, fpStudent);
			printf("Updated Successfully..");
			break;
		}
	}
	fclose(fpStudent);
}

//Function to Delete.

void deleteRecord()
{
	FiLE *fpStudent;
	int tempRoll;
	
	printf("Enter Roll number to delete: ");
	scanf("%d", &tempRoll);
	fpStudent = fopen(FiLE_NAME, "r+");
	
	while(fread(&Student, sizeof(Student), 1, fpStudent))
	{
		if(tempRoll == Student.rollNo)
		{
			Student.status = 'D';
			fseek(fpStudent, sizeof(Student)* -1, SEEK_CUR);
			fwrite(&Student, sizeof(Student), 1,fpStudent); 
			printf("Deleted Successfully..");
			break;
		}
	}
	fclose(fpStudent);
}

//Create New Record.

void createNewRecord()
{
	FiLE *fpStudent;
	
	printf("Enter Roll number: ");
	scanf("%d", &Student.rollNo);

	printf("Enter Name of the Student: ");
	scanf("%s", &Student.name);

	printf("Enter standard: ");
	scanf("%d", &Student.standard);

	fpStudent = fopen(FiLE_NAME, "a");
	fwrite(&Student, sizeof(Student), 1, fpStudent);
	fclose(fpStudent);
}

//Function to Display all records.

void displayAll()
{
	FiLE *fpStudent;
	fpStudent = fopen(FiLE_NAME, "r");
	printf("\nROLL NO\tNAME\tstandard\tstatus\n");
	while(fread(&Student, sizeof(Student), 1, fpStudent))
	{
		if(Student.status == 'D')
		{
			return;
		}
		else
		{
			printf("%d\t%s\t%d\t\t%c\n", Student.rollNo, Student.name, Student.standard, Student.status);
		}
	}
	fclose(fpStudent);
}