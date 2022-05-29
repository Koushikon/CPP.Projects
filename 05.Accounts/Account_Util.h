#ifndef _ACCOUNT_Util_H_
#define _ACCOUNT_Util_H_

#include<vector>

#include "Account.h"
#include "SavingAccount.h"

using std::vector;

// Utility helper function for Account class
void Display(const vector<Account> &accounts);
void Deposit(vector<Account> &accounts, double amount);
void Withdraw(vector<Account> &accounts, double amount);

// Utility helper function for SavingAccount class
void Display(const vector<SavingAccount> &accounts);
void Deposit(vector<SavingAccount> &accounts, double amount);
void Withdraw(vector<SavingAccount> &accounts, double amount);

#endif