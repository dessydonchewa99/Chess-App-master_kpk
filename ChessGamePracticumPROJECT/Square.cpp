#include "stdafx.h"
#include "Square.h"

Square::Square() {
	this->isEmpty = true;
}

void Square::setFigure(Figure* otherFigure) {
	this->figure = otherFigure;
	this->isEmpty = false;
}

bool Square::getIsEmpty() const {
	return this->isEmpty;
}

Figure * Square::getFigure() const {
	return this->figure;
}

Figure * Square::removeFigure() {
	this->isEmpty = true;
	Figure* result = this->figure;
	this->figure = nullptr;
	return result;
}


 Square::~Square() {
	 std::cout << "~Square() is called";
}
