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

    void draw()
    {
        short i1 = 0, i2 = 0;
        while(i1 < 25) //Displays paiting on canvas
        {
            while(i2 < 80)
            {
                tp(i2, i1);
                setColor(whatColor(area[i2][i1]), whatColor(area2[i2][i1])); //Sets color of area and area2 by whatColor
                if(area[i2][i1]!='#') printf("%c", chars[i2][i1]); //If char isn't "invisible", it doesn't print it.
                i2++;
            }
            i1++; i2 = 0;
        }
        tp(0, 0);
    }
}Troda;