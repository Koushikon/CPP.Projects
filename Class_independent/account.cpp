#include "account.h"

void Account::set_balance(double bal){
    balance += bal;
}

double Account::get_balance(){
    return balance;
}

void Account::deposit(double bal){
    balance += bal;
}

bool Account::withdraw(double bal){
    if (bal > balance)
        return false;
    balance -= bal;
    return true;
}
