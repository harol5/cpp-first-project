//
// Created by harol rojas on 1/5/25.
//

/*
* this is the actual implementation of the "Account" class methods.
 * */

#include "Account.h"

// initializing static member.
int Account::count = 0;
int Account::getCount() {
  return count;
}

// initialization list.
Account::Account(std::string nameVal, double balanceVal)
  : name(nameVal), balance(balanceVal) {
  ++count; // updating static member count everytime a new object is created.
}

// Copy constructor implementation. (shallow).
Account::Account(const Account &source) : name(source.name), balance(source.balance) {
  std::cout << "Copy constructor called for: " << source.name << std::endl;
  ++count; // updating static member count everytime a new object is copied.
}

// Destructor implementation.
Account::~Account() {
  --count; // updating static member count everytime a new object is destroyed.
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



