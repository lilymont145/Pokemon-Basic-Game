#include "Check1.h"
#include"struct.h"

bool isThisLineEmpty(CELL1** board, int x1, int y1, int x2, int y2)
{
    if (x1 == x2)
    {
        int x, y, count = 0;

        if (y1 > y2)
        {
            x = y2;
            y = y1;
        }
        else
        {
            x = y1;
            y = y2;
        }

        for (int i = x; i <= y; i++)
        {
            if (board[x1][i].isNotEmpty)
            {
                count++;
                if (count == 2) return false;
            }
        }
        if ((count == 1) && ((!board[x1][y1].isNotEmpty && board[x2][y2].isNotEmpty) || (board[x1][y1].isNotEmpty && !board[x2][y2].isNotEmpty)))
        {
            return true;
        }
        else if (count == 0)
        {
            return true;
        }

        return false;
    }

    if (y1 == y2)
    {
        int x, y, count = 0;
        if (x1 > x2)
        {
            x = x2;
            y = x1;
        }
        else
        {
            x = x1;
            y = x2;
        }
        for (int i = x; i <= y; i++)
        {
            if (board[i][y1].isNotEmpty)
            {
                count++;
                if (count == 2) return false;
            }
        }
        if ((count == 1) && ((!board[x1][y1].isNotEmpty && board[x2][y2].isNotEmpty) || (board[x1][y1].isNotEmpty && !board[x2][y2].isNotEmpty)))
        {
            return true;
        }
        else if (count == 0)
        {
            return true;
        }

        return false;
    }
    return false;
}

bool is_I_Matching(CELL1** board, int x1, int y1, int x2, int y2)
{
    //If those two blocks are next to each other horizontally

    if ((x1 == x2 + 1 || x1 == x2 - 1) && (y1 == y2))
    {
        if (board[x1][y1].letter == board[x2][y2].letter)
            return true;
    }

    //If those two blocks are next to each other vertically

    if ((y1 == y2 + 1 || y1 == y2 - 1) && (x1 == x2))
    {
        if (board[x1][y1].letter == board[x2][y2].letter)
            return true;
    }

    // If they are in the same row
    if (x1 == x2)
    {
        int y, x, count = 0;

        x = (y1 > y2 ? y2 : y1);
        y = (y1 > y2 ? y1 : y2);

        for (int i = x + 1; i < y; i++)
        {
            if (board[x1][i].isNotEmpty)
            {
                return false;
            }
        }
        return true;
    }

    // If they are in the same column
    if (y1 == y2)
    {
        int x, y, count = 0;

        x = (x1 > x2 ? x2 : x1);
        y = (x1 > x2 ? x1 : x2);

        for (int i = x + 1; i < y; i++)
        {
            if (board[i][y1].isNotEmpty)
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool is_L_Matching(CELL1** board, int x1, int y1, int x2, int y2) {

    //If they are on the same row or column

    if (x1 == x2 || y1 == y2) {
        return false;
    }

    //Check if the path from the meeting point of two block to them is empty
    bool c1, c2;

    //Scenario 1: The meeting point at x=x1 and y=y2 is empty
    if (!board[x1][y2].isNotEmpty) {
        c1 = isThisLineEmpty(board, x1, y1, x1, y2); // Path_check from block 1 to the meeting point 
        c2 = isThisLineEmpty(board, x2, y2, x1, y2); // Path_check from block 2 to the meeting point 
        if (c1 && c2) {
            return true;
        }
    }

    //Scenario 2: The meeting point at x=x2 and y=y1 is empty

    if (!board[x2][y1].isNotEmpty) {
        c1 = isThisLineEmpty(board, x1, y1, x2, y1);// Path_check from block 1 to the meeting point
        c2 = isThisLineEmpty(board, x2, y2, x2, y1);// Path_check from block 2 to the meeting point
        if (c1 && c2) {
            return true;
        }
    }
    return false;
}

bool Zcheck(CELL1** board, int x1, int y1, int x2, int y2) {

    //If they are on the same row or column

    if (x1 == x2 || y1 == y2) {
        return false;
    }

    bool c1, c2, c3;
    int x, y;

    x = (y1 > y2 ? y2 : y1);
    y = (y1 > y2 ? y1 : y2);

    for (int i = x + 1; i <= y; i++) {

        if (board[x1][i].isNotEmpty)
        {
            is_L_Matching(board, x1, i - 1, x2, y2);
        }
    }

    x = (x2 > x1 ? x2 : x1);
    y = (x2 > x1 ? x1 : x2);

    for (int i = x + 1; i <= y; i++) {
        if (board[i][y1].isNotEmpty)
        {
            is_L_Matching(board, i - 1, y1, x2, y2);
        }
    }
    return false;
}

bool Ucheck(CELL1** board, int x1, int y1, int x2, int y2, int& BOARDHEIGTH, int& BOARDWIDTH) {

    //The two pair on the same row barrier or column barrier

    if (((x1 == x2) && (x1 == 0 || x1 == BOARDHEIGTH - 1) || ((y1 == y2) && (y1 == 0 || y2 == BOARDWIDTH - 1)))) {
        return true;
    }

    bool c1, c2, c3;
    int x, y;
    if (y2 < y1) {
        x = y2;
        y = y1;
    }
    else {
        x = y1;
        y = y2;
    }
    for (int i = 0; i < BOARDWIDTH; i++) {
        if (i <= x || i >= y) {
            c3 = isThisLineEmpty(board, x1, i, x2, i);
            if (c3) {
                c1 = isThisLineEmpty(board, x1, y1, x1, i);
                c2 = isThisLineEmpty(board, x2, y2, x2, i);
                if (c1 && c2) {
                    return true;
                }
            }
            else if (i == 0 || i == (BOARDWIDTH - 1)) {
                c1 = isThisLineEmpty(board, x1, y1, x1, i);
                c2 = isThisLineEmpty(board, x2, y2, x2, i);
                if ((c1 && c2) || (c1 && y2 == i) || (y1 == i && c2)) {
                    return true;
                }
            }
        }
    }

    if (x2 < x1) {
        x = x2;
        y = x1;
    }
    else {
        x = x1;
        y = x2;
    }
    for (int i = 0; i < BOARDHEIGTH; i++) {
        if (i <= x || i >= y) {
            c3 = isThisLineEmpty(board, i, y1, i, y2);
            if (c3) {
                c1 = isThisLineEmpty(board, x1, y1, i, y1);
                c2 = isThisLineEmpty(board, x2, y2, i, y2);
                if (c1 && c2) {
                    return true;
                }
            }
            else if (i == 0 || i == (BOARDHEIGTH - 1)) {
                c1 = isThisLineEmpty(board, x1, y1, i, y1);
                c2 = isThisLineEmpty(board, x2, y2, i, y2);
                if ((c1 && c2) || (c1 && x2 == i) || (x1 == i && c2)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool allcheck(CELL1** board, int x1, int y1, int x2, int y2, int& BOARDHEIGTH, int& BOARDWIDTH)
{
    if (is_I_Matching(board, x1, y1, x2, y2)) {
        return true;
    }
    else if (is_L_Matching(board, x1, y1, x2, y2)) {
        return true;
    }
    else if (Zcheck(board, x1, y1, x2, y2)) {
        return true;
    }
    else if (Ucheck(board, x1, y1, x2, y2, BOARDHEIGTH, BOARDWIDTH)) {
        return true;
    }
    return false;
}

bool checkValidPairs(CELL1** board, int& BOARDHEIGTH, int& BOARDWIDTH) {
    char checkMatch = 'A';
    while (checkMatch >= 'A' && checkMatch <= 'Z') {
        int cnt = 0;
        int* pos = new int[BOARDHEIGTH * BOARDWIDTH];
        for (int i = 0; i < BOARDHEIGTH; i++) {
            for (int j = 0; j < BOARDWIDTH; j++) {
                if (board[i][j].letter == checkMatch && board[i][j].isNotEmpty) {
                    pos[cnt++] = i;
                    pos[cnt++] = j;
                }
            }
        }
        for (int i = 0; i < cnt - 2; i += 2) {
            for (int j = i + 2; j < cnt; j += 2) {
                if (allcheck(board, pos[i], pos[i + 1], pos[j], pos[j + 1], BOARDHEIGTH, BOARDWIDTH)) {
                    delete[] pos;
                    return true;
                }
            }
        }
        checkMatch++;
    }
    return false;
}
