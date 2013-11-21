// CF 356A
// Knight Tournament
// by A Code Rabbit

#include <cstdio>
#include <set>
using namespace std;

const int MAXN = 3e5 + 2;
int N, M, L, R, X;

set<int> alive;
int ans[MAXN];

int main() {
    scanf("%d%d", &N, &M);
    alive.clear();
    for (int i = 1; i <= N; i++)
        alive.insert(i);

    for (int i = 0; i < M; i++) {
        scanf("%d%d%d", &L, &R, &X);
        set<int>::iterator it = alive.lower_bound(L);
        while (it != alive.end() && *it <= R) {
            ans[*it] = X;
            alive.erase(it++);
        }
        alive.insert(X);
        ans[X] = 0;
    }

    for (int i = 1; i <= N; i++)
        printf("%d%c", ans[i], i == N ? '\n' : ' ');

    return 0;
}
