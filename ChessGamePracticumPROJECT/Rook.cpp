#include "stdafx.h"
#include "Rook.h"
#include"IBoard.h"

Rook::Rook(Position * position, Color color, DynamicArray<Figure*>* takenFigures) : Figure(position, color, takenFigures) {
	this->setName("Rook");
	// row col

	// up
	this->rules.push_back(new Position(-1, 0));
	// down 
	this->rules.push_back(new Position(1, 0));

	// left
	this->rules.push_back(new Position(0, -1));
	// right
	this->rules.push_back(new Position(0, 1));
}
void Rook::getPossibleMoves(DynamicArray<Move*>* result) {
	bool flag = true;
	int row, col, tempRow, tempCol;
	Color currentColor;
	row = this->position->getRow();
	column = this->position->getColumn();
	currentColor = board->getFigure(row, column)->getColor();

	for (unsigned int i = 0; i < 1; i++) {

		if (!board->isEmpty(row, column)) {
			for (unsigned int j = 0; j < rules.getSize(); j++) {
				flag = true;
				int add = 1;
				while (flag) {
					tempRow = row + add * (rules.getElementAtIndex(j)->getRow());
					tempColumn = column + add * (rules.getElementAtIndex(j)->getColumn());

					if (position->areValid(tempRow, tempColumn)) {

						if (board->isEmpty(tempRow, tempColumn)) {
							// if board is empty and attacking move is false
							result->push_back(new Move(row, column, tempRow, tempColumn));
						}
						else if (board->getFigure(tempRow, tempColumn)->getColor() != curentColor)
						{
							// if there is figure of somekind the rook could not jump over it 
							result->push_back(new Move(row, column, tempRow, tempColumn, true));
							flag = false;
						}
						else {
							flag = false;
						}
					}
					else {
						flag = false;
					}
					++add;
				}
			}
		}	

	}
}

Rook::~Rook() {
}
