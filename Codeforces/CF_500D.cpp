// CF500 D
// New Year Santa Network

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 100002;

int n;
int a[MAXN], b[MAXN], l[MAXN];
int q, r, w; 

struct edge { int v, no; };
vector<edge> u[MAXN];

ll weight[MAXN];
ll sum;

int dp(int x, int p, int no) {
    int res = 0;
    for (int i = 0; i < u[x].size(); i++)
        if (u[x][i].v != p)
            res += dp(u[x][i].v, x, u[x][i].no);
    res++;
    weight[no] = (ll)res * (n - res);
    return res;
}

int main() {
    scanf("%d", &n);
    // u.clear();
    for (int i = 1; i < n; i++) {
        scanf("%d%d%d", &a[i], &b[i], &l[i]);
        u[a[i]].push_back((edge){b[i], i});
        u[b[i]].push_back((edge){a[i], i});
    }

    dp(1, -1, 0);

    sum = 0;
    for (int i = 1; i < n; i++)
        sum += weight[i] * l[i];

    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d%d", &r, &w);
        int w0 = l[r];
        sum -= (ll)(w0 - w) * weight[r];
        l[r] = w;
        printf("%lf\n", (double)sum / n / (n - 1) * 6);
    }

    return 0;
}
