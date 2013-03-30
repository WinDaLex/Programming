// UVa 10010
// Where's Waldorf?
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <cctype>

const int MAXN = 52;

struct Point {
    int x, y;
};

const Point DRT[] = {
    {-1, -1}, {-1, 0}, {-1, 1},
    { 0, -1},          { 0, 1},
    { 1, -1}, { 1, 0}, { 1, 1},
};

int N, M, K;
char grid[MAXN][MAXN];
char word[MAXN];

bool find(int x, int y, char str[]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j <= strlen(str); j++) {
            if (j == strlen(str)) return true;
            int cur_x = x + DRT[i].x * j;
            int cur_y = y + DRT[i].y * j;
            if (grid[cur_x][cur_y] != word[j]) break;
        }
    }
    return false;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &M);
        getchar();
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++)
                grid[i][j] = tolower(getchar());
            getchar();
        }
        scanf("%d", &K);
        getchar();
        for (int i = 0; i < K; i++) {
            gets(word);
            for (int j = 0; j < strlen(word); j++)
                word[j] = tolower(word[j]);
            bool bo = true;
            for (int x = 1; x <= N && bo; x++) {
                for (int y = 1; y <= M && bo; y++) {
                    if (find(x, y, word)) {
                        printf("%d %d\n", x, y);
                        bo = false;
                    }
                }
            }
        }
        printf("%s", T ? "\n" : "");
    }

    return 0;
}

