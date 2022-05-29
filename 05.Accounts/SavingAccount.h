#ifndef _SAVING_ACCOUNT_H_
#define _SAVING_ACCOUNT_H_

#include "Account.h"

class SavingAccount : public Account
{
private:
    friend std::ostream &operator<<(std::ostream &os, const SavingAccount &s_acc);
    static constexpr const char *_defName = "Unname_Account";
    static constexpr double _defBalance = 0.0;
    static constexpr double _defIntRate = 0.0;

protected:
    double IntRate;

public:
    SavingAccount(string pname = _defName, double pbal = _defBalance, double pintRate = _defIntRate);
    bool Deposit(double amount);
    // Inherits the Withdraw methof of Account Class
};

#endif