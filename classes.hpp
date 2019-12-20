#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdio>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime> 


using namespace std;

class mouser
{

    private:
    char area[80][25], area2[80][25], chars[80][25];
    HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    int whatColor(char x) //Says about color of "char x". Colors are stored in HEX value in .wdi files:
    {
        if(x == '1') return 1;
        else if(x == '2') return 2;
        else if(x == '3') return 3;
        else if(x == '4') return 4;
        else if(x == '5') return 5;
        else if(x == '6') return 6;
        else if(x == '7') return 7;
        else if(x == '8') return 8;
        else if(x == '9') return 9;
        else if(x == 'A') return 10;
        else if(x == 'B') return 11;
        else if(x == 'C') return 12;
        else if(x == 'D') return 13;
        else if(x == 'E') return 14;
        else if(x == 'F') return 15;
        else return 0;
    }
    char whatChar(short x)
    {
        if(x == 1) return '1';
        else if(x == 2) return '2';
        else if(x == 3) return '3';
        else if(x == 4) return '4';
        else if(x == 5) return '5';
        else if(x == 6) return '6';
        else if(x == 7) return '7';
        else if(x == 8) return '8';
        else if(x == 9) return '9';
        else if(x == 10) return 'A';
        else if(x == 11) return 'B';
        else if(x == 12) return 'C';
        else if(x == 13) return 'D';
        else if(x == 14) return 'E';
        else if(x == 15) return 'F';
        else if(x == 16) return '#';
        else return '0';
    }

    public:
    void hideCursor() //Hides Cursor from user: (doesn't work if user resized window[?])
    {
        CONSOLE_CURSOR_INFO cursorInfo; //Sets variable called cursorInfo that contaisn cursors info
        cursorInfo.dwSize = 1; //Sets it's size to 1
        cursorInfo.bVisible = FALSE; //Makes it invisible
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo); //Sets value into cmd
    }

    void tp(int x, int y) //Teleports coordinates:
    {
        COORD coords; //Creates Coordinates variable named c.
        coords.X = x; //Sets X coordinate.
        coords.Y = y; //Sets Y coordinate.
        SetConsoleCursorPosition(hOut, coords); //Sets Cursor Position to c.X, c.Y.
    }

    void setColor(int bg, int c) //sets Console colors:
    {
        /*
            // Colors are implemented in numbers
            // After every 16*x there is new background, so it's: 0 - black; 16 - Blue; 32 - Green;
            // There is new color for char every 1, and it resets after hitting 16, so it's:  0 - black; 1 - Blue; 2 - Green;
        */
        SetConsoleTextAttribute(hOut, bg * 16 + c); //Sets color
    }

    void clear() //Clears 80x25 Screen:
    {
        tp(0, 0); //teleports to 0, 0
        printf("%2000d \n"); //Prints 2000 chars
    }

    void clearChars()
    {
        short i1 = 0, i2 = 0;

        while(i1 < 25)
        {
            while(i2 < 80)
            {
                area[i2][i1] = '#';
                area2[i2][i1] = ' ';
                chars[i2][i1] = ' ';
                i2++;
            }
            i2 = 0;
            i1++;
        }
    }

    void getValue(string filename)
    {
        /*Wer-Dar Paint v-1.4*/
        fstream openfile;
        string holder;
        short i1 = 0, i2 = 0;
        char prev[80][25];

        openfile.open("images/" + filename + ".wdi", ios::in); //opens .wdi file
        if(openfile.good() == false) //if it doesn't exist, it displays "error 404"(file not found).
        {
            tp(0, 0); setColor(0, 15);
            cout << "error 404";
            openfile.close();
            return;
        }
        openfile.close();
        openfile.open("images/" + filename + ".wdi", ios::in);
        while(getline(openfile, holder)) //Opens file, and gets to every line value to holder
        {
            if(i1 < 26 && i1 > 0)
            {
                while(i2 < 80)
                {
                    prev[i2][i1 - 1] = holder[i2];
                    if(holder[i2] != '#') area[i2][i1 - 1] = holder[i2];
                    i2++;
                }
            }
            if(i1 > 27 && i1 < 53)
            {
                while(i2 < 80)
                {
                    if(prev[i2][i1 - 28] != '#') area2[i2][i1 - 28] = holder[i2]; //Loads chars to area2, similiar to area, this one reads lower part of .wdi file
                    i2++;
                }
            }
            if(i1 > 54 && i1 < 80)
            {
                while(i2 < 80)
                {
                    if(prev[i2][i1 - 55] != '#') chars[i2][i1 - 55] = holder[i2]; //Loads chars to chars[x][y]
                    i2++;
                }
            }
            i2 = 0;
            i1++;
        }
        openfile.close();
    }

    void getWallue(string filename, short beColor)
    {
        /*Wer-Dar Paint v-1.4 ~ modified*/
        fstream openfile;
        string holder;
        short i1 = 0, i2 = 0;
        char prev[80][25];

        openfile.open("images/" + filename + ".wdi", ios::in); //opens .wdi file
        if(openfile.good() == false) //if it doesn't exist, it displays "error 404"(file not found).
        {
            tp(0, 0); setColor(0, 15);
            cout << "error 404";
            openfile.close();
            return;
        }
        openfile.close();
        openfile.open("images/" + filename + ".wdi", ios::in);
        while(getline(openfile, holder)) //Opens file, and gets to every line value to holder
        {
            if(i1 < 26 && i1 > 0)
            {
                while(i2 < 80)
                {
                    prev[i2][i1 - 1] = holder[i2];
                    if(holder[i2] != '#') area[i2][i1 - 1] = holder[i2];
                    if(area[i2][i1 - 1] == '5') area[i2][i1 - 1] = whatChar(beColor);
                    else if(area[i2][i1 - 1] == 'D') area[i2][i1 - 1] = whatChar(beColor + 8);
                    i2++;
                }
            }
            if(i1 > 27 && i1 < 53)
            {
                while(i2 < 80)
                {
                    if(prev[i2][i1 - 28] != '#') area2[i2][i1 - 28] = holder[i2]; //Loads chars to area2, similiar to area, this one reads lower part of .wdi file
                    if(area2[i2][i1 - 28] == '5') area2[i2][i1 - 28] = whatChar(beColor);
                    else if(area2[i2][i1 - 28] == 'D') area2[i2][i1 - 28] = whatChar(beColor + 8);
                    i2++;
                }
            }
            if(i1 > 54 && i1 < 80)
            {
                while(i2 < 80)
                {
                    if(prev[i2][i1 - 55] != '#') chars[i2][i1 - 55] = holder[i2]; //Loads chars to chars[x][y]
                    i2++;
                }
            }
            i2 = 0;
            i1++;
        }
        openfile.close();
    }

    void draw()
    {
        short i1 = 0, i2 = 0, howLong = 1;
        char helper = chars[i2][i1];
        char helparea1 = area[i2][i1];
        char helparea2 = area2[i2][i1];
        string Display;

        while(i1 < 25) //Displays paiting on canvas
        {
            while(i2 < 80)
            {
                if(area[i2][i1] == area[i2 + 1][i1] && area2[i2][i1] == area2[i2 + 1][i1] && chars[i2][i1] == chars[i2 + 1][i1] && i2 < 79)
                {
                    howLong++;
                }
                else
                {
                    tp(i2 - howLong, i1);
                    setColor(whatColor(helparea1), whatColor(helparea2));
                    for(int i = 1; i <= howLong; i++)
                    {
                        Display += helper;
                        //if(area[i2 - 1][i1] != '#') printf("%c", helper);
                    }
                    cout << Display;
                    howLong = 1;
                    if(i2 == 79)
                    {
                        tp(i2, i1);
                        setColor(whatColor(area[i2][i1]), whatColor(area2[i2][i1]));
                        if(area[i2][i1] != '#') printf("%c", chars[i2][i1]);
                    }
                }
                //if(area[i2][i1]!='#') printf("%c", chars[i2][i1]); //If char isn't "invisible", it doesn't print it.
                i2++;
                helper = chars[i2][i1];
                helparea1 = area[i2][i1];
                helparea2 = area2[i2][i1];
                Display.clear();
            }
            i1++; i2 = 0;
            helper = chars[i2][i1];
            helparea1 = area[i2][i1];
            helparea2 = area2[i2][i1];
            howLong = 1;
            Display.clear();
        }
        tp(0, 0);
    }
}Troda;

class Engine
{
    private:

    public:
        short direction;
        short Y = 50, X = 50;
        char map[100][100];

    void walls(char znak, string subname, short color)
    {
        short isUp;
        bool isVertical;

        switch(direction)
        {
            case 0:
                isUp = 1;
                isVertical = 1;
            break;
            case 1:
                isUp = -1;
                isVertical = 0;
            break;
            case 2:
                isUp = -1;
                isVertical = 1;
            break;
            case 3:
                isUp = 1;
                isVertical = 0;
            break;
        }
        if(map[X + 3 * isUp * isVertical - 4 * isUp * !isVertical][Y - 4 * isUp * isVertical - 3 * isUp * !isVertical] == znak) Troda.getWallue(subname + "5r3", color);
        if(map[X - 3 * isUp * isVertical - 4 * isUp * !isVertical][Y - 4 * isUp * isVertical + 3 * isUp * !isVertical] == znak) Troda.getWallue(subname + "5l3", color);
        if(map[X + 2 * isUp * isVertical - 4 * isUp * !isVertical][Y - 4 * isUp * isVertical - 2 * isUp * !isVertical] == znak) Troda.getWallue(subname + "5r2", color);
        if(map[X - 2 * isUp * isVertical - 4 * isUp * !isVertical][Y - 4 * isUp * isVertical + 2 * isUp * !isVertical] == znak) Troda.getWallue(subname + "5l2", color);
        if(map[X + isUp * isVertical - 4 * isUp * !isVertical][Y - 4 * isUp * isVertical - isUp * !isVertical] == znak) Troda.getWallue(subname + "5r1", color);
        if(map[X - isUp * isVertical - 4 * isUp * !isVertical][Y - 4 * isUp * isVertical + isUp * !isVertical] == znak) Troda.getWallue(subname + "5l1", color);
        if(map[X - 4 * isUp * !isVertical][Y - 4 * isUp * isVertical] == znak) Troda.getWallue(subname + "5", color);

        if(map[X + 3 * isUp * isVertical - 3 * isUp * !isVertical][Y - 3 * isUp * isVertical - 3 * isUp * !isVertical] == znak) Troda.getWallue(subname + "4r3", color);
        if(map[X - 3 * isUp * isVertical - 3 * isUp * !isVertical][Y - 3 * isUp * isVertical + 3 * isUp * !isVertical] == znak) Troda.getWallue(subname + "4l3", color);
        if(map[X + 2 * isUp * isVertical - 3 * isUp * !isVertical][Y - 3 * isUp * isVertical - 2 * isUp * !isVertical] == znak) Troda.getWallue(subname + "4r2", color);
        if(map[X - 2 * isUp * isVertical - 3 * isUp * !isVertical][Y - 3 * isUp * isVertical + 2 * isUp * !isVertical] == znak) Troda.getWallue(subname + "4l2", color);
        if(map[X + isUp * isVertical - 3 * isUp * !isVertical][Y - 3 * isUp * isVertical - isUp * !isVertical] == znak) Troda.getWallue(subname + "4r1", color);
        if(map[X - isUp * isVertical - 3 * isUp * !isVertical][Y - 3 * isUp * isVertical + isUp * !isVertical] == znak) Troda.getWallue(subname + "4l1", color);
        if(map[X - 3 * isUp * !isVertical][Y - 3 * isUp * isVertical] == znak) Troda.getWallue(subname + "4", color);

        if(map[X + 3 * isUp * isVertical - 2 * isUp * !isVertical][Y - 2 * isUp * isVertical - 3 * isUp * !isVertical] == znak) Troda.getWallue(subname + "3r3", color);
        if(map[X - 3 * isUp * isVertical - 2 * isUp * !isVertical][Y - 2 * isUp * isVertical + 3 * isUp * !isVertical] == znak) Troda.getWallue(subname + "3l3", color);
        if(map[X + 2 * isUp * isVertical - 2 * isUp * !isVertical][Y - 2 * isUp * isVertical - 2 * isUp * !isVertical] == znak) Troda.getWallue(subname + "3r2", color);
        if(map[X - 2 * isUp * isVertical - 2 * isUp * !isVertical][Y - 2 * isUp * isVertical + 2 * isUp * !isVertical] == znak) Troda.getWallue(subname + "3l2", color);
        if(map[X + isUp * isVertical - 2 * isUp * !isVertical][Y - 2 * isUp * isVertical - isUp * !isVertical] == znak) Troda.getWallue(subname + "3r1", color);
        if(map[X - isUp * isVertical - 2 * isUp * !isVertical][Y - 2 * isUp * isVertical + isUp * !isVertical] == znak) Troda.getWallue(subname + "3l1", color);
        if(map[X - 2 * isUp * !isVertical][Y - 2 * isUp * isVertical] == znak) Troda.getWallue(subname + "3", color);

        if(map[X + 2 * isUp * isVertical - isUp * !isVertical][Y - isUp * isVertical - 2 * isUp * !isVertical] == znak) Troda.getWallue(subname + "2r2", color);
        if(map[X -  2 * isUp * isVertical - isUp * !isVertical][Y - isUp * isVertical + 2 * isUp * !isVertical] == znak) Troda.getWallue(subname + "2l2", color);
        if(map[X + isUp * isVertical - isUp * !isVertical][Y - isUp * isVertical - isUp * !isVertical] == znak) Troda.getWallue(subname + "2r1", color);
        if(map[X - isUp * isVertical - isUp * !isVertical][Y - isUp * isVertical + isUp * !isVertical] == znak) Troda.getWallue(subname + "2l1", color);
        if(map[X - isUp * !isVertical][Y - isUp * isVertical] == znak) Troda.getWallue(subname + "2", color);
        
        if(map[X + isUp * isVertical][Y - isUp * !isVertical] == znak) Troda.getWallue(subname + "1r1", color);
        if(map[X - isUp * isVertical][Y + isUp * !isVertical] == znak) Troda.getWallue(subname + "1l1", color);
        if(map[X][Y] == znak) Troda.getWallue(subname + "1", color);
    }
}game;