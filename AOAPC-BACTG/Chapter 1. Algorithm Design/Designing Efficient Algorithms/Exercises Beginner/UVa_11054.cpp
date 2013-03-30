// UVa 11054
// Wine trading in Gergovia
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100002;

int N;
int a[MAXN];

int main() {
    while (scanf("%d", &N) && N) {
        for (int i = 0; i < N; i++)
            scanf("%d", &a[i]);

        long long ans = 0;
        for (int i = 0; i < N - 1; i++) {
            ans += abs(a[i]);
            a[i + 1] += a[i]; 
        }

        printf("%lld\n", ans);
    }
    

    return 0;
}
