//
// Created by harol rojas on 1/23/25.
//

#include "ClosedShape.h"

#include <iostream>
#include <ostream>

int ClosedShape::count = 0;

ClosedShape::ClosedShape(): Shape() {
    count++;
    std::cout << "ClosedShape constructor called: " << count << std::endl;
}

ClosedShape::~ClosedShape() {
    count--;
}

int ClosedShape::getCount() {
    return count;
}

void ClosedShape::setArea(double initArea) {
    std::cout << "ClosedShape set area" << std::endl;
    area = initArea;
}

double ClosedShape::getArea() const {
    return area;
}


