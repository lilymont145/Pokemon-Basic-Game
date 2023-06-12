#include"struct.h"
#include"CheckMatch1.h"

// Rewritten code with comments

// This function finds the position of a cell in a board given its x and y coordinates
CELL2* findPos(CELL2** board, int x, int y, int& BOARDHEIGHT, int& BOARDWIDTH)
{
	// Check if the coordinates are within the board's boundaries
	if (x<0 || x>BOARDWIDTH - 1 || y<0 || y>BOARDHEIGHT - 1)
		return NULL;

	// Set a temporary pointer to the row of the board
	CELL2* tmp = board[y];

	// Iterate through the row until the cell with the given x coordinate is found
	while (tmp != NULL)
	{
		if (tmp->j == x)
		{
			return tmp;
		}

		tmp = tmp->pNext;
	}
	return NULL;
}

bool I_Method(CELL2** board, int y1, int x1, int y2, int x2, int& BOARDHEIGHT, int& BOARDWIDTH)
{
	//Check 2 cells on the same column

	CELL2* tmp; CELL2* head;
	int i = 0;
	int minPos, maxPos;

	if (x1 == x2)
	{
		minPos = (y1 < y2 ? y1 : y2);
		maxPos = (y1 < y2 ? y2 : y1);
		head = findPos(board, x1, minPos, BOARDHEIGHT, BOARDWIDTH); // Find the postition of the 1st cell in pair
		tmp = head;

		while (tmp == NULL)
		{
			minPos++;

			tmp = findPos(board, x1, minPos, BOARDHEIGHT, BOARDWIDTH);

			if (minPos == maxPos)
				return true;

			if (tmp != NULL)
				return false;
		}

		while (tmp != NULL)
		{
			i++;

			tmp = findPos(board, x1, minPos + i, BOARDHEIGHT, BOARDWIDTH); // check the horizontal line if it empty

			while (tmp == NULL)
			{
				i++;
				tmp = findPos(board, x1, minPos + i, BOARDHEIGHT, BOARDWIDTH);

				if (minPos + i > maxPos) // The line between 2 cells empty
					return true;
			}

			if (minPos + i > maxPos)
				return true;

			if (minPos + i == maxPos) {

				if (tmp == NULL)
					return true;

				if (tmp->letter == head->letter)
					return true;

				return false;
			}

			if (tmp != NULL)
				return false;

		}
	}

	//Check 2 cells on the same column

	if (y1 == y2)
	{
		i = 0;
		minPos = (x1 < x2 ? x1 : x2);
		maxPos = (x1 < x2 ? x2 : x1);

		head = findPos(board, minPos, y1, BOARDHEIGHT, BOARDWIDTH);
		tmp = head;

		while (tmp == NULL)
		{
			minPos++;
			tmp = findPos(board, x1, minPos, BOARDHEIGHT, BOARDWIDTH);
			head = tmp;

			if (minPos > maxPos)
				return true;
		}

		while (tmp != NULL)
		{
			i++;
			tmp = tmp->pNext;

			if (minPos + i > maxPos)
				return true;


			if (minPos + i == maxPos) {
				if (tmp == NULL)
					return true;

				if (tmp->letter == head->letter)
					return true;

				return false;
			}

			if (tmp != NULL)
				return false;
		}

	}

	return false;
}

bool L_Method(CELL2** board, int y1, int x1, int y2, int x2, int& BOARDHEIGHT, int& BOARDWIDTH)
{
	CELL2* tmp;
	tmp = findPos(board, x2, y1,BOARDHEIGHT,BOARDWIDTH);// Find the position of the opposite cell of the selected cell

	if (tmp == NULL) //if that position is empty
	{
		int x = x2, y = y1;
		while (tmp == NULL)
		{
			if (x2 > x1)
				x--;
			else
				x++;
			tmp = findPos(board, x, y1, BOARDHEIGHT, BOARDWIDTH); //find the position of the first selected cell
		}
		tmp = NULL;
		while (tmp == NULL)
		{
			if (y2 > y1)
				y++;
			else
				y--;
			tmp = findPos(board, x2, y, BOARDHEIGHT, BOARDWIDTH); //find the position of the first selected cell
		}

		if (I_Method(board, y1, x1, y1, x, BOARDHEIGHT, BOARDWIDTH)) //Check if the first cell can connect to the opposite cell
			if (I_Method(board, y2, x2, y, x2, BOARDHEIGHT, BOARDWIDTH))
				return true;

		else if (I_Method(board, y1, x1, y1, x, BOARDHEIGHT, BOARDWIDTH))
			if (I_Method(board, y2, x2, y, x2,BOARDHEIGHT,BOARDWIDTH))
					return true;

		tmp = findPos(board, x1, y2, BOARDHEIGHT, BOARDWIDTH);
		if (tmp == NULL)
		{
			int x = x1, y = y2;

			while (tmp == NULL)
			{
				if (x1 < x2)
					x++;
				else
					x--;
				tmp = findPos(board, x, y2, BOARDHEIGHT, BOARDWIDTH);
			}
			tmp = NULL;

			while (tmp == NULL)
			{
				if (y1 < y2)
					y--;
				else
					y++;
				tmp = findPos(board, x1, y, BOARDHEIGHT, BOARDWIDTH);
			}

			if (I_Method(board, y1, x1, y1, x, BOARDHEIGHT, BOARDWIDTH))
				if (I_Method(board, y2, x2, y, x2, BOARDHEIGHT, BOARDWIDTH))
					return true;

			else if (I_Method(board, y2, x2, y2, x, BOARDHEIGHT, BOARDWIDTH))
				if (I_Method(board, y1, x1, y, x1, BOARDHEIGHT, BOARDWIDTH))
					return true;
		}

	}

	return false;
}


bool UandZMethod(CELL2** board, int y1, int x1, int y2, int x2, int& BOARDHEIGHT, int& BOARDWIDTH)
{
	CELL2* head;
	CELL2* tail;
	int x, y;

	if ((findPos(board, x1, y1 - 1, BOARDHEIGHT, BOARDWIDTH) == NULL && findPos(board, x2, y2 - 1, BOARDHEIGHT, BOARDWIDTH) == NULL) && (y1 == y2)) //left side column
		return true; // Check the path between 2 cells on the same column whether if it is empty

	else if ((findPos(board, x1, y1 + 1, BOARDHEIGHT, BOARDWIDTH) == NULL && findPos(board, x2, y2 + 1, BOARDHEIGHT, BOARDWIDTH) == NULL) && (y1 == y2)) //right side column
		return true;

	if (x1 == 0 && x2 == 0) //On the same first row
		return true;

	else if (findPos(board, x1, y1, BOARDHEIGHT, BOARDWIDTH)->pNext == NULL && findPos(board, x2, y2, BOARDHEIGHT, BOARDWIDTH)->pNext == NULL)
		return true; // Check if the path of the first cell and second cell are empty

	if ((I_Method(board, y1, x1, 0, x1, BOARDHEIGHT, BOARDWIDTH) || I_Method(board, y1, x1, BOARDHEIGHT - 1, x1, BOARDHEIGHT, BOARDWIDTH)) && (y1 != y2))
	{
		tail = findPos(board, x2, y1, BOARDHEIGHT, BOARDWIDTH); // Check the first cell to the first turning point on the barrier row

		if (tail == NULL)
		{
			y = y1;
			if (I_Method(board, y1, x1, 0, x1, BOARDHEIGHT, BOARDWIDTH)) {
				while (tail == NULL)
				{
					y++;
					tail = findPos(board, x2, y, BOARDHEIGHT, BOARDWIDTH);
				}
			}
			if (I_Method(board, y, x2, y2, x2, BOARDHEIGHT, BOARDWIDTH))
				return true; // Check if the turning point can connect to the second cell

			y = y1;

			if (I_Method(board, y1, x1, BOARDHEIGHT - 1, x1, BOARDHEIGHT, BOARDWIDTH)) {
				tail = NULL;

					while (tail == NULL)
					{
						y--;
						tail = findPos(board, x2, y, BOARDHEIGHT, BOARDWIDTH);
					}
			}

			if (I_Method(board, y, tail->j, y2, x2, BOARDHEIGHT, BOARDWIDTH))
				return true;

		}

		if (I_Method(board, tail->i, tail->j, y2, x2, BOARDHEIGHT, BOARDWIDTH))
			return true;

	}

	if ((I_Method(board, y2, x2, 0, x2, BOARDHEIGHT, BOARDWIDTH) || I_Method(board, y2, x2, BOARDHEIGHT - 1, x2, BOARDHEIGHT, BOARDWIDTH)) && (y1 != y2))
	{
		tail = findPos(board, x1, y2,BOARDHEIGHT,BOARDWIDTH);
		if (tail == NULL)
		{
			y = y2;
			if (I_Method(board, y2, x2, 0, x2, BOARDHEIGHT, BOARDWIDTH))
			{
				while (tail == NULL)
				{
					y++;
					tail = findPos(board, x1, y, BOARDHEIGHT, BOARDWIDTH);
				}
			}

			if (I_Method(board, y, x1, y1, x1, BOARDHEIGHT, BOARDWIDTH))
				return true;
			y = y2;
			if (I_Method(board, y2, x2, BOARDHEIGHT - 1, x2, BOARDHEIGHT, BOARDWIDTH))
				while (tail == NULL)
				{
					y--;
					tail = findPos(board, x1, y, BOARDHEIGHT, BOARDWIDTH);
				}
			if (I_Method(board, y, x1, y1, x1, BOARDHEIGHT, BOARDWIDTH))
				return true;
		}
		else if (I_Method(board, tail->i, tail->j, y1, x1, BOARDHEIGHT, BOARDWIDTH))
			return true;
	}


	if (x1 != x2)
	{
		for (int i = 0; i < BOARDHEIGHT; i++)
		{
			head = findPos(board, x1, i, BOARDHEIGHT, BOARDWIDTH);
			x = x1;
			tail = findPos(board, x2, i, BOARDHEIGHT, BOARDWIDTH);
			x = x2;
			if (I_Method(board, i, x1, i, x2, BOARDHEIGHT, BOARDWIDTH))
			{
				if (I_Method(board, i, x1, y1, x1, BOARDHEIGHT, BOARDWIDTH) && I_Method(board, i, x2, y2, x2, BOARDHEIGHT, BOARDWIDTH))
					return true;
			}
		}
	}

	if (y1 != y2)
	{
		for (int i = 0; i < BOARDHEIGHT; i++)
		{
			head = findPos(board, i, y1, BOARDHEIGHT, BOARDWIDTH);
			y = y1;
			tail = findPos(board, i, y2, BOARDHEIGHT, BOARDWIDTH);
			y = y2;

			if (I_Method(board, y1, i, y2, i, BOARDHEIGHT, BOARDWIDTH))
			{
				if (I_Method(board, y1, i, y1, x1, BOARDHEIGHT, BOARDWIDTH) && I_Method(board, y2, i, y2, x2, BOARDHEIGHT, BOARDWIDTH))
					return true;
			}
		}
	}

	return false;
}

bool allMethod(CELL2** board, int y1, int x1, int y2, int x2, int& BOARDHEIGHT, int& BOARDWIDTH)
{
	if (I_Method(board, y1, x1, y2, x2, BOARDHEIGHT, BOARDWIDTH))
		return true;
	else if (L_Method(board, y1, x1, y2, x2, BOARDHEIGHT, BOARDWIDTH))
		return true;
	else if (UandZMethod(board, y1, x1, y2, x2, BOARDHEIGHT, BOARDWIDTH))
		return true;

	return false;
}

void deleteNode(CELL2** board, int y, int x, int& BOARDHEIGHT, int& BOARDWIDTH)
{
	CELL2* p = findPos(board, x, y, BOARDHEIGHT, BOARDWIDTH);
	if (x == 0) {
		if (board[y]->pNext == NULL)
		{
			board[y]->deleteBox();
			if (board[y]->j < BOARDHEIGHT || board[y]->j < BOARDWIDTH) board[y]->drawBG();
			board[y] = NULL;
			return;
		}
		board[y]->letter = p->pNext->letter;

		p = board[y]->pNext;
		if (p->pNext == NULL) {
			p->deleteBox();
			if (p->j < BOARDHEIGHT || p->j < BOARDWIDTH) p->drawBG();
			delete p;
			board[y]->pNext = NULL;
		}
		else {
			while (p->pNext->pNext != NULL)
			{
				p->letter = p->pNext->letter;
				p = p->pNext;
			}
			p->letter = p->pNext->letter;
			p->pNext->deleteBox();
			if (p->pNext->j < BOARDHEIGHT || p->pNext->j < BOARDWIDTH) p->pNext->drawBG();
			delete p->pNext;
			p->pNext = NULL;
		}
	}
	else if (p->pNext != NULL) {
		while (p->pNext->pNext != NULL)
		{
			p->letter = p->pNext->letter;
			p = p->pNext;
		}
		p->letter = p->pNext->letter;
		p->pNext->deleteBox();
		if (p->pNext->j < BOARDHEIGHT || p->pNext->j < BOARDWIDTH) p->pNext->drawBG();
		delete p->pNext;
		p->pNext = NULL;
	}
	else {
		p->deleteBox();
		if (p->j < BOARDHEIGHT || p->j < BOARDWIDTH) p->drawBG();
		delete p;
		p = findPos(board, x - 1, y, BOARDHEIGHT, BOARDWIDTH);
		p->pNext = NULL;
	}
}

void deleteBoard2(CELL2** board, int y1, int x1, int y2, int x2, int& BOARDHEIGHT, int& BOARDWIDTH) {
	if (x1 > x2)
	{
		deleteNode(board, y1, x1, BOARDHEIGHT, BOARDWIDTH);
		deleteNode(board, y2, x2, BOARDHEIGHT, BOARDWIDTH);
	}
	else {
		deleteNode(board, y2, x2, BOARDHEIGHT, BOARDWIDTH);
		deleteNode(board, y1, x1, BOARDHEIGHT, BOARDWIDTH);
	}
}

bool checkValidPair2(CELL2** board, int& BOARDHEIGHT, int& BOARDWIDTH)
{
	CELL2* Head, * temp;
	for (int i = 0; i < BOARDHEIGHT; i++) {
		Head = board[i];
		while (Head != NULL) {
			int j = i;
			temp = Head->pNext;
			while (temp == NULL && j < BOARDHEIGHT - 1) {
				j++;
				temp = board[j];
			}
			while (temp != NULL) {
				if (Head->letter == temp->letter) {
					if (allMethod(board, Head->i, Head->j, temp->i, temp->j,BOARDHEIGHT,BOARDWIDTH)) {
						return true;
					}
				}
				temp = temp->pNext;
				if ((temp == NULL) && (j < BOARDHEIGHT -1)) {
					j++;
					temp = findPos(board, 0, j, BOARDHEIGHT, BOARDWIDTH);
				}
			}
			Head = Head->pNext;
		}
	}
	return false;
}

bool moveSuggestion2(CELL2** board, int& BOARDHEIGHT, int& BOARDWIDTH, position& a, position& b)
{
	CELL2* Head, * temp;
	for (int i = 0; i < BOARDHEIGHT; i++) {
		Head = board[i];
		while (Head != NULL) {
			int j = i;
			temp = Head->pNext;
			while (temp == NULL && j < BOARDHEIGHT - 1) {
				j++;
				temp = board[j];
			}
			while (temp != NULL) {
				if (Head->letter == temp->letter) {
					if (allMethod(board, Head->i, Head->j, temp->i, temp->j, BOARDHEIGHT, BOARDWIDTH))
					{
						a.x = Head->j;
						a.y = Head->i;
						b.x = temp->j;
						b.y = temp->i;
						return true;
					}
				}
				temp = temp->pNext;
				if ((temp == NULL) && (j < BOARDHEIGHT - 1)) {
					j++;
					temp = findPos(board, 0, j, BOARDHEIGHT, BOARDWIDTH);
				}
			}
			Head = Head->pNext;
		}
	}
	return false;
}
