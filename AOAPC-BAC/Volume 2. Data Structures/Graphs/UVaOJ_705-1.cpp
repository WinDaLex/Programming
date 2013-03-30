// UVaOJ 705
// Slash Maze
// by A Code Rabbit

#include <cstdio>

struct Change {
    int x;
    int y;
};

Change CHANGE[] = {
              {-1, 0},
    { 0, -1},          { 0, 1},
              { 1, 0},
};

const int LIMITS_W = 1000;
const int LIMITS_H = 1000;

int num_case = 0;

char maze[LIMITS_H][LIMITS_W];
int w, h;
int w_maze, h_maze;

void EnlargeAndSave(int x, int y, char ch);

int FloodFill(int x, int y);

int main() {
    while (scanf("%d%d", &w, &h)) {
        getchar();
        // Exit.
        if (!w && !h) {
            break;
        }
        // Inputs.
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                EnlargeAndSave(i, j, getchar());
            }
            getchar();
        }
        w_maze = w * 3;
        h_maze = h * 3;
        // DFS: Remove grids of the maze without cycles.
        for (int i = 0; i < h_maze; ++i) {
            FloodFill(i, 0);
            FloodFill(i, w_maze - 1);
        }
        for (int i = 0; i < w_maze; ++i) {
            FloodFill(0, i);
            FloodFill(h_maze - 1, i);
        }
        // DFS: Search and compete the maze with cycles.
        int max = 0;
        int sum = 0;
        for (int i = 0; i < h_maze; ++i) {
            for (int j = 0; j < w_maze; ++j) {
                int result = FloodFill(i, j) / 3;
                if (result) {
                    max = result > max ? result : max;
                    ++sum;
                }
            }
        }
        // Outputs.
        printf("Maze #%d:\n", ++num_case);
        if (sum) {
            printf("%d Cycles; the longest has length %d.\n", sum, max);
        } else {
            printf("There are no cycles.\n");
        }
        printf("\n");
    }
    
    return 0;
}

void EnlargeAndSave(int x, int y, char ch) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            maze[x * 3 + i][y * 3 + j] = ' ';
        }
    }
    if (ch == '/') {
        maze[x * 3][y * 3 + 2] = '#';
        maze[x * 3 + 1][y * 3 + 1] = '#';
        maze[x * 3 + 2][y * 3] = '#';
    } else {
        maze[x * 3][y * 3] = '#';
        maze[x * 3 + 1][y * 3 + 1] = '#';
        maze[x * 3 + 2][y * 3 + 2] = '#';
    }
}

int FloodFill(int x, int y) {
    // Exit.
    if (x < 0 || x >= h_maze
     || y < 0 || y >= w_maze) {
        return 0;
    }
    if (maze[x][y] != ' ') {
        return 0;
    }
    // Continue.
    maze[x][y] = '#';
    int sum = 1;
    for (int i = 0; i < 4; ++i) {
        sum += FloodFill(x + CHANGE[i].x, y + CHANGE[i].y);
    }
    return sum;
}
