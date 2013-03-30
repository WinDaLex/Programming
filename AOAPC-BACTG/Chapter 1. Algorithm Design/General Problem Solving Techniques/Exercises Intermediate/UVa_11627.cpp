// UVa 11627
// Slalom
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100002;
const int MAXS = 1000002;

struct Point {
    int x, y;
};

int W, V, N;
Point gate[MAXN];
int S;
int speed[MAXS];

bool check(int x) {
    double l = gate[0].x, r = gate[0].x + W;
    for (int i = 1; i < N; i++) {
        double diff_hor = gate[i].y - gate[i - 1].y;
        double time = diff_hor / x;
        double dist = time * V;
        l = max(l - dist, (double)gate[i].x);
        r = min(r + dist, (double)gate[i].x + W);
        if (l > r) return false;
    }
    return true;
}


int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &W, &V, &N);
        for (int i = 0; i < N; i++)
            scanf("%d%d", &gate[i].x, &gate[i].y);
        scanf("%d", &S);
        for (int i = 0; i < S; i++)
            scanf("%d", &speed[i]);

        int l = 0, r = 1e6;
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (check(m)) l = m;
            else r = m - 1;
        }

        int ans = 0;
        for (int i = 0; i < S; i++)
            if (speed[i] <= l)
                ans = max(speed[i], ans);

        if (ans) printf("%d\n", ans);
        else puts("IMPOSSIBLE");
    }

    return 0;
}
