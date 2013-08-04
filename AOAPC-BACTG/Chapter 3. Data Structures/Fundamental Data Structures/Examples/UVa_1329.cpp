// UVa 1329
// Corporative Network
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 20002;

int T, N, I, J;
char S[10];

int pa[MAXN], d[MAXN];

int find(int x) {
    if (pa[x] != x) {
        int anc = find(pa[x]);
        d[x] += d[pa[x]];
        pa[x] = anc;
    }
    return pa[x];
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);

        for (int i = 1; i <= N; i++) {
            pa[i] = i;
            d[i] = 0;
        }

        while (scanf("%s", S) && S[0] != 'O') {
            if (S[0] == 'E') {
                scanf("%d", &I);
                find(I);
                printf("%d\n", d[I]);
            } else {
                scanf("%d%d", &I, &J);
                pa[I] = J;
                d[I] = abs(I - J) % 1000;
            }
        }
    }

    return 0;
}
