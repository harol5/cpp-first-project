//
// Created by harol rojas on 1/23/25.
//

#include "Shape.h"

#include <iostream>
#include <ostream>

int Shape::count = 0;
int Shape::getCount() {
    return count;
}

Shape::Shape(const double initX , const double initY): x(initX), y(initY) {
    count++;
    std::cout << "Shape constructor called: " << count << std::endl;
}

Shape::~Shape() {
    count--;
}

void Shape::setX(double newX) {
    x = newX;
}

void Shape::setY(double newY) {
    y = newY;
}

double Shape::getX() const {
    return x;
}

double Shape::getY() const {
    return y;
}


