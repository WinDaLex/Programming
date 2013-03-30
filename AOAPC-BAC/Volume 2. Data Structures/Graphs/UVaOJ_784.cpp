// UVaOJ 784
// Maze Exploration
// by A Code Rabbit

#include <cstdio>
#include <cstring>

const int LIMITS_ROW = 50;
const int LIMITS_COL = 100;

struct Change {
    int x;
    int y;
};

Change change[] = {{-1, 0}, {1, 0},
                   {0, -1}, {0, 1}};

int t;
char maze[LIMITS_ROW][LIMITS_COL];
int top;

void FloodFill(int x, int y);

int main() {
    scanf("%d", &t);
    getchar();
    while (t--) {
        // Inputs.
        memset(maze, '\0', sizeof(maze));
        top = 0;
        while (gets(maze[top++])) {
            if (maze[top - 1][0] == '_') {
                break;
            }
        }
        // DFS.
        for (int i = 0; i < top - 1; ++i) {
            for (int j = 0; j < strlen(maze[i]); ++j) {
                if (maze[i][j] == '*') {
                    maze[i][j] = ' ';
                    FloodFill(i, j);
                }
            }
        }
        // Outputs.
        for (int i = 0; i < top; ++i) {
            puts(maze[i]);
        }
    }

    return 0;
}

void FloodFill(int x, int y) {
    if (x < 0 || x >= top - 1
     || y < 0 || y >= strlen(maze[x])) {
        return;
    }
    if (maze[x][y] != ' ') {
        return;
    }
    maze[x][y] = '#';
    for (int i = 0; i < 4; ++i) {
        FloodFill(x + change[i].x, y + change[i].y);
    }
}
