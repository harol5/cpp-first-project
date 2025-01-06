//
// Created by harol rojas on 1/5/25.
//

/*
* this is the actual implementation of the "Account" class methods.
 * */

#include "Account.h"

// initialization list.
Account::Account(std::string nameVal, double balanceVal): name(nameVal), balance(balanceVal){}

double Account::getBalance() {
  return balance;
}

void Account::deposit(double amount) {
  balance += amount;
}

void Account::setName(std::string n) {
  name = n;
}

std::string Account::getName() {
  return name;
}

