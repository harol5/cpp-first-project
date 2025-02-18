//
// Created by harol rojas on 1/5/25.
//

#include <iostream>
#include <ostream>
#include <string>

/*
 * .h files are used (in class context), to create the specification of a class.
 * specific implementations of each method will be done on a cpp file.
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
    std::string name;
    double balance;

protected:
    int test {0};
public:
    /*
     * default values constructor.
     *
     * Constructor Initialization list.
     * for best practices when passing value to constructors see AI chat "C++ Initialization Syntax Explained in Detail"
     * "pass-by-value and move" idiom
     */
    explicit Account(std::string nameVal = "default", double balanceVal = 0);
    // Copy constructor.
    Account(const Account &source);
    // Move constructor. -> move resources on the heap. more efficient.
    Account(Account &&source) noexcept;
    // Destructor.
    virtual ~Account();

    // COPY ASSIGNMENT OPERATOR OVERLOAD
    Account &operator=(const Account &source);
    // MOVE ASSIGNMENT OPERATOR OVERLOAD
    Account &operator=(Account &&source) noexcept;

    void setDeposit(double amount);
    virtual void setName(std::string n);


    // CONST CORRECTNESS
    [[nodiscard]] const std::string &getName() const;
    [[nodiscard]] double getBalance() const;
    double withdraw(double amount);

    static int getCount(); // because this method is static, it only has access to static members.
};

#endif //ACCOUNT_H
