#pragma once
#include "framework.h"

#include "Figure.h"
#include "Circle.h"
#include "Rect.h"
#include "Triangle.h"

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

