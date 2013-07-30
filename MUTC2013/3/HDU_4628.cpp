// HDU 4628
// Pieces
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 18;
const int INF = 1e9;

int T, N;
char S[MAXN];

bool bo[1 << MAXN];
int f[1 << MAXN];

char st[MAXN];

bool check(int s) {
    int n = 0;
    for (int i = 0; i < N; i++)
        if (s & (1 << i))
            st[n++] = S[i];

    for (int i = 0, j = n - 1; i < j; i++, j--)
        if (st[i] != st[j]) return false;
    return true;
}

int dp(int x) {
    if (f[x] != INF) return f[x];
    if (bo[x]) return f[x] = 1;

    for (int s0 = (x - 1) & x; s0; s0 = (s0 - 1) & x)
        if (bo[x - s0]) f[x] = min(f[x], dp(s0) + 1);
    return f[x];
}

int main() {
    scanf("%d", &T);
    getchar();
    while (T--) {
        gets(S);
        N = strlen(S);

        for (int i = 0; i < (1 << N); i++)
            bo[i] = check(i);

        for (int i = 0; i < (1 << N); i++)
            f[i] = INF;
        f[0] = 0;

        int all = (1 << N) - 1;
        printf("%d\n", dp(all));
    }

    return 0;
}
