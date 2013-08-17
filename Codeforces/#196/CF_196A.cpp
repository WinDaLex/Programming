// CF 196A
// Puzzles
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 52;
const int INF = 1e9;

int N, M;
int F[MAXN];

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++)
        scanf("%d", &F[i]);

    sort(F, F + M);

    int ans = INF;
    for (int i = 0; i + N - 1 < M; i++)
        ans = min(ans, F[i + N - 1] - F[i]);

    printf("%d\n", ans);

    return 0;
}
