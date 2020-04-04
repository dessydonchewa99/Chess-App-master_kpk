#pragma once
#include"Color.h"
#include"DynamicArray.h"
#include"Move.h"


#include<iostream>
class IBoard;
class Figure
{
private:
	Color color;
	bool isTaken_m;
	int turnTaken;

protected:
	char* name;
	IBoard * board;
	Position* position;
	DynamicArray<Position*> rules;
	DynamicArray<Figure*>* takenFigures;

public:
	Figure() = delete;
	Figure& operator =(Figure&) = delete;
	Figure(Figure&) = delete;
	Figure(Position* position, Color color, DynamicArray<Figure*>*);

	char*  getName() const;
	Color getColor()const;
	int getRow() const;
	int getColumn()const;
	int getTurnTaken()const;
	void getTakenFiguresList(DynamicArray<Figure*>* result);
	Figure * getLastTakenFigure();

	void setRow(int row);
	void setColumn(int column);
	void setTurnTaken(int turn);
	bool setBoard(IBoard * board);
	void setName(const char* name);

	bool isTaken()const;
	void makeNonTaken();
	std::ostream& printStats(std::ostream& os);
	void pushTakenFigureList(Figure* figure);
	void deleteLastTakenFigure();


	
	virtual bool moveFigure(int row, int column);
	virtual void getPossibleMoves( DynamicArray<Move*>* result) ;
	virtual ~Figure();

};

