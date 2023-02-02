#include "GenerationFigures.h"

Figure* GenerationFigures::getLastF() {
	Figure* f = figures[figures.size()-1];
	return f;
};

void GenerationFigures::generationFigure() {
	int x = 958/2;
	int y = 988/2;
	Circle c = Circle(x, y, 100);
	Figure* f = new Circle(x, y, 100);

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