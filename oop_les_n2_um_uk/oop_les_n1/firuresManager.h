#pragma once
#include "figure.h"

class FiguresManager
{
public:
	//std::vector<std::shared_ptr<Figure>> figures;

	std::vector<std::shared_ptr<Figure>>  figures;

	FiguresManager() {};
	~FiguresManager() {
		//for (int i = 0; i < figures.size(); i++) {
		//	//delete figures[i];
		//};
	};

	void showFigrures(HDC& hdc);

	void pushFigure(std::shared_ptr<Figure> pF);
	void delFigure(std::shared_ptr<Figure> pF);
};

