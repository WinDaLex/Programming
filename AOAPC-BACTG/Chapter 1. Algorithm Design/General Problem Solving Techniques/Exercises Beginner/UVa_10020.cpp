// UVa 10020
// Minimal coverage
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

struct Seg {
    int l, r;
    bool operator<(Seg rhs) const { return this->l < rhs.l; }
};

const int MAXN = 100002;

int N, M;
Seg seg[MAXN];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &M);
        N = 0;
        while (scanf("%d%d", &seg[N].l, &seg[N].r) && (seg[N].l || seg[N].r))
            N++;
        
        sort(seg, seg + N);

        int last = 0, cur = 0, ans = 0;
        queue<Seg> que;
        que.push(seg[0]);
        for (int i = 0; i < N; i++) {
            if (seg[i].l > cur) break;
            if (seg[i].l > last) {
                last = cur;
                ans++;
                que.push(seg[i]);
            }
            if (seg[i].r > cur) {
                cur = seg[i].r;
                que.back() = seg[i];
            }
            if (cur >= M) break;
        }

        if (cur >= M) {
            printf("%d\n", ans + 1);
            while (!que.empty()) {
                printf("%d %d\n", que.front().l, que.front().r);
                que.pop();
            }
        } else {
            puts("0");
        }
        if (T) puts("");
    }

    return 0;
}
