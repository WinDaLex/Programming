// CF500 C
// New Year Book Reading

#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

const int MAXN = 502;
const int MAXM = 1002;

int n, m;
int w[MAXN], b[MAXM];

int a[MAXN];
bool vis[MAXN];
set<int> s;
int ans;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &w[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);
     
    ans = 0;
    for (int i = 0; i < m; i++) {
        s.clear();
        for (int j = i - 1; j >= 0 && b[j] != b[i]; j--) {
            if (!s.count(b[j])) {
                ans += w[b[j] - 1];
                s.insert(b[j]);
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
