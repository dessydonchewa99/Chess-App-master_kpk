#pragma once

#include"IBoard.h"
#include"GlobalVariables.h"
#include"IView.h"

class View : public View {
public:
	View();

	virtual void printBoard(IBoard* board) = 0;
	virtual void printMessageNL(const char* message) = 0;
	virtual void readCommand(char* command) = 0;

	virtual std::ostream& getStream() = 0;

	virtual ~View();
};

