//Student Information in c - File Handling.

#include<stdio.h>
#include<stdlib.h>
#define FILE_NAME "students.dat"
#define MAX_LENGTH 30
void createStudent();
void showStudents();
void updateStudent();
void deleteStudent();
struct student
{
	int rollNumber;
	char studentName[MAX_LENGTH];
	char dateOfJoining[MAX_LENGTH];
	char course[MAX_LENGTH];
	char status;
};
int main()
{
	int option;
	do
	{
		printf("... Students Joining Details ...");
		printf("\n--------------");
		printf("\n1.Create new student details");
		printf("\n2.Show all students details");
		printf("\n3.Update student details");
		printf("\n4.delete student details");
		printf("\n5.Exit");
		printf("\n--------------");
		printf("\nPlease enter your option: ");
		scanf("%d", &option);
		switch(option)
		{
			case 1: createStudent();
			break;
			case 2: showStudents();
			break;
			case 3: updateStudent();
			break;
			case 4: deleteStudent();
			break;
			case 5: ;
			break;
			default: printf("Enter a valid option");
			break;
		}
	}while(option != 5);
}

void createStudent()
{
	printf("\nEnter new student details ...");
	struct student std;
	FILE *fpStudent;
	printf("\nEnter the roll number: ");
	scanf("%d", &std.rollNumber);
	printf("Enter the name of student: ");
	scanf("%s", std.studentName);
	printf("Enter the date of joining (dd/mm/yyyy) of student: ");
	scanf("%s", std.dateOfJoining);
	printf("Enter the branch of student: ");
	scanf("%s", std.course);
	std.status = 'A';
	fpStudent = fopen(FILE_NAME, "a");
	if(fpStudent == NULL)
	{
		printf("\nError");
		return;
	}
	fwrite(&std, sizeof(std), 1, fpStudent);
	fclose(fpStudent);
	//getch();
}

void showStudents()
{
	struct student std;
	FILE *fpStudent;
	fpStudent = fopen(FILE_NAME, "r");
	if(FILE_NAME == NULL)
	{
		printf("\nError");
		return;
	}
	while(fread(&std, sizeof(std), 1, fpStudent))
	{
		if(std.status != 'D')
		{
			printf("\nRoll number of student: %d", std.rollNumber);
			printf("\nName of student: %s", std.studentName);
			printf("\nJoining date of student: %s", std.dateOfJoining);
			printf("\nCourse of student: %s\n", std.course);
		}
	}
	fclose(fpStudent);
	//getch();
}

void updateStudent()
{
	struct student std;
	int roll_number;
	printf("Enter the roll number of student that you want to update: ");
	scanf("%d", &roll_number);
	FILE *fpStudent;
	fpStudent = fopen(FILE_NAME, "r+");
	while(fread(&std, sizeof(std), 1, fpStudent))
	{
		if(std.rollNumber == roll_number)
		{
			printf("\nEnter a new data ....");
			printf("\nEnter the name of student: ");
			scanf("%s", std.studentName);
			printf("Enter the date of joining of student: ");
			scanf("%s", std.dateOfJoining);
			printf("Enter the branch of student: ");
			scanf("%s", std.course);
			fseek(fpStudent, -sizeof(std), SEEK_CUR);
			fwrite(&std, sizeof(std), 1, fpStudent);
			break;
		}
	}
	fclose(fpStudent);
}

void deleteStudent()
{
	struct student std;
	int roll_number;
	printf("\nEnter the rollnumber of student that you want to delete: ");
	scanf("%d", &roll_number);
	FILE *fpStudent;
	fpStudent = fopen(FILE_NAME, "r+");
	if(FILE_NAME == NULL)
	{
		printf("\nError");
		return;
	}
	while(fread(&std, sizeof(std), 1, fpStudent))
	{
		if(std.rollNumber == roll_number)
		{
			std.status = 'D';
			fseek(fpStudent, -sizeof(std), SEEK_CUR);
			fwrite(&std, sizeof(std), 1, fpStudent);
			printf("\nSuccessfully deleted the record.\n");
			break;
		}
	}
	fclose(fpStudent);
}