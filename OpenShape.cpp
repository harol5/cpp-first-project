//
// Created by harol rojas on 1/23/25.
//

#include "OpenShape.h"

int OpenShape::count = 0;

OpenShape::OpenShape() {
    count++;
}

OpenShape::~OpenShape() {
    count--;
}

int OpenShape::getCount() {
    return count;
}


