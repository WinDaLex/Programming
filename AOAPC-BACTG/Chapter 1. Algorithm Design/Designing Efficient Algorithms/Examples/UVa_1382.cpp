// UVa 1382
// Distant Galaxy
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Coor {
    int x, y;
    bool operator<(Coor rhs) const { return x < rhs.x; }
};

const int MAXN = 102;

int N;
Coor pt[MAXN];

int y[MAXN];
int left[MAXN], on[MAXN], on2[MAXN];
int top;

int compute(int lower, int upper) {
    top = 0;
    left[0] = on[0] = on2[0] = 0;
    for (int i = 0; i < N; i++) {
        if (!i || pt[i].x != pt[i - 1].x) {
            top++;
            left[top] = left[top - 1]  + on2[top - 1] - on[top - 1];
            on[top] = on2[top] = 0;
        }
        on[top] += lower < pt[i].y && pt[i].y < upper ? 1 : 0;
        on2[top] += lower <= pt[i].y && pt[i].y <= upper? 1 : 0;
    }

    if (top <= 2) return N;

    int res = 0, tmp = 0;
    for (int i = 1; i <= top; i++) {
        res = max(left[i] + on2[i] + tmp, res);
        tmp = max(on[i] - left[i], tmp);
    }
    return res;
}

int main() {
    int T = 0;
    while (scanf("%d", &N) && N) {
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &pt[i].x, &pt[i].y);
            y[i] = pt[i].y;
        }

        sort(y, y + N);
        int num = unique(y, y + N) - y;
        if (num <= 2) {
            printf("Case %d: %d\n", ++T, N);
            continue;
        }

        sort(pt, pt + N);
    
        int ans = 0;
        for (int i = 0; i < num; i++)
            for (int j = i + 1; j < num; j++)
                ans = max(compute(y[i], y[j]), ans);

        printf("Case %d: %d\n", ++T, ans);
    }   
    
    return 0;
}
