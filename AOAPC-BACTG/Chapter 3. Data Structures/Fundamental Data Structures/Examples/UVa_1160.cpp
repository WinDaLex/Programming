// UVa 1160
// X-Plosives
// by A Code Rabbit

#include <cstdio>

const int MAXN = 100002;

int U, V;

int pa[MAXN];

int find(int x) {
    return pa[x] == x ? x : pa[x] = find(pa[x]);
}

int main() {
    while (scanf("%d", &U) == 1) {
        for (int i = 0; i < MAXN; i++)
            pa[i] = i;

        int ans = 0;
        while (U != -1) {
            scanf("%d", &V);

            U = find(U);
            V = find(V);
            if (U == V) ans++;
            else pa[U] = V;

            scanf("%d", &U);
        }

        printf("%d\n", ans);
    }

    return 0;
}
