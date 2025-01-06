//
// Created by harol rojas on 1/5/25.
//

#include "CheckingAccount.h"

double CheckingAccount::getBalance() {
  return balance;
}

void CheckingAccount::deposit(double amount) {
  balance += amount;
}

void CheckingAccount::setName(std::string n) {
  name = n;
}

std::string CheckingAccount::getName() {
  return name;
}