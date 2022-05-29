#include "Account_Util.h"

// Utility helper function Implementation for Account class
void Display(const vector<Account> &accounts)
{
    for (const Account &acc : accounts)
        cout << acc << endl;
}

void Deposit(vector<Account> &accounts, double amount)
{
    for (Account &acc : accounts)
    {
        if (acc.Deposit(amount))
            cout << "Deposited " << amount << " to, " << acc << endl;
        else
            cout << "Failed Deposited of " << amount << " to, " << acc << endl;
    }
}

void Withdraw(vector<Account> &accounts, double amount)
{
    for (Account &acc : accounts)
    {
        if (acc.Withdraw(amount))
            cout << "Withdraw " << amount << " from, " << acc << endl;
        else
            cout << "Failed Withdraw of " << amount << " from, " << acc << endl;
    }
}

// Utility helper function Implementation for SavingAccount class

void Display(const vector<SavingAccount> &accounts)
{
    for (const Account &acc : accounts)
        cout << acc << endl;
}

void Deposit(vector<SavingAccount> &accounts, double amount)
{
    for (Account &acc : accounts)
    {
        if (acc.Deposit(amount))
            cout << "Deposited " << amount << " to, " << acc << endl;
        else
            cout << "Failed Deposited of " << amount << " to, " << acc << endl;
    }
}

void Withdraw(vector<SavingAccount> &accounts, double amount)
{
    for (Account &acc : accounts)
    {
        if (acc.Withdraw(amount))
            cout << "Withdraw " << amount << " from, " << acc << endl;
        else
            cout << "Failed Withdraw of " << amount << " from, " << acc << endl;
    }
}