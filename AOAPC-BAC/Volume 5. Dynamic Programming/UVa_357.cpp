// UVa 357
// Let Me Count The Ways
// by A Code Rabbit

#include <cstdio>
#include <cstring>

typedef long long LL;

const int MAXN = 30002;
const int COIN[] = {1, 5, 10, 25, 50};

int N;

LL f[MAXN];

int main() {
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < MAXN; j++)
            if (j >= COIN[i]) f[j] += f[j - COIN[i]];

    while (scanf("%d", &N) != EOF) {
        if (f[N] == 1) printf("There is only 1 way to produce %d cents change.\n", N);
        else printf("There are %lld ways to produce %d cents change.\n", f[N], N);
    }
    
    return 0;
}
