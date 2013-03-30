// UVaOJ 657
// The die is cast
// by A Code Rabbit

#include <algorithm>
#include <cstdio>

using namespace std;

const int LIMITS_W = 100;
const int LIMITS_H = 100;

struct Change {
    int x;
    int y;
};

Change change[] = {{-1, 0}, {1, 0},
                   {0, -1}, {0, 1}};

int num_case = 0;

char picture[LIMITS_W][LIMITS_H];
int w, h;

int dots[LIMITS_W * LIMITS_H];
int top;

int FloodFillDie(int x, int y);
bool FloodFillDot(int x, int y);

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
                scanf("%c", &picture[i][j]);
            }
            getchar();
        }
        // DFS.
        top = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                int result = FloodFillDie(i, j);
                if (result) {
                    dots[top++] = result;
                }
            }
        }
        // Sort.
        sort(dots, dots + top);
        // Outputs
        printf("Throw %d\n", ++num_case);
        for (int i = 0; i < top - 1; ++i) {
            printf("%d ", dots[i]);
        }
        printf("%d\n", dots[top - 1]);
        printf("\n");
    }

    return 0;
}

int FloodFillDie(int x, int y) {
    if (x < 0 || x >= h
     || y < 0 || y >= w) {
        return 0;
    }
    if (picture[x][y] == '.') {
        return 0;
    }
    int sum = FloodFillDot(x, y) ? 1 : 0;
    picture[x][y] = '.';
    for (int i = 0; i < 4; ++i) {
        sum += FloodFillDie(x + change[i].x, y + change[i].y);
    }
    return sum;
}

bool FloodFillDot(int x, int y) {
    if (x < 0 || x >= h
     || y < 0 || y >= w) {
        return false;
    }
    if (picture[x][y] != 'X') {
        return false;
    }
    picture[x][y] = '*';
    for (int i = 0; i < 4; ++i) {
        FloodFillDot(x + change[i].x, y + change[i].y);
    }
    return true;
}
