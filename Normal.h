#pragma once
#include"struct.h"
#include"Console.h"
#include "CheckMatch1.h"
#include"Menu.h"
#ifndef _STRUCT_H_
#define _STRUCT_H_

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ESC_KEY 27
#define ENTER_KEY 97

void generateElements(char*& temp, int& nRows, int& nCols);
void initializeBoardView(CELL1**& board, int& rowNumbers, int& columeNumbers);
void deleteBoard(CELL1** board, int& rowNumbers, int& columeNumbers);
void displayBoard(CELL1** board, int& rowNumbers, int& columeNumbers);
void moveInBoard(CELL1** board, int& BOARDHEIGHT, int& BOARDWIDTH, int& status, int& streak, int& pairup, position& pos, player& p, position selectedPos[]);
void initNormalMode(player& p);
void shuffleElements(char* temp, int& cnt);

#endif

