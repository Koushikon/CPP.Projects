#include "account.h"
#include <iostream>

using std::cout;
using std::endl;

void withdraw_status(bool wd_status);

void withdraw_status(bool wd_status, double &bal)
{
    if (wd_status == false)
        cout << bal << " Balance Insufficient, Can't possible" << endl;
    else
        cout << "Successfully withdrawal money " << bal << endl;
}

int main()
{
    Account frank_ac;
    Account *mary_ac = new Account;

    frank_ac.set_balance(40000);
    mary_ac->set_balance(500);
    cout << "Current balance Frank's " << frank_ac.get_balance() << endl;
    cout << "Current balance Mary's " << mary_ac->get_balance() << endl;

    frank_ac.deposit(400.00);
    cout << "After deposit " << 400.00 << " Current balance Frank's " << frank_ac.get_balance() << endl
         << endl;

    bool status{};
    double bal{500.00};

    status = frank_ac.withdraw(bal);
    withdraw_status(status, bal);

    bal = 1500.00;
    status = mary_ac->withdraw(1500.00);
    withdraw_status(status, bal);

    bal = 150.00;
    status = mary_ac->withdraw(150.00);
    withdraw_status(status, bal);
    cout << "Current balance Frank's " << frank_ac.get_balance() << endl;
    cout << "Current balance Mary's " << mary_ac->get_balance() << endl
         << endl;

    delete mary_ac; // Releasing the mary_ac

    return 0;
}
