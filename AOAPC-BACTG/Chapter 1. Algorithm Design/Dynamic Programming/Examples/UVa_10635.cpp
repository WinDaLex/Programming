// UVa 10635
// Prince and Princess
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 250 * 250 + 1;
const int INF = 1e9;

int T;
int N, P, Q;
int a[MAXN], b[MAXN];

int map[MAXN];
int s[MAXN], top;
int d[MAXN], g[MAXN];

int main() {
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d%d%d", &N, &P, &Q);
        N = N * N; P = P + 1; Q = Q + 1;
        for (int i = 0; i < P; i++) scanf("%d", &a[i]);
        for (int i = 0; i < Q; i++) scanf("%d", &b[i]);

        memset(map, 0, sizeof(map));
        for (int i = 0; i < P; i++) map[a[i]] = i + 1;

        top = 0;
        for (int i = 0; i < Q; i++) {
            if (map[b[i]]) s[top++] = map[b[i]];
        }
    
        for (int i = 1; i <= top; i++) g[i] = INF;
        for (int i = 0; i < top; i++) {
            int k = lower_bound(g + 1, g + top + 1, s[i]) - g;
            g[d[i] = k] = s[i];
        }

        int ans = 0;
        for (int i = 0; i < top; i++)
            ans = max(d[i], ans);

        printf("Case %d: %d\n", cas, ans);
    }


    return 0;
}
