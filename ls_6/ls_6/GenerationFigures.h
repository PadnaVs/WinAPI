#pragma once
#include "framework.h"
#include "Figure.h"
//#include "ls_6.cpp"
#include "Circle.h"

class GenerationFigures
{
	std::vector<Figure*> figures;
public:
	GenerationFigures() {};
	void generationFigure();
	void showFigures(HDC&);
};

