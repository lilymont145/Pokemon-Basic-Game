#include "Check1.h"
bool isThisLineEmpty(CELL_1** board, int p1, int p2, int q1, int q2) {
    if (p1 == q1) {
        int y, x, count = 0;
        if (p2 > q2) 
        {
            x = q2;
            y = p2;
        }
        else 
        {
            x = p2;
            y = q2;
        }
        for (int i = x; i <= y; i++) 
        {
            if (board[p1][i].isNotEmpty) 
            {
                count++;
                if (count == 2) return false;
            }
        }
        if ((count == 1) && ((!board[p1][p2].isNotEmpty && board[q1][q2].isNotEmpty) || (board[p1][p2].isNotEmpty && !board[q1][q2].isNotEmpty))) {//sai
            return true;
        }
        else if (count == 0) 
        {
            return true;
        }
        return false;
    }
    if (p2 == q2) {
        int x, y, count = 0;
        if (p1 > q1) 
        {
            x = q1;
            y = p1;
        }
        else 
        {
            x = p1;
            y = q1;
        }
        for (int i = x; i <= y; i++) 
        {
            if (board[i][p2].isNotEmpty) 
            {
                count++;
                if (count == 2) return false;
            }
        }
        if ((count == 1) && ((!board[p1][p2].isNotEmpty && board[q1][q2].isNotEmpty) || (board[p1][p2].isNotEmpty && !board[q1][q2].isNotEmpty))) 
        {//sai
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

bool is_I_Matching(CELL_1** board, int p1, int p2, int q1, int q2) 
{
    //If those two blocks are next to each other 

    if ((p1 == q1 + 1 || p1 == q1 - 1) && (p2 == q2)) 
    {
        if (board[p1][p2].c == board[q1][q2].c)
            return true;
    }
    if ((p2 == q2 + 1 || p2 == q2 - 1) && (p1 == q1)) 
    {
        if (board[p1][p2].c == board[q1][q2].c)
            return true;
    }

    // If they are in the same row
    if (p1 == q1) {
        int y, x, count = 0;

        x = (p2 > q2? q2 : p2);
        y = (p2 > q2? p2 : q2);

        for (int i = x + 1; i < y; i++) 
        {
            if (board[p1][i].isNotEmpty) 
            {
                return false;
            }
        }
        return true;
    }

    // If they are in the same column
    if (p2 == q2) {
        int x, y, count = 0;

        x = (p1 > q1? q1 : p1);
        y = (p1 > q1? p1 : q1);

        for (int i = x + 1; i < y; i++) 
        {
            if (board[i][p2].isNotEmpty) 
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool is_L_Matching(CELL_1** board, int p1, int p2, int q1, int q2) {
    //If they are on the same row or column
    if (p1 == q1 || p2 == q2) {
        return false;
    }

    //Check if the path from the meeting point of two block to them is empty
    bool c1, c2;

    //Scenario 1: The meeting point at x=p1 and y=q2 is empty
    if (!board[p1][q2].isNotEmpty) {
        c1 = isThisLineEmpty(board, p1, p2, p1, q2); // Path_check from block 1 to the meeting point 
        c2 = isThisLineEmpty(board, q1, q2, p1, q2); // Path_check from block 2 to the meeting point 
        if (c1 && c2) {
            return true;
        }
    }

    //Scenario 2: The meeting point at x=q1 and y=p2 is empty
    if (!board[q1][p2].isNotEmpty) {
        c1 = isThisLineEmpty(board, p1, p2, q1, p2);// Path_check from block 1 to the meeting point
        c2 = isThisLineEmpty(board, q1, q2, q1, p2);// Path_check from block 2 to the meeting point
        if (c1 && c2) {
            return true;
        }
    }
    return false; 
}

bool Zcheck(CELL_1** board, int p1, int p2, int q1, int q2) {
    if (p1 == q1 || p2 == q2) {
        return false;
    }
    bool c1, c2, c3;
    int x, y;

    x = (p2 > q2? q2 : p2);
    y = (p2 > q2? p2 : q2);

    for (int i = x + 1; i < y; i++) {
        c3 = isThisLineEmpty(board, p1, i, q1, i);
        if (c3) {
            c1 = isThisLineEmpty(board, p1, p2, p1, i);
            c2 = isThisLineEmpty(board, q1, q2, q1, i);
            if (c1 && c2)
                return true;
        }
    }
    if (q1 < p1) {
        x = q1;
        y = p1;
    }
    else {
        x = p1;
        y = q1;
    }
    for (int i = x + 1; i < y; i++) {
        c3 = isThisLineEmpty(board, i, p2, i, q2);
        if (c3) {
            c1 = isThisLineEmpty(board, p1, p2, i, p2);
            c2 = isThisLineEmpty(board, q1, q2, i, q2);
            if (c1 && c2)
                return true;
        }
    }
    return false;
}

bool Ucheck(CELL_1** board, int p1, int p2, int q1, int q2) {
    if (((p1 == q1) && (p1 == 0 || p1 == BOARDHEIGTH - 1) || ((p2 == q2) && (p2 == 0 || q2 == BOARDWIDTH - 1)))) {
        return true;
    }
    bool c1, c2, c3;
    int x, y;
    if (q2 < p2) {
        x = q2;
        y = p2;
    }
    else {
        x = p2;
        y = q2;
    }
    for (int i = 0; i < BOARDWIDTH; i++) {
        if (i <= x || i >= y) {
            c3 = isThisLineEmpty(board, p1, i, q1, i);
            if (c3) {
                c1 = isThisLineEmpty(board, p1, p2, p1, i);
                c2 = isThisLineEmpty(board, q1, q2, q1, i);
                if (c1 && c2) {
                    return true;
                }
            }
            else if (i == 0 || i == (BOARDWIDTH - 1)) {
                c1 = isThisLineEmpty(board, p1, p2, p1, i);
                c2 = isThisLineEmpty(board, q1, q2, q1, i);
                if ((c1 && c2) || (c1 && q2 == i) || (p2 == i && c2)) {
                    return true;
                }
            }
        }
    }

    if (q1 < p1) {
        x = q1;
        y = p1;
    }
    else {
        x = p1;
        y = q1;
    }
    for (int i = 0; i < BOARDHEIGTH; i++) {
        if (i <= x || i >= y) {
            c3 = isThisLineEmpty(board, i, p2, i, q2);
            if (c3) {
                c1 = isThisLineEmpty(board, p1, p2, i, p2);
                c2 = isThisLineEmpty(board, q1, q2, i, q2);
                if (c1 && c2) {
                    return true;
                }
            }
            else if (i == 0 || i == (BOARDHEIGTH - 1)) {
                c1 = isThisLineEmpty(board, p1, p2, i, p2);
                c2 = isThisLineEmpty(board, q1, q2, i, q2);
                if ((c1 && c2) || (c1 && q1 == i) || (p1 == i && c2)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool allcheck(CELL_1** board, int p1, int p2, int q1, int q2) {
    if (nextcheck(board, p1, p2, q1, q2)) {
        return true;
    }
    else if (is_I_Matching(board, p1, p2, q1, q2)) {
        return true;
    }
    else if (is_L_Matching(board, p1, p2, q1, q2)) {
        return true;
    }
    else if (Zcheck(board, p1, p2, q1, q2)) {
        return true;
    }
    else if (Ucheck(board, p1, p2, q1, q2)) {
        return true;
    }
    return false;
}

bool checkValidPairs(CELL_1** board) {
    char check = 'A';
    while (check >= 'A' && check <= 'Z') {
        int cnt = 0;
        int* pos = new int[BOARDHEIGTH * BOARDWIDTH];
        for (int i = 0; i < BOARDHEIGTH; i++) {
            for (int j = 0; j < BOARDWIDTH; j++) {
                if (board[i][j].c == check && board[i][j].isNotEmpty) {
                    pos[cnt++] = i;
                    pos[cnt++] = j;
                }
            }
        }
        for (int i = 0; i < cnt - 2; i += 2) {
            for (int j = i + 2; j < cnt; j += 2) {
                if (allcheck(board, pos[i], pos[i + 1], pos[j], pos[j + 1])) {
                    delete[] pos;
                    return true;
                }
            }
        }
        check++;
        delete[] pos;
    }
    return false;
}