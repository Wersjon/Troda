#include "classes.hpp"

using namespace std;

bool drawed = false;

void help();

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
            if(rand() % 10 == 1) game.map[i1][i2] = 'W';
            i2++;
        }
        i2 = 0;
        i1++;
    }
    i1 = 0, i2 = 0;
    while(i1 < 100)
    {
        while(i2 < 100)
        {
            if(game.map[i1][i2] == 'W')
            {
                if(rand() % 2 == 1 && i1 > 0) game.map[i1 - 1][i2] = 'W';
                if(rand() % 2 == 1 && i1 < 99) game.map[i1 + 1][i2] = 'W';
                if(rand() % 2 == 1 && i2 > 0) game.map[i1][i2 - 1] = 'W';
                if(rand() % 2 == 1 && i2 < 99) game.map[i1][i2 + 1] = 'W';
                i2++;
            }
            i2++;
        }
        i2 = 0;
        i1++;
    }
    i1 = 0, i2 = 0;
    while(i1 < 100)
    {
        while(i2 < 100)
        {
            if(game.map[i1][i2] == 'W')
            {
                if(rand() % 2 == 1 && i1 > 0) game.map[i1 - 1][i2] = 'W';
                if(rand() % 2 == 1 && i1 < 99) game.map[i1 + 1][i2] = 'W';
                if(rand() % 2 == 1 && i2 > 0) game.map[i1][i2 - 1] = 'W';
                if(rand() % 2 == 1 && i2 < 99) game.map[i1][i2 + 1] = 'W';
                i2++;
            }
            i2++;
        }
        i2 = 0;
        i1++;
    }
    i1 = 0, i2 = 0;
    while(i1 < 100)
    {
        while(i2 < 100)
        {
            if(game.map[i1][i2] == 'W')
            {
                if(i1 > 0 && i2 > 0) if(game.map[i1 - 1][i2 - 1] != 'W') game.map[i1 - 1][i2 - 1] = 'P';
                if(i1 > 0) if(game.map[i1 - 1][i2] != 'W') game.map[i1 - 1][i2] = 'P';
                if(i2 > 0) if(game.map[i1][i2 - 1] != 'W') game.map[i1][i2 - 1] = 'P';
                if(i1 > 0 && i2 < 99) if(game.map[i1 - 1][i2 + 1] != 'W') game.map[i1 - 1][i2 + 1] = 'P';
                if(i1 < 99 && i2 > 0) if(game.map[i1 + 1][i2 - 1] != 'W') game.map[i1 + 1][i2 - 1] = 'P';
                if(i1 < 99 && i2 < 99) if(game.map[i1 + 1][i2 + 1] != 'W') game.map[i1 + 1][i2 + 1] = 'P';
                if(i1 < 99) if(game.map[i1 + 1][i2] != 'W') game.map[i1 + 1][i2] = 'P';
                if(i2 < 99) if(game.map[i1][i2 + 1] != 'W') game.map[i1][i2 + 1] = 'P';
            }
            i2++;
        }
        i2 = 0;
        i1++;
    }
    i1 = 0, i2 = 0;
    while(i1 < 100)
    {
        while(i2 < 100)
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
        if(game.X <= 60) game.X++;
        else if(game.Y <= 60) game.Y++;
        else game.X++;
    }

    while(true)
    {
        Troda.clearChars();
        Troda.getValue("day");
        help();
    }

    getch();

    return 0;
}

void help()
{    
    game.walls('B', "floors/f", 7);
    game.walls('P', "floors/f", 6);
    game.walls('W', "floors/f", 1);
    game.walls('#', "walls/w", 9);
    char znak;
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
            if(game.direction == 0 && game.map[game.X][game.Y - 1] != '#' && game.map[game.X][game.Y - 1] != 'W')game.Y--;
            else if(game.direction == 1 && game.map[game.X + 1][game.Y] != '#' && game.map[game.X + 1][game.Y] != 'W') game.X++;
            else if(game.direction == 2 && game.map[game.X][game.Y + 1] != '#' && game.map[game.X][game.Y + 1] != 'W') game.Y++;
            else if(game.direction == 3 && game.map[game.X - 1][game.Y] != '#' && game.map[game.X - 1][game.Y] != 'W') game.X--;
            else drawed = true;
        }
        else if(znak == 'S' || znak == 's')
        {
            if(game.direction == 0 && game.map[game.X][game.Y + 1] != '#' && game.map[game.X][game.Y + 1] != 'W') game.Y++;
            else if(game.direction == 1 && game.map[game.X - 1][game.Y] != '#' && game.map[game.X - 1][game.Y] != 'W') game.X--;
            else if(game.direction == 2 && game.map[game.X][game.Y - 1] != '#' && game.map[game.X][game.Y - 1] != 'W') game.Y--;
            else if(game.direction == 3 && game.map[game.X + 1][game.Y] != '#' && game.map[game.X + 1][game.Y] != 'W') game.X++;
            else drawed = true;
        }
        else if(znak == 'A' || znak == 'a')
        {
            if(game.direction == 0 && game.map[game.X - 1][game.Y] != '#' && game.map[game.X - 1][game.Y] != 'W') game.X--;
            else if(game.direction == 1 && game.map[game.X][game.Y - 1] != '#' && game.map[game.X][game.Y - 1] != 'W') game.Y--;
            else if(game.direction == 2 && game.map[game.X + 1][game.Y] != '#' && game.map[game.X + 1][game.Y] != 'W') game.X++;
            else if(game.direction == 3 && game.map[game.X][game.Y + 1] != '#' && game.map[game.X][game.Y + 1] != 'W') game.Y++;
            else drawed = true;
        }
        else if(znak == 'D' || znak == 'd')
        {
            if(game.direction == 0 && game.map[game.X + 1][game.Y] != '#' && game.map[game.X + 1][game.Y] != 'W') game.X++;
            else if(game.direction == 1 && game.map[game.X][game.Y + 1] != '#' && game.map[game.X][game.Y + 1] != 'W') game.Y++;
            else if(game.direction == 2 && game.map[game.X - 1][game.Y] != '#' && game.map[game.X - 1][game.Y] != 'W') game.X--;
            else if(game.direction == 3 && game.map[game.X][game.Y - 1] != '#' && game.map[game.X][game.Y - 1] != 'W') game.Y--;
            else drawed = true;
        }
        else if(znak == 'E' || znak == 'e')
        {
            game.direction++;
            if(game.direction == 4) game.direction = 0;
        }
        else if(znak == 'Q' || znak == 'q')
        {
            game.direction--;
            if(game.direction == -1) game.direction = 3;
        }
        else if(znak == 'G' || znak == 'g')
        {
            Troda.tp(0, 0);
            Troda.setColor(0, 15);
            printf("%i & game.X: %i & game.Y: %i", game.direction, game.X, game.Y);
            Sleep(500);
        }
        else if(znak == 'B' || znak == 'b')
        {
            if(game.direction == 0 && game.map[game.X][game.Y - 1] == 'W') game.map[game.X][game.Y - 1] = 'B';
            else if(game.direction == 1 && game.map[game.X + 1][game.Y] == 'W') game.map[game.X + 1][game.Y] = 'B';
            else if(game.direction == 2 && game.map[game.X][game.Y + 1] == 'W') game.map[game.X][game.Y + 1] = 'B';
            else if(game.direction == 3 && game.map[game.X - 1][game.Y] == 'W') game.map[game.X - 1][game.Y] = 'B';
        }
        Sleep(50);
    }
}