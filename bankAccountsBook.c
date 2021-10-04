// To read and display bank employee details using structure
 
#include <stdio.h>
#define NO_OF_EMPLOYEES 10
//defining structure

struct employee
{
    char    employeeName[NO_OF_EMPLOYEES][30];
    int     accountNumber[NO_OF_EMPLOYEES];
    float   balance[NO_OF_EMPLOYEES];
};

struct employee
{
    char    employeeName[30];
    int     accountNumber;
    float   balance;
};
 



int main()
{
    struct employee emp[NO_OF_EMPLOYEES];
    int numberOfEmployees;
     
    printf("Enter number of employees: ");
    scanf("%d", &numberOfEmployees);

    //read employee details

    
    for(int employeeNumber = 0; employeeNumber < numberOfEmployees; employeeNumber++)
    {
        printf("\nEnter %d employee details? \n", employeeNumber + 1);
        printf("Enter Employee Name: ");          
        scanf("%s", &emp.employeeName[employeeNumber]);
        printf("Enter  AccountNumber: ");            
        scanf("%d", &emp.accountNumber[employeeNumber]);
        printf("Enter Balance: ");        
        scanf("%f", &emp.balance[employeeNumber]);
    }
         
    //print employee details

    for(int employeeNumber = 0; employeeNumber < numberOfEmployees; employeeNumber++)
    {
        printf("\nEmployee details %d:\n", employeeNumber + 1);
        printf("EmployeeName: %s \n", emp.employeeName[employeeNumber]);
        printf("AccountNumber: %d \n", emp.accountNumber[employeeNumber]);
        printf("Balance: %f\n", emp.balance[employeeNumber]);
    }
    return 0;
}