//
// Created by harol rojas on 1/23/25.
//

#ifndef OPENSHAPE_H
#define OPENSHAPE_H


#include "Shape.h"
class OpenShape: public Shape {
private:
    static int count;
public:
    OpenShape();
    virtual ~OpenShape();
    static int getCount();
};



#endif //OPENSHAPE_H
