//
// Created by harol rojas on 1/5/25.
//

#include "CheckingAccount.h"

#include <utility>

CheckingAccount::CheckingAccount(std::string nameVal, const double balanceVal ,const int routingNumber, const long accountNumber)
    : Account{std::move(nameVal), balanceVal}, routingNumber{routingNumber}, accountNumber{accountNumber} {
    std::cout << "CheckingAccount default constructor called!!" << std::endl;
}

CheckingAccount::CheckingAccount(const CheckingAccount &source)
: Account {source}, routingNumber{source.routingNumber}, accountNumber{source.accountNumber} {
    std::cout << "CheckingAccount default constructor called!!" << std::endl;
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
