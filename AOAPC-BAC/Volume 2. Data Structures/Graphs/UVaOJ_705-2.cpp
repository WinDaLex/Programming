// UVaOJ 705
// Slash Maze
// by A Code Rabbit

#include <cstdio>

struct Change {
    int x;
    int y;
};

Change STRAIGHT_CHANGE[] = {
              {-1, 0},
    { 0, -1},          { 0, 1},
              { 1, 0},
};

Change SLASH_CHANGE[] = {
    {-1, -1},          {-1, 1},
    
    { 1, -1},          { 1, 1},
};

const int LIMITS_W = 500;
const int LIMITS_H = 500;

int num_case = 0;

char maze[LIMITS_H][LIMITS_W];
int w, h;
int w_maze, h_maze;

void EnlargeAndSave(int x, int y, char ch);

bool canArrive(int x, int y, Change change);
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
        w_maze = w * 2;
        h_maze = h * 2;
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
                int result = FloodFill(i, j);
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
    maze[x * 2][y * 2] = ch == '/' ? ' ' : '#';
    maze[x * 2][y * 2 + 1] = ch == '/' ? '#' : ' ';
    maze[x * 2 + 1][y * 2] = ch == '/' ? '#' : ' ';
    maze[x * 2 + 1][y * 2 + 1] = ch == '/' ? ' ' : '#';
}

bool canArrive(int x, int y, Change change) {
    int x_after_change = x % 2 + change.x;
    int y_after_change = y % 2 + change.y;
    if (0 <= x_after_change && x_after_change < 2
     && 0 <= y_after_change && y_after_change < 2) {
        return false;
    } else
    if ((x_after_change < 0 || x_after_change >= 2)
     && (y_after_change < 0 || y_after_change >= 2)) {
        return false;
    } else {
        return true;
    }
    printf("\n");
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
    maze[x][y] = '.';
    int sum = 1;
    for (int i = 0; i < 4; ++i) {
        sum += FloodFill(x + STRAIGHT_CHANGE[i].x, y + STRAIGHT_CHANGE[i].y);
    }
    for (int i = 0; i < 4; ++i) {
        if (canArrive(x, y, SLASH_CHANGE[i])) {
            sum += FloodFill(x + SLASH_CHANGE[i].x, y + SLASH_CHANGE[i].y);
        }
    }

    return sum;
}
