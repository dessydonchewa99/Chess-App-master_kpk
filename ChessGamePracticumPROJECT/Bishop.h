#pragma once
#include "Figure.h"
class Bishop : virtual public Figure{
public:
	Bishop() = delete;
	Bishop& operator =(Bishop&) = delete;
	Bishop(Bishop&) = delete;
	Bishop(Position* position, Color color, DynamicArray<Figure*>* takenFigures);
	virtual ~Bishop();

	void getPossibleMoves(DynamicArray<Move*>* result) override;
};

