#include "firuresManager.h"

void FiguresManager::showFigrures(HDC& hdc) {
	for (int i = 0; i < figures.size(); i++) {
		figures[i]->show(hdc);
	};
};

void FiguresManager::delFigure(Figure* fI) {
	if (fI == NULL)
		return;

	auto it = std::find(figures.begin(), figures.end(), fI);
	if (*it == fI) {
		figures.erase(it);
		delete fI;
	};
};

void FiguresManager::pushFigure(Figure* fI) {
	if (fI == NULL)
		return;

	figures.push_back(fI);
};
