//
// Created by harol rojas on 1/5/25.
//

#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include <string>

class CheckingAccount {
private:
    std::string name;
    double balance;

public:
    double getBalance();
    void deposit(double amount);
    void setName(std::string n);
    std::string getName();
};



#endif //CHECKINGACCOUNT_H
