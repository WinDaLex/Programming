// UVa 11235
// Frequent values
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100002;

int N, Q, L, R;
int A[MAXN];

int val[MAXN], cnt[MAXN], top;
int no[MAXN], left[MAXN], right[MAXN];

int f[20][MAXN];

void st() {
    for (int i = 0; i < top; i++)
        f[0][i] = cnt[i];
    for (int i = 1; (1 << i) <= top; i++)
        for (int j = 0; j + (1 << i) <= top; j++)
            f[i][j] = max(f[i - 1][j], f[i - 1][j + (1 << (i - 1))]);
}

int rmq(int l, int r) {
    int n = 0;
    while ((1 << (n + 1)) <= r + 1 - l) n++;
    return max(f[n][l], f[n][r - (1 << n) + 1]);
}

int main() {
    while (scanf("%d", &N) == 1 && N) {
        scanf("%d", &Q);
        for (int i = 1; i <= N; i++)
            scanf("%d", &A[i]);

        top = 0;
        for (int i = 1; i <= N; i++) {
            if (i == 1 || A[i - 1] < A[i]) {
                top++;
                val[top - 1] = A[i];
                cnt[top - 1] = 1;
            } else {
                cnt[top - 1]++;
            }
            no[i] = top - 1;
        }

        int left_bound = 0, right_bound = 0;
        for (int i = 1, j = N; i <= N; i++, j--) {
            if (i == 1 || A[i - 1] < A[i])
                left_bound = i;
            left[i] = left_bound;

            if (j == N || A[j] < A[j + 1])
                right_bound = j;
            right[j] = right_bound;
        }

        st();

        for (int i = 0; i < Q; i++) {
            scanf("%d%d", &L, &R);
            if (no[L] == no[R]) {
                printf("%d\n", R + 1 - L);
                continue;
            }
            int ans = max(right[L] + 1 - L, R + 1 - left[R]);
            if (no[L] + 1 <= no[R] - 1) ans = max(ans, rmq(no[L] + 1, no[R] - 1));
            printf("%d\n", ans);
        }
    }

    return 0;
}
