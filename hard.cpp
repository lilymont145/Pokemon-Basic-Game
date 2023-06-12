#include "LinkedList.h"
void drawBacgroundCell2(CELL2** board, int& BOARDHEIGHT, int& BOARDWIDTH)
{
	for (int i = 0; i < BOARDHEIGHT; i++)
	{
		CELL2* tmp = board[i];
		while (tmp != NULL)
		{
			if (tmp->letter = ' ')
			{
				tmp->drawBG();
			}
			tmp->pNext;
		}
	}
}
//This function adds a node to the end of a linked list
void push(CELL2*& head, CELL2* node)
{
	//If the list is empty, the node is the head
	if (head == NULL)
		head = node;
	else
	{
		//Create a temporary pointer to the head
		CELL2* tmp = head;

		//Iterate through the list until the last node is found
		while (tmp->pNext != NULL)
		{
			tmp = tmp->pNext;
		}

		//Set the last node's next pointer to the new node
		tmp->pNext = node;
	}
}


void createBoard(CELL2** board, int& BOARDHEIGHT, int& BOARDWIDTH)
{
	srand(time(NULL));
	//Create a node and push it into the board
	for (int i = 0; i < BOARDHEIGHT; i++)
	{
		board[i] = NULL;
		for (int j = 0; j < BOARDWIDTH; j++)
		{
			CELL2* newNode = new CELL2;
			newNode->i = i;
			newNode->j = j;
			newNode->pNext = NULL;
			push(board[i], newNode);
		}
	}

	//Put all the letters into the board
	int flag = (BOARDHEIGHT * BOARDWIDTH) / 2; //Mark half of the board
	while (flag)
	{
		int i;
		int cntPair = 2;
		char c = 'A' + rand() % 26;
		while (cntPair)
		{
			i = rand() % (BOARDHEIGHT);
			int j = rand() % (BOARDWIDTH);
			CELL2* mark = findPos(board, j, i, BOARDHEIGHT, BOARDWIDTH);
			if (mark->letter == ' ')
			{
				mark->letter = c;
				cntPair--;
			}
		}
		flag--;
	}
}

void deleteBoardView(CELL2** board, int& BOARDHEIGHT, int& BOARDWIDTH)
{
	for (int i = 0; i < BOARDHEIGHT; i++)
	{
		CELL2* tmp;
		while (board[i] != NULL) //Delete every nodes from a row
		{
			tmp = board[i];
			board[i] = board[i]->pNext;
			tmp->deleteBox();
			if (tmp->j < BOARDHEIGHT || tmp->j < BOARDWIDTH)
				tmp->drawBG();
			Sleep(500);
			delete tmp;
		}
	}
	delete[]board;
}

void displayBoardView(CELL2** board, int& BOARDHEIGHT, int& BOARDWIDTH)
{
	//Draw cells for every rows
	for (int i = 0; i < BOARDHEIGHT; i++)
	{
		CELL2* tmp = board[i];
		while (tmp != NULL)
		{
			tmp->drawBox(112);
			tmp = tmp->pNext;
		}
	}
}

void gameDisplay2()
{
	for (int i = 93; i <= 117; i++)
	{
		goToXY(i, 4);
		cout << char(196);
		goToXY(94, 5);
		cout << "Arrow keys: To navigate";
		goToXY(94, 6);
		cout << "Press a: To select";
		goToXY(94, 7);
		cout << "Press esc: To exit";
		goToXY(i, 8);
		cout << char(196);
		goToXY(94, 9);
		cout << "Press b: To suggest";
		goToXY(94, 10);
		cout << "Press s: To shuffle";
		goToXY(i, 11);
		cout << char(196);
	}

	for (int j = 5; j < 11; j++)
	{
		goToXY(92, j);
		cout << char(179);
		goToXY(118, j);
		cout << char(179);
	}
}

bool autoShuffle2(CELL2** board, int& BOARDHEIGHT, int& BOARDWIDTH)
{
	for (int i = 0; i < BOARDHEIGHT; i++)
	{
		CELL2* tmp = board[i];
		while (tmp != NULL)
		{
			if (tmp != NULL)
			{
				if (!checkValidPair2(board, BOARDHEIGHT, BOARDWIDTH))
				{
					shuffleBoard2(board, BOARDHEIGHT, BOARDWIDTH);
					return true;
				}
			}
			tmp = tmp->pNext;
		}
	}
	return false;
}
void renderBoard2(CELL2** board, int& BOARDHEIGHT, int& BOARDWIDTH)
{
	for (int i = 0; i < BOARDHEIGHT; i++)
	{
		CELL2* tmp = board[i];
		while (tmp != NULL)
		{
			tmp->drawBox(112);
			tmp = tmp->pNext;
			Sleep(50);
		}
	}
}
void moveInBoard2(CELL2** board, int& BOARDHEIGHT, int& BOARDWIDTH, int& status, int& streak, int& pairup, position& pos, player& p, position selectedPos[])
{
	int keybind, key;
	position a, b;
	CELL2* tmp, * pos1, * pos2;
	CELL2* hili1, * hili2;
	keybind = _getch();
	if (keybind && keybind != 224) // Not an arrow key
	{
		if (keybind == ESC_KEY) // An ESC key
		{
			status = 1; // You quit the game, back to main menu
		}

		else if (keybind == SHUFFLE_KEY)
		{
			shuffleBoard2(board, BOARDHEIGHT, BOARDWIDTH);
			p.point -= 20;
			Sleep(50);
		}

		else if (keybind == HELP_KEY)
		{
			if (moveSuggestion2(board, BOARDHEIGHT, BOARDWIDTH, a, b))
			{
				hili1 = findPos(board, a.x, a.y, BOARDHEIGHT, BOARDWIDTH);
				hili2 = findPos(board, b.x, b.y, BOARDHEIGHT, BOARDWIDTH);
				if (hili1 !=NULL && hili2 != NULL)
				{
					hili1->highlightMove(40);
					hili2->highlightMove(40);
					p.point -= 50;
					Sleep(300);
				}
			}
		}

		else if (keybind == ENTER_KEY)
		{
			if (pos.x == selectedPos[0].x && pos.y == selectedPos[0].y)
			{
				tmp = findPos(board, pos.x, pos.y, BOARDHEIGHT, BOARDWIDTH);
				tmp->drawBox(70); //white background when select the cell
				Sleep(500);

				tmp->isSelected = false;
				pairup = 2;
				selectedPos[0] = { -1,-1 };
			}

			else
			{
				//Select 2 cells
				selectedPos[2 - pairup].x = pos.x;
				selectedPos[2 - pairup].y = pos.y;
				tmp = findPos(board, pos.x, pos.y, BOARDHEIGHT, BOARDWIDTH);
				tmp->isSelected = true;
				pairup--;

				if (pairup == 0)
				{
					pos1 = findPos(board, selectedPos[0].x, selectedPos[0].y, BOARDHEIGHT, BOARDWIDTH);
					pos2 = findPos(board, selectedPos[1].x, selectedPos[1].y, BOARDHEIGHT, BOARDWIDTH);

					if (pos1->letter == pos2->letter)
					{
						if (allMethod(board, selectedPos[0].y, selectedPos[0].x, selectedPos[1].y, selectedPos[1].x, BOARDHEIGHT, BOARDWIDTH))
						{
							p.point += 60;
							goToXY(40, 0);
							cout << "Point: " << p.point;

							if (streak < 9) {
								streak++;
								goToXY(70, 0);
								cout << "STREAK: " << streak;
							}

							pos1->drawBox(40);
							pos2->drawBox(40);
							Sleep(500);

							deleteBoard2(board, selectedPos[0].y, selectedPos[0].x, selectedPos[1].y, selectedPos[1].x, BOARDHEIGHT, BOARDWIDTH);
						}

						//No path connection between 2 selected cells
						else
						{
							pos1->drawBox(70);
							pos2->drawBox(70);
							Sleep(500);

							streak = 1;
							goToXY(70, 0);
							cout << "STREAK: " << streak;
						}
					}
					//Wrong matching letter
					else
					{
						pos1->drawBox(70);
						pos2->drawBox(70);
						Sleep(500);

						streak = 1;
						goToXY(70, 0);
						cout << "STREAK: " << streak;
					}

					//Return to their original position

					pos1->isSelected = false;
					pos2->isSelected = false;
					pairup = 2;
					selectedPos[0] = { -1,-1 };
					selectedPos[1] = { -1,-1 };

					for (int i = pos.y; i < BOARDHEIGHT; i++)
					{
						for (int j = pos.x; j < BOARDWIDTH; j++)
						{
							tmp = findPos(board, j, i, BOARDHEIGHT, BOARDWIDTH);
							if (tmp != NULL)
							{
								pos.x = j;
								pos.y = i;
								return;
							}
						}
					}

					for (int i = 0; i <= pos.y; i++)
					{
						for (int j = 0; j <= pos.x; j++)
						{
							tmp = findPos(board, j, i, BOARDHEIGHT, BOARDWIDTH);
							if (tmp != NULL)
							{
								pos.x = j;
								pos.y = i;
								return;
							}
						}
					}
				}
			}
		}
	}
	else
	{
		if ((pos.x != selectedPos[0].x || pos.y != selectedPos[0].y) && (pos.x != selectedPos[1].x || pos.y != selectedPos[1].y)) // check if this box is selected
		{
			tmp = findPos(board, pos.x, pos.y, BOARDHEIGHT, BOARDWIDTH);
			tmp->isSelected = false;
		}

		switch (key = _getch())
		{

		case KEY_UP: //Arrow up

			for (int i = pos.x; i < BOARDWIDTH; i++)
			{
				for (int j = pos.y - 1; j >= 0; j--)
				{
					if (findPos(board, i, j, BOARDHEIGHT, BOARDWIDTH) != NULL)
					{
						pos.x = i;
						pos.y = j;
						return;
					}
				}
			}

			for (int i = pos.x - 1; i >= 0; i--)
			{
				for (int j = pos.y - 1; j >= 0; j--) {
					if (findPos(board, i, j, BOARDHEIGHT, BOARDWIDTH) != NULL)
					{
						pos.x = i;
						pos.y = j;
						return;
					}
				}
			}

			for (int i = pos.x; i < BOARDWIDTH; i++)
			{
				for (int j = BOARDHEIGHT - 1; j > pos.y; j--)
				{
					if (findPos(board, i, j, BOARDHEIGHT, BOARDWIDTH) != NULL)
					{
						pos.x = i;
						pos.y = j;
						return;
					}
				}
			}

			for (int i = pos.x; i >= 0; i--)
			{
				for (int j = BOARDHEIGHT - 1; j > pos.y; j--)
				{
					if (findPos(board, i, j, BOARDHEIGHT, BOARDWIDTH) != NULL)
					{
						pos.x = i;
						pos.y = j;
						return;
					}
				}
			}

			break;

		case KEY_DOWN: //Arrow down

			for (int i = pos.x; i < BOARDWIDTH; i++)
			{
				for (int j = pos.y + 1; j < BOARDHEIGHT; j++)
				{
					if (findPos(board, i, j, BOARDHEIGHT, BOARDWIDTH) != NULL)
					{
						pos.x = i;
						pos.y = j;
						return;
					}
				}
			}

			for (int i = pos.x - 1; i >= 0; i--)
			{
				for (int j = pos.y + 1; j < BOARDHEIGHT; j++)
				{
					if (findPos(board, i, j, BOARDHEIGHT, BOARDWIDTH) != NULL)
					{
						pos.x = i;
						pos.y = j;
						return;
					}
				}
			}

			for (int i = pos.x; i < BOARDWIDTH; i++)
			{
				for (int j = 0; j < pos.y; j++)
				{
					if (findPos(board, i, j, BOARDHEIGHT, BOARDWIDTH) != NULL)
					{
						pos.x = i;
						pos.y = j;
						return;
					}
				}
			}

			for (int i = pos.x - 1; i >= 0; i--)
			{
				for (int j = 0; j < pos.y; j++)
				{
					if (findPos(board, i, j, BOARDHEIGHT, BOARDWIDTH) != NULL)
					{
						pos.x = i;
						pos.y = j;
						return;
					}
				}
			}
			break;

		case KEY_LEFT: //Arrow left
			for (int i = pos.y; i >= 0; i--)
			{
				for (int j = pos.x - 1; j >= 0; j--)
				{
					if (findPos(board, j, i, BOARDHEIGHT, BOARDWIDTH) != NULL) {
						pos.x = j;
						pos.y = i;
						return;
					}

				}
			}

			for (int i = pos.y + 1; i < BOARDHEIGHT; i++)
			{
				for (int j = pos.x - 1; j >= 0; j--)
				{
					if (findPos(board, j, i, BOARDHEIGHT, BOARDWIDTH) != NULL) {
						pos.x = j;
						pos.y = i;
						return;
					}

				}
			}

			for (int i = pos.y; i >= 0; i--)
			{
				for (int j = BOARDWIDTH - 1; j > pos.x; j--)
				{
					if (findPos(board, j, i, BOARDHEIGHT, BOARDWIDTH) != NULL) {
						pos.x = j;
						pos.y = i;
						return;
					}
				}
			}

			for (int i = pos.y + 1; i < BOARDHEIGHT; i++)
			{
				for (int j = BOARDWIDTH - 1; j > pos.x; j--)
				{
					if (findPos(board, j, i, BOARDHEIGHT, BOARDWIDTH) != NULL) {
						pos.x = j;
						pos.y = i;
						return;
					}
				}

			}
			break;

		case KEY_RIGHT: //Arrow right

			for (int i = pos.y; i >= 0; i--)
			{
				for (int j = pos.x + 1; j < BOARDWIDTH; j++)
				{
					if (findPos(board, j, i, BOARDHEIGHT, BOARDWIDTH) != NULL) {
						pos.x = j;
						pos.y = i;
						return;
					}
				}
			}

			for (int i = pos.y + 1; i < BOARDHEIGHT; i++)
			{
				for (int j = pos.x; j < BOARDWIDTH; j++)
				{
					if (findPos(board, j, i, BOARDHEIGHT, BOARDWIDTH) != NULL) {
						pos.x = j;
						pos.y = i;
						return;
					}
				}
			}

			for (int i = pos.y; i >= 0; i--)
			{
				for (int j = 0; j < pos.x; j++)
				{
					if (findPos(board, j, i, BOARDHEIGHT, BOARDWIDTH) != NULL) {
						pos.x = j;
						pos.y = i;
						return;
					}
				}
			}

			for (int i = pos.y + 1; i < BOARDHEIGHT; i++)
			{
				for (int j = 0; j < pos.x; j++)
				{
					if (findPos(board, j, i, BOARDHEIGHT, BOARDWIDTH) != NULL) {
						pos.x = j;
						pos.y = i;
						return;
					}
				}
			}
			break;

		default:
			break;
		}
	}
}

void shuffleBoard2(CELL2** board, int& BOARDHEIGHT, int& BOARDWIDTH)
{
	srand(time(NULL));
	int count = 0;
	char* temp = new char[BOARDHEIGHT * BOARDWIDTH];
	CELL2* tmp;

	for (int i = 0; i < BOARDHEIGHT; i++)
	{
		tmp = board[i];
		while (tmp != NULL)
		{
			if (tmp != NULL)
			{
				temp[count++] = tmp->letter;
			}

			tmp = tmp->pNext;
		}
	}

	shuffleElements(temp, count);
	int index = 0;
	for (int i = 0; i < BOARDHEIGHT; i++)
	{
		tmp = board[i];
		while (tmp != NULL)
		{
			if (tmp != NULL)
			{
				tmp->letter = temp[index++];
			}

			tmp = tmp->pNext;
		}
	}

}
void initDiffMode(player& p)
{
	srand(time(NULL));
	int BOARDWIDTH = 0;
	int BOARDHEIGHT = 0;
	int mode = chooseSizeD();
	int time = 0;


	switch (mode)
	{
		case 0:
			BOARDHEIGHT = 4;
			BOARDWIDTH = 4;
			break;

		case 1:
			BOARDHEIGHT = 6;
			BOARDWIDTH = 6;
			break;

		case 2:
			customBoard(BOARDHEIGHT, BOARDWIDTH);
			Sleep(30);
			system("cls");
			break;
		default:
			break;
	}

	if (mode == 0 || mode == 1 || mode == 2)
	{
		CELL2** BOARD = new CELL2 * [BOARDHEIGHT];
		createBoard(BOARD, BOARDHEIGHT, BOARDWIDTH);

		position SelectedPos[] = { {-1,-1},{-1,-1} };
		int pairup = 2;
		int time = 0;
		position Cursor = { 0,0 };
		int status = 0; // 0: Currently playing
		// 1: The player has quitted the game

		int streak = 1;
		p.point = 0;
		goToXY(10, 0);
		cout << "NAME: "<<p.name;
		goToXY(40, 0);
		cout << "POINT: " << p.point;
		goToXY(70, 0);
		cout << "STREAK: " << streak;

		while (true)
		{
			findPos(BOARD, Cursor.x, Cursor.y, BOARDHEIGHT, BOARDWIDTH)->isSelected = true;

			if (time == 0) {
				renderBoard2(BOARD, BOARDHEIGHT, BOARDWIDTH);
				time++;
			}

			gameDisplay2();

			displayBoardView(BOARD, BOARDHEIGHT, BOARDWIDTH);

			moveInBoard2(BOARD, BOARDHEIGHT, BOARDWIDTH, status,streak, pairup, Cursor, p, SelectedPos);

			if (autoShuffle2(BOARD, BOARDHEIGHT, BOARDWIDTH)) {
				system("cls");
				shuffleScreen();
				Sleep(800);
				system("cls");
				drawBacgroundCell2(BOARD,BOARDHEIGHT,BOARDWIDTH);
				goToXY(10, 0);
                cout << "NAME: "<<p.name;
                goToXY(40, 0);
                cout << "POINT: " << p.point;
                goToXY(70, 0);
                cout << "STREAK: " << streak;

			}

			else if (!checkValidPair2(BOARD, BOARDHEIGHT, BOARDWIDTH)) {
				break;
			}

			else if (status == 1) { //Player has quitted the game, back to main menu
				break;
			}
			Sleep(10);
		}

		displayBoardView(BOARD, BOARDHEIGHT, BOARDWIDTH);
		deleteBoardView(BOARD, BOARDHEIGHT, BOARDWIDTH);
		p.point = p.point * streak;
		Sleep(1000);
		system("cls");

		if (status == 1)
		{
			resultScreen(status);
			char choice;
			goToXY(50, 17);
			cout << "Do you want to continue next game? (Y/N)";
			cin >> choice;
			if (choice == 'y' || choice == 'Y') {
				system("cls");
				initDiffMode(p);
			}
			else
				writeLeaderBoard(p);
		}

		else if (status != 1)
		{
			resultScreen(status);
			char choice;
			goToXY(50, 17);
			cout << "Do you want to continue next game? (Y/N)";
			cin >> choice;
			if (choice == 'y' || choice == 'Y') {
				system("cls");
				initDiffMode(p);
			}
			else
				writeLeaderBoardDiff(p);
			Sleep(2000);
		}
		system("cls");
	}
}
