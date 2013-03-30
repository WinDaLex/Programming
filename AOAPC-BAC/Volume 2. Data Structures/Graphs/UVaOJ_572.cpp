// UVaOJ 572
// Oil Deposits
// by A Code Rabbit

#include <cstdio>

struct Change {
    int x;
    int y;
};

const int LIMITS_M = 120;
const int LIMITS_N = 120;

Change change[] = {{-1, -1}, {-1, 0}, {-1, 1},
                    {0, -1},           {0, 1},
                    {1, -1},  {1, 0},  {1, 1}};

char grid[LIMITS_M][LIMITS_N];
int m, n;

bool FloodFill(int x, int y);

void Show() {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    while (scanf("%d%d", &m, &n)) {
        getchar();
        // Exit.
        if (!m && !n) {
            break;
        }
        // Inputs.
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%c", &grid[i][j]);
            }
            getchar();
        }
        // DFS.
        int sum = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (FloodFill(i, j)) {
                    ++sum;
                }
            }
        }
        // Outputs.
        printf("%d\n", sum);
    }

    return 0;
}

bool FloodFill(int x, int y) {
    if (x < 0 || x >= m
     || y < 0 || y >= n) {
        return 0;
    }
    if (grid[x][y] == '*') {
        return 0;
    }
    grid[x][y] = '*';
    for (int i = 0; i < 8; ++i) {
        FloodFill(x + change[i].x, y + change[i].y);
    }
    return true;
}
