//
// Created by harol rojas on 1/6/25.
//

#ifndef DEEP_H
#define DEEP_H

/*
 * Practicing deep copying.
 *
 * because this class have a raw pointer as part of its members,
 * we must implement a copy constructor. to see the implementation go to the cpp file.
 *
 * the rule is to avoid raw pointer data members if possible or use smart pointers.
 */

class Deep {
private:
    int *data;
public:
    // constructor.
    Deep(int val);
    // Copy Constructor.
    Deep(const Deep &source);
    // Move Constructor.
    Deep(Deep &&source) noexcept;
    // Destructor.
    ~Deep();

    // getters and setters.
    int getData();
    void setData(int val);
};



#endif //DEEP_H
