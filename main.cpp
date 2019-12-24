#include "classes.hpp"

using namespace std;

void act();

int main()
{
    short i1 = 0, i2 = 0;

    srand(time(NULL));

    Troda.hideCursor();
    Troda.setColor(0, 15);
    while(i1 < 500)
    {
        while(i2 < 500)
        {
            if(rand() % 10 == 1) game.map[i1][i2] = 'W';
            i2++;
        }
        i2 = 0;
        i1++;
    }
    i1 = 0, i2 = 0;
    while(i1 < 500)
    {
        while(i2 < 500)
        {
            if(game.map[i1][i2] == 'W')
            {
                if(rand() % 2 == 1 && i1 > 0) game.map[i1 - 1][i2] = 'W';
                if(rand() % 2 == 1 && i1 < 499) game.map[i1 + 1][i2] = 'W';
                if(rand() % 2 == 1 && i2 > 0) game.map[i1][i2 - 1] = 'W';
                if(rand() % 2 == 1 && i2 < 499) game.map[i1][i2 + 1] = 'W';
                i2++;
            }
            i2++;
        }
        i2 = 0;
        i1++;
    }
    i1 = 0, i2 = 0;
    while(i1 < 500)
    {
        while(i2 < 500)
        {
            if(game.map[i1][i2] == 'W')
            {
                if(rand() % 2 == 1 && i1 > 0) game.map[i1 - 1][i2] = 'W';
                if(rand() % 2 == 1 && i1 < 499) game.map[i1 + 1][i2] = 'W';
                if(rand() % 2 == 1 && i2 > 0) game.map[i1][i2 - 1] = 'W';
                if(rand() % 2 == 1 && i2 < 499) game.map[i1][i2 + 1] = 'W';
                i2++;
            }
            i2++;
        }
        i2 = 0;
        i1++;
    }
    i1 = 0, i2 = 0;
    while(i1 < 500)
    {
        while(i2 < 500)
        {
            if(game.map[i1][i2] == 'W')
            {
                if(i1 > 0 && i2 > 0) if(game.map[i1 - 1][i2 - 1] != 'W') game.map[i1 - 1][i2 - 1] = 'P';
                if(i1 > 0) if(game.map[i1 - 1][i2] != 'W') game.map[i1 - 1][i2] = 'P';
                if(i2 > 0) if(game.map[i1][i2 - 1] != 'W') game.map[i1][i2 - 1] = 'P';
                if(i1 > 0 && i2 < 499) if(game.map[i1 - 1][i2 + 1] != 'W') game.map[i1 - 1][i2 + 1] = 'P';
                if(i1 < 499 && i2 > 0) if(game.map[i1 + 1][i2 - 1] != 'W') game.map[i1 + 1][i2 - 1] = 'P';
                if(i1 < 499 && i2 < 499) if(game.map[i1 + 1][i2 + 1] != 'W') game.map[i1 + 1][i2 + 1] = 'P';
                if(i1 < 499) if(game.map[i1 + 1][i2] != 'W') game.map[i1 + 1][i2] = 'P';
                if(i2 < 499) if(game.map[i1][i2 + 1] != 'W') game.map[i1][i2 + 1] = 'P';
            }
            i2++;
        }
        i2 = 0;
        i1++;
    }
    i1 = 0, i2 = 0;
    while(i1 < 500)
    {
        while(i2 < 500)
        {
            if(game.map[i1][i2] != 'W' && game.map[i1][i2] != 'P')
            {
                if(rand() % 3 == 1)game.map[i1][i2] = '#';
                i2++;
            }
            i2++;
        }
        i2 = 0;
        i1++;
    }
    while(game.map[game.X][game.Y] == 'W' || game.map[game.X][game.Y] == '#')
    {
        if(game.X <= 260) game.X++;
        else if(game.Y <= 260) game.Y++;
        else game.X++;
    }

    while(true)
    {
        Troda.clearChars();
        game.setWeather();
        act();
    }

    getch();

    return 0;
}

void act()
{    
    char znak;

    game.onIteration();

    if(game.drawed == false)
    {
        game.walls('B', "floors/f", 7);
        game.walls('P', "floors/f", 6);
        game.walls('W', "floors/f", 1);
        game.walls('#', "walls/w", 9);
        game.generateMap();
        Troda.getValue("map");
        game.onEnd();
        Troda.draw();
        game.drawed = true;
    }

    if(kbhit())
    {
        znak = getch();
        game.drawed = false;
        switch(znak)
        {
            case 'W':
            case 'w':
                if(game.direction == 0 && game.map[game.X][game.Y - 1] != '#' && game.map[game.X][game.Y - 1] != 'W') game.Y--;
                else if(game.direction == 1 && game.map[game.X + 1][game.Y] != '#' && game.map[game.X + 1][game.Y] != 'W') game.X++;
                else if(game.direction == 2 && game.map[game.X][game.Y + 1] != '#' && game.map[game.X][game.Y + 1] != 'W') game.Y++;
                else if(game.direction == 3 && game.map[game.X - 1][game.Y] != '#' && game.map[game.X - 1][game.Y] != 'W') game.X--;
            break;
            case 'S':
            case 's':
                if(game.direction == 0 && game.map[game.X][game.Y + 1] != '#' && game.map[game.X][game.Y + 1] != 'W') game.Y++;
                else if(game.direction == 1 && game.map[game.X - 1][game.Y] != '#' && game.map[game.X - 1][game.Y] != 'W') game.X--;
                else if(game.direction == 2 && game.map[game.X][game.Y - 1] != '#' && game.map[game.X][game.Y - 1] != 'W') game.Y--;
                else if(game.direction == 3 && game.map[game.X + 1][game.Y] != '#' && game.map[game.X + 1][game.Y] != 'W') game.X++;
            break;
            case 'A':
            case 'a':
                if(game.direction == 0 && game.map[game.X - 1][game.Y] != '#' && game.map[game.X - 1][game.Y] != 'W') game.X--;
                else if(game.direction == 1 && game.map[game.X][game.Y - 1] != '#' && game.map[game.X][game.Y - 1] != 'W') game.Y--;
                else if(game.direction == 2 && game.map[game.X + 1][game.Y] != '#' && game.map[game.X + 1][game.Y] != 'W') game.X++;
                else if(game.direction == 3 && game.map[game.X][game.Y + 1] != '#' && game.map[game.X][game.Y + 1] != 'W') game.Y++;
            break;
            case 'D':
            case 'd':
                if(game.direction == 0 && game.map[game.X + 1][game.Y] != '#' && game.map[game.X + 1][game.Y] != 'W') game.X++;
                else if(game.direction == 1 && game.map[game.X][game.Y + 1] != '#' && game.map[game.X][game.Y + 1] != 'W') game.Y++;
                else if(game.direction == 2 && game.map[game.X - 1][game.Y] != '#' && game.map[game.X - 1][game.Y] != 'W') game.X--;
                else if(game.direction == 3 && game.map[game.X][game.Y - 1] != '#' && game.map[game.X][game.Y - 1] != 'W') game.Y--;
            break;
            case 'E':
            case 'e':
                game.direction++;
                if(game.direction == 4) game.direction = 0;
            break;
            case 'Q':
            case 'q':
                game.direction--;
                if(game.direction == -1) game.direction = 3;
            break;
            case 'G':
            case 'g':
                Troda.tp(0, 0);
                Troda.setColor(0, 15);
                printf("%i & game.X: %i & game.Y: %i", game.direction, game.X, game.Y);
                Sleep(500);
            break;
            case 'B':
            case 'b':
                if(game.direction == 0 && game.map[game.X][game.Y - 1] == 'W') game.map[game.X][game.Y - 1] = 'B';
                else if(game.direction == 1 && game.map[game.X + 1][game.Y] == 'W') game.map[game.X + 1][game.Y] = 'B';
                else if(game.direction == 2 && game.map[game.X][game.Y + 1] == 'W') game.map[game.X][game.Y + 1] = 'B';
                else if(game.direction == 3 && game.map[game.X - 1][game.Y] == 'W') game.map[game.X - 1][game.Y] = 'B';
            break;
            default:
                game.drawed = true;
            break;
        }
    }
    Sleep(75);
}