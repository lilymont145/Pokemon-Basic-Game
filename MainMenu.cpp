#include"Console.h"
#include "Menu.h"

//Main menu of the game
int Menu()
{
    int keybind, key, curChoice = 0;
    int choice[4] = { 0,0,0,0 };
    goToXY(50, 3);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << ".______    __   __  ___      ___       ______  __    __   __    __ ";
    goToXY(50, 4);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << "|   _  \\  |  | |  |/  /     /   \\     /      ||  |  |  | |  |  |  |";
    goToXY(50, 5);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << "|  |_)  | |  | |  '  /     /  ^  \\   |  ,----'|  |__|  | |  |  |  |";
    goToXY(50, 6);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << "|   ___/  |  | |    <     /  /_\\  \\  |  |     |   __   | |  |  |  |";
    goToXY(50, 7);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << "|  |      |  | |  .  \\   /  _____  \\ |  `----.|  |  |  | |  `--'  |";
    goToXY(50, 8);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << "| _|      |__| |__|\\__\\ /__/     \\__\\ \\______||__|  |__|  \\______/";

    goToXY(68, 28);
    cout << "Press a to choose";
    goToXY(68, 30);
    cout << "Press arrow key to navigate";

    for (int i = 63; i <= 100; i++)
    {
        goToXY(i, 26);
        cout << char(196);
        goToXY(i, 32);
        cout << char(196);
    }

    while (true)
    {
        choice[curChoice] = 1;
        if (choice[0])
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
            for (int i = 0; i < 4; i++)
            {
                goToXY(77, 11 + i);
                cout << "         ";
            }
            goToXY(78, 12);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112+3);
            cout << "NORMAL";

        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            for (int i = 0; i < 4; i++)
            {
                goToXY(77, 11 + i);
                cout << "         ";
            }
            goToXY(78, 12);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout << "NORMAL";
        }

        if (choice[1])
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
            for (int i = 0; i < 4; i++)
            {
                goToXY(77, 14 + i);
                cout << "          ";
            }
            goToXY(78, 15);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112 + 4);
            cout << "HARD";
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            for (int i = 0; i < 4; i++)
            {
                goToXY(77, 14 + i);
                cout << "          ";
            }
            goToXY(78, 15);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "HARD";
        }

        if (choice[2])
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
            for (int i = 0; i < 4; i++)
            {
                goToXY(77, 17 + i);
                cout << "            ";
            }
            goToXY(78, 18);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112 + 5);
            cout << "LEADERBOARD";
        }

        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            for (int i = 0; i < 4; i++)
            {
                goToXY(77, 17 + i);
                cout << "            ";
            }
            goToXY(78, 18);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            cout << "LEADERBOARD";
        }

        if (choice[3])
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
            for (int i = 0; i < 3; i++)
            {
                goToXY(77, 21 + i);
                cout << "         ";
            }
            goToXY(78, 22);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112 + 6);
            cout << "EXIT";
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            for (int i = 0; i < 3; i++)
            {
                goToXY(77, 21 + i);
                cout << "         ";
            }
            goToXY(78, 22);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "EXIT";
        }

        if (keybind = _getch())
        {
            if (keybind != 224)
            {
                if (keybind == ENTER_KEY)
                {
                    system("cls");
                    return curChoice;
                }
            }

            else
            {
                switch (key = _getch())
                {
                    case KEY_UP:
                        choice[curChoice] = 0;
                        if (curChoice > 0)
                            curChoice--;
                        else
                            curChoice = 3;
                        break;
                    case KEY_DOWN:
                        choice[curChoice] = 0;
                        if (curChoice < 3)
                            curChoice++;
                        else
                            curChoice = 0;
                        break;
                    default:
                        break;
                }
            }
        }
    }

}

void resultScreen(int& status)
{
    if (status == 1) {

        goToXY(50, 10);
        cout << " __   __  _______  __   __    ___      _______  _______  _______ ";
        goToXY(50, 11);
        cout << "|  | |  ||       ||  | |  |  |   |    |       ||       ||       |";
        goToXY(50, 12);
        cout << "|  |_|  ||   _   ||  | |  |  |   |    |   _   ||  _____||    ___|";
        goToXY(50, 13);
        cout << "|       ||  | |  ||  |_|  |  |   |    |  | |  || |_____ |   |___ ";
        goToXY(50, 14);
        cout << "|_     _||  |_|  ||       |  |   |___ |  |_|  ||_____  ||    ___|";
        goToXY(50, 15);
        cout << "  |   |  |       ||       |  |       ||       | _____| ||   |___ ";
        goToXY(50, 16);
        cout << "  |___|  |_______||_______|  |_______||_______||_______||_______|";
    }
    else
    {
        goToXY(50, 10);
        cout << " __   __  _______  __   __    _     _  ___   __    _ ";
        goToXY(50, 11);
        cout << "|  | |  ||       ||  | |  |  | | _ | ||   | |  |  | |";
        goToXY(50, 12);
        cout << "|  |_|  ||   _   ||  | |  |  | || || ||   | |   |_| |";
        goToXY(50, 13);
        cout << "|       ||  | |  ||  |_|  |  |       ||   | |       | ";
        goToXY(50, 14);
        cout << "|_     _||  |_|  ||       |  |       ||   | |  _    |";
        goToXY(50, 15);
        cout << "  |   |  |       ||       |  |   _   ||   | | | |   | ";
        goToXY(50, 16);
        cout << "  |___|  |_______||_______|  |__| |__||___| |_|  |__|";
    }
}

void LoginScreen()
{

    for (int i = 56 ; i <= 99; i++)
    {
        if (i <= 69 && i >= 57) {
            goToXY(i,11);
            cout << char(196);
        }
        goToXY(i, 14);
        cout << char(196);
        goToXY(i, 23);
        cout << char(196);
    }

    goToXY(60, 12);
    cout << "LOG IN";
    goToXY(57, 17);
    cout << "USER:";
    goToXY(57, 20);
    cout << "PASS:";
    for (int i = 12; i <= 22; i++)
    {
        if (i <= 13)
        {
            goToXY(56, i);
            cout << char(179);
            goToXY(70, i);
            cout << char(179);
        }

        else if (i >= 15)
        {
            goToXY(55, i);
            cout << char(179);
            goToXY(100, i);
            cout << char(179);
        }
    }
    int a;
    COORD cursor = { 70,17 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
    cin >> a;
    cursor = { 70,20 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
    cin >> a;



    cout << "\n\n\n\n\n";
    system("pause");
}

void RegisterScreen(player& p)
{

    for (int i = 56; i <= 99; i++)
    {
        if (i <= 69 && i >= 57) {
            goToXY(i, 11);
            cout << char(196);
        }
        goToXY(i, 14);
        cout << char(196);
        goToXY(i, 23);
        cout << char(196);
    }

    goToXY(60, 12);
    cout << "REGISTER";
    goToXY(57, 17);
    cout << "USER:";
    goToXY(57, 20);
    cout << "PASS:";
    for (int i = 12; i <= 22; i++)
    {
        if (i <= 13)
        {
            goToXY(56, i);
            cout << char(179);
            goToXY(70, i);
            cout << char(179);
        }

        else if (i >= 15)
        {
            goToXY(55, i);
            cout << char(179);
            goToXY(100, i);
            cout << char(179);
        }
    }
    COORD cursor = { 70,17 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
    cin.getline(p.name, NAMESIZE - 1);
    cursor = { 70,20 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);

    ofstream fp;
    fp.open("account.bin", ios::app | ios::binary);
    if (!fp.is_open())
    {
        return;
    }
    fp.write((char*)&p.name, sizeof(NAMESIZE));
    fp.close();
}

int chooseSize()
{
    goToXY(30, 10);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    cout << " ________   ________  ________  _____ ______   ________  ___               _____ ______   ________  ________  _______      ";
    goToXY(30, 11);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    cout << "|\\   ___  \\|\\   __  \\|\\   __  \\|\\   _ \\  _   \\|\\   __  \\|\\  \\             |\\   _ \\  _   \\|\\   __  \\|\\   ___ \\|\\  ___ \\     ";
    goToXY(30, 12);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    cout << "\\ \\  \\\\ \\  \\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\\\\\__\\ \\  \\ \\  \\|\\  \\ \\  \\            \\ \\  \\\\\\__\\ \\  \\ \\  \\|\\  \\ \\  \\_|\\ \\ \\   __/|   ";
    goToXY(30, 13);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    cout << " \\ \\  \\\\ \\  \\ \\  \\\\\\  \\ \\   _  _\\ \\  \\\\|__| \\  \\ \\   __  \\ \\  \\            \\ \\  \\\\|__| \\  \\ \\  \\\\\\  \\ \\  \\ \\\\ \\ \\  \\_|/__  ";
    goToXY(30, 14);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    cout << "  \\ \\  \\\\ \\  \\ \\  \\\\\\  \\ \\  \\\\  \\\\ \\  \\    \\ \\  \\ \\  \\ \\  \\ \\  \\____        \\ \\  \\    \\ \\  \\ \\  \\\\\\  \\ \\  \\_\\\\ \\ \\  \\_|\\ \\ ";
    goToXY(30, 15);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    cout << "   \\ \\__\\\\ \\__\\ \\_______\\ \\__\\\\ _\\\\ \\__\\    \\ \\__\\ \\__\\ \\__\\ \\_______\\       \\ \\__\\    \\ \\__\\ \\_______\\ \\_______\\ \\_______\\\\";
    goToXY(30, 16);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    cout << "    \\|__| \\|__|\\|_______|\\|__|\\|__|\\|__|     \\|__|\\|__|\\|__|\\|_______|        \\|__|     \\|__|\\|_______|\\|_______|\\|_______|";

    cout << R"(

     __                                _.--'"7
    `. `--._                        ,-'_,-  ,'
     ,'  `-.`-.                   /' .'    ,|
     `.     `. `-     __...___   /  /     - j
       `.     `  `.-""        " .  /       /
         \     /                ` /       /
          \   /                         ,'
          '._'_               ,-'       |
             | \            ,|  |   ...-'
             || `         ,|_|  |   | `             _..__
            /|| |          | |  |   |  \  _,_    .-"     `-.
           | '.-'          |_|_,' __!  | /|  |  /           \
   ,-...___ .=                  ._..'  /`.| ,`,.      _,.._ |
  |   |,.. \     '  `'        ____,  ,' `--','  |    /      |
 ,`-..'  _)  .`-..___,---'_...._/  .'      '-...'   |      /
'.__' ""'      `.,------'"'      ,/            ,     `.._.' `.
  `.             | `--........,-'.            .         \     \
    `-.          .   '.,--""     |           ,'\        |      .
       `.       /     |          L          ,\  .       |  .,---.
         `._   '      |           \        /  .  L      | /   __ `.
            `-.       |            `._   ,    l   .    j |   '  `. .
              |       |               `"' |  .    |   /  '      .' |
              |       |                   j  |    |  /  , `.__,'   |
              `.      L                 _.   `    j ,'-'           |
               |`"---..\._______,...,--' |   |   /|'      /        j
               '       |                 |   .  / |      '        /
                .      .              ____L   \'  j    -',       /
               / `.     .          _,"     \   | /  ,-','      ,'
              /    `.  ,'`-._     /         \  i'.,'_,'      .'
             .       `.      `-..'             |_,-'      _.'
             |         `._      |            ''/      _,-'
             |            '-..._\             `__,.--'
            ,'           ,' `-.._`.            .
           `.    __      |       "'`.          |
             `-"'  `""""'            7         `.
                                    `---'--.,'"`' mh )";


    int keybind, key, curChoice = 0;
    int choice[4] = { 0,0,0,0 };

    while (true)
    {
        choice[curChoice] = 1;
        if (choice[0])
        {
            for (int i = 0; i < 4; i++)
            {
                goToXY(77, 11 + i);
                cout << "      ";
            }
            goToXY(78, 12);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout << " 4x4 ";
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            for (int i = 0; i < 4; i++)
            {
                goToXY(77, 11 + i);
                cout <<  "       ";
            }
            goToXY(78, 12);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << " 4x4 ";
        }

        if (choice[1])
        {

            for (int i = 0; i < 4; i++)
            {
                goToXY(77, 14 + i);
                cout <<  "       ";
            }
            goToXY(78, 15);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout << " 6x6 ";
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            for (int i = 0; i < 4; i++)
            {
                goToXY(77, 14 + i);
                cout << "       ";
            }
            goToXY(78, 15);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            cout << " 6x6 ";
        }

        if (choice[2])
        {
            for (int i = 0; i < 4; i++)
            {
                goToXY(77, 17 + i);
                cout << "         ";
            }
            goToXY(78, 18);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout << " CUSTOM ";
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
            for (int i = 0; i < 4; i++)
            {
                goToXY(77, 17 + i);
                cout << "         ";
            }
            goToXY(78, 18);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
            cout << " CUSTOM ";
        }
        if (choice[3])
        {
            for (int i = 0; i < 3; i++)
            {
                goToXY(78, 20 + i);
                cout << "         ";
            }
            goToXY(79, 21);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout << "EXIT";
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            for (int i = 0; i < 3; i++)
            {
                goToXY(78, 20 + i);
                cout << "         ";
            }
            goToXY(79, 21);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            cout << "EXIT";
        }

        if (keybind = _getch())
        {
            if (keybind != 224)
            {
                if (keybind == ENTER_KEY)
                {
                    system("cls");
                    return curChoice;
                }
            }

            else
            {
                switch (key = _getch())
                {
                case KEY_UP:
                    choice[curChoice] = 0;
                    if (curChoice > 0)
                        curChoice--;
                    else
                        curChoice = 3;
                    break;
                case KEY_DOWN:
                    choice[curChoice] = 0;
                    if (curChoice < 3)
                        curChoice++;
                    else
                        curChoice = 0;
                    break;
                default:
                    break;

                }
            }

        }
    }

}

int chooseSizeD()
{
    goToXY(30, 10);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << " ___  ___  ________  ________  ________          _____ ______   ________  ________  ______      ";
    goToXY(30, 11);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "|\\  \\|\\  \\|\\   __  \\|\\   __  \\|\\   ___ \\        |\\   _ \\  _   \\|\\   __  \\|\\   ___ \\|\\ ___ \\     ";
    goToXY(30, 12);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "\\ \\  \\\\\\  \\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\_|\\ \\       \\ \\  \\\\\\__\\ \\  \\ \\  \\|\\  \\ \\  \\_|\\ \\ \\   __/|    ";
    goToXY(30, 13);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << " \\ \\   __  \\ \\   __  \\ \\   _  _\\ \\  \\ \\\\ \\       \\ \\  \\\\|__| \\  \\ \\  \\\\\\  \\ \\  \\ \\\\ \\ \\  \\_|/__  ";
    goToXY(30, 14);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "  \\ \\  \\ \\  \\ \\  \\ \\  \\ \\  \\\\  \\\\ \\  \\_\\\\ \\       \\ \\  \\    \\ \\  \\ \\  \\\\\\  \\ \\  \\_\\\\ \\ \\  \\_|\\ \\  ";
    goToXY(30, 15);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "   \\ \\  \\ \\  \\ \\  \\ \\  \\ \\  \\\\  \\\\ \\  \\_\\\\ \\       \\ \\  \\    \\ \\  \\ \\  \\\\\\  \\ \\  \\_\\\\ \\ \\  \\_|\\ \\ ";
    goToXY(30, 16);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "   \\ \\__\\ \\__\\ \\__\\ \\__\\ \\__\\\\ _\\\\ \\_______\\       \\ \\__\\    \\ \\__\\ \\_______\\ \\_______\\ \\_______\\";
    goToXY(30, 16);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "    \\|__|\\|__|\\|__|\\|__|\\|__|\\|__|\\|_______|        \\|__|     \\|__|\\|_______|\\|_______|\\|_______|";

    cout << R"(

                ."-,.__
                 `.     `.  ,
              .--'  .._,'"-' `.
             .    .'         `'
             `.   /          ,'
               `  '--.   ,-"'
                `"`   |  \
                   -. \, |
                    `--Y.'      ___.
                         \     L._, \
               _.,        `.   <  <\                _
             ,' '           `, `.   | \            ( `
          ../, `.            `  |    .\`.           \ \_
         ,' ,..  .           _.,'    ||\l            )  '".
        , ,'   \           ,'.-.`-._,'  |           .  _._`.
      ,' /      \ \        `' ' `--/   | \          / /   ..\
    .'  /        \ .         |\__ - _ ,'` `        / /     `.`.
    |  '          ..         `-...-"  |  `-'      / /        . `.
    | /           |L__           |    |          / /          `. `.
   , /            .   .          |    |         / /             ` `
  / /          ,. ,`._ `-_       |    |  _   ,-' /               ` \
 / .           \"`_/. `-_ \_,.  ,'    +-' `-'  _,        ..,-.    \`.
.  '         .-f    ,'   `    '.       \__.---'     _   .'   '     \ \
' /          `.'    l     .' /          \..      ,_|/   `.  ,'`     L`
|'      _.-""` `.    \ _,'  `            \ `.___`.'"`-.  , |   |    | \
||    ,'      `. `.   '       _,...._        `  |    `/ '  |   '     .|
||  ,'          `. ;.,.---' ,'       `.   `.. `-'  .-' /_ .'    ;_   ||
|| '              V      / /           `   | `   ,'   ,' '.    !  `. ||
||/            _,-------7 '              . |  `-'    l         /    `||
. |          ,' .-   ,' ||               | .-.        `.      .'     ||
 `'        ,'    `".'    |               |    `.        '. -.'       `'
          /      ,'      |               |,'    \-.._,.'/'
          .     /        .               .       \    .''
        .`.    |         `.             /         :_,'.'
          \ `...\   _     ,'-.        .'         /_.-'
           `-.__ `,  `'   .  _.>----''.  _  __  /
                .'        /"'          |  "'   '_
               /_|.-'\ ,".             '.'`__'-( \
                 / ,"'"\,'               `/  `-.|" mh )";


    int keybind, key, curChoice = 0;
    int choice[4] = { 0,0,0,0 };

    while (true)
    {
        choice[curChoice] = 1;
        if (choice[0])
        {
            for (int i = 0; i < 4; i++)
            {
                goToXY(77, 11 + i);
                cout << "      ";
            }
            goToXY(78, 12);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout << " 4x4 ";
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            for (int i = 0; i < 4; i++)
            {
                goToXY(77, 11 + i);
                cout << "       ";
            }
            goToXY(78, 12);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << " 4x4 ";
        }

        if (choice[1])
        {

            for (int i = 0; i < 4; i++)
            {
                goToXY(77, 14 + i);
                cout << "       ";
            }
            goToXY(78, 15);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout << " 6x6 ";
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            for (int i = 0; i < 4; i++)
            {
                goToXY(77, 14 + i);
                cout << "       ";
            }
            goToXY(78, 15);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            cout << " 6x6 ";
        }

        if (choice[2])
        {
            for (int i = 0; i < 4; i++)
            {
                goToXY(77, 17 + i);
                cout << "         ";
            }
            goToXY(78, 18);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout << " CUSTOM ";
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
            for (int i = 0; i < 4; i++)
            {
                goToXY(77, 17 + i);
                cout << "         ";
            }
            goToXY(78, 18);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
            cout << " CUSTOM ";
        }
        if (choice[3])
        {
            for (int i = 0; i < 3; i++)
            {
                goToXY(78, 20 + i);
                cout << "         ";
            }
            goToXY(79, 21);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout << "EXIT";
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            for (int i = 0; i < 3; i++)
            {
                goToXY(78, 20 + i);
                cout << "         ";
            }
            goToXY(79, 21);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            cout << "EXIT";
        }

        if (keybind = _getch())
        {
            if (keybind != 224)
            {
                if (keybind == ENTER_KEY)
                {
                    system("cls");
                    return curChoice;
                }
            }

            else
            {
                switch (key = _getch())
                {
                case KEY_UP:
                    choice[curChoice] = 0;
                    if (curChoice > 0)
                        curChoice--;
                    else
                        curChoice = 3;
                    break;
                case KEY_DOWN:
                    choice[curChoice] = 0;
                    if (curChoice < 3)
                        curChoice++;
                    else
                        curChoice = 0;
                    break;
                default:
                    break;

                }
            }

        }
    }

}

void customBoard(int& BOARDHEIGHT, int& BOARDWIDTH)
{
    char size = '0';
    char size2 = '0';
    do {
        goToXY(48, 2);
        cout << " ____     __  __  ____    ______  _____            ______  ________   ____      ";
        goToXY(48, 3);
        cout << "/\\  _`\\  /\\ \\/\\ \\/\\  _`\\ /\\__  _\\/\\  __`\\  /'\\_/`\\/\\__  _\\/\\_____  \\ /\\  _`\\    ";
        goToXY(48, 4);
        cout << "\\ \\ \\/\\_\\\\ \\ \\ \\ \\ \\,\\L\\_\\/_/\\ \\/\\ \\ \\/\\ \\/\\      \\/_/\\ \\/\\/____//'/'\\ \\ \\L\\_\\  ";
        goToXY(48, 5);
        cout << " \\ \\ \\/_/_\\ \\ \\ \\ \\/_\\__ \\  \\ \\ \\ \\ \\ \\ \\ \\ \\ \\__\\ \\ \\ \\ \\     //'/'  \\ \\  _\\L  ";
        goToXY(48, 6);
        cout << "  \\ \\ \\L\\ \\\\ \\ \\_\\ \\/\\ \\L\\ \\ \\ \\ \\ \\ \\ \\_\\ \\ \\ \\_/\\ \\ \\_\\ \\__ //'/'___ \\ \\ \\L\\ \\\\";
        goToXY(48, 7);
        cout << "   \\ \\____/ \\ \\_____\\ `\\____\\ \\ \\_\\ \\ \\_____\\ \\_\\\\ \\_\\/\\_____\\/\\_______\\\\ \\____/";
        goToXY(48, 8);
        cout << "    \\/___/   \\/_____/\\/_____/  \\/_/  \\/_____/\\/_/ \\/_/\\/_____/\\/_______/ \\/___/ ";
        goToXY(56, 11);
        cout << "----------------------------------------------------";
        goToXY(69, 12);
        cout << "INPUT THE SIZE OF THE BOARD";
        goToXY(58, 14);
        cout << "BOARDHEIGHT: ";
        goToXY(58, 16);
        cout << "BOARDWIDTH: ";
        goToXY(56, 18);
        cout << "----------------------------------------------------";
        goToXY(75, 20);
        cout << "CONDITIONS ";
        goToXY(58, 22);
        cout << "1/ THE INPUT SIZE MUST BE A VALID NUMBER";
        goToXY(59, 23);
        cout << "BETWEEN 1 TO 8";
        goToXY(58, 26);
        cout << "2/ THE MULTIPLY OF THE HEIGHT AND THE WIDTH";
        goToXY(58, 27);
        cout << "MUST BE AN EVEN NUMBER AND GREATER THAN 2";
        goToXY(56, 29);
        cout << "----------------------------------------------------";

        COORD cursor = { 74,14 };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
        cin >> size;
        cin.ignore();
        BOARDHEIGHT = int(size - '0');
        cursor = { 74,16 };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
        cin >> size2;
        cin.ignore();
        BOARDWIDTH = int(size2 - '0');
        Sleep(20);
        if (size > 56 || size < 48 || size2>56 || size2 < 48)
        {
            goToXY(75, 31);
            cout << "Invalid number";
            Sleep(100);
            system("cls");
        }
        else if ((BOARDHEIGHT * BOARDWIDTH) % 2 != 0 || BOARDHEIGHT * BOARDWIDTH == 2)
        {
            goToXY(75, 31);
            cout << "Invalid size";
            Sleep(100);
            system("cls");
        }
    } while (size > 56 || size < 48 || (size2 > 56 || size2 < 48) || (BOARDHEIGHT * BOARDWIDTH) % 2 != 0 || BOARDHEIGHT * BOARDWIDTH == 2);
}

void writeLeaderBoard(player p)
{
    ofstream outFile("scores1.bin", ios::app | ios::binary);// create binary file for writing
    if (!outFile) { // check if file opened successfully
        cout << "Error opening file" << endl;
        return;
    }
    // write player name to file
    outFile.write(p.name, sizeof(p.name));
    // write player score to file
    outFile.write((char*)&p.point, sizeof(int));
    outFile.close(); // close file
}

void readLeaderBoard(player accN[], int& numPlayers) {
    ifstream inFile("scores1.bin", ios::binary); // open binary file for reading
    if (!inFile) { // check if file opened successfully
        cout << "Error opening file" << endl;
        return;
    }
    numPlayers = 0;
    while (inFile.read((char*)&accN[numPlayers], sizeof(player))) { // read player record from file
        numPlayers++;
    }
    inFile.close(); // close file
}

void getPlayerInfo(player& p)
{
    goToXY(50, 12);
    cout << "Enter player name: ";
    cin >> p.name;
    cin.ignore();
    p.point = 0;
    system("cls");
}

void shuffleScreen()
{
    cout << R"(
                                  .-') _                                        _   .-')                      (`-.      ('-.
                                 (  OO) )                                      ( '.( OO )_                  _(OO  )_  _(  OO)
         .-'),-----.  ,--. ,--.  /     '._        .-'),-----.    ,------.       ,--.   ,--.).-'),-----. ,--(_/   ,. \(,------.
        ( OO'  .-.  ' |  | |  |  |'--...__)      ( OO'  .-.  '('-| _.---'       |   `.'   |( OO'  .-.  '\   \   /(__/ |  .---'
        /   |  | |  | |  | | .-')'--.  .--'      /   |  | |  |(OO|(_\           |         |/   |  | |  | \   \ /   /  |  |
        \_) |  |\|  | |  |_|( OO )  |  |         \_) |  |\|  |/  |  '--.        |  |'.'|  |\_) |  |\|  |  \   '   /, (|  '--.
          \ |  | |  | |  | | `-' /  |  |           \ |  | |  |\_)|  .--'        |  |   |  |  \ |  | |  |   \     /__) |  .--'
           `'  '-'  '('  '-'(_.-'   |  |            `'  '-'  '  \|  |_)         |  |   |  |   `'  '-'  '    \   /     |  `---..-..-..-.
             `-----'   `-----'      `--'              `-----'    `--'           `--'   `--'     `-----'      `-'      `------'`-'`-'`-')";


    Sleep(2000);
}

void displayLeaderBoard(player acc[], int& numPlayers)
{
    system("cls");

    for (int i = 0; i < numPlayers - 1; i++)
    {
        for (int j = i + 1; j < numPlayers; j++)
        {
            if (acc[i].point < acc[j].point)
            {
                player tmp = acc[i];
                acc[i] = acc[j];
                acc[j] = tmp;
            }
        }
    }

    cout << R"(








                                             _      _____  ___ ______ _________________  _____  ___  ____________
                                            | |    |  ___|/ _ \|  _  \  ___| ___ \ ___ \|  _  |/ _ \ | ___ \  _  \
                                            | |    | |__ / /_\ \ | | | |__ | |_/ / |_/ /| | | / /_\ \| |_/ / | | |
                                            | |    |  __||  _  | | | |  __||    /| ___ \| | | |  _  ||    /| | | |
                                            | |____| |___| | | | |/ /| |___| |\ \| |_/ /\ \_/ / | | || |\ \| |/ /
                                            \_____/\____/\_| |_/___/ \____/\_| \_\____/  \___/\_| |_/\_| \_|___/

                                                                                                                     )";


    for (int i = 45; i <= 105; i++)
    {
        goToXY(i, 17);
        cout << char(196);
        goToXY(i, 24);
        cout << char(196);
    }
    goToXY(50, 18);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    cout << "NAME";
    goToXY(100, 18);
    cout << "POINT";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    int index = 19;
    if (numPlayers < 5) {
        for (int i = 0; i < numPlayers; i++)
        {
            goToXY(50, index);
            cout << acc[i].name;
            goToXY(100, index);
            cout << acc[i].point;
            index++;
        }
    }
    else if (numPlayers >= 5)
    {
        for (int i = 0; i < 5; i++)
        {
            goToXY(50, index);
            cout << acc[i].name;
            goToXY(100, index);
            cout << acc[i].point;
            index++;
        }
    }
    cout << "\n\n\n\n\n\n\n\n\n";
    system("pause");
}

void HackingNormal(player accountN[],int number_player,player Info)
{
    for(int i = 0; i < number_player; i++)
    {
        if(strcmp(Info.name,accountN[i].name))
        {
            goToXY(50,12);
            cout<<"Hacking account: "<<Info.name<<" (Y/N): ";
            char select;
            cin>>select;
            if(select =='Y'||select =='y')
            {
                goToXY(50,13);
                cout<<"Enter points: ";
                cin>>accountN[i].point;
                Info.point = accountN[i].point;
                writeLeaderBoard(Info);
                return;
            }
            else{
                cout<<"There's no player";
                return;
            }
        }
    }
}
void HackingHard(player accountH[],int number_player,player Info)
{
    for(int i = 0; i < number_player; i++)
    {
        if(strcmp(Info.name,accountH[i].name))
        {
            goToXY(50,12);
            cout<<"Hacking account: "<<Info.name<<" (Y/N): ";
            char select;
            cin>>select;
            if(select =='Y'||select =='y')
            {
                goToXY(50,13);
                cout<<"\nEnter points";
                cin>>accountH[i].point;
                Info.point = accountH[i].point;
                writeLeaderBoardDiff(Info);
                return;
            }
            else{
                cout<<"There's no player";
                return;
            }
        }
    }
}
void HackingScreen(player accountH[],int number_player1,player accountN[],int number_player,player Info)
{
    cout<<R"(










                ******       **       ******  **   **       *******     *******     *******   ****     ****
                /*////**     ****     **////**/**  **       /**////**   **/////**   **/////** /**/**   **/**
                /*   /**    **//**   **    // /** **        /**   /**  **     //** **     //**/**//** ** /**
                /******    **  //** /**       /****         /*******  /**      /**/**      /**/** //***  /**
                /*//// ** **********/**       /**/**        /**///**  /**      /**/**      /**/**  //*   /**
                /*    /**/**//////**//**    **/**//**       /**  //** //**     ** //**     ** /**   /    /**
                /******* /**     /** //****** /** //**      /**   //** //*******   //*******  /**        /**
                ///////  //      //   //////  //   //       //     //   ///////     ///////   //         // )";
    char select;
    goToXY(50,30);
    cout<<"Do you want to continue? ";
    cin >>select;
    if(select =='Y'||select =='y')
    {
        system("cls");
        goToXY(50,12);
        cout<<"Normal or Hard (N/H)? ";
        cin>> select;
        if(select =='N'||select =='n')
        {
            system("cls");
                HackingNormal(accountN,number_player,Info);
                return;
        }
        else if(select =='H'||select =='h')
        {
            system("cls");
                HackingHard(accountH,number_player1,Info);
                return;
        }
        else
        {
            system("cls");
            return;
        }
    }
    else if(select =='N'||select =='n')
    {
        system("cls");
        return;
    }
    return;
}
void writeLeaderBoardDiff(player p)
{
    ofstream outFile("scores2.bin", ios::app | ios::binary);// create binary file for writing
    if (!outFile) { // check if file opened successfully
        cout << "Error opening file" << endl;
        return;
    }
    // write player name to file
    outFile.write(p.name, sizeof(p.name)); // write player name to file
    // write player score to file
    outFile.write((char*)&p.point, sizeof(int)); // write player score to file
    outFile.close(); // close file
}



void readLeaderBoardDiff(player acc[], int& numPlayers) {
    ifstream inFile("scores2.bin", ios::binary); // open binary file for reading
    if (!inFile) { // check if file opened successfully
        cout << "Error opening file" << endl;
        return;
    }
    numPlayers = 0;
    while (inFile.read((char*)&acc[numPlayers], sizeof(player))) { // read player record from file
        numPlayers++;
    }
    inFile.close(); // close file
}

int chooseLeaderBoard()
{
    int keybind, key, curChoice = 0;
    int choice[2] = { 0,0 };

    while (true)
    {
        choice[curChoice] = 1;
        if (choice[0])
        {
            for (int i = 0; i < 4; i++)
            {
                goToXY(77, 11 + i);
                cout << "      ";
            }
            goToXY(78, 12);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout << " NORMAL LEADERBOARD ";
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            for (int i = 0; i < 4; i++)
            {
                goToXY(77, 11 + i);
                cout << "       ";
            }
            goToXY(78, 12);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << " NORMAL LEADERBOARD ";
        }

        if (choice[1])
        {

            for (int i = 0; i < 4; i++)
            {
                goToXY(77, 14 + i);
                cout << "       ";
            }
            goToXY(78, 15);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout << " HARD LEADERBOARD ";
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            for (int i = 0; i < 4; i++)
            {
                goToXY(77, 14 + i);
                cout << "       ";
            }
            goToXY(78, 15);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            cout << " HARD LEADERBOARD ";
        }

        if (keybind = _getch())
        {
            if (keybind != 224)
            {
                if (keybind == ENTER_KEY)
                {
                    system("cls");
                    return curChoice;
                }
            }

            else
            {
                switch (key = _getch())
                {
                case KEY_UP:
                    choice[curChoice] = 0;
                    if (curChoice > 0)
                        curChoice--;
                    else
                        curChoice = 1;
                    break;
                case KEY_DOWN:
                    choice[curChoice] = 0;
                    if (curChoice < 1)
                        curChoice++;
                    else
                        curChoice = 0;
                    break;
                default:
                    break;

                }
            }

        }
    }
}
