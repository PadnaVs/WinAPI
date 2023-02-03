#pragma once
#include "Figure.h"

class Rect :
    public Figure
{
public:
    Rect() {};
    Rect(int ix, int iy, int ir) : Figure(ix, iy, ir) {
    
    };
    void show(HDC&);
};

