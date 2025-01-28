//
// Created by harol rojas on 1/23/25.
//

#ifndef CIRCLE_H
#define CIRCLE_H
#include "ClosedShape.h"

class Circle: public ClosedShape {
private:
    double radius;
public:
    explicit Circle(double initRadius = 1.0);
    virtual ~Circle();

    virtual void draw() override;
    virtual void erase() override;
    virtual void rotate() override;

    virtual void setArea(double initArea);

    double getRadius() const;
    void setRadius(double newRadius);
};



#endif //CIRCLE_H
