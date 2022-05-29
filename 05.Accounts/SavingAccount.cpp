#include "SavingAccount.h"

std::ostream &operator<<(std::ostream &os, const SavingAccount &s_acc)
{
    os << "And the salary goes to: " << s_acc.Name << " and he got " << s_acc.Balance << " dollers. with interest rate of " << s_acc <<"%" << endl;
    return os;
}

SavingAccount::SavingAccount(string pname, double pbal, double pintRate)
    : Account{pname, pbal}, IntRate{pintRate}
{
    // cout << "Saving Account Constructor." << endl;
}

bool SavingAccount::Deposit(double amount)
{
    amount += amount * (IntRate / 100);
    return Account::Deposit(amount);
}