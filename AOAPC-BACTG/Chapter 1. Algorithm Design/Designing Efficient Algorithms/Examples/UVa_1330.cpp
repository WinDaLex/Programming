// UVa 1330
// City Game
// by A Code Rabbit

#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;

const int MAXM = 1002;
const int MAXN = 1002;

int M, N;
char grid[MAXM][MAXN];

int h[MAXN], l[MAXN], r[MAXN];

char getch() {
    char ch = getchar();
    while (!isalpha(ch)) ch = getchar();
    return ch;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &M, &N);
        for (int i = 1; i <= M; i++)
            for (int j = 1; j <= N; j++)
                grid[i][j] = getch();

        for (int i = 1; i <= N; i++) {
            l[i] = r[i] = N;
            h[i] = 0;
        }

        int ans = 0;
        for (int i = 1; i <= M; i++) {
            for (int j = 1, cur = 0; j <= N; j++) {
                cur  = grid[i][j] == 'R' ? 0 : cur + 1;
                l[j] = grid[i][j] == 'R' ? N : min(cur, l[j]);
                h[j] = grid[i][j] == 'R' ? 0 : h[j] + 1;
            }
            for (int j = N, cur = 0; j >= 1; j--) {
                cur  = grid[i][j] == 'R' ? 0 : cur + 1;
                r[j] = grid[i][j] == 'R' ? N : min(cur, r[j]);
                ans  = max((l[j] + r[j] - 1) * h[j], ans);
            }
        }
    
        printf("%d\n", ans * 3);
    }

    return 0;
}
