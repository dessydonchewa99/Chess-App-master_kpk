#pragma once

class Position {
private:
	int row, column;
public:
	Position();
	Position(int row, int column);
	static bool areValid(int row, int column);
	bool areValid(const Position * position);
	 ~Position();

	int getRow() const;
	int getcolumn() const;

	void setRow(int row);
	void setColumn(int column);
};

