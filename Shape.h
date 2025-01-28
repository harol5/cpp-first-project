//
// Created by harol rojas on 1/23/25.
//

#ifndef SHAPE_H
#define SHAPE_H

/*
 * This is an abstract class.
 *
 * it has concrete methods, fields.
 */
class Shape {
private:
    static int count;
    double x, y;
public:
    virtual void draw() = 0;
    virtual void rotate() = 0;
    virtual void erase() = 0;

    [[nodiscard]] double getX() const;
    [[nodiscard]] double getY() const;
    void setX(double newX);
    void setY(double newY);

    explicit Shape(double initX = 0.0, double initY = 0.0);
    virtual ~Shape();

    static int getCount();
};



#endif //SHAPE_H
