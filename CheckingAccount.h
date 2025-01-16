//
// Created by harol rojas on 1/5/25.
//

#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"

class CheckingAccount: public Account {
private:
    int routingNumber;
    long accountNumber;

public:
    explicit CheckingAccount(std::string nameVal = "default", double balanceVal = 0, int routingNumber = 0, long accountNumber = 0);

    // copy
    CheckingAccount(const CheckingAccount &source);

    //destructor
    ~CheckingAccount();

    void setRoutingNumber(int r);
    void setAccountNumber(long a);
    [[nodiscard]] int getRoutingNumber() const;
    [[nodiscard]] long getAccountNumber() const;
    /*double getBalance();
    void deposit(double amount);
    void setName(std::string n);
    std::string getName();*/
};



#endif //CHECKINGACCOUNT_H
