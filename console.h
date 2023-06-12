#pragma once
#include"struct.h"
void goToXY(int rowPos, int colPos);
void setCursorToConsole(bool visible, DWORD size);
void resizeWindow(int x, int y);
void initWindow(int length, int width);
bool allcheck(CELL1** board, int x1, int y1, int x2, int y2, int& BOARDHEIGTH, int& BOARDWIDTH);
