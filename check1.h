#pragma once
#ifndef _CHECK1_H_
#define _CHECK1_H_

#include "Struct.h"
bool nextcheck(CELL_1**, int p1, int p2, int q1, int q2);
bool isThisLineEmpty(CELL_1**, int p1, int p2, int q1, int q2);
bool is_I_Matching(CELL_1**, int p1, int p2, int q1, int q2);
bool is_L_Matching(CELL_1**, int p1, int p2, int q1, int q2);
bool Zcheck(CELL_1**, int p1, int p2, int q1, int q2);
bool Ucheck(CELL_1**, int p1, int p2, int q1, int q2);
bool allcheck(CELL_1**, int p1, int p2, int q1, int q2);
bool checkValidPairs(CELL_1**);

#endif