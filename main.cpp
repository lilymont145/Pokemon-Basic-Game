#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <fstream>


#define PADDING 500
#define NAMESIZE 50
#define PASSSIZE 50
#define BOARDSIZE 999
#define URLSIZE 100

using namespace std;
void outputMenu(int& selection);
void randomMap(char matrix[][BOARDSIZE], int nC, int mR);
int main()
{
    srand((unsigned int)time(NULL));
    int selection = 1;
    // do{
    // Output the main menu 
    // outputMenu(selection);
    // switch (selection)
    // {
    //     case 1:
    //     {
    //      break;
    //     }
    //     case 2:
    //     {
    //      break;
    //     }
    // }
    // }while (selection != 3);
    char MAP1[100][BOARDSIZE];
    int n=3,m=4;
    randomMap(MAP1, n, m);
    for(int i=0;i<n;i++)
     {
          for(int j=0;j<m;j++)
          {
               cout<<MAP1[i][j]<<" ";
          }
          cout<<endl;
     }
    system("Pause");
    return 0;
}
void outputMenu(int& selection){
    cout << "WELCOME TO THE MATCHING GAME";
    cout << endl;
    system("Color 07");
    cout << "1. START " << endl;
    cout << "2. LEADERBOARD " << endl;
    cout << "3. EXIT " << endl;
    cout << endl;
    cout << "SELECT OPTION " << endl;
    cin >> selection;
    while (selection > 3 || selection < 1)
    {
        cout << "ERROR. TYPE AGAIN " << endl;
        cin >> selection;
    }
    return;
}
bool CountOccurrences(char matrix[][BOARDSIZE], int nC, int mR,char check)
{
    int i,j;
    int count=0;
    for (i=0; i<nC; i++)
    {
        for (j=0; j<mR; j++)
        {
           if(matrix[i][j]==check)
           {
            count++;
           }
        }
    }
    if (count%2==0)
    {
        return 1;
    }
    else return 0;
}
void randomMap(char matrix[][BOARDSIZE], int nC, int mR, int level){
    int i,j;
    int check=0;
    do{
    for (i=0; i<nC; i++)
    {
        for (j=0; j<mR; j++)
        {
            matrix[i][j] = (char)('A'+rand()%('Z'-'A'+1));
        }
    }
    for (i=0; i<nC; i++)
    {
        for (j=0; j<mR; j++)
        {
            check +=CountOccurrences(matrix, nC, mR, matrix[i][j]);
        }
    }
    }while (check!=(nC*mR));


}
bool isDelete(char matrix[][BOARDSIZE],int x,int y, int z,int t,bool isVisited[][BOARDSIZE])
{
    if (matrix[x][y]!=matrix[z][t])
    {
        return 0;
    }

}
bool isIMatching(char matrix[][BOARDSIZE],int x,int y, int z,int t,bool isVisited[][BOARDSIZE])
{
    if (x==z)
    {
        int temp=(y>t)?t:y;
        int temp1=(y<t)?t:y;
        for(int j = temp + 1; j < temp1; j++)
        {
            if(isVisited[x][j] == 0)
            return 0;
        }
        return 1;
    }
    else if(y==t)
    {
        int temp=(x>z)?z:x;
        int temp1=(x<z)?z:x;
        for(int j = temp + 1; j < temp1; j++)
        {
            if(isVisited[x][j] == 0)
            return 0;
        }
        return 1;
    }

}
bool isLMatching(char matrix[][BOARDSIZE],int x,int y, int z,int t,bool isVisited[][BOARDSIZE])
{
    int higherRow=(x>z)?x:z;
    int higherColumn=(y<t)?t:y;
    if(higherRow==x&&higherColumn==t)
    {
        int meetX=x;
        int meetY=t;
        if(isVisited[meetX][meetY]==0)
        {
            return false;
        }
        else
        {
            for(int j = y+1; j < t; j++)
            {
                if (isVisited[x][j]==0)
                return 0;
            }
            for(int j = x-1; j > z; j--)
            {
                if (isVisited[x][j]==0)
                return 0;
            }
            return 1;
        }
    }
    if(higherRow==x&&higherColumn==y)
    {
        int meetX=z;
        int meetY=t;
        if(isVisited[meetX][meetY]==0)
        {
            return false;
        }
        else
        {
            for(int j = t + 1; j< y; j++)
            {
                if (isVisited[z][j]==0)
                return 0;
            }
            for(int j = z-1; j> x; j--)
            {
                if (isVisited[z][j]==0)
                return 0;
            }
            return 1;
        }
    }
}

