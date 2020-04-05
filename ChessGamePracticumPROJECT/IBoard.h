#pragma once
#include"Square.h"
#include"GlobalVariables.h"

class Figure;
class IBoard {
public:
	virtual void placeFigures() = 0;
	virtual bool isEmpty(int row, int column) = 0;
	virtual Figure* getFigure(int row, int column) = 0;
	virtual bool setFigure(int row, int column, Figure* currentFigure) = 0;
	virtual bool makeTileEmpty(int row, int column) = 0;
};

