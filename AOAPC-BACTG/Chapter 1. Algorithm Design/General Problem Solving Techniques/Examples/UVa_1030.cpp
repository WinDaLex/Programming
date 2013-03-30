// UVa 1030
// Image Is Everything
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <cctype>

#define FOR(i,a,b) for (int i = a; i < b; i++)

struct Point {
    int x, y , z;
};

const int MAXN = 12;

int N;
char view[6][MAXN][MAXN];
char cube[MAXN][MAXN][MAXN];

char read_char() {
    while (1) {
        char ch = getchar();
        if (!isspace(ch)) return ch;
    }
}

Point get_coor(int k, int i, int j, int d) {
    switch (k) {
    case 0: return (Point){d, j, i};
    case 1: return (Point){N - 1 - j, d, i};
    case 2: return (Point){N - 1 - d, N - 1 - j, i};
    case 3: return (Point){j, N - 1 - d, i};
    case 4: return (Point){N - 1 - i, j, d};
    case 5: return (Point){i, j, N - 1 - d};
    }
} 

int main() {
    while (scanf("%d", &N) && N) {
        FOR(i, 0, N) FOR(k, 0, 6) FOR(j, 0, N) view[k][i][j] = read_char();

        FOR(x, 0, N) FOR(y, 0, N) FOR(z, 0, N) cube[x][y][z] = '#';

        bool bo = false;
        while (!bo) {
            bo = true;
            FOR(k, 0, 6) FOR(i, 0, N) FOR(j, 0, N) FOR(d, 0, N) {
                Point pt = get_coor(k, i, j, d);
                char &cur = cube[pt.x][pt.y][pt.z];
                if (view[k][i][j] == '.') cur = '.';
                if (cur == '.') continue;
                if (cur == '#') cur = view[k][i][j];
                if (cur == view[k][i][j]) break;
                // The color is wrong, current cube must be absent!
                cur = '.';
                bo = false;
            }
        }
        
        int ans = 0;
        FOR(x, 0, N) FOR(y, 0, N) FOR(z, 0, N)
            if (cube[x][y][z] != '.')
                ans++;

        printf("Maximum weight: %d gram(s)\n", ans);
    }

    return 0;
}
