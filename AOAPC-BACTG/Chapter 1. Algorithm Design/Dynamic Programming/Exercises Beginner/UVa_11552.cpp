// UVa 11552
// Fewest Flogp
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int LEN = 1002;
const int ABC = 26;
const int INF = 1e9;

int T, K;
char S[LEN];

int f[ABC][ABC];
int g[ABC], cnt[ABC];

int compute(int begin, int end, int fst, int lst) {
    memset(cnt, 0, sizeof(cnt));
    for (int i = begin; i < end; i++)
        cnt[S[i] - 'a']++;

    if (!cnt[fst] || !cnt[lst]) return INF;
    if (K >= 2 && fst == lst && cnt[fst] < 2) return INF;

    int res = 0;
    for (int i = 0; i < ABC; i++)
        res += cnt[i] ? 1 : 0;
    res--;

    if (fst == lst && res > 0) 
        res++;

    return res;
}

int dp(int s, int x, int y) {
    int res = INF;
    for (int i = 0; i < ABC; i++)
        res = min(g[i] + (i == x ? 0 : 1), res);

    res += compute((s - 1) * K, s * K, x, y);

    return res;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%s", &K, S);
    
        memset(g, 0, sizeof(g));
        for (int k = 1; k <= strlen(S) / K; k++) {
            for (int i = 0; i < ABC; i++)
                for (int j = 0; j < ABC; j++)
                    f[i][j] = dp(k, j, i);

            for (int i = 0; i < ABC; i++)
                g[i] = *min_element(f[i], f[i] + ABC);
        }

        int ans = *min_element(g, g + ABC) + 1;

        printf("%d\n", ans);
    }
    
    return 0;
}
