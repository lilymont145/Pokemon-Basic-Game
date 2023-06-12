#pragma once
#include"struct.h"
#include"Menu.h"

bool isThisLineEmpty(CELL1** board, int x1, int y1, int x2, int y2);
bool is_I_Matching(CELL1** board, int x1, int y1, int x2, int y2);
bool is_L_Matching(CELL1** board, int x1, int y1, int x2, int y2);
bool Zcheck(CELL1** board, int x1, int y1, int x2, int y2);
bool Ucheck(CELL1** board, int x1, int y1, int x2, int y2, int& BOARDHEIGTH, int& BOARDWIDTH);
bool allcheck(CELL1** board, int x1, int y1, int x2, int y2, int& BOARDHEIGTH, int& BOARDWIDTH);
bool checkValidPairs(CELL1** board, int& BOARDHEIGTH, int& BOARDWIDTH);
bool moveSuggestion(CELL1** board, int& BOARDHEIGHT, int& BOARDWIDTH, position& a, position& b);
