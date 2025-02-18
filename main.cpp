#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "Account.h"
#include "Deep.h"
#include "CheckingAccount.h"
#include "Shape.h"
#include "ClosedShape.h"
#include "Circle.h"

/*
 * throughout this file, we'll see the namespace "std" use a lot.
 * you can use the statement "using namespace std;" instead. you cal do this with
 * any other namespace as well.
 */
using namespace std;


/* ==========================================
 * c++ feature only: namespaces, cout,cin and "<<" , ">>" operators.
 */
void ioTools() {
    int myNumber;
    std::cout << "Enter a number: ";
    std::cin >> myNumber;
    std::cout << "You entered " << myNumber << std::endl;

    float locationX = 134.232;
    double locationY = 123.232;
    long double locationZ = 123.232;

    std::cout << "size of float is: " << sizeof(locationX) << std::endl;
    std::cout << "size of double is: " << sizeof(locationY) << std::endl;
    std::cout << "size of long double is: " << sizeof(locationZ) << std::endl;

    const unsigned int age = 30;
    std::cout << "age is: " << age << std::endl;
}

void arrays() {
    /*
     * just like C, even pointer arithmetic.
     */

    int ages[] {50,34,78,21};

    std::cout << "size of array is: " << sizeof(ages) << std::endl;
    std::cout << "size of int pointer is: " << sizeof(&ages) << std::endl;
    std::cout << "length of array is: " << sizeof(ages) / sizeof(*ages) << std::endl;

    for (int i = 0; i < std::size(ages); i++) {
        std::cout << "ages at index " << i << " is: " << *(ages + i) << std::endl;
    }

    int building[10][5][20];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 20; k++) {
                int valueJ = 2;
                int valueI = 1;
                int valueK = 3;
                *(*(*(building + i) + j) + k) = valueI * valueJ * valueK;
                std::cout << "building at index " << i << " " << j << " " << k << " is: " << building[i][j][k] << std::endl;
            }
        }
    }


    Account accounts[10]; // this initializes all the 10 Account objects calling the default constructor.
    for (int i = 0; i < 10; i++) {
        accounts[i] = Account{std::to_string(i), 100.0};
        std::cout << "accounts at index " << i << " is: " << accounts[i].getName() << std::endl;
    }
}

/* ==========================================
 * c++ feature only: vectors (like ArrayList in java).
 */
void vectorPractice () {
    // like ArrayList in java.

    // vector initialization with specific size.
    std::vector<char> vowels (26);

    // vector initialization with specific size and value.
    std::vector highTemperatures (365, 80.0);

    // vector initialization with specific values.
    std::vector<int> ages {50,34,78,21};

    // adds at the end of the vector.
    vowels.push_back('a');

    // this is how you create 2d vectors.
    vector<vector<int>> matrix (3, vector<int> (3));

    vector<Account> accounts (10, Account{});
}

/* ==========================================
 * c++ feature only: strings like most programmin languages.
 *
 * CONST
 */
void stringPractice () {
    const string name {"harol"};
    const string lastName = {"rojas perez", 5};
    const int age = 30;

    // string concatenation.
    string fullName = name + " " + lastName;
    fullName += " " + to_string(age);

    // I had to add the const keyword because the variable im referencing is a constant variable.
    // that "const" DOES NOT MAKE THE ACTUAL POINTER CONSTANT.
    const string *p_name = &name;
    const int *p_age = &age;

    // LOOK!!, I was able to change the value of the pointer (memory address).
    p_name = &lastName;

    // This is how you declare a pointer constant that points to a variable (in this case string type);
    // BUT!! take a look at the fullname variable, when it was declared, "const" keyword was not used. but by adding the "const string"
    // it made the variable read-only if access from the pointer
    const string *const p_fullName = &fullName;
    // (*p_fullName) = "juan"; // error.
    /*p_fullName = &lastName;*/ // error.

    cout << "mem addr name: " << p_name << endl;
    cout << "mem addr name: " << &name << endl;
}

/* ==========================================
 * c++ feature only: new ways to declare variables.
 *
 * see AI chat "C++ Initialization Syntax Explained in Detail"
 */
void variableDeclarations () {
    int a {45}; // preferred!!
    int b (45);
    int c = 45;
}

unsigned long long int factorial (unsigned long long int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

/* ==========================================
 * c++ feature only: new way to allocate and free memory.
 *
 * CONST
 */
void pointersAndMemAllocation () {
    int a {45};
    cout << "a is: " << &a << endl;

    int *p_a {&a};
    cout << "p_a is: " << &p_a << endl;

    // "new" -> malloc();
    int *p_b = new int;
    *p_b = 45;
    // "delete" -> free();
    delete p_b;

    // with arrays.
    int *p_ages {nullptr};
    p_ages = new int[10];
    for (int i = 0; i < 10; i++) {
        *(p_ages + i) = i;
        cout << "p_ages at index " << i << " is: " << *(p_ages + i) << endl;
    }
    delete p_ages;

    // constants and pointers.
    int highScore {100};
    int lowScore {10};
    const int *p_score {&highScore}; // dereferencing this pointer and trying to change the value will be not allowed.
    /**p_score = 45;*/ // error.
    p_score = &lowScore; // ok.

    int *const p_const_score {&highScore}; // with this syntax now the pointers can not be change.
    /*p_const_score = &lowScore;*/ // error.
}

/* ==========================================
 * c++ feature only: references variable with "&".
 */
void rValueReferences () {
    int a {1};
    int &r_a {a}; // alias. not present in C
    int *p_a {&a};
}

/* ==========================================
 * c++ feature only: rvalues and lvalues.
 */
void rvaluesAndLvalues () {
    // a is an lvalue (locator value) because it is addressable.
    int a{};
    // 23 is a rvalue (right value) because it can not be addressed, persisted or assigned.
    a = 23;

    // lvalue references(&) can only be used with lvalues;
    int &r_a {a};
    /*int &r_b {45};*/ // ERROR!!

    // you can use rvalue references(&&) if you want to make a reference to a rvalue ONLY!!.
    int &&r_rvalue {23};
    /*int &&r_rvalue_2 {a};*/ // ERROR!!

    int &r_rvalue_ref {r_rvalue};
}

/* ==========================================
 * c++ feature only: OOP Classes.
 */
class Person {
    private:
        string name;
        int age;
    public:
        /*
         * Constructor Initialization list.
         * for best practices when passing value to constructors see AI chat "C++ Initialization Syntax Explained in Detail"
         * "pass-by-value and move" idiom
         */
        Person(): name ("default"), age (0) {};
        Person(string name, const int age): name (std::move(name)), age (age) {};

        // const correctness. see AI chat "returning conts references from object methods" for more info.
        int getAge () const {
            return this->age;
        }

        // const correctness. see AI chat "returning conts references from object methods" for more info.
        const string &getName () const {
            return this->name;
        }

        void printInfo () {
            cout << "name is: " << this->name << endl;
            cout << "age is: " << this->age << endl;
        }
};

// testing the static member "count" of the Account class.
void displayActiveAccounts () {
    cout << "--- displayActiveAccounts called!!: active accounts: " << Account::getCount() << endl;
}

/* ==========================================
 * c++ feature only: Function parameters types.
 *
 * understanding const, Lvalues and Rvalues in function parameters.
 */

/*
 * this function takes Rvalue and Lvalues;
 * argument passed by Lvalue const reference (read only)
 */
void displayAccountInfo (const Account &account) {
    cout << "--- ----------------- displayAccountInfo function called: by const Lvalue reference. (read) no constructors called ===" << endl;
    displayActiveAccounts();

    // CONST CORRECTNESS -> because on the scope of this function the account variable is constant.
    // any method belonging to the class must have the "const" keyword before the curly braces
    // to indicate to the compiler that this method, DOES NOT CHANGE the internal state of the object.
    cout << "account name is: " << account.getName() << endl;
    cout << "account balance is: " << account.getBalance() << endl;
    cout << "--- ----------------- done ---------------------------- ---" << endl;
}

// argument passed by Lvalue reference (modify)
void changeBalanceAccount (Account &account) {
    cout << "--- ----------------- changeBalanceAccount function called: by Lvalue reference. (modify) no constructors called ===" << endl;
    cout << "account name is: " << account.getName() << endl;
    cout << "account balance is: " << account.getBalance() << endl;
    displayActiveAccounts();
    account.setDeposit(account.getBalance() + 2000);
    cout << "--- ----------------- done ---------------------------- ---" << endl;
}

// argument pass by value (copy)
void estimateBalanceAccount (Account account) {
    cout << "--- ----------------- estimateBalanceAccount function called: value. (copy) copy constructors called ===" << endl;
    cout << "account name is: " << account.getName() << endl;
    cout << "account balance is: " << account.getBalance() << endl;
    displayActiveAccounts();
    double ownedFees = 200.56;
    account.setDeposit(account.getBalance() - ownedFees);
    cout << "balance is after paying fees: " <<  account.getBalance()  << endl;
    cout << "--- ----------------- done ---------------------------- ---" << endl;
}

// argument passed by Rvalue reference.
void saveAccountOnTheFly (Account &&account) {
    cout << "--- ----------------- saveAccountOnTheFly function called: by Rvalue reference. move constructors called ===" << endl;
    cout << "account name is: " << account.getName() << endl;
    cout << "account balance is: " << account.getBalance() << endl;
    displayActiveAccounts();

    /*
     * IMPORTANT OBSERVATION!!
     *
     * the "account" parameter is a Rvalue reference type, meaning it points to a Rvalue, so you might think
     * I can just initialize a variable with it and the move constructor will be called because it is a Rvalue reference
     * BUT NO!!!! the "account" variable itself is a Lvalue, because it has a name. so if we do not use std::move,
     * it will call the copy constructor instead.
     *
     * e.g. const Account copyAccount = account; -> copy constructor is called.
     *
     * so we need to cast the Lvalue to an actual Rvalue so the move constructor can actually be used.
     */
    const Account movedAccount = std::move(account); // without this, the move constructor is not called

    displayActiveAccounts();
    cout << "name is: " << movedAccount.getName() << endl;
    cout << "--- ----------------- done ---------------------------- ---" << endl;
}

/* ==========================================
 * c++ feature only: Classes and function parameters.
 *
 * Practicing function and classes.
 *
 * Move Copy constructors.
 */
void practicingClasses () {
    Person p1 {"harol", 30}; // was this created on the stack or heap? -> on the stack
    p1.printInfo();

    Person *p2 = new Person {"juan", 30}; // heap allocation
    p2->printInfo(); // arrow operator. use when dealing with pointers.

    Person *p3 = new Person {"gloria", 30};
    (*p3).printInfo(); // dereferencing, then accessing member with dot operator.

    Person *p4 = new Person ("maria", 30);
    (*p4).printInfo();

    Account p1Accounts {p1.getName(),100.67};
    displayAccountInfo(p1Accounts); // Lvalue (locator value)
    Account &r_p1Accounts = p1Accounts; // Lvalue reference
    displayAccountInfo(r_p1Accounts);

    Account p2Accounts { p2->getName(),200.67};
    displayAccountInfo(p2Accounts); // Lvalue (locator value)

    Account newAccount; // initialize with default values.
    displayAccountInfo(newAccount); // Lvalue (locator value)

    // -- testing the static member "count" of the Account class.
    displayActiveAccounts();

    // Rvalue because even thought the param is a Lvalue reference, it has the const keyword which does not allow to modify the object.
    displayAccountInfo(Account{"Rvalue to Lvalue const reference param",999.99});

    // -- this function takes Rvalues as arguments only.
    saveAccountOnTheFly(Account{"Rvalue to Rvalue reference param",888.88});
    /*saveAccountOnTheFly(p2Accounts);*/ // ERROR!! because p2Accounts is a Lvalue.
    saveAccountOnTheFly(std::move(p2Accounts)); // I used the std::move so the Lvalue is cast to a Rvalue.

    // -- this function takes Lvalues only;
    changeBalanceAccount(newAccount);
    displayAccountInfo(newAccount); //checking that the original object was actually updated.

    // -- here we are testing how c++ makes copies of object by calling the copy constructor.
    estimateBalanceAccount(newAccount);
    Account p1AccountsCopy {p1Accounts}; // new - prefer!!
    Account p1AccountsCopy2 (p1Accounts); // new
    Account newAccountsCopy = newAccount; // old. here Im not assigning, I'm initializing.

    // testing the static member "count" of the Account class.
    displayActiveAccounts();

    // cleaning
    delete p2;
    delete p3;
    delete p4;
}

/* ==========================================
 * c++ feature only: operator overloading.
 *
 * --- Copy and move assignment operators overload.
 * - difference between initializing and assigning.
 */
void assignmentOperator () {
    // ------- COPY ASSIGNMENT----------
    cout << "--- ----------------- copy assignment operator test ---------------" << endl;
    Account account1 {"name1", 100.0}; // initializing.
    displayAccountInfo(account1);

    Account account2 = account1; // initializing as well (NOT ASSIGNING).
    Account account3; // initializing (with default values).
    displayAccountInfo(account3);

    /*
    *  this will call the copy assignment operator (`operator=` const Lvalue reference). if not implemented, compiler will provide one.
    *  this class does not need a custom one because it does not manage any unique resource that must be tranfer
    *  or don't have any raw pointer members.
     */
    account3 = account1; // COPY assigning!!!! because the right hand side is a Lvalue.
    displayAccountInfo(account3);

    Deep deep1 {10};
    Deep deep2 {20};

    // calling custom copy assignment operator because this class has a raw pointer member.
    deep1 = deep2; // COPY assigning!!!! because the right hand side is a Lvalue.
    cout << "deep1 data is: " << deep1.getData() << endl;

    // ------- MOVE ASSIGNMENT----------
    cout << "--- ----------------- move assignment operator test ---------------" << endl;
    // initializing. copy no require to account4, elision of constructors (RVO).
    Account account4 = Account {"name4", 100.0};
    displayAccountInfo(account4);

    /*
    *  this will call the move assignment operator (`operator=` Rvalue reference). if not implemented, compiler will provide one.
    *  this class does not need a custom one because it does not manage any unique resource that must be transfer
    *  or don't have any raw pointer members.
     */
    account4 = Account {"name5", 100.0};// MOVE assigning!!!! because the right hand side is a Rvalue.
}

/* ==========================================
 * c++ feature only: new ways to declare variables (Classes).
 *
 * see AI chat "C++ Initialization Syntax Explained in Detail"
 */
void differentWaysOfInitialization() {
    Account account1 {"name1", 100.0};
    /*Account account2 = {"name2", 200.0};*/ // once I added the "explicit" keyword to the default constructor, I can not initialize like this.
    Account account3 = Account {"name3", 300.0};
    Account account4 ("account4", 400.0);
    Account account5 =  Account("account5", 500.0);
}

void understandingSTDMoveSemantics() {
    /*
     * see AI chat "Understanding References and std::move in C++" for more info.
     */

    Account account1 {"name1", 100.0};
    saveAccountOnTheFly(std::move(account1));

    /*Account account2 = {"name2", 200.0};*/ // once I added the "explicit" keyword to the default constructor, I can not initialize like this.
    Account account2 {"name2", 200.0};

    // will these 2 reference variables (Lvalue and Rvalue) point to the same memory address account2 is using? -> YES!! so what is the actual difference?
    Account &lValueRef_account2 = account2;
    Account &&rValueRef_account2 = std::move(account2);

    cout << "account2 memory addres is: " << &account2 << endl;
    cout << "lValueRef_account2 memory addres is: " << &lValueRef_account2 << endl;
    cout << "rValueRef_account2 memory addres is: " << &rValueRef_account2 << endl;
}

/* ==========================================
 * c++ feature only: Inheritance.
 *
 * Understanding how default, copy and move constructors are executed when
 * dealing with inheritance.
 *
 * see class CheckingAccount for more details.
 *
 */
void practicingInheritance () {
    /*CheckingAccount a1 {"john",4678.46,347656783,12345678901234};*/
    CheckingAccount a1;
    displayActiveAccounts();
    cout << "a1 account number is: " << a1.getAccountNumber() << endl;
    cout << "a1 routing number is: " << a1.getRoutingNumber() << endl;
    cout << "a1 balance is: " << a1.getBalance() << endl;
    cout << "a1 name is: " << a1.getName() << endl;

    a1.setAccountNumber(1234567891233);
    a1.setRoutingNumber(123456789);
    a1.setDeposit(3000.45);
    a1.setName("juan");

    cout << "a1 account number is: " << a1.getAccountNumber() << endl;
    cout << "a1 routing number is: " << a1.getRoutingNumber() << endl;
    cout << "a1 balance is: " << a1.getBalance() << endl;
    cout << "a1 name is: " << a1.getName() << endl;

    cout << "--- ----------------- Moving ---------------------------- ---" << endl;

    CheckingAccount a2 = std::move(a1);

    cout << "a2 account number is: " << a2.getAccountNumber() << endl;
    cout << "a2 routing number is: " << a2.getRoutingNumber() << endl;
    cout << "a2 balance is: " << a2.getBalance() << endl;
    cout << "a2 name is: " << a2.getName() << endl;

    cout << "a1 account number is: " << a1.getAccountNumber() << endl;
    cout << "a1 routing number is: " << a1.getRoutingNumber() << endl;
    cout << "a1 balance is: " << a1.getBalance() << endl;
    cout << "a1 name is: " << a1.getName() << endl;

}

/* ==========================================
 * c++ feature only: overwriting ancestor class methods.
 *
 * understanding the behavior when overwriting methods in classes (static vs dynamic polymorphism).
 *
 */
void overwritingAncestorMethods () {
    /*
     * Observations:
     *
     * take a look at the following the object created.
     * the first one creates an object on the heap (Account a CheckingAccount b).
     * the second and third one on the stack (CheckingAccount c).
     *
     * after running this code, the object Account(a) created on the heap, did not call the overwritten setDeposit methods
     * implemented on the CheckingAccount class, instead, the parent implementation was used. WHY??
     * because, static polymorphism was used, meaning that the compiler bound the methods to the parent implementation because that
     * was actually what was written in the code.
     *
     * this behavior is only present when you use pointers or references, and the class type that was used to create the object (left side)
     * is a parent class.
     *
     * To avoid this behavior you have to add the "virtual" keyword in front of the methods, inside the parent class.
     *
     * the second and third object (CheckingAccount b CheckingAccount c) did actually use the overwritten method, then it called the parent implementation.
     */
    Account *a = new CheckingAccount {};
    a->setDeposit(1000.0); // will use parent implementation (no virtual).
    a->setName("john"); // will use own implementation (virtual).
    /*a->setAccountNumber(1111111111);*/ // ERROR!! CAN ONLY ACCESS METHODS CREATED ON THE PARENT CLASS
    cout << " ------- john balance is: " << a->getBalance() << endl;
    delete a;

    CheckingAccount *b = new CheckingAccount {};
    b->setName("carlos");
    b->setDeposit(1000.0);
    b->setAccountNumber(1111111111);
    cout << " ------- carlos balance is: " << b->getBalance() << endl;
    delete b;

    CheckingAccount c {};
    c.setName("rufus");
    c.setDeposit(1000.0);
    c.setAccountNumber(2222222222);
    cout << " ------- rufus balance is: " << c.getBalance() << endl;

    Account &r_cAccount = c;
    r_cAccount.setDeposit(349.45);
    cout << " ------- rufus account number is: " << r_cAccount.getBalance() << endl;
}

/* ==========================================
 * c++ feature only: returning by value, reference or pointer.
 */
Account modifyAndReturnCopyAccount (Account account) {
    displayActiveAccounts();
    account.setName(account.getName() + " modified");
    account.setDeposit(account.getBalance() + 1000);
    return account;
}

// I think these are more useful in the class context, because does not make sense to return a reference to a variable that
// will go out of scope when the function returns
Account &modifyAndReturnReferenceAccount (Account &account) {
    displayActiveAccounts();
    account.setName(account.getName() + " modified");
}

Account* createAccountOnTheHeap () {
    auto *p_account = new Account {"account on the heap", 200.0};
    return p_account;
}

void practicingReturningValues () {
    Account account1 {"name1", 100.0};
    displayActiveAccounts();

    /*
     * the move constructor will be used here because before the object copied to the function
     * goes out of scope, it will move its resources to the assigned variable.
     */
    Account account2 = modifyAndReturnCopyAccount(account1);
    displayActiveAccounts();

    cout << "account2 balance is: " << account2.getBalance() << endl;
}

/* ==========================================
 * c++ feature only: Abstract classes and interfaces.
 *
 * pure virtual functions.
 *
 */
void practicingAbstractClassesAndInterfaces () {
    // these are abstract classes because they have at least one pure virtual function, or they extend a class with
    // pure virtual functions but do not provide implementation for all of them.

    /* Shape s{}; */ // ERROR!!
    /* ClosedShape cs{}; */ // ERROR!!
    /* Shape s2 = Circle{}; */ // ERROR!!


    // Circle class can be instantiated because it creates implementation for all the pure virtual methods defined
    // in the Shape and ClosedShape Abstract classes.
    Circle circle{};
    circle.setX(3.5);
    circle.setY(4.5);
    circle.setRadius(10);

    Shape &r_Shape = circle;
    r_Shape.draw();
    cout << "r_Shape x is: " << r_Shape.getX() << endl;
    cout << "r_Shape y is: " << r_Shape.getY() << endl;

    ClosedShape &r_ClosedShape = circle;
    r_ClosedShape.draw();
    r_ClosedShape.setArea(100.0);
    cout << "r_ClosedShape area is: " << r_ClosedShape.getArea() << endl;

    Shape *p_Shape = new Circle{34.5};
    p_Shape->setX(45.7);
    p_Shape->setY(56.7);
    p_Shape->draw();

    ClosedShape *p_ClosedShape = new Circle{};
    p_ClosedShape->setArea(34.78);
    p_ClosedShape->draw();


    delete p_Shape;
    delete p_ClosedShape;
}

/* ==========================================
 * c++ feature only: Smart pointers.
 *
 * understanding how to use unique and shared smart pointers.
 *
 */
void practicingUniquePointers() {
    /*
     * Unique pointers will delete automatically.
     * they are just a wrapper for pointers.
     */

    // this is error prompted because it creates a raw pointer (new) then transfers ownership to the unique pointer
    std::unique_ptr<Account> accountOne {new Account{"juan",3000.0}};
    // preferred method.
    const auto accountTwo = std::make_unique<Account>("maria",4000.0);
    // unique pointers cannot be copied, only moved.
    const std::unique_ptr<Account> accountThree = std::move(accountOne);

    cout << "accountTwo name is: " << accountTwo->getName() << endl;
    cout << "accountThree name is: " << accountThree->getName() << endl;

    Account *p = accountTwo.get();
    cout << "address of accountOne: " << p << endl;


    vector<unique_ptr<Account>> uniqueAccounts;
    uniqueAccounts.push_back(std::make_unique<Account>("juan",3000.0));
    uniqueAccounts.push_back(std::make_unique<CheckingAccount>("maria",4000.0,3434786798,12345678901234));

    for (const auto &account : uniqueAccounts) {
        displayAccountInfo(*account);
    }
}

int main() {
    /*vector<Account> accounts {Account{"john",1000.0}};
    accounts.push_back(Account{"jane",2000.0});

    for (auto &account : accounts) {
        displayAccountInfo(account);
    }*/

    practicingUniquePointers();
    return 0;
}