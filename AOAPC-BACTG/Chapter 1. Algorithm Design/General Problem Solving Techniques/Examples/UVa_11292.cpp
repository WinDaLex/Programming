// UVa 11292
// Dragon of Loowater
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 20002;

int n, m;
int head[MAXN], knight[MAXN];

int main() {
    while (scanf("%d%d", &n, &m) && n && m) {
        for (int i = 0; i < n; i++) scanf("%d", &head[i]);
        for (int i = 0; i < m; i++) scanf("%d", &knight[i]);

        sort(head, head + n);
        sort(knight, knight + m);

        int ans = 0, cnt = 0;
        for (int i = 0; i < m && cnt < n; i++)
            if (knight[i] >= head[cnt]) {
                ans += knight[i];
                cnt++;
            }

        if (cnt < n) printf("Loowater is doomed!\n");
        else printf("%d\n", ans);
    }

    return 0;
}
