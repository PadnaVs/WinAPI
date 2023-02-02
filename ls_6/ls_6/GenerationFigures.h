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
	~GenerationFigures() {
		for (int i = 0; i < figures.size(); i++) {
			delete figures[i];
		};
	}
	Figure* getLastF();
	void generationFigure();
	void moveFigures();
	void showFigures(HDC&);
};

