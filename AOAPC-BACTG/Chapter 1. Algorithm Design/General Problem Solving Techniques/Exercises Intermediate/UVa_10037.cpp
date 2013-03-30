// UVa 10037
// Bridge
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1002;

int N;
int t[MAXN];

int order[MAXN * 3], top;
int ans;

void pass(int p1 = 0, int p2 = 0, int p3 = 0, int p4 = 0, int p5 = 0, int p6 = 0) {
    if (p1) order[top++] = p1; 
    if (p2) order[top++] = p2; 
    if (p3) order[top++] = p3; 
    if (p4) order[top++] = p4; 
    if (p5) order[top++] = p5; 
    if (p6) order[top++] = p6; 
    ans += max(p1, p2) + p3 + max(p4, p5) + p6;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
            scanf("%d", &t[i]);

        if (N == 1) {
            printf("%d\n%d\n", t[0], t[0]);
            printf("%s", T ? "\n" : "");
            continue;
        }

        sort(t, t + N);

        top = 0; ans = 0;
        int a = t[0], b = t[1], idx;
        for (idx = N; idx > 3; idx -= 2) {
            int c = t[idx - 2], d = t[idx - 1];
            if (c < b * 2 - a) pass(a, d, a, a, c, a);
            else pass(a, b, a, c, d, b);
        }
        if (idx == 3) pass(t[0], t[2], t[0], t[0], t[1]);
        else if (idx == 2) pass(t[0], t[1]);

        printf("%d\n", ans);
        for (int i = 0; i < N - 2; i++)
            printf("%d %d\n%d\n", order[i * 3], order[i * 3 + 1], order[i * 3 + 2]);
        printf("%d %d\n", order[N * 3 - 6], order[N * 3 - 5]);
        printf("%s", T ? "\n" : "");
    }

    return 0;
}
