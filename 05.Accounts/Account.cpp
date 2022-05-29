#include "Account.h"

std::ostream &operator<<(std::ostream &os, const Account &acc)
{
    os << "And the salary goes to: " << acc.Name << " and he got " << acc.Balance << " dollers." << endl;
    return os;
}

Account::Account(std::string pname, double pbal) : Name{pname}, Balance{pbal}
{
    // cout << "Account Constructor." << endl;
}

bool Account::Deposit(double amount)
{
    if (amount < 0)
    {
        cout << "You Cannot Deposit Minus Amount." << endl;
        return false;
    }
    else
    {
        Balance += amount;
        return true;
    }
}

bool Account::Withdraw(double amount)
{
    if (Balance - amount > 0)
    {
        Balance -= amount;
        return true;
    }
    {
        cout << "Balance Unsufficient." << endl;
        return false;
    }
}

double Account::GetBalance() const
{
    return Balance;
}