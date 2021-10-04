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
    FILE *customerPtr;

    customerPtr = fopen("F:\\Training\\bankCustomer.txt","r");
    if(customerPtr == NULL)
    {
      printf("Nothing in the file");              
    }
     
    //read Customer details

    printf("\nCustomer details are: \n");

    fread(&cust, sizeof(cust), 1, customerPtr);
    
    printf("Customer Name: %s\n", &cust.customerName);
    
    printf("AccountNumber: %d\n", &cust.accountNumber);
   
    printf("Balance: %f\n", &cust.balance);
    

    fclose(customerPtr);
    
    return 0;
}