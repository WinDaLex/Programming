// UVa 10795
// A Different Task
// by A Code Rabbit

#include <cstdio>

typedef long long LL;

const int MAXN = 62;

int N;
int start[MAXN], finish[MAXN];

LL f(int p[], int x, int pos) {
    if (!x) return 0;
    if (p[x] == pos) return f(p, x - 1, pos);
    else return f(p, x - 1, 6 - p[x] - pos) + (1LL << (x - 1));
}

int main() {
    int cas = 1;
    while (scanf("%d", &N) && N) {
        for (int i = 1; i <= N; i++) scanf("%d", &start[i]);
        for (int i = 1; i <= N; i++) scanf("%d", &finish[i]);

        int k = N;
        while (k && start[k] == finish[k]) k--;

        LL ans = 0;
        if (k)  {
            ans += f(start, k - 1, 6 - start[k] - finish[k]);
            ans += f(finish, k - 1, 6 - start[k] - finish[k]);
            ans += 1;
        }

        printf("Case %d: %lld\n", cas++, ans);
    }

    return 0;
}
