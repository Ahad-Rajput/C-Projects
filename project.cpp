#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int Max_Accounts = 50;

string accountHolder[Max_Accounts];
int accountNum[Max_Accounts];
double balance[Max_Accounts];

int numAccounts = 0;

void createAccount();
int findAccount(int searchAccountNum);
void checkBalance();
void deposit();
void withdraw();
void deleteAccount();

void displayMenu()
{
    cout << "\n-------> Welcome to ABC Bank <-------\n\n";
    cout << "1. Create Account\n";
    cout << "2. Check Balance\n";
    cout << "3. Deposit\n";
    cout << "4. Withdraw\n";
    cout << "5. Delete Account\n";
    cout << "6. Exit\n";
    cout << "\n-------------------------------------------\n\n";
}

int main()
{
    int choice;
    do
    {
        displayMenu();

        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createAccount();
            break;
        case 2:
            checkBalance();
            break;
        case 3:
            deposit();
            break;
        case 4:
            withdraw();
            break;
        case 5:
            deleteAccount();
            break;
        case 6:
            cout << "---> Exiting the Program.\nThank you for using ABC Bank Management...\n";
            break;
        
        default:
            cout << "Invalid choice. Please try again\n";
            break;
        }
    } while (choice != 6);
    return 0;   
}

void createAccount()
{
    if (numAccounts < Max_Accounts)
    {
        cout << "Enter Account Holder's name : ";
        cin.ignore();
        getline(cin, accountHolder[numAccounts]);

        cout << "Enter Initial Amount : ";
        cin >> balance[numAccounts];

        accountNum[numAccounts] = 201 + numAccounts;

        cout << ".........................................\n";
        cout << "Your Account is successfully created...\nYour Account Number is " << accountNum[numAccounts] << endl;

        numAccounts++;
    }
    else
    {
        cout << "Sorry, We can't create your account as We reached Maximum limit.\n";
    }
}

int findAccount(int searchAccountNum)
{
    for (int i = 0; i < numAccounts; i++)
    {
        if (accountNum[i] == searchAccountNum)
        {
            return i;  // Account found, return its index
        }
    }
    return -1;  // Account not found
}

void checkBalance()
{
    int searchAccountNum;
    cout << "Enter your account number : ";
    cin >> searchAccountNum;

    int index = findAccount(searchAccountNum);
    if (index != -1)
    {
        cout << "\nAccount Holder's name : " << accountHolder[index] << endl << endl;
        cout << "Account Number : " << accountNum[index] << endl << endl;
        cout << "Balance : "<< fixed << setprecision(2) << balance[index] << endl << endl;
    }
    else
    {
        cout << "Account not found.\n";
    }  
}

void deposit()
{
    int searchAccountNum;
    cout << "Enter your Account number : ";
    cin >> searchAccountNum;

    int index = findAccount(searchAccountNum);
    if (index != -1)
    {
        int amount;
        cout << "\nHello, " << accountHolder[index] << endl << endl;
        cout << "Enter the amount , You want to deposit : ";
        cin >> amount;

        balance[index] += amount;
        cout << "Deposit Successfully...\nUpdated Balance : " << fixed << setprecision(2) << balance[index] << endl;
    }
    else
    {
        cout << "Account not found.\n";
    }
}
    
void withdraw()
{
    int searchAccountNum ;
    cout << "Enter your Account number : ";
    cin >> searchAccountNum;

    int index = findAccount(searchAccountNum);
    if (index != -1)
    {
        int amount;
        cout << "\nHello " << accountHolder[index] << endl << endl;
        cout << "Enter the amount , You want to withdraw : ";
        cin >> amount;

       if (amount < balance[index])
       {
        balance[index] -= amount;
        cout << "Withdrawal successful...\nRemaining Balance : " << fixed << setprecision(2) << balance[index] << endl;
       }
       else
       {
        cout << "Insufficient Balance! Withdrawal not allowed.\n";
       }
    }
    else
    {
        cout << "Account not found";
    }
}

void deleteAccount()
{
    int searchAccountNum;
    cout << "Enter the account number : ";
    cin >> searchAccountNum;

    int index = findAccount(searchAccountNum);

    if(index != -1)
    {
        accountHolder[index] = "";
        balance[index] = 0;
        cout << "Account successfully deleted.\n";
    }
    else
    {
        cout << "Account not found.\n";
    }
}