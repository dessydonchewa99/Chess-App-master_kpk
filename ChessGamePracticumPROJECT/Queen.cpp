#include "stdafx.h"
#include "Queen.h"
#include"Bishop.h"
#include"Rook.h"
#include"Figure.h"

Queen::Queen(Position * position, Color color, DynamicArray<Figure*>* takenFigures) : Figure(position, color, takenFigures), Rook(position, color, takenFigures), Bishop(position, color, takenFigures) {
	
	this->setName("Queen");
}
void Queen::getPossibleMoves(DynamicArray<Move*>* result) {
	// It's enought to call getPossibleMoves method (Polymorphic)
	 Rook::getPossibleMoves(result);
}

Queen::~Queen() {
}
