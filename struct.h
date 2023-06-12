#pragma once
#include<iostream>
#include<cstring>
#include<Windows.h>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<fstream>

#define PADDING 500 // bytes
#define NAMESIZE 100
#define PASSSIZE 100
#define BOARDSIZE 999
#define URLSIZE 100
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ESC_KEY 27
#define ENTER_KEY 97
#define SHUFFLE_KEY 115
#define HELP_KEY 98
#define HACK_KEY 107
using namespace std;

struct position {
	int x, y;
};

struct player {
	char name[NAMESIZE];
	int point;
};

struct saveState
{
	int* pos;
	char* saveLetter;
};

struct CELL1
{
	int i, j;
	char letter = ' ';
	bool isNotEmpty = true;
	bool isSelected = false;
	void drawBox(int);
	void deleteBox();
	void drawBG();
	void highlightMove(int);
};

struct CELL2
{
	int i, j;
	char letter = ' ';
	bool isSelected = false;
	CELL2* pNext;
	void drawBox(int);
	void deleteBox();
	void drawBG();
	void highlightMove(int);
};
