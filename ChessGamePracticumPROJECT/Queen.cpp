#include "stdafx.h"
#include "Queen.h"
#include"Bishop.h"
#include"Rook.h"
#include"Figure.h"

Queen::Queen(Position * position, Color color, DynamicArray<Figure*>* takenFigures) : Figure(position, color, takenFigures),
Rook(position, color, takenFigures), Bishop(position, color, takenFigures) {
	
	this->setName("Queen");
}
void Queen::getPossibleMoves(DynamicArray<Move*>* result) {
	// This it why it's enought to call only one of the getPossibleMoves method (Polymorphic)
	 Rook::getPossibleMoves(result);
}

Queen::~Queen() {
}
