// HDU 4647
// Another Graph Game
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <functional>
using namespace std;

typedef long long LL;

const int MAXN = 100002;

int N, M;
LL W[MAXN];

int main() {
    while (scanf("%d%d", &N, &M) == 2) {
        for (int i = 1; i <= N; i++) {
            cin >> W[i];
            W[i] *= 2;
        }

        int u, v, w;
        for (int i = 0; i < M; i++) {
            scanf("%d%d%d", &u, &v, &w);
            W[u] += w;
            W[v] += w;
        }

        sort(W + 1, W + 1 + N, greater<LL>());

        LL ans = 0;
        for (int i = 1; i <= N; i++)
            ans += i % 2 ? W[i] : -W[i];
        ans /= 2;

        cout << ans << endl;
    }

    return 0;
}
