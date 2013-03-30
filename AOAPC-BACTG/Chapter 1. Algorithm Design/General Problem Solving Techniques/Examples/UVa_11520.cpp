// UVa 11520
// Fill the Square
// by A Code Rabbit

#include <cstdio>
#include <cstring>

const int MAXN = 12;

int N;
char square[MAXN][MAXN];

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d", &N);
        getchar();
        memset(square, 0, sizeof(square));
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++)
                square[i][j] = getchar();
            getchar();
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (square[i][j] != '.') continue;
                for (char ch = 'A'; ch <= 'Z'; ch++) {
                    if (ch == square[i - 1][j]) continue;
                    if (ch == square[i + 1][j]) continue;
                    if (ch == square[i][j - 1]) continue;
                    if (ch == square[i][j + 1]) continue;
                    square[i][j] = ch;
                    break;
                }
            }
        }

        printf("Case %d:\n", cas);
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++)
                putchar(square[i][j]);
            putchar('\n');
        }
    }


    return 0;
}
