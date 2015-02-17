// Codeforces #292 B
// Drazil and His Happy Friends

#include <cstdio>

const int MAXN = 102;
const int MAXM = 102;

int N, M, B, G, X, Y;

bool h[MAXN + MAXM];
int pa[MAXN + MAXM];

int find(int x) {
    return pa[x] == x ? x : pa[x] = find(pa[x]);
}

void uni(int x, int y) {
    int px = find(x), py = find(y);
    if (px != py) pa[px] = py;
}

int main() {
    scanf("%d%d", &N, &M);
    scanf("%d", &B);
    for (int i = 0; i < B; i++) {
        scanf("%d", &X);
        h[X] = true;
    }
    scanf("%d", &G);
    for (int i = 0; i < G; i++) {
        scanf("%d", &Y);
        h[N + Y] = true;
    }

    for (int i = 0; i < N + M; i++) pa[i] = i;
    for (int i = 0; i < N * M; i++) uni(i % N, N + i % M);
    for (int i = 0; i < N + M; i++) if (h[i]) h[find(i)] = true;

    for (int i = 0; i < N + M; i++) {
        if (!h[find(i)]) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");

    return 0;
}
