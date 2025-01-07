//
// Created by harol rojas on 1/5/25.
//

#include <iostream>
#include <ostream>
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
    static int count; // this belongs to the class, not objects. and will be initialized on the cpp file.
    string name;
    double balance;
public:
    // default values constructor.
    Account(std::string nameVal = "default", double balanceVal = 0);
    // Copy constructor.
    Account(const Account &source);
    // Move constructor. -> move resources on the heap. more efficient.
    Account(Account &&source) noexcept;
    // Destructor.
    ~Account();

    double getBalance();
    void deposit(double amount);
    void setName(string name);
    std::string getName();

    static int getCount(); // because this method is static, it only has access to static members.
};

#endif //ACCOUNT_H
