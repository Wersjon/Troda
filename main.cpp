#include "classes.hpp"

using namespace std;

char map[100][100];
short Y = 50, X = 50, direction = 0;
bool drawed = false;

void walls();

int main()
{
    short i1 = 0, i2 = 0;

    srand(time(NULL));

    Troda.hideCursor();
    Troda.setColor(0, 15);
    while(i1 < 100)
    {
        while(i2 < 100)
        {
            if(rand() % 5 == 1)map[i1][i2] = '#';
            i2++;
        }
        i2 = 0;
        i1++;
    }

    while(true)
    {
        Troda.clearChars();
        Troda.getValue("day");
        walls();
    }

    getch();

    return 0;
}

void walls()
{
    char znak;
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
    if(map[X + isUp * 3 * isVertical - 4 * isUp * !isVertical][Y - 4 * isUp * isVertical - 3 * isUp * !isVertical] == '#') Troda.getValue("smalls/s3r");
    if(map[X - isUp * 3 * isVertical - 4 * isUp * !isVertical][Y - 4 * isUp * isVertical + 3 * isUp * !isVertical] == '#') Troda.getValue("smalls/s3l");
    if(map[X + isUp * 2 * isVertical - 4 * isUp * !isVertical][Y - 4 * isUp * isVertical - 3 * isUp * !isVertical] == '#') Troda.getValue("smalls/s2r");
    if(map[X - isUp * 2 * isVertical - 4 * isUp * !isVertical][Y - 4 * isUp * isVertical + 3 * isUp * !isVertical] == '#') Troda.getValue("smalls/s2l");
    if(map[X + isUp * isVertical - 4 * isUp * !isVertical][Y - 4 * isUp * isVertical - 3 * isUp * !isVertical] == '#') Troda.getValue("smalls/s1r");
    if(map[X - isUp * isVertical - 4 * isUp * !isVertical][Y - 4 * isUp * isVertical + 3 * isUp * !isVertical] == '#') Troda.getValue("smalls/s1l");
    if(map[X - 4 * isUp * !isVertical][Y - 4 * isUp * isVertical] == '#') Troda.getValue("smalls/s1");

    if(map[X + isUp * 3 * isVertical - 3 * isUp * !isVertical][Y - 3 * isUp * isVertical - 3 * isUp * !isVertical] == '#') Troda.getValue("ids/id17");
    if(map[X - isUp * 3 * isVertical - 3 * isUp * !isVertical][Y - 3 * isUp * isVertical + 3 * isUp * !isVertical] == '#') Troda.getValue("ids/id16");
    if(map[X + isUp * 2 * isVertical - 3 * isUp * !isVertical][Y - 3 * isUp * isVertical - 2 * isUp * !isVertical] == '#') Troda.getValue("ids/id15");
    if(map[X - isUp * 2 * isVertical - 3 * isUp * !isVertical][Y - 3 * isUp * isVertical + 2 * isUp * !isVertical] == '#') Troda.getValue("ids/id14");
    if(map[X + isUp * isVertical - 3 * isUp * !isVertical][Y - 3 * isUp * isVertical - isUp * !isVertical] == '#') Troda.getValue("ids/id13");
    if(map[X - isUp * isVertical - 3 * isUp * !isVertical][Y - 3 * isUp * isVertical + isUp * !isVertical] == '#') Troda.getValue("ids/id12");
    if(map[X - 3 * isUp * !isVertical][Y - 3 * isUp * isVertical] == '#') Troda.getValue("ids/id11");

    if(map[X + isUp * 3 * isVertical - 2 * isUp * !isVertical][Y - 2 * isUp * isVertical - 3 * isUp * !isVertical] == '#') Troda.getValue("ids/Hh");
    if(map[X - isUp * 3 * isVertical - 2 * isUp * !isVertical][Y - 2 * isUp * isVertical + 3 * isUp * !isVertical] == '#') Troda.getValue("ids/Gh");
    if(map[X + isUp * 2 * isVertical - 2 * isUp * !isVertical][Y - 2 * isUp * isVertical - 2 * isUp * !isVertical] == '#') Troda.getValue("ids/id10");
    if(map[X - isUp * 2 * isVertical - 2 * isUp * !isVertical][Y - 2 * isUp * isVertical + 2 * isUp * !isVertical] == '#') Troda.getValue("ids/id9");
    if(map[X + isUp * isVertical - 2 * isUp * !isVertical][Y - 2 * isUp * isVertical - isUp * !isVertical] == '#') Troda.getValue("ids/id8");
    if(map[X - isUp * isVertical - 2 * isUp * !isVertical][Y - 2 * isUp * isVertical + isUp * !isVertical] == '#') Troda.getValue("ids/id7");
    if(map[X - 2 * isUp * !isVertical][Y - 2 * isUp * isVertical] == '#') Troda.getValue("ids/id6");

    if(map[X + isUp * 2 * isVertical - isUp * !isVertical][Y - isUp * isVertical - 2 * isUp * !isVertical] == '#') Troda.getValue("ids/id10h");
    if(map[X - isUp * 2 * isVertical - isUp * !isVertical][Y - isUp * isVertical + 2 * isUp * !isVertical] == '#') Troda.getValue("ids/id9h");
    if(map[X + isUp * isVertical - isUp * !isVertical][Y - isUp * isVertical - isUp * !isVertical] == '#') Troda.getValue("ids/id5");
    if(map[X - isUp * isVertical - isUp * !isVertical][Y - isUp * isVertical + isUp * !isVertical] == '#') Troda.getValue("ids/id4");
    if(map[X - isUp * !isVertical][Y - isUp * isVertical] == '#') Troda.getValue("ids/id3");
    
    if(map[X + isUp * isVertical][Y - isUp * !isVertical] == '#') Troda.getValue("ids/id2");
    if(map[X - isUp * isVertical][Y + isUp * !isVertical] == '#') Troda.getValue("ids/id1");
    
    if(drawed == false)
    {
        Troda.draw();
        drawed = true;
    }
    if(kbhit())
    {
        znak = getch();
        drawed = false;
        if(znak == 'W' || znak == 'w')
        {
            if(direction == 0 && map[X][Y-1] != '#')Y--;
            else if(direction == 1 && map[X+1][Y] != '#') X++;
            else if(direction == 2 && map[X][Y+1] != '#') Y++;
            else if(direction == 3 && map[X-1][Y] != '#') X--;
            else drawed = true;
        }
        else if(znak == 'S' || znak == 's')
        {
            if(direction == 0 && map[X][Y+1] != '#') Y++;
            else if(direction == 1 && map[X-1][Y] != '#') X--;
            else if(direction == 2 && map[X][Y-1] != '#') Y--;
            else if(direction == 3 && map[X+1][Y] != '#') X++;
            else drawed = true;
        }
        else if(znak == 'A' || znak == 'a')
        {
            if(direction == 0 && map[X-1][Y] != '#') X--;
            else if(direction == 1 && map[X][Y-1] != '#') Y--;
            else if(direction == 2 && map[X+1][Y] != '#') X++;
            else if(direction == 3 && map[X][Y+1] != '#') Y++;
            else drawed = true;
        }
        else if(znak == 'D' || znak == 'd')
        {
            if(direction == 0 && map[X+1][Y] != '#') X++;
            else if(direction == 1 && map[X][Y+1] != '#') Y++;
            else if(direction == 2 && map[X-1][Y] != '#') X--;
            else if(direction == 3 && map[X][Y-1] != '#') Y--;
            else drawed = true;
        }
        else if(znak == 'E' || znak == 'e')
        {
            direction++;
            if(direction == 4) direction = 0;
        }
        else if(znak == 'Q' || znak == 'q')
        {
            direction--;
            if(direction == -1) direction = 3;
        }
        else if(znak == 'G' || znak == 'g')
        {
            Troda.tp(0, 0);
            Troda.setColor(0, 15);
            printf("%i", direction);
            Sleep(500);
        }
    }
}