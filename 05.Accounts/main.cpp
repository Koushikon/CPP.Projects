#include <iostream>
#include <vector>
#include "Account.h"
#include "SavingAccount.h"
#include "Account_Util.h"

using namespace std;

int main()
{
    cout.precision(2);
    cout << fixed;

    // Accounts
    vector<Account> accounts;
    accounts.push_back(Account{});
    accounts.push_back(Account{"Marry"});
    accounts.push_back(Account{"Jhony", 1700.00});
    accounts.push_back(Account{"Beats", 25600.50});

    Display(accounts);
    Deposit(accounts, 500.12);
    Withdraw(accounts, 780.00);

    // Saving Accounts
    vector<SavingAccount> sav_accounts;
    sav_accounts.push_back(SavingAccount{});
    sav_accounts.push_back(SavingAccount{"Marry"});
    sav_accounts.push_back(SavingAccount{"Jhony", 1700.00});
    sav_accounts.push_back(SavingAccount{"Beats", 25600.50, 7.25});

    Display(sav_accounts);
    Deposit(sav_accounts, 500.12);
    Withdraw(sav_accounts, 780.00);

    return 0;
}
