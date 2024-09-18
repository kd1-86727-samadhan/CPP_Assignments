#include <iostream>
using namespace std;

double amount = 0;
enum EAccountType
{
    EXIT,
    SAVING,
    CURRENT,
    DMAT
};

class InSufficientFundsException
{
    int accno;
    double currentBalance;
    double withdrawAmount;
    string message;

public:
    InSufficientFundsException()
    {
        message = "Some exception occured";
    }

    InSufficientFundsException(int accno, double currentBalance, string message)
    {
        this->accno = accno;
        this->currentBalance = currentBalance;
        this->message = message;
    }

    void display()
    {
        cout << "\nExcpetion: InSufficientFundsException";
        cout << "\nAccount number: " << this->accno;
        cout << "\nCurrent Balance: " << this->currentBalance;
        cout << "\nMessage: " << this->message;
    }
};  // InSufficientFundsException

class Account
{
    int accno;
    EAccountType e;
    double balance;

public:
    Account()
    {
        // cout << "\nAccount()";
        this->accno = 0;
        this->balance = 0;
    }

    Account(int accno, EAccountType e, double bal)
    {
        this->accno = accno;
        this->e = e;
        this->balance = bal;
    }

    void accept()
    {
        int choice;
        cout << "\nEnter the account number: ";
        cin >> this->accno;
        cout<<"\n****Menu****";
        cout << "\n1. Saving";
        cout << "\n2. Current";
        cout << "\n3. DMAT";
        cout<<"\nChoose the account type: ";
        cin >> choice;
        e = EAccountType(choice);
        cout << "\nEnter the balance: ";
        cin >> this->balance;
    }

    void display()
    {
        cout<<"\n*********************************************";
        cout<<"\nAccount no: "<<this->accno;
        cout<<"\nAccount Balance: "<<this->balance;
        switch(e)
        {
            case SAVING:
                {
                    cout<<"\nAccount Type: Saving";
                }
                break;
                
            case CURRENT:
                {
                    cout<<"\nAccount Type: Current";
                }
                break;
            
            case DMAT:
                {
                    cout<<"\nAccount Type: DMAT";
                }
                break;

        }   // switch
        cout<<"\nBalance: "<<this->balance;
        cout<<"\n*********************************************";
    }

    void deposit()
    {
        cout<<"\nEnter the amount: ";
        cin>>amount;

        if (amount < 0)
        {
            throw InSufficientFundsException(accno, balance,"\nCan not deposit amount less than or equal to zero");
        }
        else
        {
            balance = balance + amount;
            cout << "\nUpdated Balance: " << balance;
        }
    }

    void withdraw()
    {
        cout<<"\nEnter the amount: ";
        cin>>amount;

        if (amount > balance)
        {
            throw InSufficientFundsException(accno, balance, "Insufficient balance can not withdraw money !!!!");
        }
        else
        {
            balance = balance - amount;
            cout << "\nUpdated Balance: " << balance;
        }
    }

    void checkBalance()
    {
        cout<<"\n******************";
        cout<<"\n*Balance: "<<this->balance <<"*";
        cout<<"\n******************";
    }
}; // Account

int main()
{
    Account *account[5];
    int index = 0;
    int choice;

    do
    {
        cout<<"\n**********Menu**********";
        cout<<"\n*   0. Exit            *";
        cout<<"\n*   1. Add Account     *";
        cout<<"\n*   2. Display Account *";
        cout<<"\n*   3. Deposit         *";
        cout<<"\n*   4. Withdraw        *";
        cout<<"\n*   5. Check Balance   *";
        cout<<"\n************************";
        cout<<"\n\nEnter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 0:
                {
                    cout<<"\nThank for using our app !!!!";
                }
                break;
                
            case 1:
                {
                    if(index < 3)
                    {
                        account[index] = new Account;
                        account[index]->accept();
                    }
                }
                break;

            case 2:
                {
                    account[index]->display();
                }
                break;
            
            case 3:
                {
                    try
                    {
                        account[index]->deposit();
                    }
                    catch(InSufficientFundsException insfe)
                    {
                        insfe.display();
                    }
                }
                break;
            
            case 4:
                {
                    try
                    {
                        account[index]->withdraw();
                    }
                    catch(InSufficientFundsException insfe)
                    {
                        insfe.display();
                    }
                }
                break;

                case 5:
                    {
                        account[index]->checkBalance();
                    }
                    break;  

                default:
                    cout<<"\nInvalid Choice !!!!";
                    break;    
        }   // switch
    }while(choice != 0);
    return 0;
}