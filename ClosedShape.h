//
// Created by harol rojas on 1/23/25.
//

#ifndef CLOSEDSHAPE_H
#define CLOSEDSHAPE_H
#include "Shape.h"

/*
 * TODO: what is really the point of having properties in a abstract class?
 *
 */
class ClosedShape: public Shape {
private:
    static int count;
    double area {0.0};
public:
    ClosedShape();
    virtual ~ClosedShape();

    virtual void setArea(double initArea) = 0;
    [[nodiscard]] double getArea() const;

    static int getCount();
};



#endif //CLOSEDSHAPE_H
