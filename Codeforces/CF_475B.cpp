// CF 475B
// Strongly Connected City
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 22;
const int MAXM = 22;

int N, M;

int city[MAXN * MAXM][MAXN * MAXM];
char line[MAXN];

void connectH(int x, char dirt) {
    if (dirt == '>') {
        for (int i = 0; i < M - 1; i++) 
            city[x * M + i][x * M + i + 1] = true;
    } else {
        for (int i = M - 1; i > 0; i--) 
           city[x * M + i][x * M + i - 1] = true;
    }
}

void connectV(int y, char dirt) {
    if (dirt == 'v') {
        for (int i = 0; i < N - 1; i++) 
            city[i * M + y][(i + 1) * M + y] = true;
    } else {
        for (int i = N - 1; i > 0; i--) 
           city[i * M + y][(i - 1) * M + y] = true;
    }
}

int main() {
    scanf("%d%d", &N, &M);
    gets(line);

    memset(city, sizeof(city), false);
    for (int i = 0; i < N; i++) connectH(i, getchar());
    gets(line);
    for (int i = 0; i < M; i++) connectV(i, getchar());
    gets(line);

    int tot = N * M;

    for (int k = 0; k < tot; k++)
        for (int i = 0; i < tot; i++)
            for (int j = 0; j < tot; j++)
                if (city[i][k] && city[k][j])
                    city[i][j] = true;

    bool bo = false;
    for (int i = 0; i < tot; i++)
        for (int j = 0; j < tot; j++)
            if (i != j && !city[i][j])
                bo = true;

    puts(bo ? "NO" : "YES");

    return 0;
}
