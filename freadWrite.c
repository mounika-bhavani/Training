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

    customerPtr = fopen("F:\\Training\\bankCustomer.txt","w");
    if(customerPtr == NULL)
    {
      printf("Nothing in the file");              
    }
     
    //read Customer details

    printf("\nEnter customer details :\n");
    printf("Customer Name: ");          
    scanf("%s", &cust.customerName);
    
    printf("AccountNumber: ");            
    scanf("%d", &cust.accountNumber);
   
    printf("Balance: ");        
    scanf("%f", &cust.balance);
    
    fwrite(&cust, sizeof(cust), 1, customerPtr);
    
    printf("\n %s \n %d \n %f", cust.customerName, cust.accountNumber, cust.balance);

    fclose(customerPtr);

    customerPtr = fopen("F:\\Training\\bankCustomer.txt","r");

    printf("\nCustomer details are: \n");

    fread(&cust, sizeof(cust), 1, customerPtr);
    
    printf("Customer Name: %s", &cust.customerName);
    
    printf("AccountNumber: %d", &cust.accountNumber);
   
    printf("Balance: %f", &cust.balance);
    

    fclose(customerPtr);
    
    
    return 0;
}