// CF 206B
// Vasya and Public Transport
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1002;
const int MAXM = 1002;

int C1, C2, C3, C4;
int N, M;
int A[MAXN], B[MAXN];

int ans;

int main() {
    scanf("%d%d%d%d", &C1, &C2, &C3, &C4);
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    for (int i = 0; i < M; i++) scanf("%d", &B[i]);

    ans = 0;
    int sum1 = 0;
    for (int i = 0; i < N; i++)
        sum1 += min(A[i] * C1, C2);
    ans += min(sum1, C3);

    int sum2 = 0;
    for (int i = 0; i < M; i++)
        sum2 += min(B[i] * C1, C2);
    ans += min(sum2, C3);

    printf("%d\n", min(ans, C4));

    return 0;

}
