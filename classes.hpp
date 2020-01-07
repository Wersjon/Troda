#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdio>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

class image
{
public:
    char area[80][25], area2[80][25], chars[80][25];
    std::string name;

    image()
    {
        //
    }
};

std::vector <image> images;

class mouser
{
private:
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
    short getId(std::string originalName)
    {
        short i = 0;
        while(i <= howmany)
        {
            if(images[i].name == originalName) return i;
            i++;
        }
        return 0;
    }
public:
    short howmany;
    char area[80][25], area2[80][25], chars[80][25];

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

    void getValue(std::string filename)
    {
        short i1 = 0, i2 = 0, picNum = getId(filename);

        while(i1 < 25)
        {
            while(i2 < 80)
            {
                if(images[picNum].area[i2][i1] != '#')
                {
                    area[i2][i1] = images[picNum].area[i2][i1];
                    area2[i2][i1] = images[picNum].area2[i2][i1];
                    chars[i2][i1] = images[picNum].chars[i2][i1];
                }
                i2++;
            }
            i2 = 0;
            i1++;
        }
    }

    void getWallue(std::string filename, short beColor)
    {
        short i1 = 0, i2 = 0, picNum = getId(filename);

        while(i1 < 25)
        {
            while(i2 < 80)
            {
                if(images[picNum].area[i2][i1] != '#')
                {
                    area[i2][i1] = images[picNum].area[i2][i1];
                    if(images[picNum].area2[i2][i1] == '5') area2[i2][i1] = whatChar(beColor);
                    else if(images[picNum].area2[i2][i1] == 'D') area2[i2][i1] = whatChar(beColor + 8);
                    else area2[i2][i1] = images[picNum].area2[i2][i1];

                    chars[i2][i1] = images[picNum].chars[i2][i1];
                }
                if(images[picNum].area[i2][i1] == '5') area[i2][i1] = whatChar(beColor);
                if(images[picNum].area[i2][i1] == 'D') area[i2][i1] = whatChar(beColor + 8);
                i2++;
            }
            i2 = 0;
            i1++;
        }
    }
    void draw()
    {
        short i1 = 0, i2 = 0, howLong = 1;
        char helper = chars[i2][i1];
        char helparea1 = area[i2][i1];
        char helparea2 = area2[i2][i1];
        std::string Display;
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
                    tp(i2 - howLong + 1, i1);
                    setColor(whatColor(helparea1), whatColor(helparea2));
                    for(int i = 1; i <= howLong; i++)
                    {
                        Display += helper;
                        //if(area[i2 - 1][i1] != '#') printf("%c", helper);
                    }
                    std::cout << Display;
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
    short days = 0, hours = 5, minutes = 0, seconds = 0, before = 1;

    char returnchar(short nmb)
    {
        switch(nmb)
        {
            case 0: return '0'; break;
            case 1: return '1'; break;
            case 2: return '2'; break;
            case 3: return '3'; break;
            case 4: return '4'; break;
            case 5: return '5'; break;
            case 6: return '6'; break;
            case 7: return '7'; break;
            case 8: return '8'; break;
            case 9: return '9'; break;
            default: return 'F'; break;
        }
    }

public:
    short direction;
    short Y = 250, X = 250;
    char map[500][500];
    bool drawed = false;

    void walls(char znak, std::string subname, short color)
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

    void generateMap()
    {
        char half = (char)220;
        short i1 = -3, i2 = -4, charC, bgC;

        while(i1 <= 7)
        {
            Troda.setColor(0, 15);
            Troda.tp(67, 4 + (-4 + i1) / 2);
            printf(" ");
            Troda.tp(72 + 5, 4 + (-4 + i1) / 2);
            printf(" ");
            while(i2 <= 4)
            {
                if(i1 <= 1)
                {
                    switch(map[X + i2][Y + i1 - 2])
                    {
                        case 'W':
                            bgC = 9;
                        break;
                        case 'P':
                            bgC = 14;
                        break;
                        case '#':
                            bgC = 8;
                        break;
                        case 'B':
                            bgC = 15;
                        break;
                        default:
                            bgC = 10;
                        break;
                    }
                    switch(map[X + i2][Y + i1 - 1])
                    {
                        case 'W':
                            charC = 9;
                        break;
                        case 'P':
                            charC = 14;
                        break;
                        case '#':
                            charC = 8;
                        break;
                        case 'B':
                            charC = 15;
                        break;
                        default:
                            charC = 10;
                        break;
                    }
                }
                if(i1 > 2)
                {
                    switch(map[X + i2][Y + i1 - 4])
                    {
                        case 'W':
                            bgC = 9;
                        break;
                        case 'P':
                            bgC = 14;
                        break;
                        case '#':
                            bgC = 8;
                        break;
                        case 'B':
                            bgC = 15;
                        break;
                        default:
                            bgC = 10;
                        break;
                    }
                    switch(map[X + i2][Y + i1 - 3])
                    {
                        case 'W':
                            charC = 9;
                        break;
                        case 'P':
                            charC = 14;
                        break;
                        case '#':
                            charC = 8;
                        break;
                        case 'B':
                            charC = 15;
                        break;
                        default:
                            charC = 10;
                        break;
                    }
                }
                if(i1 == -3) bgC = 0;
                else if(i1 == 7) charC = 0;
                else if(i1 == 1 && i2 == 0) charC = 12;
                Troda.area[72 + i2][4 + (-4 + i1) / 2] = Troda.whatChar(bgC);
                Troda.area2[72 + i2][4 + (-4 + i1) / 2] = Troda.whatChar(charC);
                Troda.chars[72 + i2][4 + (-4 + i1) / 2] = half;
                Troda.setColor(bgC, charC);
                i2++;
            }
        i1++;
        i1++;
        i2 = -4;
        }
    }
    void setWeather()
    {
        if(hours > 19 || hours < 4) Troda.getValue("dan/night");
        else if(hours >= 4 && hours <= 5) Troda.getValue("dan/neither");
        else if(hours >= 6 && hours <= 7) Troda.getValue("dan/either");
        else if(hours >= 8 && hours <= 15) Troda.getValue("dan/day");
        else if(hours >= 16 && hours <= 17) Troda.getValue("dan/either");
        else if(hours >= 18 && hours <= 19) Troda.getValue("dan/neither");

        switch(direction)
        {
            case 0:
                switch(hours)
                {
                    case 0:
                    case 1:
                        Troda.getValue("dan/moons/moon4");
                    break;
                    case 2:
                    case 3:
                        Troda.getValue("dan/moons/moon3l");
                    break;
                    case 4:
                    case 5:
                        Troda.getValue("dan/moons/moon2l");
                    break;
                    case 6:
                    case 7:
                        Troda.getValue("dan/moons/moon1l");
                        Troda.getValue("dan/suns/sun1r");
                    break;
                    case 8:
                    case 9:
                        Troda.getValue("dan/suns/sun2r");
                    break;
                    case 10:
                    case 11:
                        Troda.getValue("dan/suns/sun3r");
                    break;
                    case 12:
                    case 13:
                        Troda.getValue("dan/suns/sun4");
                    break;
                    case 14:
                    case 15:
                        Troda.getValue("dan/suns/sun3l");
                    break;
                    case 16:
                    case 17:
                        Troda.getValue("dan/suns/sun2l");
                    break;
                    case 18:
                    case 19:
                        Troda.getValue("dan/suns/sun1l");
                        Troda.getValue("dan/moons/moon1r");
                    break;
                    case 20:
                    case 21:
                        Troda.getValue("dan/moons/moon2r");
                    break;
                    case 22:
                    case 23:
                        Troda.getValue("dan/moons/moon3r");
                    break;
                }
            break;
            case 1:
                switch(hours)
                {
                    case 0:
                    case 1:
                        Troda.getValue("dan/moons/moon4");
                    break;
                    case 6:
                    case 7:
                        Troda.getValue("dan/suns/sun1");
                    break;
                    case 8:
                    case 9:
                        Troda.getValue("dan/suns/sun2");
                    break;
                    case 10:
                    case 11:
                        Troda.getValue("dan/suns/sun3");
                    break;
                    case 12:
                    case 13:
                        Troda.getValue("dan/suns/sun4");
                    break;
                    case 18:
                    case 19:
                        Troda.getValue("dan/moons/moon1");
                    break;
                    case 20:
                    case 21:
                        Troda.getValue("dan/moons/moon2");
                    break;
                    case 22:
                    case 23:
                        Troda.getValue("dan/moons/moon3");
                    break;
                }
            break;
            case 2:
                switch(hours)
                {
                    case 0:
                    case 1:
                        Troda.getValue("dan/moons/moon4");
                    break;
                    case 2:
                    case 3:
                        Troda.getValue("dan/moons/moon3r");
                    break;
                    case 4:
                    case 5:
                        Troda.getValue("dan/moons/moon2r");
                    break;
                    case 6:
                    case 7:
                        Troda.getValue("dan/moons/moon1r");
                        Troda.getValue("dan/suns/sun1l");
                    break;
                    case 8:
                    case 9:
                        Troda.getValue("dan/suns/sun2l");
                    break;
                    case 10:
                    case 11:
                        Troda.getValue("dan/suns/sun3l");
                    break;
                    case 12:
                    case 13:
                        Troda.getValue("dan/suns/sun4");
                    break;
                    case 14:
                    case 15:
                        Troda.getValue("dan/suns/sun3r");
                    break;
                    case 16:
                    case 17:
                        Troda.getValue("dan/suns/sun2r");
                    break;
                    case 18:
                    case 19:
                        Troda.getValue("dan/suns/sun1r");
                        Troda.getValue("dan/moons/moon1l");
                    break;
                    case 20:
                    case 21:
                        Troda.getValue("dan/moons/moon2l");
                    break;
                    case 22:
                    case 23:
                        Troda.getValue("dan/moons/moon3l");
                    break;
                }
            break;
            case 3:
                switch(hours)
                {
                    case 0:
                    case 1:
                        Troda.getValue("dan/moons/moon4");
                    break;
                    case 2:
                    case 3:
                        Troda.getValue("dan/moons/moon3");
                    break;
                    case 4:
                    case 5:
                        Troda.getValue("dan/moons/moon2");
                    break;
                    case 6:
                    case 7:
                        Troda.getValue("dan/moons/moon1");
                    break;
                    case 12:
                    case 13:
                        Troda.getValue("dan/suns/sun4");
                    break;
                    case 14:
                    case 15:
                        Troda.getValue("dan/suns/sun3");
                    break;
                    case 16:
                    case 17:
                        Troda.getValue("dan/suns/sun2");
                    break;
                    case 18:
                    case 19:
                        Troda.getValue("dan/suns/sun1");
                    break;
                }
            break;
        }
        if(hours % 2 == 0 && minutes == 0) drawed = false;
    }

    void onIteration()
    {
        seconds += 10;
        if(seconds >= 60)
        {
            minutes++;
            seconds = 0;
        }
        if(minutes >= 60) 
        {
            minutes = 0;
            hours++;
            if(hours >= 24)
            {
                hours = 0;
                days++;
            }
        }
        short firstHours = 0, secondHours = hours, firstMinutes = 0, secondMinutes = minutes;
        while(secondHours >= 10)
        {
            secondHours -= 10;
            firstHours++;
        }
        while(secondMinutes >= 10)
        {
            secondMinutes -= 10;
            firstMinutes++;
        }
        Troda.setColor(2, 10);
        Troda.tp(70, 7); printf("%c%c:%c%c", returnchar(firstHours), returnchar(secondHours), returnchar(firstMinutes), returnchar(secondMinutes));
        Troda.area[70][7] = '2'; Troda.area2[70][7] = 'A'; Troda.chars[70][7] = returnchar(firstHours);
        Troda.area[71][7] = '2'; Troda.area2[71][7] = 'A'; Troda.chars[71][7] = returnchar(secondHours);
        Troda.area[73][7] = '2'; Troda.area2[73][7] = 'A'; Troda.chars[73][7] = returnchar(firstMinutes);
        Troda.area[74][7] = '2'; Troda.area2[74][7] = 'A'; Troda.chars[74][7] = returnchar(secondMinutes);
    }

    void onEnd()
    {
        short i1 = 0, i2 = hours;

        Troda.area2[72][0] = 'F'; //N
        Troda.area2[78][3] = 'F'; //E
        Troda.area2[66][3] = 'F'; //W
        Troda.area2[72][6] = 'F'; //S
        if(direction == 0) Troda.area2[72][0] = 'C'; //N
        else if(direction == 1) Troda.area2[78][3] = 'C'; //E
        else if(direction == 3) Troda.area2[66][3] = 'C'; //W
        else if(direction == 2) Troda.area2[72][6] = 'C'; //S
        onIteration();
    }
}game;