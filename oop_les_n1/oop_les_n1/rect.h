#pragma once
#include "figure.h"
#include "framework.h"

class Rect :
    public Figure
{
    float fWidth  = 0.f;
    float fHeight = 0.f;

    ~Rect() {
        sFigureInfo += L"\nЯ квадрат";
    };
public:
    Rect(float fiX, float fiY, float fiW, float fiH) : Figure(fiX, fiY) {
        fWidth  = fiW;
        fHeight = fiH;
    };
    
    void show(HDC& hdc);
};

