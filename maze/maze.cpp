#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAZE_WIDTH = 10;
const int MAZE_HEIGHT = 10;

vector<vector<bool>> maze(MAZE_WIDTH, vector<bool>(MAZE_HEIGHT, false));

void generateMaze() {
    srand(time(nullptr));
    for (int x = 0; x < MAZE_WIDTH; ++x) {
        for (int y = 0; y < MAZE_HEIGHT; ++y) {
            maze[x][y] = rand() % 2 == 0; 
        }
    }
}

void displayMaze(int playerX, int playerY) {
    for (int y = 0; y < MAZE_HEIGHT; ++y) {
        for (int x = 0; x < MAZE_WIDTH; ++x) {
            if (x == playerX && y == playerY) {
                cout << "P "; 
            } else if (maze[x][y]) {
                cout << "# "; 
            } else {
                cout << ". "; 
            }
        }
        cout << endl;
    }
}

int main() {
    generateMaze();

    int playerX = 0;
    int playerY = 0;

    while (true) {
        displayMaze(playerX, playerY);

        cout << "Enter your move (W/A/S/D): ";
        char move;
        cin >> move;

        switch (move) {
            case 'W':
            case 'w':
                if (playerY > 0 && !maze[playerX][playerY - 1]) {
                    playerY--;
                }
                break;
            case 'A':
            case 'a':
                if (playerX > 0 && !maze[playerX - 1][playerY]) {
                    playerX--;
                }
                break;
            case 'S':
            case 's':
                if (playerY < MAZE_HEIGHT - 1 && !maze[playerX][playerY + 1]) {
                    playerY++;
                }
                break;
            case 'D':
            case 'd':
                if (playerX < MAZE_WIDTH - 1 && !maze[playerX + 1][playerY]) {
                    playerX++;
                }
                break;
            default:
                cout << "Invalid move. Use W/A/S/D." << endl;
        }

        if (playerX == MAZE_WIDTH - 1 && playerY == MAZE_HEIGHT - 1) {
            cout << "Congratulations! You found the exit!" << endl;
            break;
        }
    }

    return 0;
}
