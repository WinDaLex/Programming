// UVa 10079
// Pizza Cutting
// by A Code Rabbit

#include <cstdio>

typedef long long LL;

int N;

int main() {
    while (scanf("%d", &N) && N >= 0) {
        printf("%lld\n", (LL)N * (N + 1) / 2 + 1);
    }

    return 0;
}
