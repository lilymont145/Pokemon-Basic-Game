#include<Windows.h>
using namespace std;

//Used to move your cursor to a specific location in the console
void goToRowsColumns(int rowPos, int colPos)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	int xPos = colPos;
	int yPos = rowPos;

	COORD cursorPos;

	cursorPos.X = xPos;
	cursorPos.Y = yPos;
	SetConsoleCursorPosition(console, cursorPos);

}

//Set the shape and size of your cursor
void setCursorToConsole(bool visible, DWORD size)
{
	if (size == 0) {
		size = 20;
	}

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;

	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console, &lpCursor);
}

//Resize the window console
void resizeWindow(int x, int y)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, x, y, TRUE);
}

//Modify the window console
void initWindow(int length, int width)
{
	resizeWindow(width, length);
	setCursorToConsole(0, 0);
}

