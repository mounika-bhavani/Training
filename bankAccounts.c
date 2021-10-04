// To read and display bank customer details using structure
 
#include <stdio.h>
#define FILE_NAME bankCustomer.dat
void readCustomerDetails();
void allCustomersDetails();
//defining structure

struct customer
{
    char customerName[30];
    int accountNumber;
    float balance;
};
 
int main()
{
    int opt;

    struct customer cust;
    char name[20];
    FILE *fpCustomer;

    //read Customer details

    void readCustomerDetails()
    {
        printf("\nEnter customer details :\n");
        printf("AccountNumber: ");            
        scanf("%d", &cust.accountNumber);

        printf("Customer Name: ");          
        scanf("%s", cust.customerName);

        printf("Balance: ");        
        scanf("%f", &cust.balance);

        fpCustomer = fopen("FILE_NAME", "a");
        if(fpCustomer == NULL)
        {
          printf("Nothing in the file");              
        }

        fwrite(&cust, sizeof(cust), 1, fpCustomer);

        fclose(fpCustomer);

    }

    void allCustomersDetails()
    {
        fpCustomer = fopen("FILE_NAME","r");
        if(fpCustomer == NULL)
        {
            printf("Nothing in the file");              
        }
        int count = 1;
        while(fread(&cust, sizeof(cust), 1, fpCustomer))
        {
            printf("Customer %d details are: \n", count);
            printf("Customer accountNumber: %d\n", cust.accountNumber);
            printf("Customer Name: %s\n", cust.customerName);
            printf("Balance: %f\n", cust.balance);
            count++;
        }
        fclose(fpCustomer);
    }

    do
    {
        printf("Bank Customers\n");
        printf("-------------------------------\n");
        printf("1. New Customer\n");
        printf("2. Show all Customers\n");
        printf("3. Exit\n");
        printf("Please enter option: ");
        scanf("%d", &opt);

        switch(opt)
        {
            case 1:
            readCustomerDetails();
            break;
            case 2:
            allCustomersDetails();
        }
    }while(opt != 3);

    return 0;
}
