#include "classes.hpp"

void act();

int main()
{
    SetConsoleCP(852);

    printf("loading...");

    std::fstream openfile;
    std::string holder;
    int line = 0, i2 = 0, obraz = 0;

    /* Wer-Dar Paint v-1.4* + wdd */
    openfile.open("images/disk.wdd", std::ios::in); //opens .wdd file
    if(openfile.good() == false) //if it doesn't exist, it displays "error 404"(file not found).
    {
        std::cout << "User Error #1 - disk.wdd not found";
        openfile.close();
        getch();
        exit(0);
    }
    while(!openfile.eof())
    {
        getline(openfile, holder);
        if(holder == "@") images.push_back(image());
    }
    
    openfile.close();
    
    openfile.open("images/disk.wdd", std::ios::in); //opens .wdd file
    while(!openfile.eof())
    {  
        getline(openfile, holder);
        line++;
        if(holder == "@") obraz++;

        if(line % 80 == 2)
        {
            images[obraz].name = holder;
        }
        else if(line % 80 >= 4 && line % 80 <= 28)
        {
            i2 = 0;
            while(i2 < 80)
            {
                images[obraz - 1].area[i2][line - (4 + (obraz - 1) * 80)] = holder[i2];
                i2++;
            }
        }
        else if(line % 80 >= 30 && line % 80 <= 54)
        {
            i2 = 0;
            while(i2 < 80)
            {
                images[obraz - 1].area2[i2][line - (30 + (obraz - 1) * 80)] = holder[i2]; //Loads chars to area2, similiar to area, this one reads lower part of .wdi file
                i2++;
            }
        }
        else if(line % 80 >= 56 && line % 80 <= 79 || line % 80 == 0)
        {
            i2 = 0;
            while(i2 < 80)
            {
                images[obraz - 1].chars[i2][line - (56 + (obraz - 1) * 80)] = holder[i2]; //Loads chars to chars[x][y]
                i2++;
            }
        }
    }
    openfile.close();
    
    Troda.howmany = images.size() - 1;

    short i1 = 0;
    i2 = 0;

    srand(time(NULL));

    Troda.hideCursor();
    Troda.setColor(0, 15);

    while(i1 < 500)
    {
        while(i2 < 500)
        {
            game.biomes[i1][i2] = '0';
            game.map[i1][i2] = 'W';
            if(rand() % 20 == 1) game.biomes[i1][i2] = 'A';
            if(rand() % 20 == 2) game.biomes[i1][i2] = 'B';
            if(rand() % 20 == 3) game.biomes[i1][i2] = 'C';
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
            if(game.biomes[i1][i2] != '0')
            {
                if(rand() % 2 == 1 && i1 > 0) game.biomes[i1 - 1][i2] = game.biomes[i1][i2];
                if(rand() % 2 == 1 && i1 < 499) game.biomes[i1 + 1][i2] = game.biomes[i1][i2];
                if(rand() % 2 == 1 && i2 > 0) game.biomes[i1][i2 - 1] = game.biomes[i1][i2];
                if(rand() % 2 == 1 && i2 < 499) game.biomes[i1][i2 + 1] = game.biomes[i1][i2];
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
            if(game.biomes[i1][i2] != '0')
            {
                if(rand() % 2 == 1 && i1 > 0) game.biomes[i1 - 1][i2] = game.biomes[i1][i2];
                if(rand() % 2 == 1 && i1 < 499) game.biomes[i1 + 1][i2] = game.biomes[i1][i2];
                if(rand() % 2 == 1 && i2 > 0) game.biomes[i1][i2 - 1] = game.biomes[i1][i2];
                if(rand() % 2 == 1 && i2 < 499) game.biomes[i1][i2 + 1] = game.biomes[i1][i2];
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
            if(game.biomes[i1][i2] != '0')
            {
                if(rand() % 2 == 1 && i1 > 0) game.biomes[i1 - 1][i2] = game.biomes[i1][i2];
                if(rand() % 2 == 1 && i1 < 499) game.biomes[i1 + 1][i2] = game.biomes[i1][i2];
                if(rand() % 2 == 1 && i2 > 0) game.biomes[i1][i2 - 1] = game.biomes[i1][i2];
                if(rand() % 2 == 1 && i2 < 499) game.biomes[i1][i2 + 1] = game.biomes[i1][i2];
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
            if(game.biomes[i1][i2] != '0')
            {
                if(rand() % 2 == 1 && i1 > 0) game.biomes[i1 - 1][i2] = game.biomes[i1][i2];
                if(rand() % 2 == 1 && i1 < 499) game.biomes[i1 + 1][i2] = game.biomes[i1][i2];
                if(rand() % 2 == 1 && i2 > 0) game.biomes[i1][i2 - 1] = game.biomes[i1][i2];
                if(rand() % 2 == 1 && i2 < 499) game.biomes[i1][i2 + 1] = game.biomes[i1][i2];
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
            if(game.biomes[i1][i2] == 'A')
            {
                game.map[i1][i2] = 'G';
            }
            if(game.biomes[i1][i2] == 'B')
            {
                if(rand() % 2 == 1) game.map[i1][i2] = 'G';
                else game.map[i1][i2] = '#';
            }
            if(game.biomes[i1][i2] == 'C')
            {
                game.map[i1][i2] = 'P';
            }
            if(game.biomes[i1 - 1][i2] == '0' && game.map[i1][i2] != '#') game.map[i1][i2] = 'P';
            if(game.biomes[i1 + 1][i2] == '0' && game.map[i1][i2] != '#') game.map[i1][i2] = 'P';
            if(game.biomes[i1][i2 - 1] == '0' && game.map[i1][i2] != '#') game.map[i1][i2] = 'P';
            if(game.biomes[i1][i2 + 1] == '0' && game.map[i1][i2] != '#') game.map[i1][i2] = 'P';

            i2++;
        }
        i2 = 0;
        i1++;
    }
    i1 = 0, i2 = 0;
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
        game.walls('G', "floors/f", 2);
        game.walls('B', "floors/f", 7);
        game.walls('P', "floors/f", 6);
        game.walls('W', "floors/f", 1);

        game.walls('#', "walls/w", 9);
        
        game.generateMap();
        Troda.getValue("map");
        game.onEnd();
        Troda.draw();
        game.drawed = true;
        game.onIteration();
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