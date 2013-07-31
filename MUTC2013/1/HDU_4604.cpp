// HDU 4604
// Deque
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

const int MAXN = 100002;
const int INF = 1e9;

int T, N;
int A[MAXN];

int f1[MAXN], f2[MAXN];
int r1[MAXN], r2[MAXN];

int same[MAXN];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
            scanf("%d", &A[i]);

        for (int i = 1; i <= N; i++) r1[i] = INF;
        for (int i = N - 1; i >= 0; i--) {
            int cur = upper_bound(r1 + 1, r1 + N + 1, A[i]) - r1;
            same[i] = cur - (lower_bound(r1 + 1, r1 + N + 1, A[i]) - r1);
            r1[f1[i] = cur] = A[i];
        }

        for (int i = 1; i <= N; i++) r2[i] = -INF;
        for (int i = N - 1; i >= 0; i--) {
            int cur = upper_bound(r2 + 1, r2 + N + 1, A[i], greater<int>()) - r2;
            r2[f2[i] = cur] = A[i];
        }
        
        int ans = 0;
        for (int i = 0; i < N; i++)
            ans = max(ans, f1[i] + f2[i] - 1 - same[i]);

        printf("%d\n", ans);
    }

    return 0;
}
