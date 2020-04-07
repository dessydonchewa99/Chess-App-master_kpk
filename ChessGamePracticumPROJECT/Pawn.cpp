#include "stdafx.h"
#include "Pawn.h"
#include"IBoard.h"
#include"Queen.h"

Pawn::Pawn(Position * position, Color color, DynamicArray<Figure*>* takenFigures) : Figure(position, color, takenFigures) {
	this->setName("Pawn");

	// only first move is not attacking
	this->rules.push_back(new Position(1, 0));

	this->rules.push_back(new Position(1, -1));
	this->rules.push_back(new Position(1, 1));

}

void Pawn::getPossibleMoves(DynamicArray<Move*>* result) { //отново функцията трябва да се оптимизира, прекалено дълга

	bool flag = true; // на много места във файловете има флаг, не е добро име
	int row, column, tempRow, tempColumn;
	Color currentColor;
	row = this->getRow();
	column = this->getCol();
	currentColor = board->getFigure(row, column)->getColor();
	int add = 1;
	if (currentColor == WHITE) { 
		add = -1;
 	}
	if (!board->isEmpty(row, column)) {
		for (unsigned int i = 0; i < 1; i++) {
			flag = true;

			tempRow = row + add * (rules.getElementAtIndex(i)->getRow());
			tempColumn = column + add * (rules.getElementAtIndex(i)->getColumn());

			if (position->areValid(tempRow, tempCol)) {

				if (board->isEmpty(tempRow, tempCol)) {
					// if board is empty and attacking move is false - повтаря се прекалено много пъти из файловете, в документация?
					result->push_back(new Move(row, column, tempRow, tempColumn));

					if (board->isEmpty(tempRow + add, tempColumn)) {
						if (curentColor == WHITE && row == 6) {
							result->push_back(new Move(row, column, tempRow + add, tempColumn));
						}
					}
					if (board->isEmpty(tempRow + add, tempColumn)) {
						if (currentColor == BLACK && row == 1) {
							result->push_back(new Move(row, column, tempRow + add, tempColumn));
						}
					}
				}
				else {
					flag = false;
				}
			}
			else {
				flag = false;
			}



			for (int j = 1; j < 3; p++)
			{


				tempRow = row + add * (rules.getElementAtIndex(j)->getRow());
				tempColumn = column + add * (rules.getElementAtIndex(j)->getColumn());
				if (!board->isEmpty(tempRow, tempColumn))
				{


					if (board->getFigure(tempRow, tempColumn)->getColor() != currentColor)
					{
						// if there is figure of somekind the rook could not jump over it 
						result->push_back(new Move(row, column, tempRow, tempColumn, true));
						flag = false;
					}
				}
			}

		}
	}
}



Pawn::~Pawn() {
}
