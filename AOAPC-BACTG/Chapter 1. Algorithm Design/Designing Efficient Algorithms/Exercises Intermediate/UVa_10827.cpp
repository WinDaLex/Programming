// UVa 10827
// Maximum sum on a torus
// by A Code Rabbit

#include <cstdio>
#include <deque>
#include <iostream>
using namespace std;

struct State { int y, v; };

const int MAXN = 77 * 2;
const int INF = 1e9;

int T, N;
int a[MAXN][MAXN];

int s[MAXN][MAXN];
deque<State> mque;
int ans;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                scanf("%d", &a[i][j]);

        for (int i = 1; i <= N * 2; i++) {
            for (int j = 1; j <= N * 2; j++) {
                a[i][j] = a[(i - 1) % N + 1][(j - 1) % N + 1];        
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
            }
        }

        ans = -INF;
        for (int x1 = 0; x1 < N; x1++) {
            for (int x2 = x1 + 1; x2 <= x1 + N; x2++) {
                mque.clear();
                for (int y = 1; y <= N * 2; y++) {
                    if (!mque.empty() && mque.front().y < y - N) mque.pop_front();
                    State cur = (State){y, s[x2][y] - s[x1][y]};
                    ans = max(cur.v - (mque.empty() ? 0 : mque.front().v), ans);
                    while (!mque.empty() && cur.v <= mque.back().v) mque.pop_back();
                    mque.push_back(cur);
                }
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
