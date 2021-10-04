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
    char name[10];
    FILE *customerPtr;

    customerPtr = fopen("F:\\Training\\bankCustomer.dat","w");
    if(customerPtr == NULL)
    {
      printf("Nothing in the file");              
    }
     
    //read Customer details

    printf("\nEnter customer details :\n");
    printf("Customer Name: ");          
    scanf("%s", &cust.customerName);
    fprintf(customerPtr, "%s\n", cust.customerName );
    printf("AccountNumber: ");            
    scanf("%d", &cust.accountNumber);
    fprintf(customerPtr, "%d\n", cust.accountNumber);
    printf("Balance: ");        
    scanf("%f", &cust.balance);
    fprintf(customerPtr, "%f\n", cust.balance);
     
    //print customer details

    printf("\nCustomer details are: \n");
    printf("Customer Name: %s\n", cust.customerName);
    printf("AccountNumber: %d\n", cust.accountNumber);
    printf("Balance: %f\n", cust.balance);

    fclose(customerPtr);
    
    return 0;
}