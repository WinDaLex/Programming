// UVa 11538
// Chess Queen
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;

LL N, M;

int main() {
    while (scanf("%lld%lld", &N, &M) && (N || M)) {
        if (N > M) swap(N, M);
        printf("%lld\n", N * M * (N + M - 2) + 2 * N * (N - 1) * (3 * M - N - 1) / 3);
    }

    return 0;
}
