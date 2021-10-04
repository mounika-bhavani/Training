// To read and display bank customer details using structure
 
#include <stdio.h>
 
int main()
{
    char name[20], temp, custo;
    FILE *customerPtr;

    customerPtr = fopen("F:\\Training\\bankCustomer.txt","r");
    if(customerPtr == NULL)
    {
      printf("Nothing in the file");              
    }
    
     
    //print customer details from file.

    temp = fscanf(customerPtr, "%[^\n]", name);
    while(temp != EOF)
    {
        printf("%s \n", name);
        temp = fscanf(customerPtr, "%s", name);
    }
   
    // printf("\nCustomer details are: \n");
    // printf("Customer Name: %s\n", cust.customerName);
    // printf("AccountNumber: %d\n", cust.accountNumber);
    // printf("Balance: %f\n", cust.balance);

    fclose(customerPtr);
    
    return 0;
}