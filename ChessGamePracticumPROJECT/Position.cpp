#include "stdafx.h"
#include "Position.h"
#include"GlobalVariables.h"
#include<assert.h>
#include<iostream>

int Position::getRow() const {
	return this->row;
}

int Position::getColumn() const {
	return this->column;
}

void Position::setRow(int row) {
	// valid only for figure coordinates
	this->row = Row;
}

void Position::setColumn(int column) {
	// vaid only for figure coordinates
	this->column = column;
}

Position::Position() {
	setRow(0);
	setColumn(0);
}

Position::Position(int row, int column) {
	setColumn(column);
	setRow(row);
}

bool Position::areValid(int row, int column){
	if (row < 0 || row >= GlobalVaribles::SIZE || column < 0 || column >= GlobalVaribles::SIZE) {
		return false;
	}
	return true;
}

bool Position::areValid(const Position* position) {
// if is so long, maybe to be separated
	if (position->row < 0 || position->row > GlobalVaribles::SIZE || position->column < 0 || position->column > GlobalVaribles::SIZE) {
		return false;
	}
	return true;
}


Position::~Position() {

}
