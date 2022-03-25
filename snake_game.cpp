#include <iostream>
#include <conio.h>

using namespace std;
bool gameOver;

// map dimensions
const int width = 20;
const int height = 20;

// head position
int x, y, fruitX, fruitY, score;

enum eDirection{STOP=0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void Setup() {
    gameOver = false;
    dir = STOP;
    
    // so that snake will start in centre of the map
    x = width / 2;
    y = height / 2;

    // randomly distribute fruit throughout map
    fruitX = rand() % width;
    fruitY = rand() % height;

    score = 0;

}

void Draw() {
    system("cls");
    
    // define map exterior using '#'
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    // print the map interior (like printing a matrix)
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                cout << "#";
            
            if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "F";
            else
                cout << " ";

            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;
    cout << "Score: " << score << endl;
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'w':
            dir = UP;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void Logic() {
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    if (x > width || x < 0 || y > height || y < 0)
        gameOver = true;
    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
    }
}

int main()
{
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
    }

    return 0;
}

