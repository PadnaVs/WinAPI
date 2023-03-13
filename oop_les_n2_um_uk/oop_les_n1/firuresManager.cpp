#include "firuresManager.h"

void FiguresManager::showFigrures(HDC& hdc) {
	for (int i = 0; i < figures.size(); i++) {
		figures[i]->show(hdc);
	};
};

void FiguresManager::delFigure(std::shared_ptr<Figure> pF) {
	if (pF == NULL)
		return;

	auto it = std::find(figures.begin(), figures.end(), pF);
	if (*it == pF) {
		figures.erase(it);
	};
};

void FiguresManager::pushFigure(std::shared_ptr<Figure> pF) {
	if (pF == NULL)
		return;

	figures.push_back(pF);
};
