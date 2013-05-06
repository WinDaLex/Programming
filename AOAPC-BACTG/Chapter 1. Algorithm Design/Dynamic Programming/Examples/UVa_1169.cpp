// UVa 1169
// Robotruck
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;

const int MAXN = 100002;

struct Package { int x, y, w; };

int T, C, N;
Package p[MAXN];

int dist[MAXN], length[MAXN], weight[MAXN];
deque<int> mque;
int f[MAXN];

int func(int x) { return f[x] + dist[x + 1] - length[x + 1]; }

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &C, &N);
        for (int i = 1; i <= N; i++)
            scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].w);
        p[0] = (Package) {0, 0, 0};

        dist[0] = length[0] = weight[0] = 0;
        for (int i = 1; i <= N; i++) {
            dist[i] = abs(p[i].x) + abs(p[i].y);
            length[i] = length[i - 1] + abs(p[i].x - p[i - 1].x) + abs(p[i].y - p[i - 1].y);
            weight[i] = weight[i - 1] + p[i].w;
        }

        mque.clear();
        mque.push_front(0);
        f[0] = 0;
        for (int i = 1; i <= N; i++) {
            while (weight[i] - weight[mque.front()] > C) mque.pop_front();
            f[i] = func(mque.front()) + length[i] + dist[i];
            while (!mque.empty() && func(i) < func(mque.back())) mque.pop_back();
            mque.push_back(i);
        }

        printf("%d\n", f[N]);
        if (T) printf("\n");
    }
    
    return 0;
}
