// UVa 10318
// Security Panel
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <cctype>

const int MAXR = 7;
const int MAXC = 7;

int R, C;
int grid[3][3];

int panel[MAXR][MAXC];
int ans[MAXR * MAXC], top;
int min_val;
int best[MAXR * MAXC];

bool check() {
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (!panel[i][j]) return false;
    return true;
}

void print() {
    if (top < min_val) {
        memcpy(best, ans, sizeof(ans));
        min_val = top;
    }
}

void press(int x, int y) {
    for (int i = x - 1; i <= x + 1; i++)
        for (int j = y - 1; j <= y + 1; j++)
            if (i >= 0 && i < R && j >= 0 && j < C)
                if (grid[i - x + 1][j - y + 1])
                    panel[i][j] = !panel[i][j];
}

void search(int x, int y) {
    if (y >= C) { x++; y = 0; }
    if (x >= R) { if (check()) print(); return; }
    if (x >= 2 && !panel[x - 2][y]) return;

    search(x, y + 1);
    press(x, y);
    ans[top++] = x * C + y + 1;

    search(x, y + 1);
    press(x, y);
    top--;
}

char getch() {
    char ch = getchar();
    while (isspace(ch)) ch = getchar();
    return ch;
}

int main() {
    int T = 0;
    while (scanf("%d%d", &R, &C) && (R || C)) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                grid[i][j] = (getch() == '*' ? 1 : 0);

        memset(panel, 0, sizeof(panel));
        printf("Case #%d\n", ++T);
        top = 0, min_val = MAXR * MAXC;
        search(0, 0);

        if (min_val == MAXR * MAXC) {
            puts("Impossible.");
        } else {
            for (int i = 0; i < min_val; i++)
                printf("%d%c", best[i], i < min_val - 1 ? ' ' : '\n');
        }
    }

    return 0;
}
