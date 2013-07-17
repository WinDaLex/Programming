// UVa 11388
// GCD LCM
// by A Code Rabbit

#include <cstdio>

int T, G, L;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &G, &L);
        if (L % G == 0) printf("%d %d\n", G, L);
        else puts("-1");
    }

    return 0;
}
