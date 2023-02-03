#pragma once
#include "framework.h"
#include "Figure.h"
class Triangle :
    public Figure
{
    POINT pts[4] = { {20,10}, {60,30}, {90,20} , {20,10} };
    HBRUSH hbr = 0;
public:
    Triangle() {};
    Triangle(int ix, int iy, int ir) : Figure(ix, iy, ir) {
        int r =  1 + rand() % 255;
        int g =  1 + rand() % 255;
        int b =  1 + rand() % 255;

        hbr = CreateSolidBrush(RGB(r,g,b));
    };
    void show(HDC&);
};

