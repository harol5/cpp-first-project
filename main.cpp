#include <iostream>
#include <vector>
#include <string>
/*#include <algorithm>*/
/*#include <cmath>*/
/*#include <cstdlib>*/
/*#include <cstdio>*/
/*#include <cstring>*/
/*#include <cctype>*/
/*#include <ctime>*/
/*#include <cassert>*/

#include "Account.h"

/*
 * throughout this file, we'll see the namespace "std" use a lot.
 * you can use the statement "using namespace std;" instead. you cal do this with
 * any other namespace as well.
 */
using namespace std;


/*
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
}

/*
 * c++ feature only: vectors (like ArrayList in java).
 */
void vectorPractice () {
    // like ArrayList in java.

    // vector initialization with a specific size.
    std::vector<char> vowels (26);

    // vector initialization with a specific size and value.
    std::vector highTemperatures (365, 80.0);

    // vector initialization with a specific values.
    std::vector<int> ages {50,34,78,21};

    // adds at the end of the vector.
    vowels.push_back('a');

    // this is how you create 2d vectors.
    vector<vector<int>> matrix (3, vector<int> (3));
}

/*
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

/*
 * c++ feature only: 2 new ways to declare variables.
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

/*
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

/*
 * c++ feature only: references variable with "&".
 */
void aliases () {
    int a {1};
    int &r_a {a}; // alias. not present in C
    int *p_a {&a};
}

/*
 * c++ feature only: OOP Classes.
 */
class Person {
    private:
        string name;
        int age;
    public:
        // Constructor Initialization list.
        Person(): name ("default"), age (0) {};
        Person(string name, int age): name (name), age (age) {};

        int getAge () {
            return this->age;
        }

        string getName () {
            return this->name;
        }

        void printInfo () {
            cout << "name is: " << this->name << endl;
            cout << "age is: " << this->age << endl;
        }
};

void practicingClasses () {
    Person p1 {"harol", 30}; // was this created on the stack or heap? -> on the stack
    p1.printInfo();

    Person *p2 = new Person {"juan", 30}; // heap allocation
    p2->printInfo(); // arrow operator. use when dealing with pointers.
    delete p2;

    Person *p3 = new Person {"gloria", 30};
    (*p3).printInfo(); // dereferencing, then accessing member with dot operator.
    delete p3;

    Person *p4 = new Person ("maria", 30);
    (*p4).printInfo();
    delete p4;

    Account p1Accounts {"harol",100.67};
    cout << "harol balance is: " << p1Accounts.getBalance() << endl;

    Account newAccount;
    cout << "new account name is: " << newAccount.getName() << " and balance is: " << newAccount.getBalance() << endl;
}

int main() {
    practicingClasses();
    return 0;
}