struct disjoint_set {
    int p[MAXN];

    void init(int n) {
        for (int i = 1; i <= n; i++)
            p[i] = i;
    }

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    int merge(int x, int y) {
        p[find(x)] = find(y);
    }
};

struct disjoint_set {
    int p[MAXN];
    int w[MAXN];

    void init(int n) {
        memset(w, 0, sizeof(w));
        for (int i = 0; i < n; i++)
            p[i] = i;
    }

    int find(int x) {
        if (p[x] == x) return x;
        int tmp = find(p[x]);
        w[x] = (w[x] + w[p[x]]) % MOD;
        return p[x] = tmp;
    }

    void merge(int x, int y, int d) {
        int px = find(x), py = find(y);
        p[px] = py;
        w[px] = (w[y] - w[x] + d + MOD) % MOD;
    }
};
