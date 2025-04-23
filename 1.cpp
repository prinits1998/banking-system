#include<iostream>
using namespace std;


class BankAccount
 {
protected:

    int accountnumber;
    string accountHolder;
    double accountBalance;

public:

    void setValues(int number, string holder, double balance)
    {
        accountnumber = number;
        accountHolder = holder;
        accountBalance = balance;
    }

    void deposit(double amount)
     {

        if (amount > 0) 
        {
            cout << accountBalance << " + " << amount << " = ";
            accountBalance += amount;
            cout << accountBalance << endl;
        } 

        else 
        {
            cout << "don't preess 0:" << endl;
        }
        
        cout << "----------------------------------------------" << endl;
    }


    void withdraw(double amount)
     {

        if (amount <= accountBalance) 
        {
            cout << accountBalance << " - " << amount << " = ";
            accountBalance -= amount;
            cout << accountBalance << endl;
        } 

        else 
        {
            cout << "Bouns Check:" << endl;
        }

        cout << "----------------------------------------------" << endl;
    }

    double getBalance() 
    {
        return accountBalance;
    }


    void displayInformation()
     {

        cout << "Account number: " << accountnumber << endl;
        cout << "Account holder name: " << accountHolder << endl;
        cout << "balance: " << accountBalance << endl;
        cout << "----------------------------------------------" << endl;
    }
};

class SavingAccount : public BankAccount
 {

    public:
           void calculateInterest(double rate) 
           {
             double interest = (getBalance() * rate) / 100;
             cout << "account interest: " << interest << endl;
             cout << getBalance() << " + " << interest << " = " << getBalance() + interest << endl;

             cout << "----------------------------------------------" << endl;

           }

};

class CheckingAccount : public BankAccount 
{
    public:
           void checkOverdraft(double withdrawAmount, double limit)
            {
               if (withdrawAmount <= getBalance() + limit) 
               { 
                  double remaining = withdrawAmount - (getBalance() + (getBalance() * 5) / 100); 
                  cout << withdrawAmount << " - " << (getBalance() + (getBalance() * 5) / 100) << " = " << remaining << endl;
               }
               else 
               {
                   cout << "the overdraft limit!!" << endl;
               }
              
               cout << "----------------------------------------------" << endl;
            }
};


class FixedDepositAccount : public BankAccount 
{
    public:
           void calculateInterest(double rate, double amount)
            {
               if (amount <= getBalance()) 
               {
                  int term;
                  cout << "Enter F.D.in months: ";
                  cin >> term;

                  double interest = (amount * rate * term) / 100;
                  cout << "F.D. interest: " << interest << endl;
                  cout << amount << " + " << interest << " = " << amount + interest << endl;
               }
               else 
               {
                  cout << "The F.D. amount in bank balance:" << endl;
               }

              cout << "----------------------------------------------" << endl;
           }
};


int main()
 {
    int accountNumber, option;
    string accountHolder;
    double Balance, amount, withdrawAmount, overdraftLimit;

    cout << "Enter account number: ";
    cin >> accountNumber;

    cout << "Enter account holder name: ";
    cin >> accountHolder;

    cout << "Enter account balance: ";
    cin >> Balance;

    SavingAccount savingAcc;
    savingAcc.setValues(accountNumber, accountHolder, Balance);
    
    CheckingAccount checkingAcc;
    FixedDepositAccount fixedAcc;

    do
     {
        cout << "1. Deposit amount\n2. Withdraw amount\n3. Display Account Info\n4. Saving Interest\n5. Check Overdraft\n6. Fixed Deposit Interest\n0. Exit\n";
        cout << "Enter your option: ";
        
        cin >> option;

        switch (option)
        {
            case 1:
                   cout << "Enter deposit amount: ";
                   cin >> amount;

                   savingAcc.deposit(amount);
            break;

            case 2:
                   cout << "Enter withdraw amount: ";
                   cin >> amount;

                   savingAcc.withdraw(amount);
            break;

            case 3:
                   savingAcc.displayInformation();
            break;

            case 4:
                   savingAcc.calculateInterest(5); 
            break;

            case 5: 
                   checkingAcc.setValues(accountNumber, accountHolder, savingAcc.getBalance());
                   cout << "Enter overdraft limit: ";

                   cin >> overdraftLimit;
                   cout << "Enter withdrawal amount: ";

                   cin >> withdrawAmount;
                   checkingAcc.checkOverdraft(withdrawAmount, overdraftLimit);
            break;

            case 6: 
                   fixedAcc.setValues(accountNumber, accountHolder, savingAcc.getBalance());
                   cout << "Enter F.D. amount: ";

                   cin >> amount;
                   fixedAcc.calculateInterest(7, amount); 
            break;

            case 0:
                   cout << "Thank you..." << endl;
            break;

            default:
                   cout << "Invalid option" << endl;
            break;
        }

    } while (option != 0);

}
