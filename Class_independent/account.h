#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
    double balance;
public:
    void set_balance(double bal);
    double get_balance();
    void deposit(double bal);
    bool withdraw(double bal);
};

#endif // ACCOUNT_H
