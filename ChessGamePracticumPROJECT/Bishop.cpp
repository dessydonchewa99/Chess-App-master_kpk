#include "stdafx.h"
#include "Bishop.h"
#include"IBoard.h"


Bishop::Bishop(Position * position, Color color, DynamicArray<Figure*>* takenFigures) : Figure(position, color, takenFigures) {

	this->setName("Bishop");

	// down 1, right 1
	this->rules.push_back(new Position(1, 1));
	// down 1, left 1
	this->rules.push_back(new Position(1, -1));

	// up 1, right 1
	this->rules.push_back(new Position(-1, 1));
	// up 1, left 1
	this->rules.push_back(new Position(-1, -1));
}

void Bishop::getPossibleMoves(DynamicArray<Move*>* result) { //твърде дълга
	bool flag = true;
	int row, column, tempRow, tempColumn, colorCorrection;
	colorCorrection = 1;
	Color currentColor;
	row = position->getRow();
	column = position->getColumn();
	currentColor = board->getFigure(row, column)->getColor();
	if (currentColor == BLACK) {
		colorCorrection = -1;
	}

	for (int i = 0; i < GlobalVaribles::SIZE; i++) {

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
						// if there is enemy figure and attacking move is true
						else if (board->getFigure(tempRow, tempColumn)->getColor() != currentColor) {
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

Bishop::~Bishop(){
}
