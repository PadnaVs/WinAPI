#pragma once
#include "figure.h"

class Triangle :
    public Figure
{
    std::vector<POINT> points;
    
    void setCentre();
public:
    float height = 0.f;

    Triangle(POINT ipt1, POINT ipt2, POINT ipt3) {
        points.push_back(ipt1);
        points.push_back(ipt2);
        points.push_back(ipt3);

        setCentre();
        sFigureInfo = L"Удалена фигура.\nX: " + std::to_wstring(fX) + L" Y: " + std::to_wstring(fY);
    };
    ~Triangle() {
        sFigureInfo += L"\nЯ треугольник";
    };
    void show(HDC& hdc);
};

