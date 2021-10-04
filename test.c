//To Update, Delete, read, create a record in the file.

#include<stdio.h>
#include<stdlib.h>
void createNewRecord();
void displayAllRecords();
void updateRecord();
void deleteRecord();

struct customer
{
    int accountNumber;
    char customerName[30];
    float balance;
    char status;
}Customer;

void main()
{
    //struct customer Customer;
    int choice;
    do
    {
        printf("\n----Welcome To online Bank---------\n");
        printf("1. CREATE\n2. DISPLAY\n3. DELETE\n4. UPDATE\n5. EXIT");
        printf("\n------------------------------------------\n");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
            case 1:
            createNewRecord();
            break;
            case 2:
            displayAllRecords();
            break;
            case 3:
            deleteRecord();
            break;
            case 4:
            updateRecord();
            break;
            case 5:
            exit(1);
            break;
            default:
            printf("\nPlease enter above choices only...\n");
            break;
        }
    } while (choice != 5);
}



//Function to update.

void updateRecord()
{
    FILE *fpCustomer;
    int tempAccNumber,accNumber ;
    printf("Enter Account Number you want to update: ");
    scanf("%d", &accNumber);
    fpCustomer = fopen("bankCustomer.dat", "r+");
    while(fread(&Customer, sizeof(Customer), 1, fpCustomer))
    {
        tempAccNumber = Customer.accountNumber;
        if(tempAccNumber == accNumber)
        {
            printf("Enter Name to be updated: ");
            scanf("%s", &Customer.customerName);
            fseek(fpCustomer, sizeof(Customer)* -1, SEEK_CUR);
            fwrite(&Customer, sizeof(Customer), 1, fpCustomer);
            break;
        }

    }
    fclose(fpCustomer);
   // main();
}


//Function to create new Record.

void createNewRecord()
{
    FILE *fpCustomer;
    fpCustomer = fopen("bankCustomer.dat", "a");
    printf("Enter the Account no: ");
    scanf("%d", &Customer.accountNumber);
    printf("Enter the Name: ");
    scanf("%s", Customer.customerName);
    printf("Enter the balance: ");
    scanf("%f", &Customer.balance);
    fwrite(&Customer, sizeof(Customer), 1, fpCustomer);
    fclose(fpCustomer);
}

//Function to delete a record in a file.

void deleteRecord()
{
    FILE *fpCustomer;
    int accNumber;
    printf("Enter the Account number you want to delete :");
    scanf("%d", &accNumber);
    fpCustomer = fopen("bankCustomer.dat", "r+");
    while (fread(&Customer, sizeof(Customer), 1, fpCustomer))
    {
        if (Customer.accountNumber == accNumber)
        {
            Customer.status = 'D';
            fseek(fpCustomer,sizeof(Customer)* -1,SEEK_CUR);
            fwrite(&Customer, sizeof(Customer), 1, fpCustomer);
            printf("Deleted Successfully...");
            break;
        }
    }
    fclose(fpCustomer);
}

//Function to display all Records.

void displayAllRecords()
{
    FILE *fpCustomer;
    fpCustomer = fopen("bankCustomer.dat", "r");
    printf("\nAccount Number\tName\tBalance\tstatus\n\n");
    while (fread(&Customer, sizeof(Customer), 1, fpCustomer))
    {
        if(Customer.status != 'D')
        printf("  %d\t\t%s\t%.2f\t\t\n", Customer.accountNumber, Customer.customerName, Customer.balance);
    }
    fclose(fpCustomer);
}
