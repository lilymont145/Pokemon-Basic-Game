#pragma once
#include"struct.h"
int Menu();
void resultScreen(int& status);
void LoginScreen();
void RegisterScreen(player& p);
int chooseSize();
int chooseSizeD();
void customBoard(int& BOARDHEIGHT, int& BOARDWIDTH);
void shuffleScreen();
void getPlayerInfo(player& p);
void readLeaderBoard(player accN[], int& numPlayers);
void writeLeaderBoard(player p);
void displayLeaderBoard(player acc[], int& numPlayers);
void readLeaderBoardDiff(player acc[], int& numPlayers);
void writeLeaderBoardDiff(player p);
int chooseLeaderBoard();
void HackingNormal(player accountN[],int number_player,player Info);
void HackingHard(player accountH[],int number_player,player Info);
void HackingScreen(player accountH[],int number_player1,player accountN[],int number_player,player Info);

