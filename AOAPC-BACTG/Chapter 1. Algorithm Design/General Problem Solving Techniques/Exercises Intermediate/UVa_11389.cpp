// UVa 11389
// The Bus Driver Problem
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

const int MAXN = 102;

int N, D, R;
int morning[MAXN], everning[MAXN];

int main() {
    while (scanf("%d%d%d", &N, &D, &R) && (N || D || R)) {
        for (int i = 0; i < N; i++) scanf("%d", &morning[i]);
        for (int i = 0; i < N; i++) scanf("%d", &everning[i]);

        sort(morning, morning + N);
        sort(everning, everning + N, greater<int>());

        int ans = 0;
        for (int i = 0; i < N; i++) {
            int tmp = morning[i] + everning[i] - D;
            ans += tmp > 0 ? tmp : 0;
        }

        printf("%d\n", ans * R);
    }

    return 0;
}
