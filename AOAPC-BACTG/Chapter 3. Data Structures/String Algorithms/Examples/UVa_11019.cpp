// UVa 11019
// Matrix Matcher
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 1002, MAXM = 1002;
const int MAXX = 102, MAXY = 102;
const int ALPHA = 26;

int T, N, M, X, Y;
char S[MAXN][MAXM], P[MAXX][MAXY];

int cnt[MAXN][MAXM];

struct ac_automaton {
    int ch[MAXX * MAXY][ALPHA];
    vector<int> val[MAXX * MAXY];
    int f[MAXX * MAXY];
    int sz;

    void init() {
        sz = 1;
        memset(ch[0], 0, sizeof(ch[0]));
    }

    int idx(char c) {
        return c - 'a';
    }

    void insert(char *s, int v) {
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; i++) {
            int c = idx(s[i]);
            if (!ch[u][c]) {
                memset(ch[sz], 0, sizeof(ch[sz]));
                val[sz].clear();
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        val[u].push_back(v);
    }

    void find(char *t, int r) {
        int n = strlen(t);
        int j = 0;
        for (int i = 0; i < n; i++) {
            int c = idx(t[i]);
            while (j && !ch[j][c]) j = f[j];
            j = ch[j][c];
            if (!val[j].empty())
                for (vector<int>::iterator iter = val[j].begin(); iter != val[j].end(); iter++)
                    if (r - *iter >= 0)
                        cnt[r - *iter][i]++;
        }
    }

    int get_fail() {
        queue<int> q;
        f[0] = 0;

        for (int c = 0; c < ALPHA; c++) {
            int u = ch[0][c];
            if (u) { f[u] = 0; q.push(u); }
        }

        while (!q.empty()) {
            int r = q.front(); q.pop();
            for (int c = 0; c < ALPHA; c++) {
                int u = ch[r][c];
                if (!u) continue;
                q.push(u);
                int v = f[r];
                while (v && !ch[v][c]) v = f[v];
                f[u] = ch[v][c];
            }
        }
    }
} acm;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; i++)
            scanf("%s", S[i]);
        scanf("%d%d", &X, &Y);
        for (int i = 0; i < X; i++)
            scanf("%s", P[i]);
    
        memset(cnt, 0, sizeof(cnt));
        acm.init();
        for (int i = 0; i < X; i++)
            acm.insert(P[i], i);
        acm.get_fail();
        for (int i = 0; i < N; i++)
            acm.find(S[i], i);

        int ans = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (cnt[i][j] == X)
                    ans++;

        printf("%d\n", ans);
    }

    return 0;
}
