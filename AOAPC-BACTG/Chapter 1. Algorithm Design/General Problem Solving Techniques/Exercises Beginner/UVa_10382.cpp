// UVa 10382
// Watering Grass
// by A Code Rabbit

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct Sprinkler {
    double l, r;
    bool operator<(Sprinkler rhs) const { return this->l < rhs.l; }
};

const int MAXN = 10002;

int N, L, W;
int p, r;

Sprinkler sprinkler[MAXN];

int main() {
    while (scanf("%d%d%d", &N, &L, &W) != EOF) {
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &p, &r);
            if (r < W / 2.0) {
                sprinkler[i] = (Sprinkler){L, L};
                continue;
            }
            double tmp = sqrt(pow(r, 2) - pow(W / 2.0, 2));
            sprinkler[i] = (Sprinkler){p - tmp, p + tmp};
        }

        sort(sprinkler, sprinkler + N);

        double last = 0, cur = 0;
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (cur >= L) break;
            if (sprinkler[i].l > cur) break;
            if (sprinkler[i].l > last) {
                last = cur;
                ans++;
            }
            cur = max(sprinkler[i].r, cur);
        }

        printf("%d\n", cur >= L ? ans + 1 : -1);
    }

    return 0;
}
