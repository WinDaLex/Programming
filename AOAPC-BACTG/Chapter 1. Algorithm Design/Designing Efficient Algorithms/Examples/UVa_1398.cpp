// UVa 1398
// Meteor
// by A Code Rabbit

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 100002;
const int INF = 2e9;
const int LCM = 2520;

int W, H, N;
int x, y, a, b;

int begin, end;
int pt[MAXN * 2];
int top;

void compute(int s, int d, int v) {
    if (v == 0) {
        if (s <= 0 || s >= d) begin = end = 0;
    } else if (v > 0) {
        begin = max(-s * LCM / v, begin);
        end = min((d - s) * LCM / v, end);
    } else {
        begin = max((d - s) * LCM / v, begin);
        end = min(-s * LCM / v, end);
    }
}

void parse() {
    begin = 0, end = INF;

    compute(x, W, a);
    compute(y, H, b);

    if (begin >= end) return;
    pt[top++] = begin * 2;
    pt[top++] = end * 2 - 1;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &W, &H);
        scanf("%d", &N);
        top = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d%d%d%d", &x, &y, &a, &b);
            parse();
        }

        sort(pt, pt + top);

        int cur = 0, ans = 0;
        for (int i = 0; i < top; i++) {
            cur += pt[i] % 2 ? -1 : 1;
            ans = max(cur, ans);
        }

        printf("%d\n", ans);
    }

    return 0;
}
