#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Account
{
private:
    friend std::ostream &operator<<(std::ostream &os, const Account &acc);
    static constexpr const char *_defName = "Unname_Account";
    static constexpr double _defBalance = 0.0;

protected:
    string Name;
    double Balance;

public:
    Account(string pname = _defName, double pbal = _defBalance);
    bool Deposit(double amount);
    bool Withdraw(double amount);
    double GetBalance() const;
};

#endif