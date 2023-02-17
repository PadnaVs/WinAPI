#pragma once
#include "framework.h"
#include "Figure.h"
class Triangle :
    public Figure
{
public:
    Triangle() {};
    Triangle(int ix, int iy, int ir) : Figure(ix, iy, ir) {
    };
    void show(HDC&);
};

