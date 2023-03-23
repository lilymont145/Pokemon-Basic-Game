#include"struct.h"
#include"console.h"
#include<conio.h>

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

void initializeBoardView(CELL1**& board, int& rowNumbers, int& columnNumbers)
{
	srand(time(NULL));

	//Create a new board
	board = new CELL1 * [rowNumbers];

	for (int i = 0; i < rowNumbers; i++)
	{
		board[i] = new CELL1[columnNumbers];

		for (int j = 0; j < columnNumbers; j++) {
			board[i][j].j = j;
			board[i][j].i = i;
		}
	}

	//Generate elements to the board
	int pos = 0;
	char* temp;

	//Generate characters into a char array
	generateElements(temp, rowNumbers, columnNumbers);

	//Put all the elements into the board
	int flagPos = (rowNumbers * columnNumbers) / 2;
	while (flagPos) {
		int index;
		int cntPair = 2;
		while (cntPair)
		{
			int index = rand() % (rowNumbers * columnNumbers);

			if (board[index / columnNumbers][index % columnNumbers].letter == ' ') {

				board[index / columnNumbers][index % columnNumbers].letter = temp[pos++];
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
				board[i][j].deleteBox();
			//display background (implement later...)
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

//void moveInBoard(CELL1** board, int& rowNumbers, int& columeNumbers, int& status, int& pairup, position& pos, player& p, position selectedPos[])
//{
//	int keybind, key;
//	keybind = _getch();
//
//}