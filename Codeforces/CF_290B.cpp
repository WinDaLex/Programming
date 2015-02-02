// Codeforces #290 B
// Fox And Two Dots

#include <cstdio>
#include <cctype>

const int MAXN = 52;

int N, M;
char A[MAXN][MAXN];

bool vis[MAXN][MAXN];

char getch() {
    char ch = getchar();
    while (!isupper(ch)) ch = getchar();
    return ch;
}

bool dfs(int x, int y, int px, int py) {
    if (x < 1 || x > N || y < 1 || y > M) return false;
    if (A[x][y] != A[px][py]) return false;
    if (vis[x][y]) return true;

    vis[x][y] = true;
    if ((x - 1 != px || y != py) && dfs(x - 1, y, x, y)) return true;
    if ((x + 1 != px || y != py) && dfs(x + 1, y, x, y)) return true;
    if ((x != px || y - 1 != py) && dfs(x, y - 1, x, y)) return true;
    if ((x != px || y + 1 != py) && dfs(x, y + 1, x, y)) return true;
    return false;
}

bool hasCycle() {
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (!vis[i][j] && dfs(i, j, i, j))
                return true;
    return false;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            A[i][j] = getch();

    puts(hasCycle() ? "Yes" : "No");

    return 0;
}
