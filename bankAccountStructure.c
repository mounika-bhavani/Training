// program to read and display bank employee details using structure
 
#include <stdio.h>
 
//defining structure

struct employee
{
    char    employeeName[30];
    int     accountNumber;
    float   balance;
};
 
int main()
{
    struct employee emp;
     
    //read employee details

    printf("\nEnter employee details :\n");
    printf("EmployeeName: ");          
    scanf("%s", &emp.employeeName);
    printf("AccountNumber: ");            
    scanf("%d", &emp.accountNumber);
    printf("Balance: ");        
    scanf("%f", &emp.balance);
     
    //print employee details

    printf("\nEmployee details:");
    printf("EmployeeName: %s\n", emp.employeeName);
    printf("AccountNumber: %d", emp.accountNumber);
    printf("Balance: %f\n", emp.balance);
    
    return 0;
}