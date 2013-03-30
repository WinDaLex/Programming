// UVa 1121
// Subsequence
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100002;

int N, S;
int a[MAXN];

int main() {
    while (scanf("%d%d", &N, &S) != EOF) {
        for (int i = 0; i < N; i++)
            scanf("%d", &a[i]);
        
        int sum = 0, ans = N + 1;


        for (int l = 0, r = 0; r < N; r++) {
            sum += a[r];
            while (sum >= S) {
                ans = min(r + 1 - l, ans);
                sum -= a[l++];
            }
        }

        printf("%d\n", ans < N + 1 ? ans : 0);
    }

    return 0;
}
