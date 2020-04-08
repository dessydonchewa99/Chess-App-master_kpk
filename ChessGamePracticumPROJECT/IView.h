#pragma once

#include"IBoard.h"
#include<iostream>

//файлове и класове с I не е добра идея, какво е това I
class IView {
public:
	virtual void printBoard(IBoard* board) = 0;
	virtual void printMessageNL(const char* message) = 0;
	virtual std::ostream& getStream() = 0;
	virtual void readCommand(char* command) = 0;	
};

