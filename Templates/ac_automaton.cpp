struct AcAutomaton {
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
                printf("%d: ", i);
                print(j);
            } else if (last[j]) {
                printf("%d: ", i);
                print(last[j]);
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
