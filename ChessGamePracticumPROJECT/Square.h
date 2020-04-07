#pragma once
#include"Figure.h"

class Square {
private: 
	Figure* figure;
	bool isEmpty;
public:
	Square();
	Square& operator = (Square&) = delete;
	Square(Square&) = delete;
	~Square();

	void setFigure(Figure* otherFigure);

	bool getIsEmpty() const;
	Figure* getFigure() const;

	Figure* removeFigure();
};

