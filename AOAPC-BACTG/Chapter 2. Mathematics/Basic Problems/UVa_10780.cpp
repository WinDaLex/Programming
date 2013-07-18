// UVa 10780
// Again Prime? No Time.
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10002;
const int PIN = 2002;
const int INF = 1e9;

int T, M, N;

int vis[MAXN];
int prime[PIN], top;

int cnt_m[PIN], cnt_n[PIN];

void sieve_prime() {
    memset(vis, false, sizeof(vis));
    top = 0;
    for (int i = 2; i < MAXN; i++) {
        if (!vis[i]) {
            prime[top++] = i;
            for (int j = i * i; j < MAXN; j += i)
                vis[j] = true;
        }
    }
}

void factor(int n, int *cnt) {
    for (int i = 0; i < top && n != 1; i++) {
        while (n % prime[i] == 0) {
            cnt[i]++;
            n /= prime[i];
        }
    }
}

int main() {
    sieve_prime(); 

    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d%d", &M, &N);

        memset(cnt_m, 0, sizeof(cnt_m));
        factor(M, cnt_m);

        memset(cnt_n, 0, sizeof(cnt_n));
        for (int i = 2; i <= N; i++)
            factor(i, cnt_n);

        int ans = INF;
        for (int i = 0; i < top; i++)
            if (cnt_m[i])
                ans = min(ans, cnt_n[i] / cnt_m[i]);

        printf("Case %d:\n", cas);
        if (ans) printf("%d\n", ans);
        else puts("Impossible to divide");
    }

    return 0;
}
