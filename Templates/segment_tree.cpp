#define lson(x) ((x) << 1)
#define rson(x) ((x) << 1 | 1)

const int MAXN = the number of leaves of the segment tree;
const int ROOT = 1;

// single point updated
struct seg{
    int w;
};

struct segment_tree {
    seg node[MAXN * 4];

    void update(int pos) {
        node[pos].w = node[lson(pos)].w + node[rson(pos)].w;
    }

    void build(int l, int r, int pos) {
        if (l == r) { node[pos].w = 0; return; }
        int m = l + r >> 1;
        build(l, m, lson(pos));
        build(m + 1, r, rson(pos));
        update(pos);
    }

    void modify(int l, int r, int pos, int x, int y) {
        if (l == r) { node[pos].w += y; return; }
        int m = l + r >> 1;
        if (x <= m) modify(l, m, lson(pos), x, y);
        else modify(m + 1, r, rson(pos), x, y);
        update(pos);
    }

    int query(int l, int r, int pos, int x, int y) {
        if (x <= l && r <= y) return node[pos].w;
        int m = l + r >> 1;
        int res = 0;
        if (x <= m) res += query(l, m, lson(pos), x, y);
        if (y > m) res += query(m + 1, r, rson(pos), x, y);
        return res;
    }

    int remove(int l, int r, int pos, int x) {
        if (l == r) { node[pos].w = 0; return l; }
        int m = l + r >> 1;
        int res;
        if (x < node[lson(pos)].w) res = remove(l, m, lson(pos), x);
        else res= remove(m + 1, r, rson(pos), x - node[lson(pos)].w);
        update(pos);
        return res;
    }

};

// segment updated
struct seg {
    int w;
    int flag;
};

struct segment_tree {
    seg node[MAXN << 2];
    void update(int pos) { node[pos].w = node[lson(pos)].w + node[rson(pos)].w; }
    void build(int l, int r, int pos) {
        node[pos].flag = 0;
        if (l == r) {
            node[pos].w = 0;
            return;
        }
        int m = l + r >> 1;
        build(l, m, lson(pos));
        build(m + 1, r, rson(pos));
        update(pos);
    }
    void push(int l, int r, int pos) {
        seg& father = node[pos];
        seg& lson = node[lson(pos)];
        seg& rson = node[rson(pos)];
        int len = r + 1 - l;
        if (father.flag) {
            lson.flag += father.flag;
            rson.flag += father.flag;
            lson.w += father.flag * (len - (len >> 1));
            rson.w += father.flag * (len >> 1);
            father.flag = 0;
        }
    }
    void modify(int l, int r, int pos, int x, int y, int z) {
        if (x <= l && r <= y) {
            int len = r + 1 - l;
            node[pos].w += z * len;
            node[pos].flag += z;
            /* node[pos].flag = z; is wrong. */
            return;
        }
        push(l, r, pos);
        int m = l + r >> 1;
        if (x <= m) modify(l, m, lson(pos), x, y, z);
        if (y > m) modify(m + 1, r, rson(pos), x, y, z);
        update(pos);
    }
    int query(int l, int r, int pos, int x, int y) {
        if (x <= l && r <= y) return node[pos].w;
        push(l, r, pos);
        int m = l + r >> 1;
        int res = 0;
        if (x <= m) res += query(l, m, lson(pos), x, y);
        if (y > m) res += query(m + 1, r, rson(pos), x, y);
        return res;
    }
};
