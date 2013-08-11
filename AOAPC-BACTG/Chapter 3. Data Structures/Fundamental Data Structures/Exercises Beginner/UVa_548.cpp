// UVa 548
// Tree
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10002;
const int INF = 1e9;

struct Ans {
    int sum, v;
    Ans(int sum, int v) : sum(sum), v(v) { }
    bool operator<(Ans rhs) const {
        return sum < rhs.sum || (sum == rhs.sum && v < rhs.v);
    }
};

int N;
int S1[MAXN], S2[MAXN];
char ch;

int* find(int *s, int v) {
    for (int *p = s; *p; p++)
        if (*p == v)
            return p;
}

Ans build(int n, int *s1, int *s2) {
    if (n <= 1) { return n == 1 ? Ans(s1[0], s1[0]) : Ans(INF, INF); }
    int p = find(s2, s1[n - 1]) - s2;
    Ans ret = min(build(n - p - 1, s1 + p, s2 + p + 1), build(p, s1, s2));
    ret.sum += s1[n - 1];
    return ret;
}

int main() {
    while (scanf("%d%c", &S2[0], &ch) == 2) {
        N = 1;
        while (ch != '\n') scanf("%d%c", &S2[N++], &ch);
        for (int i = 0; i < N; i++) scanf("%d", &S1[i]);

        printf("%d\n", build(N, S1, S2).v);
    }

    return 0;
}
