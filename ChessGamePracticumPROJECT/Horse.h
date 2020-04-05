#pragma once
#include "Figure.h"

class Horse : public Figure {
public:
	Horse() = delete;
	Horse& operator =(Horse&) = delete;
	Horse(Horse&) = delete;
	virtual ~Horse();
	Horse(Position* position, Color color, DynamicArray<Figure*>* takenFigures);
	
};

