#include"struct.h"
#include"console.h"
#include"Normal.h"
#include "Menu.h"
#include "LinkedList.h"


int main()
{
	player p;
	player accN[100]; player accD[100];
	int numPlayersN; int numPlayerD;
	int status; int leaderboard;
	int hack=0;
	PlaySound(TEXT("PikachuBG.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
	getPlayerInfo(p);
	initWindow(1000, 500);
	while ((status = Menu()) != 3)
	{

		switch (status)
		{
		case 0:
			initNormalMode(p);
			break;

		case 1:
			initDiffMode(p);
			break;

		case 2:
			leaderboard = chooseLeaderBoard();
			if (leaderboard == 0)
			{
				readLeaderBoard(accN, numPlayersN);
				displayLeaderBoard(accN, numPlayersN);
				hack=_getch();
				if(hack == HACK_KEY)
                {
                    system("cls");
                    HackingScreen(accD,numPlayerD,accN,numPlayersN,p);
                    system("cls");
                    break;
                }
                else
                {
                    system("cls");
                    break;
                }
			}
			else if (leaderboard == 1)
			{
				readLeaderBoardDiff(accD, numPlayerD);
				displayLeaderBoard(accD, numPlayerD);
				system("cls");
				if(hack == HACK_KEY)
                {
                    system("cls");
                    HackingScreen(accD,numPlayerD,accN,numPlayersN,p);
                    system("cls");
                    break;
                }
                else
                {
                    system("cls");
                    break;
                }
			}
			break;

		default:
			break;

		}
	}
	return 0;
}
