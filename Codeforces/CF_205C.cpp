// CF 205C
// Find Maximum
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100002;

int N;
int A[MAXN];
char S[MAXN];

int sum[MAXN];

int main() {
    scanf("%d", &N);
    sum[0] = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        sum[i] = sum[i - 1] + A[i];
    }
    scanf("%s", S);

    int cur = 0, ans = 0;
    for (int i = 1; i <= N; i++) {
        if (S[N - i] == '1') {
            ans = max(ans, cur + sum[N - i]);
            cur += A[N + 1 - i];
        }
    }
    ans = max(ans, cur);

    printf("%d\n", ans);


    return 0;
}
