// CF 206C
// Vasya and Robot
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100002;
const int INF = 1e9;

int N, L, R, QL, QR;
int W[MAXN];

int ans;
int sum[MAXN];

int compute(int l) {
    int res = sum[l] * L + (sum[N] - sum[l]) * R;
    int r = N - l;
    if (l == r) return res;
    return res + (l > r ? (l - r - 1) * QL : (r - l - 1) * QR);
}

int main() {
    scanf("%d%d%d%d%d", &N, &L, &R, &QL, &QR);
    sum[0] = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &W[i]);
        sum[i] = sum[i - 1] + W[i];
    }

    ans = INF;
    for (int i = 0; i <= N; i++)
        ans = min(ans, compute(i));

    printf("%d\n", ans);

    return 0;
}
