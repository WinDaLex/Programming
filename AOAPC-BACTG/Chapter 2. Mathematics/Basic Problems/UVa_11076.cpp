// UVa 11076
// Add Again
// by A Code Rabbit

#include <cstdio>
#include <cstring>

typedef unsigned long long ULL;

const int MAXN = 14;

int N;
int D[MAXN];

int factorial[13];
int count[10];

int main() {
    factorial[0] = 1;
    for (int i = 1; i < 13; i++)
        factorial[i] = factorial[i - 1] * i;

    while (scanf("%d", &N) && N) {
        for (int i = 0; i < N; i++)
            scanf("%d", &D[i]);

        ULL sum = 0;
        for (int i = 0; i < N; i++)
            sum += D[i];

        memset(count, 0, sizeof(count));
        for (int i = 0; i < N; i++)
            count[D[i]]++;

        sum *= factorial[N - 1];
        for (int i = 0; i < 10; i++)
            sum /= factorial[count[i]];

        ULL ans = 0;
        for (int i = 0; i < N; i++)
            ans = ans * 10 + sum;

        printf("%llu\n", ans);
    }

    return 0;
}
