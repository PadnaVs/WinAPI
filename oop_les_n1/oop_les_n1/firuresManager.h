#pragma once
#include "figure.h"

class FiguresManager
{
public:
	std::vector<Figure*> figures;

	FiguresManager() {};
	~FiguresManager() {
		for (int i = 0; i < figures.size(); i++) {
			delete figures[i];
		};
	};

	void showFigrures(HDC& hdc);

	void pushFigure(Figure* fI);
	void delFigure(Figure* fI);
};

