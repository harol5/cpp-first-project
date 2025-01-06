//
// Created by harol rojas on 1/5/25.
//

#include <string>
using namespace std;

/*
 * .h files are used (in class context), to create the specificition of a class.
 * specific implementations of each methos will be dome on a cpp file.
 *
 * the "#ifndef", "#define", and "#endif" directives are used to make sure the header file is only process once when
 * multiple #include "Account.h" are present in multiple cpp files.
 *
 * some compilers support the "#pragma once" directive which could be used instead of the previous ones.
 *
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
private:
    string name;
    double balance;

public:
    Account(std::string nameVal = "default", double balanceVal = 0);
    double getBalance();
    void deposit(double amount);
    void setName(string name);
    std::string getName();
};

#endif //ACCOUNT_H
