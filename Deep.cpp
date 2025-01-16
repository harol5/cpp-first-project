//
// Created by harol rojas on 1/6/25.
//

#include "Deep.h"

#include <iostream>
#include <ostream>

// Constructor implementation.
Deep::Deep(int val) {
    data = new int;
    *data = val;
}

// Copy Constructor Implementation.
Deep::Deep(const Deep &source) {
    /*
     * the copy MUST HAVE its on memory location for the data pointer.
     * if we just do a shallow copy, we will be copying the same memory address, this
     * is bad because when the copy is destroyed, the pointer will be freed and the original object will have
     * an invalid memory address.
     */
    data = new int;
    *data = *source.data;
}

/*
 * Move Constructor.
 *
 * this constructor is useful for efficiency, because instead of copying the object,
 * it will move its resources.
 *
 * As you can see, the parameter is a Rvalue reference so
 * of course this will be call when a Rvalue is used.
 *
 * example of Rvalue for this class: Deep{10}
 */
Deep::Deep(Deep &&source) noexcept {
    // copies the pointer to the obj that is moving to.
    data = source.data;
    // then, we reset the old object's pointer.
    source.data = nullptr;
}

// Destructor implementation
Deep::~Deep() {
    delete data;
}

// setter
void Deep::setData(int val) {
    *data = val;
}

// getter
int Deep::getData() {
    return *data;
}

// copy assignment operator overload
Deep &Deep::operator=(const Deep &source) {
    std::cout << "Copy assignment operator called for." << *source.data << std::endl;
    // if the source is the same as the current object, we don't need to do anything.
    if (this == &source) {
        std::cout << "same object" << std::endl;
        return *this;
    }
    // otherwise, we need to delete the old data and copy the new one.
    delete this->data;
    this->data = new int;
    *this->data = *source.data;
    return *this;
}

// move assignment operator overload
Deep &Deep::operator=(Deep &&source) noexcept {
    // if the source is the same as the current object, we don't need to do anything.
    if (this == &source) {
        return *this;
    }
    // otherwise, we need to delete the old data and copy the new one.
    delete this->data;
    this->data = source.data;
    source.data = nullptr;
    return *this;
}


