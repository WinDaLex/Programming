// UVa 1449
// Dominating Patterns
// by A Code Rabbit

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN = 150 + 2;
const int PLEN = 70 + 2;
const int TLEN = 1000000 + 2;
const int MAXM = 150 * 70 + 2;
const int ALPHA = 26 + 2;

int cnt[MAXN];

struct ac_automaton {
    int ch[MAXM][ALPHA];
    int val[MAXM];
    int f[MAXM];
    int last[MAXM];
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
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        val[u] = v;
    }

    void find(char *t) {
        int n = strlen(t);
        int j = 0;
        for (int i = 0; i < n; i++) {
            int c = idx(t[i]);
            while (j && !ch[j][c]) j = f[j];
            j = ch[j][c];
            if (val[j]) {
            //    printf("%d: ", i);
            //    print(j);
                cnt[val[j]]++;
            } else if (last[j]) {
            //    printf("%d: ", i);
            //    print(last[j]);
                cnt[val[last[j]]]++;
            }
        }
    }

    void print(int j) {
        if (j) {
            printf("%d\n", val[j]);
            print(last[j]);
        }
    }

    int get_fail() {
        queue<int> q;
        f[0] = 0;

        for (int c = 0; c < ALPHA; c++) {
            int u = ch[0][c];
            if (u) { f[u] = 0; q.push(u); last[u] = 0; }
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
                last[u] = val[f[u]] ? f[u] : last[f[u]];
            }
        }
    }
};

int N;
char P[MAXN][PLEN];
char T[TLEN];

ac_automaton ac;

int main() {
    while (scanf("%d", &N) == 1 && N) {
        for (int i = 1; i <= N; i++)
            scanf("%s", P[i]);
        scanf("%s", T);

        memset(cnt, 0, sizeof(cnt));
        ac.init();
        for (int i = 1; i <= N; i++)
            ac.insert(P[i], i);
        ac.get_fail();

        ac.find(T);

        int max_val = 0;
        for (int i = 1; i <= N; i++)
            max_val = max(max_val, cnt[i]);

        printf("%d\n", max_val);
        for (int i = 1; i <= N; i++)
            if (cnt[i] == max_val)
                puts(P[i]);
    }

    return 0;
}
