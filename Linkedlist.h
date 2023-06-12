#pragma once
#include "struct.h"
#include "Normal.h"
#include "Menu.h"
#include "Console.h"

CELL2* findPos(CELL2** board, int x, int y, int& BOARDHEIGHT, int& BOARDWIDTH);
bool I_Method(CELL2** board, int y1, int x1, int y2, int x2, int& BOARDHEIGHT, int& BOARDWIDTH);
bool L_Method(CELL2** board, int y1, int x1, int y2, int x2, int& BOARDHEIGHT, int& BOARDWIDTH);
bool UandZMethod(CELL2** board, int y1, int x1, int y2, int x2, int& BOARDHEIGHT, int& BOARDWIDTH);
bool allMethod(CELL2** board, int y1, int x1, int y2, int x2, int& BOARDHEIGHT, int& BOARDWIDTH);
void deleteNode(CELL2** board, int y, int x, int& BOARDHEIGHT, int& BOARDWIDTH);
void deleteBoard2(CELL2** board, int y1, int x1, int y2, int x2, int& BOARDHEIGHT, int& BOARDWIDTH);
bool checkValidPair2(CELL2** board, int& BOARDHEIGHT, int& BOARDWIDTH);
void createBoard(CELL2** board, int& BOARDHEIGHT, int& BOARDWIDTH);
void deleteBoardView(CELL2** board, int& BOARDHEIGHT, int& BOARWIDTH);
void displayBoardView(CELL2** board, int& BOARDHEIGHT, int& BOARDWIDTH);
void moveInBoard2(CELL2** board, int& BOARDHEIGHT, int& BOARDWIDTH, int& status, int& streak, int& pairup, position& pos, player& p, position selectedPos[]);
void initDiffMode(player& p);
bool moveSuggestion2(CELL2** board, int& BOARDHEIGHT, int& BOARDWIDTH, position& a, position& b);
void shuffleBoard2(CELL2** board, int& BOARDHEIGHT, int& BOARDWIDTH);
