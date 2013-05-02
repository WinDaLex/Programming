// UVa_10534
// Wavio Sequence
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 10002;
const int INF = 1e9;

int N;
int a[MAXN];

int f1[MAXN], f2[MAXN];
int r[MAXN];

int main() {
    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++)
            scanf("%d", &a[i]);

        for (int i = 0; i < N; i++) r[i] = INF;
        for (int i = 0; i < N; i++) {
            int rank = lower_bound(r, r + N, a[i]) - r;
            r[f1[i] = rank] = a[i];
        }

        for (int i = 0; i < N; i++) r[i] = INF;
        for (int i = N - 1; i >= 0; i--) {
            int rank = lower_bound(r, r + N, a[i]) - r;
            r[f2[i] = rank] = a[i];
        }

        int ans = 0;
        for (int i = 0; i < N; i++)
            ans = max(min(f1[i], f2[i]) * 2 + 1, ans);

        printf("%d\n", ans);
    }

    return 0;
}
