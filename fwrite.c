// To read and display bank customer details using structure
 
#include <stdio.h>
 
//defining structure

struct customer
{
    
    int accountNumber;
    char customerName[30];
    float balance;
};
 
int main()
{
    struct customer cust;
    FILE *customerPtr;
    int count;
    customerPtr = fopen("F:\\Training\\bankCustomer.txt", "w");
    if(customerPtr == NULL)
    {
      printf("Nothing in the file");              
    }
     
    //read Customer details

    printf("\nEnter customer details :\n");
    // printf("Customer Name: ");          
    // scanf("%s", &cust.customerName);
    
    printf("AccountNumber: ");            
    scanf("%d", &cust.accountNumber);

    printf("Customer Name: ");          
    scanf("%s", &cust.customerName);
    
   
    printf("Balance: ");        
    scanf("%f", &cust.balance);
    
    count = fwrite(&cust, sizeof(cust), 1, customerPtr);

    fclose(customerPtr);
    
    return 0;
}