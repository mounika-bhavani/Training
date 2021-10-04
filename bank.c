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
    FILE *fpCustomer1;
    int tempAcc, accNumber,Choice;
    printf("Enter Account number to update:");
    scanf("%d", &accNumber);
    fpCustomer = fopen("bankCustomer.dat", "r");
    fpCustomer1 = fopen("temp.dat", "w");
    
    while (fread(&Customer, sizeof(Customer), 1, fpCustomer))
    {
        tempAcc = Customer.accountNumber;
        if (tempAcc == accNumber)
        {
            do
            {
                printf("\n ...what do you want to Update ...");
                printf("\n1. Update Name of Account Number %d", accNumber);
                printf("\n2. Update balance of Account Number %d", accNumber);
                //printf("\n3. Update both Name and balance of Account Number %d", accNumber);
                printf("\n4. EXIT");
                printf("\nEnter your choice:");
                scanf("%d", &Choice);
                switch (Choice)
                {
                    case 1:
                    printf("Enter Name:");
                    scanf("%s", &Customer.customerName);
                    break;
                    case 2:
                    printf("Enter balance : ");
                    scanf("%f", &Customer.balance);
                    break;
                    case 3:
                    printf("Enter Name: ");
                    scanf("%s", &Customer.customerName);
                    printf("Enter balance: ");
                    scanf("%f", &Customer.balance);
                    break;
                    case 4:
                    main ();
                    break;
                    default:
                    printf("Please Enter one of the above choices");
                    break;
                }
                //fseek(fpCustomer, sizeof(Customer)*-1, SEEK_SET);
                fwrite(&Customer, sizeof(Customer), 1, fpCustomer1);
            }while(Choice != 4);
        }    
    }
    fclose(fpCustomer);
    fclose(fpCustomer1);
    //FILE *fpCustomer;
    //FILE *fpCustomer1;
    fpCustomer = fopen("bankCustomer.dat", "w");
    fpCustomer1 = fopen("temp.dat", "r");
    while (fread(&Customer, sizeof(Customer), 1, fpCustomer1))
    {
        fwrite(&Customer, sizeof(Customer), 1, fpCustomer);
    }
    
    fclose(fpCustomer);
    fclose(fpCustomer1);
    //printf("RECORD UPDATED");
}


//Function to create new Record.

void createNewRecord()
{
    FILE *fpCustomer;
    fpCustomer = fopen("bankCustomer.dat", "a");
    printf("Enter the Account no: ");
    scanf("%d", &Customer.accountNumber);
    printf("Enter the Name: ");
    scanf("%s", &Customer.customerName);
    printf("Enter the balance: ");
    scanf("%f", &Customer.balance);
    fwrite(&Customer, sizeof(Customer), 1, fpCustomer);
    fclose(fpCustomer);
}

//Function to delete a record in a file.

void deleteRecord()
{
    FILE *fpCustomer;
    FILE *fpCustomer1;
    int accNumber, tempAccNumber;
    printf("Enter the Account number you want to delete :");
    scanf("%d", &accNumber);
    fpCustomer = fopen("bankCustomer.dat", "r");
    fpCustomer = fopen("temp.dat", "w");
    while (fread(&Customer, sizeof(Customer), 1, fpCustomer))
    {
        tempAccNumber = Customer.accountNumber;
        if (tempAccNumber != accNumber)
        {
            fwrite(&Customer, sizeof(Customer), 1, fpCustomer1);
        }
    }
    fclose(fpCustomer);
    fclose(fpCustomer1);
    fpCustomer = fopen("bankCustomer.dat", "w");
    fpCustomer1 = fopen("temp.dat", "r");
    while (fread(&Customer, sizeof(Customer), 1, fpCustomer1))
    {
        fwrite(&Customer, sizeof(Customer), 1, fpCustomer);
    }
    fclose(fpCustomer);
    fclose(fpCustomer1);

    //printf("\nRECORD DELETED\n");
}

//Function to display all Records.

void displayAllRecords()
{
    FILE *fpCustomer;
    fpCustomer = fopen("bankCustomer.dat", "r");
    printf("\nAccount Number\tName\tBalance\n\n");
    while (fread(&Customer, sizeof(Customer), 1, fpCustomer))
    {
        printf("  %d\t\t%s\t%.2f\n", Customer.accountNumber, Customer.customerName, Customer.balance);
    }
    fclose(fpCustomer);
}
