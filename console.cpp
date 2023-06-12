#include"struct.h"
using namespace std;

//Used to move your cursor to a specified location in the console
void goToXY(int rowPos, int colPos)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	int xPos = rowPos;
	int yPos = colPos;

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
	setCursorToConsole(false, 0);
}



