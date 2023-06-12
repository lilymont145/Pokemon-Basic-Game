#include "Normal.h"
void generateElements(char*& temp, int& nRows, int& nCols)
{
	temp = new char[nRows * nCols];
	int index = 0;

	for (int i = 0; i < (nRows * nCols) / 2; i++)
	{
		temp[i] = 'A' + rand() % 26;
	}

	for (int i = (nRows * nCols) / 2; i < nRows * nCols; i++)
	{
		temp[i] = temp[index++];
	}
}

int countRemaningElements(CELL1** board,int& BOARDHEIGHT, int& BOARDWIDTH)
{
	int count = 0;
	for (int i = 0; i < BOARDHEIGHT; i++)
	{
		for (int j = 0; j < BOARDWIDTH; j++)
		{
			if (board[i][j].isNotEmpty && board[i][j].letter != ' ')
			{
				count++;
			}
		}
	}
	return count;
}

void shuffleElements(char* temp, int& cnt)
{
	char swap;
	for (int i = 0; i < cnt; i++)
	{
		int swap_index = rand() % cnt;
		swap = temp[i];
		temp[i] = temp[swap_index];
		temp[swap_index] = swap;
	}
}
void shuffleBoard(CELL1** board, int& BOARDHEIGHT, int& BOARDWIDTH)
{
	int elements = countRemaningElements(board, BOARDHEIGHT, BOARDWIDTH);

	char* temp = new char[elements];
	int cnt = 0;
	for (int i = 0; i < BOARDHEIGHT; i++)
	{
		for (int j = 0; j < BOARDWIDTH; j++)
		{
			if (board[i][j].isNotEmpty && board[i][j].letter != ' ')
			{
				temp[cnt++] = board[i][j].letter;
			}
		}
	}

	shuffleElements(temp, cnt);

	int pos = 0;
	for (int i = 0; i < BOARDHEIGHT; i++)
	{
		for (int j = 0; j < BOARDWIDTH; j++)
		{
			if (board[i][j].isNotEmpty && board[i][j].letter != ' ')
			{
				board[i][j].letter = temp[pos++];
			}
		}
	}
	delete[]temp;


}
void initializeBoardView(CELL1**& board, int& rowNumbers, int& columeNumbers)
{
	srand(time(NULL));

	//Create a new board
	board = new CELL1 * [rowNumbers];

	for (int i = 0; i < rowNumbers; i++)
	{
		board[i] = new CELL1[columeNumbers];

		for (int j = 0; j < columeNumbers; j++) {
			board[i][j].j = j;
			board[i][j].i = i;
		}
	}

	//Generate elements to the board
	int pos = 0;
	char* temp;

	//Generate characters into a char array
	generateElements(temp, rowNumbers, columeNumbers);

	//Put all the elements into the board
	int flagPos = (rowNumbers * columeNumbers) / 2;
	while (flagPos) {
		int index;
		int cntPair = 2;
		while (cntPair)
		{
			int index = rand() % (rowNumbers * columeNumbers);

			if (board[index / columeNumbers][index % columeNumbers].letter == ' ') {

				board[index / columeNumbers][index % columeNumbers].letter = temp[pos++];
				cntPair--;
			}
		}
		flagPos--;
	}

	delete[]temp;
}

//delete a box when a pair up are made and after finished game
void deleteBoard(CELL1** board, int& rowNumbers, int& columeNumbers)
{
	for (int i = 0; i < rowNumbers; i++)
	{
		for (int j = 0; j < columeNumbers; j++)
		{
			if (board[i][j].isNotEmpty)
			{
				board[i][j].deleteBox();
				if (j < rowNumbers || j < columeNumbers)
				{
					board[i][j].drawBG();
				}
			}
		}
	}
	for (int i = 0; i < rowNumbers; i++)
	{
		delete[]board[i];
	}
	delete[]board;
}

void displayBoard(CELL1** board, int& rowNumbers, int& columeNumbers)
{
	for (int i = 0; i < rowNumbers; i++)
	{
		for (int j = 0; j < columeNumbers; j++)
		{
			board[i][j].drawBox(112);

		}
	}
}

void renderBoard(CELL1** board, int& rowNumbers, int& columeNumbers)
{
	for (int i = 0; i < rowNumbers; i++)
	{
		for (int j = 0; j < columeNumbers; j++)
		{
			board[i][j].drawBox(112);
			Sleep(50);
		}
	}
}

void gameDisplay()
{
	for (int i = 98; i <= 122; i++)
	{
		goToXY(i, 4);
		cout << char(196);
		goToXY(99, 5);
		cout << "Arrow keys: To navigate";
		goToXY(99, 6);
		cout << "Press a: To select";
		goToXY(99, 7);
		cout << "Press esc: To exit";
		goToXY(i, 8);
		cout << char(196);
		goToXY(99, 9);
		cout << "Press b: To suggest";
		goToXY(99, 10);
		cout << "Press s: To shuffle";
		goToXY(i, 11);
		cout << char(196);
	}

	for (int j = 5; j < 11; j++)
	{
		goToXY(97, j);
		cout << char(179);
		goToXY(123, j);
		cout << char(179);
	}
}

bool autoShuffle(CELL1** board, int& BOARDHEIGHT, int& BOARDWIDTH)
{
	for (int i = 0; i < BOARDHEIGHT; i++)
	{
		for (int j = 0; j < BOARDWIDTH; j++)
		{
			if (board[i][j].isNotEmpty)
			{
				if (!checkValidPairs(board, BOARDHEIGHT, BOARDWIDTH))
				{
					shuffleBoard(board, BOARDHEIGHT, BOARDWIDTH);
					return true;
				}
			}
		}
	}
	return false;
}

void moveInBoard(CELL1** board, int& BOARDHEIGHT, int& BOARDWIDTH, int& status, int& streak, int& pairup, position& pos, player& p, position selectedPos[])
{
	int keybind, key;
	position a, b;
	keybind = _getch();
	if (keybind && keybind != 224) // Not an arrow key
	{
		if (keybind == ESC_KEY) // An ESC key
		{
			status = 1; // You quit the game, back to main menu
		}
		else if (keybind == HELP_KEY)
		{
			if (moveSuggestion(board, BOARDHEIGHT, BOARDWIDTH, a, b))
			{
				if (board[a.x][a.y].isNotEmpty && board[b.x][b.y].isNotEmpty) {

					board[a.x][a.y].highlightMove(40); //green background
					board[b.x][b.y].highlightMove(40);
					p.point -= 20;
					Sleep(1000);
				}
			}
		}
		else if (keybind == SHUFFLE_KEY)
		{
			shuffleBoard(board, BOARDHEIGHT, BOARDWIDTH);
			p.point -= 10;
			Sleep(50);
		}
		else if (keybind == ENTER_KEY)
		{
			if (pos.x == selectedPos[0].x && pos.y == selectedPos[0].y)
			{
				board[selectedPos[0].y][selectedPos[0].x].drawBox(70); //white background
				Sleep(500);

				board[selectedPos[0].y][selectedPos[0].x].isSelected = false;
				pairup = 2;
				selectedPos[0] = { -1, -1 };
			}

			else
			{
				selectedPos[2 - pairup].x = pos.x;
				selectedPos[2 - pairup].y = pos.y;
				board[pos.y][pos.x].isSelected = true;
				pairup--;

				if (pairup == 0)
				{
					if (board[selectedPos[0].y][selectedPos[0].x].letter == board[selectedPos[1].y][selectedPos[1].x].letter) // if this pair is valid
					{
						if (allcheck(board, selectedPos[0].y, selectedPos[0].x, selectedPos[1].y, selectedPos[1].x, BOARDHEIGHT, BOARDWIDTH))
						{
							p.point += 40;

							goToXY(40, 0);
							cout << "Point: " << p.point;

							if (streak < 9) {
								streak++;
								goToXY(70, 0);
								cout << "STREAK: " << streak;
							}

							board[selectedPos[0].y][selectedPos[0].x].drawBox(40);
							board[selectedPos[1].y][selectedPos[1].x].drawBox(40);
							Sleep(500);

							board[selectedPos[0].y][selectedPos[0].x].isNotEmpty = false;
							board[selectedPos[0].y][selectedPos[0].x].deleteBox();
							if (selectedPos[0].x < BOARDHEIGHT || selectedPos[0].x < BOARDWIDTH) board[selectedPos[0].y][selectedPos[0].x].drawBG();

							board[selectedPos[1].y][selectedPos[1].x].isNotEmpty = false;
							board[selectedPos[1].y][selectedPos[1].x].deleteBox();
							if (selectedPos[1].x < BOARDHEIGHT || selectedPos[1].x < BOARDWIDTH) board[selectedPos[1].y][selectedPos[1].x].drawBG();
						}
						else
						{
							board[selectedPos[0].y][selectedPos[0].x].drawBox(70);
							board[selectedPos[1].y][selectedPos[1].x].drawBox(70);
							Sleep(500);

							streak = 1;
							goToXY(70, 0);
							cout << "STREAK: " << streak;
						}
					}

					else
					{

						board[selectedPos[0].y][selectedPos[0].x].drawBox(70);
						board[selectedPos[1].y][selectedPos[1].x].drawBox(70);
						Sleep(500);

						streak = 1;
						goToXY(70, 0);
						cout << "STREAK: " << streak;
					}

					//Return to their original position

					board[selectedPos[0].y][selectedPos[0].x].isSelected = false;
					board[selectedPos[1].y][selectedPos[1].x].isSelected = false;
					pairup = 2;
					selectedPos[0] = { -1, -1 };
					selectedPos[1] = { -1, -1 };

					for (int i = pos.y; i < BOARDHEIGHT; i++)
					{
						for (int j = pos.x; j < BOARDWIDTH; j++)
						{
							if (board[i][j].isNotEmpty) //Select the cell which is not empty
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
							if (board[i][j].isNotEmpty)
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
	//Moving around in the console using keyboard
	else
	{
		if ((pos.x != selectedPos[0].x || pos.y != selectedPos[0].y) && (pos.x != selectedPos[1].x || pos.y != selectedPos[1].y)) // check if this box is selected
			board[pos.y][pos.x].isSelected = false;

		switch (key=_getch())
		{
			case KEY_UP: //Arrow up

			for (int i = pos.x; i < BOARDWIDTH; i++)
			{
				for (int j = pos.y - 1; j >= 0; j--)
				{
					if (board[j][i].isNotEmpty) //only move around the cells that are empty
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
					if (board[j][i].isNotEmpty)
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
					if (board[j][i].isNotEmpty)
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
					if (board[j][i].isNotEmpty)
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
						if (board[j][i].isNotEmpty)
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
						if (board[j][i].isNotEmpty)
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
						if (board[j][i].isNotEmpty)
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
						if (board[j][i].isNotEmpty)
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
						if (board[i][j].isNotEmpty) {
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
						if (board[i][j].isNotEmpty) {
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
						if (board[i][j].isNotEmpty) {
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
						if (board[i][j].isNotEmpty) {
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
						if (board[i][j].isNotEmpty) {
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
						if (board[i][j].isNotEmpty) {
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
						if (board[i][j].isNotEmpty) {
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
						if (board[i][j].isNotEmpty) {
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

void initNormalMode(player& p)
{
	srand(time(NULL));
	int BOARDWIDTH;
	int BOARDHEIGHT;
	int mode = chooseSize();

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
		CELL1** BOARD;
		initializeBoardView(BOARD, BOARDHEIGHT, BOARDWIDTH);

		position SelectedPos[] = { {-1,-1},{-1,-1} };
		int pairup = 2;
		int time = 0;
		position Cursor = { 0,0 };
		int status = 0; // 0: Currently playing
		// 1: The player has quitted the game

		int streak = 1;
		p.point = 0;
		goToXY(10, 0);
		cout << "NAME: " << p.name;
		goToXY(40, 0);
		cout << "POINT: " << p.point;
		goToXY(70, 0);
		cout << "STREAK: " << streak;

		while (true)
		{
			BOARD[Cursor.y][Cursor.x].isSelected = true;

			if (time == 0) {
				renderBoard(BOARD, BOARDHEIGHT, BOARDWIDTH);
				time++;
			}

			gameDisplay();

			displayBoard(BOARD, BOARDHEIGHT, BOARDWIDTH);

			moveInBoard(BOARD, BOARDHEIGHT, BOARDWIDTH, status,streak, pairup, Cursor, p, SelectedPos);

			if (autoShuffle(BOARD, BOARDHEIGHT, BOARDWIDTH)) {
				system("cls");
				shuffleScreen();
				system("cls");
			}

			else if (!checkValidPairs(BOARD, BOARDHEIGHT, BOARDWIDTH)) {
				break;
			}

			else if (status == 1) {//Player has quitted the game, back to main menu
				break;
			}
			Sleep(10);

		}

		displayBoard(BOARD, BOARDHEIGHT, BOARDWIDTH);
		deleteBoard(BOARD, BOARDHEIGHT, BOARDWIDTH);
		p.point = p.point * streak;
		BOARDHEIGHT = 0; BOARDWIDTH = 0;
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
				initNormalMode(p);
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
				initNormalMode(p);
			}
			else
				writeLeaderBoard(p);
			Sleep(2000);
		}
	}
	system("cls");
}
