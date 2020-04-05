#pragma once
#include "Figure.h"
#include"Bishop.h"
#include"Rook.h"

class Queen : public Rook, public Bishop
{
	//Class queen shares one array for storing moves with Rook and Bishop constructor
public:
	Queen() = delete;
	Queen& operator = (Queen&) = delete;
	Queen(Queen&) = delete;
	virtual ~Queen();

	Queen(Position* position, Color color, DynamicArray<Figure*>* takenFigures);
	void getPossibleMoves(DynamicArray<Move*>* result) override;
};

