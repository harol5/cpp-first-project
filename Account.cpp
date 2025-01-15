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

/*
 * Constructor Initialization list.
 * for best practices when passing value to constructors see AI chat "C++ Initialization Syntax Explained in Detail".
*  "pass-by-value and move" idiom
 */
Account::Account(std::string nameVal, double balanceVal)
  : name(std::move(nameVal)), balance(balanceVal) {
  std::cout << "default constructor called for: " << nameVal << std::endl;
  ++count; // updating static member count everytime a new object is created.
}

// Copy constructor implementation. (shallow).
Account::Account(const Account &source) : name(source.name), balance(source.balance) {
  std::cout << "Copy constructor called for: " << source.name << std::endl;
  ++count; // updating static member count everytime a new object is copied.
}

Account::Account(Account &&source) noexcept {
  std::cout << "Move constructor called for: " << source.name << std::endl;
  name = std::move(source.name);
  balance = std::move(source.balance);
  ++count; // updating static member count everytime a new object is moved.
}

// Destructor implementation.
Account::~Account() {
  --count; // updating static member count everytime a new object is destroyed.
  std::cout << "Account destructor called." << std::endl;
};

// CONST CORRECTNESS
const std::string &Account::getName() const {
  return name;
}

double Account::getBalance() const {
  return balance;
}

void Account::deposit(double amount) {
  balance += amount;
}

void Account::setName(std::string n) {
  name = n;
}

// COPY ASSIGNMENT OPERATOR OVERLOAD
Account &Account::operator=(const Account &source) {
  std::cout << "Copy assignment operator called for: " << source.name << std::endl;
  if (this == &source) {
    return *this;
  }

  name = source.name;
  balance = source.balance;
  return *this;
}

// MOVE ASSIGNMENT OPERATOR OVERLOAD
Account &Account::operator=(Account &&source) noexcept {
  std::cout << "Move assignment operator called for: " << source.name << std::endl;
  name = std::move(source.name);
  balance = std::move(source.balance);
}





