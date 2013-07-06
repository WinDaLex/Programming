// UVa 10453
// Make Palindrome
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1002;

char S[MAXN], T[MAXN];
int N;

int f[MAXN][MAXN];
int p[MAXN][MAXN];

void print(int x, int y) {
    if (x == 0 && y == 0) return;

    if (x == 0 || p[x][y] == 2) {
        print(x, y - 1);
        putchar(T[y - 1]);
    } else if (y == 0 || p[x][y] == 1) {
        print(x - 1, y);
        putchar(S[x - 1]);
    } else {
        print(x - 1, y - 1);
        putchar(S[x - 1]);
    }
}

int main() {
    while (gets(S)) {
        N = strlen(S);
        for (int i = 0; i < N; i++)
            T[i] = S[N - 1 - i];
        T[N] = '\0';

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (S[i - 1] == T[j - 1]) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                    p[i][j] = 0;
                } else if (f[i - 1][j] > f[i][j - 1]) {
                    f[i][j] = f[i - 1][j];
                    p[i][j] = 1;
                } else {
                    f[i][j] = f[i][j - 1];
                    p[i][j] = 2;
                }
            }
        }

        printf("%d ", N - f[N][N]);
        print(N, N);
        printf("\n");
    }

    return 0;
}
