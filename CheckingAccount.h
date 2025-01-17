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
    // move
    CheckingAccount(CheckingAccount &&source) noexcept;
    //destructor
    virtual ~CheckingAccount();

    // own methods.
    void setRoutingNumber(int r);
    void setAccountNumber(long a);
    [[nodiscard]] int getRoutingNumber() const;
    [[nodiscard]] long getAccountNumber() const;

    //override
    void setDeposit(double amount);
    virtual void setName(std::string n) override;
};



#endif //CHECKINGACCOUNT_H
