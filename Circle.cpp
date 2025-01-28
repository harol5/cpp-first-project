//
// Created by harol rojas on 1/23/25.
//

#include "Circle.h"

#include <iostream>
#include <ostream>
#include <numbers>

Circle::Circle(const double initRadius): radius(initRadius) {}

Circle::~Circle() = default;



void Circle::draw() {
    std::cout << "Drawing a circle" << std::endl;
}

void Circle::erase() {
    std::cout << "Erasing a circle" << std::endl;
}

void Circle::rotate() {
    std::cout << "Rotating a circle" << std::endl;
}

void Circle::setArea(double initArea) {
    std::cout << "Setting area of a circle" << std::endl;
    ClosedShape::setArea(std::numbers::pi * radius * radius);
}

double Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(const double newRadius) {
    radius = newRadius;
}


