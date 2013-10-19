struct fenwick_tree {
    int c[MAXN], n;

    void init(int n) {
        memset(c, 0, sizeof(c));
        this->n = n;
    }

    void add(int x, int v) {
        for (int i = x; i <= n; i+= i & -i)
            c[i] += v;
    }

    int sum(int x) {
        int res = 0;
        for (int i = x; i > 0; i -= i & -i)
            res += c[i];
        return res;
    }
};

struct new_fenwick_tree { 
    fenwick_tree b1, b2; 

    void init(int x) {
        b1.init(x); b2.init(x);
    } 

    void add(int x, int y, int z) { 
        b1.add(x, z); 
        b1.add(y + 1, -z); 
        b2.add(x, z * x); 
        b2.add(y + 1, -z * (y + 1)); 
    } 

    int sum(int x) {
        return (x + 1) * b1.sum(x) - b2.sum(x);
    } 
};

struct fenwick_tree_2d {
    int c[MAXN][MAXM], n, m;

    void init(int x, int y) {
        memset(c, 0, sizeof(c)); n = x; m = y;
    }

    void add(int x, int y, int z) {
        int tmp = y;
        while (x <= n) {
            y = tmp;
            while (y <= m) {
                c[x][y] += z;
                y += y & -y;
            }
            x += x & -x;
        }
    }

    int sum(int x, int y) {
        int res = 0, tmp = y;
        while (x > 0) {
            y = tmp;
            while (y > 0) {
                res += c[x][y];
                y -= y & -y;
            }
            x -= x & -x;
        }
        return res;
    }
};
