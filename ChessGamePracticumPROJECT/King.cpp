#include "stdafx.h"
#include "King.h"
#include"IBoard.h"

/**
* Construct new King
*@param Position * position
*@param Color color
*@param DynamicArray<Figure * > * takenFigures
*@return King
*/
King::King(Position* position, Color color, DynamicArray<Figure*>* takenFigures) : Figure(position, color, takenFigures) {
	this->setName("King");

	// голямо повторение на описанието за позиция, може да се премести в документация 	// или отделен .h файл

	// row col
	// up left (diagonal)
	this->rules.push_back(new Position(-1, -1));
	// up
	this->rules.push_back(new Position(-1, 0));
	// up right(diagonal)
	this->rules.push_back(new Position(-1, 1));
	// right
	this->rules.push_back(new Position(0, 1));
	// down right (diagonal)
	this->rules.push_back(new Position(1, 1));
	// down 
	this->rules.push_back(new Position(1, 0));
	// down left (diagonal)
	this->rules.push_back(new Position(1, -1));
	// left 
	this->rules.push_back(new Position(0, -1));
}

//************************************
// Method:    getPossibleMoves
// FullName:  King::getPossibleMoves
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: DynamicArray<Move * > * result
//************************************
void King::getPossibleMoves(DynamicArray<Move*>* result) {
	DynamicArray<Position*> freePosition;
	DynamicArray<Move*> attackedPosition;

	for (int i = 0; i < GlobalVaribles::SIZE; i++)
	{
		for (int j = 0; j < GlobalVaribles::SIZE; j++)
		{
			if (board->isEmpty(i, j)) {
				freePosition.push_back(new Position(i, j));
			}
			else if (!board->isEmpty(i, j)) {
				if (this->position->getCol() != j && this->position->getRow() != i)
				{
					this->board->getFigure(i, j)->getPossibleMoves(&attackedPosition);
				}

			}
		}
	}

	int tempRow, tempColumn;
	bool isAttacked = false;

	for (unsigned int i = 0; i < rules.getSize(); i++)
	{
		tempRow = position->getRow() + this->rules.getElementAtIndex(i)->getRow();
		tempColumn = position->getColumn() + this->rules.getElementAtIndex(i)->getColumn();

		// if the position is empty and not attacked

		isAttacked = false;
		if (this->position->areValid(tempRow,tempColumn)) {

			for (unsigned int i = 0; i < attackedPosition.getSize(); i++) {

				if (attackedPosition.getElementAtIndex(i)->getToRow() == tempRow
					&& attackedPosition.getElementAtIndex(i)->getToColumn() == tempColumn) {
					isAttacked = true;
				}
			}
			if (!isAttacked && board->isEmpty(tempRow, tempColumn)) {
				result->push_back(new Move(this->position->getRow(), this->position->getColumn(), tempRow, tempColumn, false));
			}
			if (!this->board->isEmpty(tempRow, tempColumn) && !isAttacked) {
				if (this->board->getFigure(tempRow, tempColumn)->getColor() != this->getColor()) {

					//тук също има много аргументи, НО е конструктор, затова би трябвало да нарушава чистия код
					result->push_back(new Move(this->position->getRow(), this->position->getColumn(), tempRow, tempColumn, true));
				}
			}

		}
	}
}

King::~King() {
}
