#include<iostream>
#include<cstring>
#include<Windows.h>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;

struct position {
	int x, y;
};

struct player {
	string name = "";
	int point;
};

struct CELL1
{
	int i, j;
	char letter = ' ';
	bool isNotEmpty = true;
	bool isSelected = false;
	void drawBox(int);
	void deleteBox();
};

struct CELL2
{
	int i, j;
	char letter = ' ';
	bool isSelected = false;
	CELL2* pNext;
	void drawBox(int);
	void deleteBox();
};