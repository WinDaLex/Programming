// UVa 437
// The Tower of Babylon
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

const int MAXN = 32;

struct Block {
    int x, y, z;
    bool operator<(Block rhs) const {
        return this->x < rhs.x || (this->x == rhs.x && this->y < rhs.y);
    }
};

int T, N;
int X[MAXN], Y[MAXN], Z[MAXN];

Block blocks[MAXN * 6];
int top;
map<int, int> f1, f2;

void add(int x, int y, int z) {
    blocks[top++] = (Block) {x, y, z};
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    while (scanf("%d", &N) && N) {
        top = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d%d%d", &X[i], &Y[i], &Z[i]);
            add(X[i], Y[i], Z[i]);
            add(X[i], Z[i], Y[i]);
            add(Y[i], X[i], Z[i]);
            add(Y[i], Z[i], X[i]);
            add(Z[i], X[i], Y[i]);
            add(Z[i], Y[i], X[i]);
        }

        sort(blocks, blocks + N * 6);

        f1.clear();
        f2.clear();
        for (int i = 0; i < N * 6; i++) {
            int cur = blocks[i].y;

            int max_val = 0;
            for (map<int, int>::iterator
                    iter = f1.begin(); iter != f1.end(); iter++)
            {
                int w = iter->first, v = iter->second;
                if (w >= cur) break;
                max_val = max(v, max_val);
            }

            f2[cur] = max(max_val + blocks[i].z, (f2.count(cur) ? f2[cur] : 0));

            if (i < N * 6 - 1 && blocks[i].x < blocks[i + 1].x) {
                for (map<int, int>::iterator
                        iter = f2.begin(); iter != f2.end(); iter++)
                {
                    int w = iter->first, v = iter->second;
                    f1[w] = (f1.count(w) ? max(v, f1[w]) : v);
                }
                f2.clear();
            }
        }

        int ans = 0;
        ans = max_element(f1.begin(), f1.end(), cmp)->second;

        printf("Case %d: maximum height = %d\n", ++T, ans);
    }

    return 0;
}
