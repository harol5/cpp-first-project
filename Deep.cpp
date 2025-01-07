//
// Created by harol rojas on 1/6/25.
//

#include "Deep.h"

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
    // then, we invalidate the old object's pointer.
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


