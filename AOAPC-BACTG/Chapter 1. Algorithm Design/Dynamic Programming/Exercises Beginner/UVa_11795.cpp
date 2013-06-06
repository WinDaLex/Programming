// UVa 11795
// Mega Man's Missions
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const int MAXN = 18;

int T, N;
int A[MAXN];

LL f[1 << MAXN];

bool check(int s, int s0) {
    int t = A[0];
    for (int i = 0; i < N; i++)
        if (s0 & (1 << i))
            t |= A[i + 1];
    return (s | t) == t;
} 

int main() {
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d", &N);
        getchar();
        memset(A, 0, sizeof(A));
        for (int i = 0; i < N + 1; i++) {
            for (int j = 0; j < N; j++)
                A[i] += (1 << j) * (getchar() - '0');
            getchar();
        }

        f[0] = 1;
        for (int s = 1; s < (1 << N); s++) {
            f[s] = 0;
            for (int i = 0; i < N; i++) {
                int s0 = s ^ (1 << i);
                if (s & (1 << i) && check(s, s0))
                    f[s] += f[s0];
            }
        }

        int all = (1 << N) - 1;
        printf("Case %d: %lld\n", cas, f[all]);
    }

    return 0;
}
