//
// Created by harol rojas on 1/5/25.
//

#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(std::string nameVal, const double balanceVal ,const int routingNumber, const long accountNumber)
    : Account{std::move(nameVal), balanceVal}, routingNumber{routingNumber}, accountNumber{accountNumber} {
    std::cout << "CheckingAccount default constructor called!!" << std::endl;
}

CheckingAccount::CheckingAccount(const CheckingAccount &source)
    : Account {source}, routingNumber{source.routingNumber}, accountNumber{source.accountNumber} {
    std::cout << "CheckingAccount default constructor called!!" << std::endl;
}

CheckingAccount::CheckingAccount(CheckingAccount &&source) noexcept
    : Account {std::move(source)}{
    std::cout << "CheckingAccount Move constructor called!!" << std::endl;
    routingNumber = source.routingNumber;
    accountNumber = source.accountNumber;

    source.routingNumber = 0;
    source.accountNumber = 0;
}

CheckingAccount::~CheckingAccount() {
    std::cout << "CheckingAccount destructor called." << std::endl;
}

void CheckingAccount::setRoutingNumber(const int r) {
    routingNumber = r;
}

void CheckingAccount::setAccountNumber(const long a) {
    accountNumber = a;
}

int CheckingAccount::getRoutingNumber() const {
    return routingNumber;
}

long CheckingAccount::getAccountNumber() const {
    return accountNumber;
}

//overrides parent implementation.
void CheckingAccount::setDeposit(double amount) {
    std::cout << "CheckingAccount::setDeposit called." << std::endl;
    // subtracting 5% fee for checking account deposits.
    amount = amount - (amount * 0.05);
    // we can call the parent implementation so it can do its part.
    Account::setDeposit(amount);
}

void CheckingAccount::setName(std::string n) {
    std::cout << "CheckingAccount::setName called." << std::endl;
    n = "Checking Account: " + n;
    Account::setName(std::move(n));
}
