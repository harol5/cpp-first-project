//
// Created by harol rojas on 1/23/25.
//

#include "ClosedShape.h"

int ClosedShape::count = 0;

ClosedShape::ClosedShape() {
    count++;
}

ClosedShape::~ClosedShape() {
    count--;
}

int ClosedShape::getCount() {
    return count;
}

double ClosedShape::getArea() const {
    return area;
}


