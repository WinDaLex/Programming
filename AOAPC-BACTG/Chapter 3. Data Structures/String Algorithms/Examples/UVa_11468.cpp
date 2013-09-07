// UVa 11468
// Substring
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN = 64;
const int MAX_NODE = 500;
const int MAXK = 22;
const int LEN = 102;

int T, K, N, L;
char S[MAXK][22], ch[10];
double P[MAXN];

int idx[256];

struct ac_automaton {
    int ch[MAX_NODE][MAXN];
    bool match[MAX_NODE];
    int f[MAX_NODE];
    int sz;
    bool vis[MAX_NODE][LEN];
    double d[MAX_NODE][LEN];

    void init() {
        sz = 1;
        memset(ch[0], 0, sizeof(ch[0]));
        memset(vis, false, sizeof(vis));
    }

    void insert(char *s) {
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; i++) {
            int c = idx[s[i]];
            if (!ch[u][c]) {
                memset(ch[sz], 0, sizeof(ch[sz]));
                match[sz] = false;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        match[u] = true;
    }

    int get_fail() {
        queue<int> q;
        f[0] = 0;

        for (int c = 0; c < MAXN; c++) {
            int u = ch[0][c];
            if (u) { f[u] = 0; q.push(u); }
        }

        while (!q.empty()) {
            int r = q.front(); q.pop();
            for (int c = 0; c < MAXN; c++) {
                int u = ch[r][c];
                if (!u) { ch[r][c] = ch[f[r]][c]; continue; }
                q.push(u);
                int v = f[r];
                while (v && !ch[v][c]) v = f[v];
                f[u] = ch[v][c];
                match[u] |= match[f[u]];
            }
        }
    }

    double dp(int x, int y) {
        if (!y) return 1.0;
        if (vis[x][y]) return d[x][y];
        vis[x][y] = true;

        d[x][y] = 0.0;
        for (int i = 0; i < N; i++)
            if (!match[ch[x][i]])
                d[x][y] += P[i] * dp(ch[x][i], y - 1);
        return d[x][y];
    }
};

ac_automaton ac;

int main() {
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d", &K);
        for (int i = 0; i < K; i++)
            scanf("%s", S[i]);

        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%s%lf", ch, &P[i]);
            idx[ch[0]] = i;
        }
        scanf("%d", &L);

        ac.init();
        for (int i = 0; i < K; i++)
            ac.insert(S[i]);
        ac.get_fail();

        printf("Case #%d: %.6lf\n", cas, ac.dp(0, L));
    }

    return 0;
}
