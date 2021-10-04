// To read and display bank customer details using structure
 
#include <stdio.h>
 
//defining structure

struct customer
{
    char customerName[30];
    int accountNumber;
    float balance;
};
 
int main()
{
    struct customer cust;
     
    //read Customer details

    printf("\nEnter customer details :\n");
    printf("Customer Name: ");          
    scanf("%s", &cust.customerName);
    printf("AccountNumber: ");            
    scanf("%d", &cust.accountNumber);
    printf("Balance: ");        
    scanf("%f", &cust.balance);
     
    //print customer details

    printf("\nCustomer details are: \n");
    printf("Customer Name: %s\n", cust.customerName);
    printf("AccountNumber: %d", cust.accountNumber);
    printf("Balance: %f\n", cust.balance);
    
    return 0;
}