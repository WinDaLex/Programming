// HDU 4715
// Difference Between Primes
// by A Code Rabbit

#include <cstdio>
#include <cmath>
#include <cstring>

const int MAXN = 10000002;
const int MAXP = 700000;

int T, N;

bool vis[MAXN];
int prime[MAXP];

void sieve(int n) {
    int m = (int)sqrt(n + 0.5);
    memset(vis, false, sizeof(vis));
    for (int i = 2; i <= m; i++) if (!vis[i])
        for (int j = i * i ; j <= n; j += i) vis[j] = true;
}

int gen_primes(int n) {
    sieve(n);
    int c = 0;
    for (int i = 2; i <= n; i++) if (!vis[i])
        prime[c++] = i;
    return c;
}

int main() {
    int top = gen_primes(MAXN - 2);

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        bool bo = false;
        if (N < 0) {
            bo = true;
            N = -N;
        }
        for (int i = 0; i < top; i++) {
            if (prime[i] + N > MAXN) {
                printf("FAIL\n");
                break;
            
            } else if (!vis[prime[i] + N]) {
                if (bo) printf("%d %d\n", prime[i], prime[i] + N);
                else printf("%d %d\n", prime[i] + N, prime[i]);
                break;
            }
        }
    }
    
    return 0;
}
