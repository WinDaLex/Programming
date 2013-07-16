// UVa 10006
// Carmichael Numbers
// by A Code Rabbit

#include <cstdio>
#include <cstring>

const int MAXN = 65002;
typedef long long LL;

int N;

bool vis[MAXN];

int quick_power(int a, int n, int m) {
    if (n == 0) return 1;
    int x = quick_power(a, n / 2, m);
    LL res = (LL)x * x % m;
    if (n % 2) res = (res * a) % m;
    return res;
}

bool check(int n) {
    for (int i = 2; i < n; i++)
        if (quick_power(i, n, n) != i)
            return false;
    return true;
}

int main() {

    memset(vis, false, sizeof(vis));
    for (int i = 2; i < MAXN; i++)
        for (int j = i * 2; j < MAXN; j += i)
            vis[j] = true;

    while (scanf("%d", &N) != EOF && N) {
        if (vis[N] && check(N))
            printf("The number %d is a Carmichael number.\n", N);
        else
            printf("%d is normal.\n", N);
    }

    return 0;
}
