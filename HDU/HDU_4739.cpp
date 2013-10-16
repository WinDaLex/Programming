// HDU 4739
// Zhuge Liang's Mines
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 22;

struct coord {
    int x, y;
    bool operator<(coord rhs) const {
        return x < rhs.x || (x == rhs.x && y < rhs.y);
    }
};

int N;
coord mine[MAXN];

int f[1 << MAXN];

bool check(coord a, coord b, coord c, coord d) {
    return (a.x == b.x && b.y == d.y && d.x == c.x && c.y == a.y)
        && (b.y - a.y == d.x - b.x);
}

int main() {
    while (scanf("%d", &N) && N != -1) {
        for (int i = 0; i < N; i++)
            scanf("%d%d", &mine[i].x, &mine[i].y);

        sort(mine, mine + N);

        vector<int> square;
        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++)
                for (int k = j + 1; k < N; k++)
                    for (int l = k + 1; l < N; l++)
                        if (check(mine[i], mine[j], mine[k], mine[l]))
                            square.push_back((1 << i) + (1 << j) + (1 << k) + (1 << l));

        memset(f, 0, sizeof(f));
        for (int x = 0; x < 1 << N; x++)
            for (int i = 0; i < square.size(); i++)
                if ((x & square[i]) == square[i])
                    f[x] = max(f[x], f[x ^ square[i]] + 1);

        printf("%d\n", f[(1 << N) - 1] * 4);
    }

    return 0;
}
