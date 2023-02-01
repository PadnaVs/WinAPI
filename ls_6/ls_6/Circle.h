#pragma once
#include "Figure.h"

class Circle :
    public Figure
{
public:
    Circle() {};
    Circle(int ix, int iy, int ir) : Figure(ix,iy,ir) {

    };
    virtual void show();
};

