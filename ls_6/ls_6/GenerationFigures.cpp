#include "GenerationFigures.h"

Figure* GenerationFigures::getLastF() {
	Figure* f = figures[figures.size()-1];
	return f;
};

void GenerationFigures::generationFigure() {
	int x = 958/2;
	int y = 988/2;

	int numF = 1 + rand() % 3;
	
	Figure* f = 0;

	switch (numF)
	{
	case 1:
		f = new Circle(x, y, 100);
		break;
	case 2:
		f = new Rect(x, y, 100);
		break;
	case 3:
		f = new Triangle(x, y, 100);
		break;
	default:
		return;
		break;
	}

	figures.push_back(f);
};

void GenerationFigures::moveFigures() {
	for (int i = 0; i < figures.size(); i++) {
		figures[i]->move();
	};
};

void GenerationFigures::showFigures(HDC &hdc) {
	for (int i = 0; i < figures.size(); i++) {
		Figure* f = 0;
		f = figures[i];
		f->show(hdc);
	}
}