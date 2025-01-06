//
// Created by harol rojas on 1/5/25.
//

/*
* this is the actual implementation of the "Account" class methods.
 * */

#include "Account.h"

// initialization list.
Account::Account(std::string nameVal, double balanceVal)
  : name(nameVal), balance(balanceVal), data(new int){}

// Copy constructor implementation.
Account::Account(const Account &source) : name(source.name), balance(source.balance) {
  std::cout << "Copy constructor called for: " << source.name << std::endl;
}

// Destructor implementation.
Account::~Account() {
  std::cout << "Account destructor called." << std::endl;
};



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

