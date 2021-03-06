// ChessGamePracticumPROJECT.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "stdafx.h"
#include"Board.h"
#include"ConsoleView.h"
#include<iostream>
#include<Windows.h>
#include"GlobalVariables.h"
#include"DynamicArray.h"
#include "IGame.h"
#include"Game.h"
#pragma warning(disable: 4996) 
using namespace std;


/*

fixed?(maybe still bugs) bugs: 
	pawn could not ataack(check possible moves generator),
	bishop move in place where other figure was (check figure move set empty board tile)


  
  CAUTION - Figure knows it's corrdinates and board knows every figure coordinates
  // The reason for that's we identify uniquely each figure by it's coordinates- or it's taken 
  // lead to programmer forgetting to update figure coordinates
  // TODO : add auto update mechanism or store the information in one place, and add unique id to each figure 
*/

int main()
{

	RECT rect;
	HWND console = GetConsoleWindow();

	GetWindowRect(console, &rect); //stores the console's current dimensions

	MoveWindow(console, rect.left, rect.top, 1400, 1200, TRUE);
 //1400 и 1200 трябва да се изкарат като константи, но трябва да се провери конструктора за имената


	CONSOLE_FONT_INFOEX consoleFontInfoex;

	consoleFontInfoex.cbSize = sizeof(consoleFontInfoex);
	consoleFontInfoex.dwFontSize.X = 9;
	consoleFontInfoex.dwFontSize.Y = 9;
	consoleFontInfoex.FontFamily = FF_DONTCARE;
	consoleFontInfoex.FontWeight = FW_NORMAL;
	wcscpy_s(consoleFontInfoex.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, & consoleFontInfoex);
	std::ostream& out = std::cout;

	ConsoleView* view = new ConsoleView(out);

	IGame* game = new Game(view);
	game->startGame();
	
	return 0;
}

