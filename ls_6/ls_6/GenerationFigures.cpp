#include "GenerationFigures.h"

void GenerationFigures::generationFigure() {
	int x = 958/2;
	int y = 988/2;
	Circle c = Circle(x, y, 100);
	Figure* f = &c;

	figures.push_back(f);
};

void GenerationFigures::showFigures(HDC &hdc) {
	for (int i = 0; i < figures.size(); i++) {
		Figure* f = 0;
		f = figures[i];
		f->show(hdc);
	}
}