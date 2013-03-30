// UVaOJ 705
// Slash Maze
// by A Code Rabbit

#include <cstdio>
#include <cstring>


enum Direction {
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3,
};

struct Change {
    int x;
    int y;
};

const Direction DIRECTION[] = {
    UP,
    DOWN,
    LEFT,
    RIGHT,
};
// Form four directions what are UP, DOWN, LEFT, RIGHT.
const Change CHANGE[] = {
    {-1,  0},
    { 1,  0},
    { 0, -1},
    { 0,  1},
};

// Form four directions what are UP, DOWN, LEFT, RIGHT.
const Direction REFLEX_SLASH[] = {
    LEFT,
    RIGHT,
    UP,
    DOWN,
};
const Direction REFLEX_BACKSLASH[] = {
    RIGHT,
    LEFT,
    DOWN,
    UP, 
};

const int LIMITS_W = 100;
const int LIMITS_H = 100;

int num_case = 0;

char maze[LIMITS_W][LIMITS_H];
int w, h;

bool is_visited[LIMITS_W][LIMITS_H][4];

Direction Opposite(Direction direction);
int FloodFill(int x, int y, Direction direction);

int main() {
    while (scanf("%d%d", &w, &h)) {
        getchar();
        // Exit.
        if (!w && !h) {
            break;
        }
        // Inputs.
        for (int i = 0; i < h; ++i) {
            gets(maze[i]);
        }
        // DFS: Remove grids of the maze without cycles.
        memset(is_visited, false, sizeof(is_visited));
        for (int i = 0; i < h; ++i) {
            FloodFill(i, 0, LEFT);
            FloodFill(i, w - 1, RIGHT);
        }
        for (int i = 0; i < w; ++i) {
            FloodFill(0, i, UP);
            FloodFill(h - 1, i, DOWN);
        }
        //Show();
        // DFS: Search and compete the maze with cycles.
        int max = 0;
        int sum = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                for (int k = 0; k < 4; k++) {
                    int result = FloodFill(i, j, DIRECTION[k]);
                    if (result) {
                        max = result > max ? result : max;
                        ++sum;
                    }
                }
            }
        }
        // Outputs.
        //Show();
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

Direction Opposite(Direction direction) {
    if (direction == LEFT) {
        return RIGHT;
    } else
    if (direction == RIGHT) {
        return LEFT;
    } else
    if (direction == UP) {
        return DOWN;
    } else
    if (direction == DOWN) {
        return UP;
    }
}

int FloodFill(int x, int y, Direction direction) {
    // Exit.
    if (x < 0 || x >= h
     || y < 0 || y >= w) {
        return 0;
    }
    if (is_visited[x][y][direction]) {
        return 0;
    }
    is_visited[x][y][direction] = true;
    // Continue.
    Direction direction_leave;
    if (maze[x][y] == '/') {
        direction_leave = REFLEX_SLASH[direction];
    } else {
        direction_leave = REFLEX_BACKSLASH[direction]; 
    }
    is_visited[x][y][direction_leave] = true;
    return 1 + FloodFill(x + CHANGE[direction_leave].x,
                         y + CHANGE[direction_leave].y,
                         Opposite(direction_leave));
}
